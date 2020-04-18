CC = gcc
CFLAGS = -pthread -lrt 

all: server client


server:
		gcc -o example/server example/server.c lib/network.c $(CFLAGS)

client:
		gcc -o example/client example/client.c lib/network.c

reset:
		rm -rf example/client example/server
