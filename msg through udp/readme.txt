This question is implemented in cpp.

SYSTEM REQUIREMENT:

Ubuntu 18.04 LTS or higher
G++ compiler for Ubuntu
A text editor

COMPILATION

Compile the server.cpp file first and then the client.cpp file.

  FOR SERVER  compiling:  g++ udpser.cpp -oserver
              execution:  ./server
  FOR SERVER  compiling:  g++ udpcli.cpp -oclient
              execution:  ./client
Then In client Terminal Input the msg for which you will see the msg displayed in server terminal. 

LIMITATIONS

This code is limited to one client only. There is only one-to-one connection. To achieve multiple connections we can use threading.


