#!/bin/sh

cd ./kern/
echo "Building kernel..."
make kernel
cd ../user
echo "Building userland..."
make userland
cd ../ #end where we started
