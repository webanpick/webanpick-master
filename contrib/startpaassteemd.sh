#!/bin/bash

VERSION=`cat /etc/webanpickdversion`

if [[ "$IS_BROADCAST_NODE" ]]; then
  WEBANPICKD="/usr/local/webanpickd-default/bin/webanpickd"
elif [[ "$IS_AH_NODE" ]]; then
  WEBANPICKD="/usr/local/webanpickd-default/bin/webanpickd"
else
  WEBANPICKD="/usr/local/webanpickd-full/bin/webanpickd"
fi

chown -R webanpickd:webanpickd $HOME

# clean out data dir since it may be semi-persistent block storage on the ec2 with stale data
rm -rf $HOME/*

# seed nodes come from doc/seednodes.txt which is
# installed by docker into /etc/webanpickd/seednodes.txt
SEED_NODES="$(cat /etc/webanpickd/seednodes.txt | awk -F' ' '{print $1}')"

ARGS=""

# if user did not pass in any desired
# seed nodes, use the ones above:
if [[ -z "$WEBANPICKD_SEED_NODES" ]]; then
    for NODE in $SEED_NODES ; do
        ARGS+=" --p2p-seed-node=$NODE"
    done
fi

# if user did pass in desired seed nodes, use
# the ones the user specified:
if [[ ! -z "$WEBANPICKD_SEED_NODES" ]]; then
    for NODE in $WEBANPICKD_SEED_NODES ; do
        ARGS+=" --p2p-seed-node=$NODE"
    done
fi

NOW=`date +%s`
WEBANPICKD_FEED_START_TIME=`expr $NOW - 1209600`

ARGS+=" --follow-start-feeds=$WEBANPICKD_FEED_START_TIME"

WEBANPICKD_PROMOTED_START_TIME=`expr $NOW - 604800`
ARGS+=" --tags-start-promoted=$WEBANPICKD_PROMOTED_START_TIME"

if [[ ! "$DISABLE_BLOCK_API" ]]; then
   ARGS+=" --plugin=block_api"
fi

# overwrite local config with image one
if [[ "$IS_BROADCAST_NODE" ]]; then
  cp /etc/webanpickd/config-for-broadcaster.ini $HOME/config.ini
elif [[ "$IS_AH_NODE" ]]; then
  cp /etc/webanpickd/config-for-ahnode.ini $HOME/config.ini
elif [[ "$IS_OPSWHITELIST_NODE" ]]; then
  cp /etc/webanpickd/fullnode.opswhitelist.config.ini $HOME/config.ini
else
  cp /etc/webanpickd/fullnode.config.ini $HOME/config.ini
fi

chown webanpickd:webanpickd $HOME/config.ini

cd $HOME

mv /etc/nginx/nginx.conf /etc/nginx/nginx.original.conf
cp /etc/nginx/webanpickd.nginx.conf /etc/nginx/nginx.conf

# get blockchain state from an S3 bucket
echo webanpickd: beginning download and decompress of s3://$S3_BUCKET/blockchain-$VERSION-latest.tar.bz2
if [[ "$USE_RAMDISK" ]]; then
  mkdir -p /mnt/ramdisk
  mount -t ramfs -o size=${RAMDISK_SIZE_IN_MB:-51200}m ramfs /mnt/ramdisk
  ARGS+=" --shared-file-dir=/mnt/ramdisk/blockchain"
  if [[ "$IS_BROADCAST_NODE" ]]; then
    aws s3 cp s3://$S3_BUCKET/broadcast-$VERSION-latest.tar.bz2 - | pbzip2 -m2000dc | tar x --wildcards 'blockchain/block*' -C /mnt/ramdisk 'blockchain/shared*'
  elif [[ "$IS_AH_NODE" ]]; then
    aws s3 cp s3://$S3_BUCKET/ahnode-$VERSION-latest.tar.bz2 - | pbzip2 -m2000dc | tar x --wildcards 'blockchain/block*' -C /mnt/ramdisk 'blockchain/shared*'
  else
    aws s3 cp s3://$S3_BUCKET/blockchain-$VERSION-latest.tar.bz2 - | pbzip2 -m2000dc | tar x --wildcards 'blockchain/block*' -C /mnt/ramdisk 'blockchain/shared*'
  fi
  chown -R webanpickd:webanpickd /mnt/ramdisk/blockchain
else
  if [[ "$IS_BROADCAST_NODE" ]]; then
    aws s3 cp s3://$S3_BUCKET/broadcast-$VERSION-latest.tar.bz2 - | pbzip2 -m2000dc | tar x
  elif [[ "$IS_AH_NODE" ]]; then
    aws s3 cp s3://$S3_BUCKET/ahnode-$VERSION-latest.tar.bz2 - | pbzip2 -m2000dc | tar x
  else
    aws s3 cp s3://$S3_BUCKET/blockchain-$VERSION-latest.tar.bz2 - | pbzip2 -m2000dc | tar x
  fi
fi
if [[ $? -ne 0 ]]; then
  if [[ ! "$SYNC_TO_S3" ]]; then
    echo notifyalert webanpickd: unable to pull blockchain state from S3 - exiting
    exit 1
  else
    echo notifywebanpickdsync webanpickdsync: shared memory file for $VERSION not found, creating a new one by replaying the blockchain
    mkdir blockchain
    aws s3 cp s3://$S3_BUCKET/block_log-latest blockchain/block_log
    if [[ $? -ne 0 ]]; then
      echo notifywebanpickdsync webanpickdsync: unable to pull latest block_log from S3, will sync from scratch.
    else
      ARGS+=" --replay-blockchain --force-validate"
    fi
    touch /tmp/isnewsync
  fi
fi

# for appbase tags plugin loading
ARGS+=" --tags-skip-startup-update"

cd $HOME

if [[ "$SYNC_TO_S3" ]]; then
  touch /tmp/issyncnode
  chown www-data:www-data /tmp/issyncnode
fi

chown -R webanpickd:webanpickd $HOME/*

# let's get going
cp /etc/nginx/healthcheck.conf.template /etc/nginx/healthcheck.conf
echo server 127.0.0.1:8091\; >> /etc/nginx/healthcheck.conf
echo } >> /etc/nginx/healthcheck.conf
rm /etc/nginx/sites-enabled/default
cp /etc/nginx/healthcheck.conf /etc/nginx/sites-enabled/default
/etc/init.d/fcgiwrap restart
service nginx restart
exec chpst -uwebanpickd \
    $WEBANPICKD \
        --webserver-ws-endpoint=127.0.0.1:8091 \
        --webserver-http-endpoint=127.0.0.1:8091 \
        --p2p-endpoint=0.0.0.0:2001 \
        --data-dir=$HOME \
        $ARGS \
        $WEBANPICKD_EXTRA_OPTS \
        2>&1&
SAVED_PID=`pgrep -f p2p-endpoint`
echo $SAVED_PID >> /tmp/webanpickdpid
mkdir -p /etc/service/webanpickd
if [[ ! "$SYNC_TO_S3" ]]; then
  cp /usr/local/bin/paas-sv-run.sh /etc/service/webanpickd/run
else
  cp /usr/local/bin/sync-sv-run.sh /etc/service/webanpickd/run
fi
chmod +x /etc/service/webanpickd/run
runsv /etc/service/webanpickd
