#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <string.h>
#include <unistd.h>


void main()
{

int sockfd,ret,i,n;

sockfd=socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in socket_addr;

char buffer[1024],filename[1024],num[4];

socket_addr.sin_family=AF_INET;
socket_addr.sin_addr.s_addr=INADDR_ANY;
socket_addr.sin_port=htons(9009);
//memset(&socket_addr,0,sizeof(socket_addr));
ret=connect(sockfd,(struct sockaddr*)&socket_addr,sizeof(socket_addr));

if(ret<0)
{
printf("error connecting client to server\n");
exit(1);
}

printf("connecting success \n");
while(1)
{

printf("\nenter the name of file to download      Note : enter 'q' to exit \n");

scanf("%s",buffer);


send(sockfd,buffer,sizeof(buffer),0);
strcpy(filename,buffer);
char ch[1024]="downloaded_";
strcat(ch,filename);
printf("data send to server :%s \n",buffer);

recv(sockfd,&num, sizeof(num),0);
n=atoi(num);
recv(sockfd,&buffer, n,0);

if(num[0]!='0')
 {
    FILE *ptr;
i=0;
    ptr = fopen(ch, "w");
    while(i<n)
    {
        fprintf(ptr, "%c", buffer[i]);
        i++;
    }
    fclose(ptr);
    printf("\n File downloaded succesfully !!! \n");
}

else if(buffer[0]=='q') {
    printf("Thank you !!\n");
    close(sockfd);
    exit(1);

}
else {
    printf("Sorry...file not found !!\n");
    close(sockfd);
    exit(1);
}
}


}



