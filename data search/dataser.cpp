#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
#define Blocksize 10 
#define PORT	 8080 
#include <fstream>

using namespace std; 


int main() { 
	int sockfd; 
	char buffer[1024]; 
	struct sockaddr_in servaddr, cliaddr; 
	socklen_t len;
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		cout<<"socket failed"<<endl;
		exit(0);
	} 
	else 
		cout<<"socket created successfully"<<endl;

	memset(&servaddr, 0, sizeof(servaddr)); 
	memset(&cliaddr, 0, sizeof(cliaddr)); 
	
 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
	servaddr.sin_port = htons(PORT); 
	
	if ( bind(sockfd, (const struct sockaddr *)&servaddr, 
			sizeof(servaddr)) < 0 ) 
	{ 
		cout<<"Error in binding"<<endl; 
		exit(0); 
	} 
	else
	cout<<"Binded Successfully"<<endl;
	
	
	int  n; 
	len = sizeof(cliaddr); 

	

		n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len); 
		buffer[n] = '\0';
		string search= buffer;
		
		cout<<"Request received from client"<<endl;
		ifstream inFile;
		string line;

		inFile.open("pdata.dat");

		if(!inFile){
		cout << "Unable to open file" << endl;
		exit(1);
		}

		string ret;
		size_t pos;
		while(inFile.good())
  		{
      		getline(inFile,line); // get line from file
      		pos=line.find(search); // search
      		if(pos!=string::npos) // string::npos is returned if string is not found
        		{
            		cout <<"Details Found!"<<endl;
            		ret=line;
            		break;
        		}
        		else ret = "Details not found";
  		}
  		int m=ret.length();
		char hello[m + 1]; 
    	strcpy(hello, ret.c_str()); 
		sendto(sockfd, (const char *)hello, strlen(hello),MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len); 
		
		cout<<"Details of requested person sent to client"<<endl;
	
	
	return 0; 
} 

