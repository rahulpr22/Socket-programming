#include<bits/stdc++.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
using namespace std; 
int main()
{
	struct sockaddr_in sa,cli;
	int n,sockfd;
	int len;char buff[100];
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
		{ 
			cout<<"Error in Socket creation"<<endl;
			exit(0);
		}
	else
		cout<<"Socket created successfully"<<endl;

	bzero(&sa,sizeof(sa));
	sa.sin_family=AF_INET;
	sa.sin_port=htons(5600);

	if(connect(sockfd,(struct sockaddr*)&sa,sizeof(sa))<0)
		{
			cout<<"Error in connection failed"<<endl;	
			exit(0);
		}
	else
		cout<<"connected successfully"<<endl;

	if(n=read(sockfd,buff,sizeof(buff))<0)
		{
			cout<<"Error in Reading"<<endl;
			exit(0);
		}
	else

		cout<<"Day-time recieved from server----->"<<buff<<endl;

	return 0;
}