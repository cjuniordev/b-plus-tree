#!/bin/bash

BIN_DIR=./bin
if [ ! -d "$BIN_DIR" ];
then
    mkdir $BIN_DIR
fi

make && bin/bplus