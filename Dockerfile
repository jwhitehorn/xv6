FROM debian:10.2

RUN apt-get update
RUN apt-get -y install build-essential qemu qemu-kvm
RUN apt-get -y install gcc-multilib

RUN mkdir /src
WORKDIR /src/
COPY . .

CMD ./build.sh && QEMUEXTRA=-nographic make qemu
