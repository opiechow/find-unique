#!/bin/sh
# Could have been a Makefile but I'm too lazy
gcc -std=c11 -Wall -pthread -lm main.c -o main
./main
