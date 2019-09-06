#!/bin/zsh

rm /mnt/c/Users/lxlps/Desktop/dpd_c
make clean
make
cp -f /mnt/c/Users/lxlps/Desktop/dpd/dpd_c /mnt/c/Users/lxlps/Desktop/dpd_c
sync