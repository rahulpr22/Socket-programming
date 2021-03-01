#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define PORT	 8080 


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

	cout<<"Message recieved from client----->"<<buffer<<endl;
	
	return 0; 
} 

