#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start webanpickd traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/webanpickd
  cp /usr/local/bin/webanpick-sv-run.sh /etc/service/webanpickd/run
  chmod +x /etc/service/webanpickd/run
  runsv /etc/service/webanpickd
elif [[ "$IS_TESTNET" ]]; then
  /usr/local/bin/testnetinit.sh
else
  /usr/local/bin/startpaaswebanpickd.sh
fi
