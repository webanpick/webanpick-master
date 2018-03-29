FROM phusion/baseimage:0.9.19

#ARG WEBANPICKD_BLOCKCHAIN=https://example.com/webanpickd-blockchain.tbz2

ARG WEBANPICK_STATIC_BUILD=ON
ENV WEBANPICK_STATIC_BUILD ${WEBANPICK_STATIC_BUILD}

ENV LANG=en_US.UTF-8

RUN \
    apt-get update && \
    apt-get install -y \
        autoconf \
        automake \
        autotools-dev \
        bsdmainutils \
        build-essential \
        cmake \
        doxygen \
        gdb \
        git \
        libboost-all-dev \
        libreadline-dev \
        libssl-dev \
        libtool \
        ncurses-dev \
        pbzip2 \
        pkg-config \
        python3 \
        python3-dev \
        python3-jinja2 \
        python3-pip \
        nginx \
        fcgiwrap \
        awscli \
        jq \
        wget \
        virtualenv \
    && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* && \
    pip3 install gcovr

ADD . /usr/local/src/webanpick

RUN \
    cd /usr/local/src/webanpick && \
    git submodule update --init --recursive && \
    mkdir build && \
    cd build && \
    cmake \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_WEBANPICK_TESTNET=ON \
        -DLOW_MEMORY_NODE=OFF \
        -DCLEAR_VOTES=ON \
        -DSKIP_BY_TX_ID=ON \
        .. && \
    make -j$(nproc) chain_test test_fixed_string plugin_test && \
    ./tests/chain_test && \
    ./tests/plugin_test && \
    ./programs/util/test_fixed_string && \
    cd /usr/local/src/webanpick && \
    doxygen && \
    programs/build_helpers/check_reflect.py && \
    programs/build_helpers/get_config_check.sh && \
    rm -rf /usr/local/src/webanpick/build

RUN \
    cd /usr/local/src/webanpick && \
    git submodule update --init --recursive && \
    mkdir build && \
    cd build && \
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr/local/webanpickd-testnet \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_WEBANPICK_TESTNET=ON \
        -DLOW_MEMORY_NODE=OFF \
        -DCLEAR_VOTES=ON \
        -DSKIP_BY_TX_ID=ON \
        -DENABLE_SMT_SUPPORT=ON \
        -DWEBANPICK_STATIC_BUILD=${WEBANPICK_STATIC_BUILD} \
        .. && \
    make -j$(nproc) chain_test test_fixed_string plugin_test && \
    make install && \
    ./tests/chain_test && \
    ./tests/plugin_test && \
    ./programs/util/test_fixed_string && \
    cd /usr/local/src/webanpick && \
    doxygen && \
    programs/build_helpers/check_reflect.py && \
    programs/build_helpers/get_config_check.sh && \
    rm -rf /usr/local/src/webanpick/build

RUN \
    cd /usr/local/src/webanpick && \
    git submodule update --init --recursive && \
    mkdir build && \
    cd build && \
    cmake \
        -DCMAKE_BUILD_TYPE=Debug \
        -DENABLE_COVERAGE_TESTING=ON \
        -DBUILD_WEBANPICK_TESTNET=ON \
        -DLOW_MEMORY_NODE=OFF \
        -DCLEAR_VOTES=ON \
        -DSKIP_BY_TX_ID=ON \
        -DCHAINBASE_CHECK_LOCKING=OFF \
        .. && \
    make -j$(nproc) chain_test plugin_test && \
    ./tests/chain_test && \
    ./tests/plugin_test && \
    mkdir -p /var/cobertura && \
    gcovr --object-directory="../" --root=../ --xml-pretty --gcov-exclude=".*tests.*" --gcov-exclude=".*fc.*" --gcov-exclude=".*app*" --gcov-exclude=".*net*" --gcov-exclude=".*plugins*" --gcov-exclude=".*schema*" --gcov-exclude=".*time*" --gcov-exclude=".*utilities*" --gcov-exclude=".*wallet*" --gcov-exclude=".*programs*" --output="/var/cobertura/coverage.xml" && \
    cd /usr/local/src/webanpick && \
    rm -rf /usr/local/src/webanpick/build

RUN \
    cd /usr/local/src/webanpick && \
    git submodule update --init --recursive && \
    mkdir build && \
    cd build && \
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr/local/webanpickd-default \
        -DCMAKE_BUILD_TYPE=Release \
        -DLOW_MEMORY_NODE=ON \
        -DCLEAR_VOTES=ON \
        -DSKIP_BY_TX_ID=OFF \
        -DBUILD_WEBANPICK_TESTNET=OFF \
        -DWEBANPICK_STATIC_BUILD=${WEBANPICK_STATIC_BUILD} \
        .. \
    && \
    make -j$(nproc) && \
    make install && \
    cd .. && \
    ( /usr/local/webanpickd-default/bin/webanpickd --version \
      | grep -o '[0-9]*\.[0-9]*\.[0-9]*' \
      && echo '_' \
      && git rev-parse --short HEAD ) \
      | sed -e ':a' -e 'N' -e '$!ba' -e 's/\n//g' \
      > /etc/webanpickdversion && \
    cat /etc/webanpickdversion && \
    rm -rfv build && \
    mkdir build && \
    cd build && \
    cmake \
        -DCMAKE_INSTALL_PREFIX=/usr/local/webanpickd-full \
        -DCMAKE_BUILD_TYPE=Release \
        -DLOW_MEMORY_NODE=OFF \
        -DCLEAR_VOTES=OFF \
        -DSKIP_BY_TX_ID=ON \
        -DBUILD_WEBANPICK_TESTNET=OFF \
        -DWEBANPICK_STATIC_BUILD=${WEBANPICK_STATIC_BUILD} \
        .. \
    && \
    make -j$(nproc) && \
    make install && \
    rm -rf /usr/local/src/webanpick

