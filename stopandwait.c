#include <stdio.h>
#include <stdlib.h>
typedef struct frame{
    int info, seq;
} frame;
int ack, t=5, k, disconnect=0;
int errorack=1, errorframe=1;
char turn='s';
frame p;
sender();
receiver();
int main() {
    p.info=0;
    p.seq=0;
    while(!disconnect){
        sender();
        for(k=1,k<=10000000,k++){
            receiver();
        }
    }
}
void sender(){
    static int flag=0;
    if(turn=='s'){
        if(errorack=0){
            printf("sender: packet sent with seq no: %d\n",p.seq);
            errorframe=rand()%4;
            printf("%d\n",(errorframe==0?"error while sending the packet"));
            turn='r';
        }
        else{
            if(flag==1){
                printf("sender: acknowledgement received for the packet %d",ack);
                if(p.seq==5){
                    disconnect=1;
                    return;
                }
                p.info+=1;
                p.seq+=1;
                printf("sender: packet sent with seq no: %d\n",p.seq);
                errorframe=rand()%4;
                printf("%d\n",(errorframe==0?"error while sending the packet"));
                turn='r';
                flag=1;
            }
        }
        else{
            t--;
            printf("sender time reducing");
            if(t==0){
                turn='s';
                disconnect=0;
                t=5;
            }
        }
    }
    void receiver(){
        static int frexp=1;
        if(turn=='r'){
            if(errorframe!=0){
                if(p.seq==frexp){
                    printf("receiver:received packet with sequence no: %d",p.seq);
                    ack=p.seq;
                    frexp+=1;
                    turn='s';
                    errorack=rand()%4;
                    printf("%d\n",(errorack==0?"error while sending ACK"));
                }
            }
            else{
                printf("receiver: duplicate packet received");
                ack=frexp-1;
                turn='s';
                errorack=rand()%4;
                printf("%d\n",(errorack==0?"error while sending ACK"));
            }
        }
    }
}
