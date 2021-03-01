#include<bits/stdc++.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <unistd.h>
using namespace std;


int main( )
{
	struct sockaddr_in sa;
	struct sockaddr_in cli;
	int sockfd,conntfd;
	int ch;char str[100];
	time_t t;
	socklen_t len;

sockfd=socket(AF_INET,SOCK_STREAM,0);

	if(sockfd<0)
		{
			cout<<"error in socket creation"<<endl;;
			exit(0);
		}
	else
		cout<<"Socket created Successfully"<<endl;

	bzero(&sa,sizeof(sa));
	sa.sin_port=htons(5600);
	sa.sin_addr.s_addr=htonl(0);

	if(bind(sockfd,(struct sockaddr*)&sa,sizeof(sa))<0)
		{
			cout<<"Error in binding"<<endl;
		}
	else
	cout<<"Binded Successfully"<<endl;

	listen(sockfd,50);

	for(;;)
		{
			len=sizeof(ch);
			conntfd=accept(sockfd,(struct sockaddr*)&cli,&len);
			cout<<"Request Recieved"<<endl;
			t=time(NULL);
			snprintf(str,sizeof(str),"%s",ctime(&t));
			cout<<"Sent day-time to client as----->"<<str<<endl;;
			write(conntfd,str,100);
		}

	return 0;
}