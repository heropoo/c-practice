# FROM ubuntu:14.04  trusty
# FROM ubuntu:16.04  xenial
# FROM ubuntu:18.04  bionic
# FROM ubuntu:20.04  focal
# FROM ubuntu:22.04  jammy 
# FROM ubuntu:24.04  noble  last
FROM ubuntu:24.04

# set a faster repositorie
# RUN sed -i 's/security.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list \
#    && sed -i 's/archive.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list

RUN apt-get update && apt-get install -y openssh-server gcc make flex bison

RUN sed -i s/#PermitRootLogin.*/PermitRootLogin\ yes/ /etc/ssh/sshd_config

ENV ROOT_PASSWORD 123456
RUN echo "root:${ROOT_PASSWORD}" | chpasswd

EXPOSE 22

COPY entrypoint.sh /usr/bin/
RUN chmod +x /usr/bin/entrypoint.sh

CMD ["/usr/bin/entrypoint.sh"]
