#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <time.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h>
#include <netinet/in.h>
 
int main()
{
    time_t clock;
    char dataSending[1025],sample[1024]; 
    int clintListn = 0, clintConnt = 0;
    struct sockaddr_in ipOfServer;
    clintListn = socket(AF_INET, SOCK_STREAM, 0); 
    memset(&ipOfServer, '0', sizeof(ipOfServer));
    memset(dataSending, '0', sizeof(dataSending));
    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
    ipOfServer.sin_port = htons(2017);         
    bind(clintListn, (struct sockaddr*)&ipOfServer , sizeof(ipOfServer));
    listen(clintListn , 5);

    while(1)
    {
        printf("\n\nHi,Iam running server.Some Client hit me fast \n");
        clintConnt = accept(clintListn, (struct sockaddr*)NULL, NULL);
 
        clock = time(NULL);

        //printf("enter your message!!!\n");
        //scanf("%s",sample);
        snprintf(dataSending, sizeof(dataSending), "%s\n", "Hello server its client speaking"); 
 
        write(clintConnt, dataSending, strlen(dataSending));
 
        close(clintConnt);
        sleep(1);
     }
 
     return 0;
}
