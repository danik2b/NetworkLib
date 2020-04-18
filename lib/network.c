
#include "network.h"

/* Create Server and Client sockets. */

int server_socket()
{
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  if(sock == -1)
  {
    perror("Server socket was not created!");
    exit(1);
  }

  return sock;
}

int client_socket()
{

  int sock = socket(AF_INET,SOCK_STREAM,0);

  if(sock == -1)
  {
    perror("Client socket was not created!");
    exit(1);
  }

  return sock;
}

/* Server Functions */

void server_endpoint(int port, char *address)
{
  bzero((char *) &server, sizeof(server)); //zero out server struct.

  server.sin_family = AF_INET; // set the protocol.
  server.sin_addr.s_addr = inet_addr(address); //set the ip address.
  server.sin_port = htons(port); //set the port number to listen on.
}

void server_bind(int sock)
{
  if(bind(sock, (struct sockaddr *)&server,sizeof(server)) == -1)
  {
      perror("Server socket was not bound!");
      exit(1);
  }
}

void server_listen(int sock, int backlog)
{
  listen(sock, backlog);
}

int server_accept(int sock, struct sockaddr_in client, int client_size)
{
  int new_con = accept(sock, (struct sockaddr *)&client, &client_size); //accept the new connection.

  return new_con;
}

/* Client Functions */

void client_connect(int socket)
{
  if(connect(socket, (struct sockaddr *)&server, sizeof(server)) == -1)
  {
    perror("Client socket couldn't connect!");
    exit(1);
  }
}

/* Data command functions. */

void send_string(int socket, char * string)
{
  write(socket, string, strlen(string));
}

void send_int(int socket, int integer)
{
  write(socket, &integer, sizeof(int));
}

void receive_string(int socket, char *output)
{
  read(socket, output, sizeof(output));
}

int receive_int(int socket)
{
  int temp;
  recv(socket, &temp, sizeof(int),0);

  return temp;
}
