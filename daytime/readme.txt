This question is implemented in cpp.

SYSTEM REQUIREMENT:

Ubuntu 18.04 LTS or higher
G++ compiler for Ubuntu
A text editor

COMPILATION

Compile the server.cpp file first and then the client.cpp file.
  FOR SERVER  compiling:  g++ dayser.cpp -oserver
              execution:  ./server
  FOR SERVER  compiling:  g++ daycli.cpp -oclient
              execution:  ./client

LIMITATIONS

This code is limited to one client only. There is only one-to-one connection. To achieve multiple connections we can use threading.


