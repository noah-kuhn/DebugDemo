#
# Makefile for debugging demo
# Authors: Thomas Peavler, Noah Kuhn
#

CC=gcc
CC_FLAGS= -g -o0 -Wall
DEPS = debug.h

all:
	$(CC) $(CC_FLAGS) -o debug debug.c

clean:
	rm debug