
#include "../lib/network.h"

#include <pthread.h>
#include <unistd.h>

#define BACKLOG 5 //amount of connections.


void main(int argc, char **argv)
{

  int socket = server_socket(); //initialize the socket.

  if(argc < 3 || argc > 3)
  {
    printf("Usage: ./server <host> <port> \n");
    exit(1);
  }

  server_endpoint(atoi(argv[2]), (char *)argv[1]); //create server endpoint.

  server_bind(socket); //bind the socket.

  server_listen(socket, BACKLOG); //listen for incoming socket connections.

  while(1)
  {
    int newcon = server_accept(socket, client, sizeof(client)); //accept the connection.

    if(newcon == -1) //make sure client connection has been accepted.
    {
      perror("Client socket connection failed!");
      close(newcon);
    }

    /*
      Server has now accepted the socket and can interact with it.
    */

    char buffer[200];

    memset(buffer, 0, 200);

    receive_string(newcon, buffer);

    printf("Server received: %s \n", buffer);

    bzero(buffer, 200); //reset buffer to 0x00

    strcpy(buffer, "PONG!");

    send_string(newcon, buffer);

    printf("Server sent: %s \n", buffer);

    printf("Server closing socket %d, bye bye! \n", newcon);

    close(newcon);

    break; //break loop.

  }

  close(socket);
  exit(1);
}
