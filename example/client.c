#include "../lib/network.h"

#include <string.h>

void main(int argc, char **argv)
{
  int socket = create_socket(); //create a socket.

  if(argc < 3 || argc > 3)
  {
    printf("Usage: ./client <host> <port> \n");
    exit(1);
  }

  server_endpoint(atoi(argv[2]), (char *)argv[1]); //set the destination endpoint.

  client_connect(socket); //connect to the server.

  /*
    Client would be connected at this point and we can interact with the server.
  */

  char buffer[200];

  memset(buffer, 0, 200);

  strcpy(buffer, "PING!");

  send_string(socket, buffer);

  printf("Client sent: %s \n", buffer);

  bzero(buffer, 200); //reset buffer to 0x00

  receive_string(socket, buffer);

  printf("Client received: %s \n", buffer);

  printf("Client closing socket %d, bye bye! \n", socket);

  close(socket);


}
