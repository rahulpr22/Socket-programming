This question is implemented in cpp.

SYSTEM REQUIREMENT:

Ubuntu 18.04 LTS or higher
G++ compiler for Ubuntu
A text editor

COMPILATION

Compile the server.cpp file first and then the client.cpp file.
Path for all the three files server,client and datafile should be same.

  FOR SERVER  compiling:  g++ dataser.cpp -oserver
              execution:  ./server
  FOR SERVER  compiling:  g++ dataclient.cpp -oclient
              execution:  ./client

Then In client Terminal Input either name or phone number .
Then server will respond by searching for the details in datafile and if match found sends Name and Phone Number back to client and Details will be displayed on client terminal. 

LIMITATIONS

This code is limited to one client only. There is only one-to-one connection. To achieve multiple connections we can use threading.


