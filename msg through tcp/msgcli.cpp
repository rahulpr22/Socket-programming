#include<bits/stdc++.h>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 
using namespace std;
int main() 
{ 
	int sock = 0,msg; 
	struct sockaddr_in serv_addr; 
	char buffer[1024] = {0}; 

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
			cout<<"socket failed"<<endl;
			return -1; 
	}
	else
		cout<<"Connection Established"<<endl; 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 

	if(connect(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
		{
			cout<<"Error in connection failed"<<endl;	
			exit(0);
		}
	else
		cout<<"connected successfully"<<endl;
	
	string s;
	cout<<"Input the msg to server"<<endl;
	cin>>s;
	int x=s.size();
	char hello[x];

	for(int i=0;i<x;i++)
		hello[i]=s[i];

	
	send(sock , hello , strlen(hello) , 0 ); 
	cout<<"Message sent to Server"<<endl;
	return 0; 
} 


