#
# Makefile for debugging demo
# Authors: Thomas Peavler, Noah Kuhn
#

CC=gcc
CC_FLAGS= -g -I.
DEPS = debug.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CC_FLAGS)

debugdemo: debug.o
	$(CC) -o debug debug.o