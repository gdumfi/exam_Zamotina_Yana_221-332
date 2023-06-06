FROM ubuntu

MAINTAINER Zamotina Yana 221-332

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools -y
RUN apt-get install build-essential -y

WORKDIR /root/
RUN mkdir server
WORKDIR /root/server/
COPY *.cpp /root/server/
COPY *.h /root/server/
COPY *.pro /root/server/

RUN qmake setvetToStart.pro
RUN make setvetToStart

ENTRYPOINT ["./setvetToStart"]
