#!/bin/sh

cd ./kern/
echo "Building kernel..."
make kernel || exit 1
cd ../user
echo "Building userland..."
make userland || exit 1
cd ../ #end where we started
