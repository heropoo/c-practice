FROM ubuntu:18.04

MAINTAINER	Heropoo "aiyouyou1000@163.com"

#set a faster repositorie
RUN cp /etc/apt/sources.list /etc/apt/sources.list.bk \
    && sed -i 's/security.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list \
    && sed -i 's/archive.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list

RUN apt-get update && apt-get -y install vim git gcc g++ make autoconf
