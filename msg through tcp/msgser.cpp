#include <bits/stdc++.h> 
#include <unistd.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 
using namespace std;
int main() 
{ 
	int server_fd, new_socket, msg; 
	struct sockaddr_in sa; 
	int opt = 1; 
	int addrlen = sizeof(sa); 
	char buffer[1024] = {0}; 
	
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		cout<<"socket failed"<<endl;
		exit(0); 
	} 
	else 
		cout<<"socket created successfully"<<endl;
	
	sa.sin_family = AF_INET; 
	sa.sin_addr.s_addr = INADDR_ANY; 
	sa.sin_port = htons( PORT ); 
 
	if(bind(server_fd,(struct sockaddr*)&sa,sizeof(sa))<0)
		{
			cout<<"Error in binding"<<endl;
		}
	else
	cout<<"Binded Successfully"<<endl;
	
	

	if (listen(server_fd, 10000) < 0) 
	{ 
		cout<<"listening failed"<<endl; 
		exit(0); 
	} 
	else
		cout<<"listening..."<<endl;

	if ((new_socket = accept(server_fd, (struct sockaddr *)&sa, 
					(socklen_t*)&addrlen))<0) 
	{ 
		cout<<"Accepting failed"<<endl; 
		exit(0); 
	} 
	else
		cout<<"Message received from client"<<endl;

	msg = read( new_socket , buffer, 1024); 
	cout<<buffer<<endl;
	
	return 0; 
} 
