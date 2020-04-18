
# C Network Library
A network Library Written in C using BSD sockets.
## How to use
Use the command below to compile both server and client files.
```
make all
```
cd into /example and run each command in seperate terminal windows.
```
./server 127.0.0.1 12345
./client 127.0.0.1 12345
```
The client will connect, send some data, receive some data and finally disconnect.
