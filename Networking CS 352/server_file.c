#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <string.h>
#include <unistd.h>



int main()
{
char ch;
struct sockaddr_in socket_addr;
int sockfd,ret,newsockfd,i;
char buffer[1024],num[4];


sockfd=socket(AF_INET,SOCK_STREAM,0);

socket_addr.sin_port=htons(9009);
socket_addr.sin_family=AF_INET;
socket_addr.sin_addr.s_addr=INADDR_ANY;

//memset(&socket_addr,0,sizeof(socket_addr));

ret=bind(sockfd,(struct sockaddr*)&socket_addr,sizeof(socket_addr));
if(ret<0)
{
printf("Error binding\n");
exit(1);

}

printf("Binding success\n");


ret=listen(sockfd,10);
if(ret<0)
{
printf("Error listening\n");
exit(1);
}

printf("listening successfull\n");

newsockfd=accept(sockfd,NULL,NULL);

while(1)
{

recv(newsockfd,&buffer,sizeof(buffer),0);
printf("data received from client is : %s\n",buffer);

FILE *ptr ;
ptr=fopen(buffer,"r");

if(ptr==NULL) {
    num[0] = '0';
    send(newsockfd, num, sizeof(num), 0);
    close(sockfd);
    exit(1);
}


i=0;

    ch=fgetc(ptr);
while(ch!=EOF)
{
    buffer[i]=ch;
    ch=fgetc(ptr);
    i++;
}

fclose(ptr);

    snprintf(num,10,"%d",i);
    send(newsockfd,num, sizeof(num),0);
    send(newsockfd, buffer, i, 0);

}


}
