#
# Makefile for debugging demo
# Authors: Thomas Peavler, Noah Kuhn
#

CC=gcc
CFLAGS=-I.
DEPS = debug.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

debugdemo: debug.o
	$(CC) -o debug debug.o