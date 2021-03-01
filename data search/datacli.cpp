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
	struct sockaddr_in	 servaddr; 

	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
		cout<<"socket failed"<<endl;
		exit(0);
	} 
	else cout<<"Connection Established"<<endl;

	memset(&servaddr, 0, sizeof(servaddr)); 
	
	servaddr.sin_family = AF_INET; 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_addr.s_addr = INADDR_ANY; 
		socklen_t len;

	int n; 
	string msg;
	cout<<"Input either Name or Phone Number to Server"<<endl;
	cin>>msg;
	n = msg.length(); 
    char hello[n + 1]; 
    strcpy(hello, msg.c_str()); 
	sendto(sockfd, (const char *)hello, strlen(hello),MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr)); 
	cout<<"Request sent to server"<<endl; 
	int x;
		x = recvfrom(sockfd, (char *)buffer, 1024,MSG_WAITALL, (struct sockaddr *) &servaddr, &len); 
    buffer[x] = '\0'; 
    cout<<"Details Received from server"<<endl;

    cout<<"Name and Phone Number of person are------->"<<buffer<<endl;
	close(sockfd); 
	return 0; 
} 
