#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void){
    //initialise the variables
    int client_sock;
    struct sockaddr_in client_addr, server_addr;
    char server_msg[2000], client_msg[2000], temp; 
    while(1){
        //clean the buffers
        memset(server_msg,'\0',sizeof(server_msg));
        memset(client_msg,'\0',sizeof(client_msg));

        //craete the socket
        client_sock= socket(AF_INET, SOCK_STREAM,0);
        if(client_sock<0){
            printf("unable to create the socket");
            return -1;
        }
        printf("socket created successfully");

        //set port and ip address
        server_addr.sin_family=AF_INET;
        server_addr.sin_port=htons(3000);
        server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

        //connect the sockets
        if(connect(client_sock(struct sockaddr*)&server_addr, sizeof(server_addr))<0){
            printf("unable to connect");
            return -1;
        }
        //send msg to server
        printf("enter msg: ");
        gets(client_msg);
        if(send(client_sock, client_msg, strlen(client_msg),0)<0){
            printf("unable to send msg");
            return -1;
        }
        //recv msg from server
        if(recv(client_sock, server_msg, sizeof(server_msg),0)<0){
            printf("unable to receive message");
            return -1;
        }
        printf("message from server: %s\n",server_msg);
        memset(client_msg,'\0',sizeof(client_msg));
    }
    close(client_sock);
    return 0;
}