RUN \
    apt-get remove -y \
        automake \
        autotools-dev \
        bsdmainutils \
        build-essential \
        cmake \
        doxygen \
        dpkg-dev \
        libboost-all-dev \
        libc6-dev \
        libexpat1-dev \
        libgcc-5-dev \
        libhwloc-dev \
        libibverbs-dev \
        libicu-dev \
        libltdl-dev \
        libncurses5-dev \
        libnuma-dev \
        libopenmpi-dev \
        libpython-dev \
        libpython2.7-dev \
        libreadline-dev \
        libreadline6-dev \
        libssl-dev \
        libstdc++-5-dev \
        libtinfo-dev \
        libtool \
        linux-libc-dev \
        m4 \
        make \
        manpages \
        manpages-dev \
        mpi-default-dev \
        python-dev \
        python2.7-dev \
        python3-dev \
    && \
    apt-get autoremove -y && \
    rm -rf \
        /var/lib/apt/lists/* \
        /tmp/* \
        /var/tmp/* \
        /var/cache/* \
        /usr/include \
        /usr/local/include

RUN useradd -s /bin/bash -m -d /var/lib/webanpickd webanpickd

RUN mkdir /var/cache/webanpickd && \
    chown webanpickd:webanpickd -R /var/cache/webanpickd

# add blockchain cache to image
#ADD $WEBANPICKD_BLOCKCHAIN /var/cache/webanpickd/blocks.tbz2

ENV HOME /var/lib/webanpickd
RUN chown webanpickd:webanpickd -R /var/lib/webanpickd

VOLUME ["/var/lib/webanpickd"]

# rpc service:
EXPOSE 8090
# p2p service:
EXPOSE 2001

# add seednodes from documentation to image
ADD doc/seednodes.txt /etc/webanpickd/seednodes.txt

# the following adds lots of logging info to stdout
ADD contrib/config-for-docker.ini /etc/webanpickd/config.ini
ADD contrib/fullnode.config.ini /etc/webanpickd/fullnode.config.ini
ADD contrib/fullnode.opswhitelist.config.ini /etc/webanpickd/fullnode.opswhitelist.config.ini
ADD contrib/config-for-broadcaster.ini /etc/webanpickd/config-for-broadcaster.ini
ADD contrib/config-for-ahnode.ini /etc/webanpickd/config-for-ahnode.ini
ADD contrib/testnet.config.ini /etc/webanpickd/testnet.config.ini
ADD contrib/fastgen.config.ini /etc/webanpickd/fastgen.config.ini

# add normal startup script that starts via sv
ADD contrib/webanpickd.run /usr/local/bin/webanpick-sv-run.sh
RUN chmod +x /usr/local/bin/webanpick-sv-run.sh

# add nginx templates
ADD contrib/webanpickd.nginx.conf /etc/nginx/webanpickd.nginx.conf
ADD contrib/healthcheck.conf.template /etc/nginx/healthcheck.conf.template

# add PaaS startup script and service script
ADD contrib/startpaaswebanpickd.sh /usr/local/bin/startpaaswebanpickd.sh
ADD contrib/testnetinit.sh /usr/local/bin/testnetinit.sh
ADD contrib/paas-sv-run.sh /usr/local/bin/paas-sv-run.sh
ADD contrib/sync-sv-run.sh /usr/local/bin/sync-sv-run.sh
ADD contrib/healthcheck.sh /usr/local/bin/healthcheck.sh
RUN chmod +x /usr/local/bin/startpaaswebanpickd.sh
RUN chmod +x /usr/local/bin/testnetinit.sh
RUN chmod +x /usr/local/bin/paas-sv-run.sh
RUN chmod +x /usr/local/bin/sync-sv-run.sh
RUN chmod +x /usr/local/bin/healthcheck.sh

# new entrypoint for all instances
# this enables exitting of the container when the writer node dies
# for PaaS mode (elasticbeanstalk, etc)
# AWS EB Docker requires a non-daemonized entrypoint
ADD contrib/webanpickdentrypoint.sh /usr/local/bin/webanpickdentrypoint.sh
RUN chmod +x /usr/local/bin/webanpickdentrypoint.sh
CMD /usr/local/bin/webanpickdentrypoint.sh
