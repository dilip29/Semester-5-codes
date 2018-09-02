#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include <unistd.h>
int main()
{
 
 
    char ch[1024];
    char ch1[1024];
    //char ch2[]="wrong input";
 
    int server_socket;
    server_socket=socket(AF_INET, SOCK_STREAM, 0);
    //socket for server created
 
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port=htons(9002);
    server_address.sin_addr.s_addr=INADDR_ANY;
     
    bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    //binding the server socket to the ports
 
    listen(server_socket,5);
    //listen for client sockets
 
    int client_socket;
    client_socket=accept(server_socket,NULL, NULL);
    //accepting a connection from client socket
     int m=0;
    while(1){

       
        recv(client_socket, &ch, sizeof(ch), 0);
    printf("The recieved data from the client is:\n%s\n",ch);
    
    if(ch[0]=='9')
    {
        ch1[0]='A';
        ch1[1]='\0';
    send(client_socket,ch1,sizeof(ch1),0);
    }

    else if (ch[0]=='8')
    //else
    { 
     ch1[0]='B';
     ch1[1]='\0';
    send(client_socket,ch1,sizeof(ch1),0);
    }

    else if (ch[0]=='7')
    //else
    { 
     ch1[0]='C';
     ch1[1]='\0';
    send(client_socket,ch1,sizeof(ch1),0);
    }

    else if (ch[0]=='6')
    //else
    { 
     ch1[0]='D';
     ch1[1]='\0';
    send(client_socket,ch1,sizeof(ch1),0);
    }

    else if(ch[0]=='q')
    {
        
        ch1[0]='q';
     ch1[1]='\0';
    send(client_socket,ch1,sizeof(ch1),0);
    close(server_socket);

    return 0;
    }

    else
    
    { 
     ch1[0]='F';
     ch1[1]='\0';
    send(client_socket,ch1,sizeof(ch1),0);
    }

    

    }
 
    close(server_socket);
    return 0;
}
