#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(void){
    //initialize all the variables
    int socket_desc, client_sock, client_size;
    struct sockaddr_in client_addr, server_addr;
    char server_msg[2000], client_msg[2000], temp;

    //clean the buffers
    memset(server_msg,'\0',sizeof(server_msg));
    memset(client_msg,'\0',sizeof(client_msg));

    //create socket
    socket_desc=socket(AF_INET, SOCK_STREAM,0);
    if(socket_desc<0){
        printf("unable to create the socket");
        return -1;
    }
    printf("socket created successfully");

    //set port and ip address
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(3000);
    server_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

    //bind the sockets
    int bvalue=1020;
    bvalue=bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(bvale<0){
        printf("unable to bind");
        return -1;
    }
    //listen for client
    if(listen(socket_desc,1)<0){
        printf("error");
        return -1;
    }
    while(1){
        //accept incoming connection
        client_size=sizeof(client_addr);
        client_sock=accept(socket_desc,(struct sockaddr*)&client_addr, &client_size);
        if(client_sock < 0){
            printf("unable to accept");
            return -1;
        }
        //receive and send messgaes 
        if(recv(client_sock, client_msg, sizeof(client_msg),0)<0){
            printf("unable to receive");
            return -1;
        }
        printf("message from client: %s\n",client_msg);
        printf("enter messgae: ");
        gets(server_msg);
        if(send(client_sock, server_msg, strlen(server_msg),0)<0){
            printf("unable to send");
            return -1;
        }
        memset(client_msg,'\0',sizeof(client_msg));
    }
    close(client_sock);
    close(socket_desc);
    return 0;
}