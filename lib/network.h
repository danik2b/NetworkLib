#ifndef __NETWORK__
#define __NETWORK__


/* Import Standard Libs */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Structs to store Server and Client interface details. */

struct sockaddr_in server, client;
