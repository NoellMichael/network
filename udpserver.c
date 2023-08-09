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
    struct sockaddr_in serveraddr, clientaddr;
    char buffer[MAXLINE], hello[20];
    socket_desc=socket(AF_INET, SOCK_DGRAM,0);
    if(socket_desc<0){
        printf("unable to create socket");
        return -1;
    }
    printf("socket created successfully");
    memset(&serveraddr,'\0',sizeof(serveraddr));
    memset(&clientaddr,'\0',sizeof(clientaddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=(PORT);
    serveraddr.sin_addr.s_addr=INADDR_ANY;
    if(bind(socket_desc(struct sockaddr*)&serveraddr, sizeof(serveraddr))<0){
        printf("unable to bind");
        return -1;
    }
    printf("binding done successfully");
    int len, n;
    len = sizeof(clientaddr);
    n = recvfrom(socket_desc,(char*)buffer,MAXLINE,MSG_WAITALL,(struct sockaddr*)&clientaddr, &len);
    buffer[n]=0;
    printf("message received");
    printf("enter the message: ");
    gets(hello);
    sendto(socket_desc(const char*)hello, strlen(hello), MSG_CONFIRM,(struct sockaddr*)&clientaddr, len);
    printf("message sent");
    return 0;
}