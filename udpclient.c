#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define MAXLINE 1024
#define PORT 4000
int main(void){
    int socket_desc;
    struct sockaddr_in serveraddr;
    char buffer[MAXLINE], hello[20];
    socket_desc=socket(AF_INET, SOCK_DGRAM,0);
    if(socket_desc<0){
        printf("unable to create socket");
        return -1;
    }
    printf("socket created successfully");
    memset(&serveraddr,'\0',sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=(PORT);
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    int len, n;
    len = sizeof(serveraddr);
    printf("enter the message:\n");
    gets(hello);
    sendto(socket_desc(const char*)hello, strlen(hello), MSG_CONFIRM,(struct sockaddr*)&serveraddr, len);
    printf("message sent\n");
    n = recvfrom(socket_desc,(char*)buffer,MAXLINE,MSG_WAITALL,(struct sockaddr*)&serveraddr, &len);
    buffer[n]=0;
    printf("message received");
    return 0;
}