FROM debian:10.2

RUN apt-get update
RUN apt-get -y install build-essential qemu qemu-kvm

RUN mkdir /src
WORKDIR /src/

CMD cd ./kern/ && make kernel && cd ../ && QEMUEXTRA=-nographic make qemu
