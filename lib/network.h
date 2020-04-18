#ifndef __NETWORK__
#define __NETWORK__


/* Import Standard Libs */

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>

/* Structs to store Server and Client interface details. */

struct sockaddr_in server, client;

/* Create Server and Client sockets. */

int create_socket();

/* Server Functions */

void server_endpoint(int port, char * address);

void server_bind(int sock);

void server_listen(int sock, int backlog);

int server_accept(int sock, struct sockaddr_in client, int client_size);

/* Client Functions */

void client_connect(int sock);

/* Data commands for sending and receiving data. */

void send_string(int socket, char * string);

void send_int(int socket, int integer);

void receive_string(int socket, char * output);

int receive_int(int socket);

#endif
