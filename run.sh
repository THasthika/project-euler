#!/bin/bash

cd $1

make clean
make
bin/main
