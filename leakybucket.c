#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define num_of_packets 10

int rnd(int a){
    int rn = random()%a;
    return rn = 0 ? 1:rn;
}
int main(){
    int packet_size[num_of_packets], i, clk, bucket_size, op, op_rate, p_time, pack_sz_rm, packt_sz;
    for(i=0;i<num_of_packets;++i){
        packet_size[i]=rnd(6)*10;
    }
    for(i=0;i<num_of_packets;++i){
        printf("packet %d: %d bytes",i,packet_size[i]);
    }
        printf("enter the op rate: ");
        scanf("%d",&op_rate);
        printf("enter the bucket size: ");
        scanf("%d",&bucket_size);
    for(i=0;i<num_of_packets;++i){
        if((packet_size[i] +pack_sz_rm) > bucket_size)
            if(packet_size[i] > bucket_size){
                printf("packet is greater than bucket size. REJECTED.");
            }
            else{
                printf("bucket capacity exceeded");
            }
        else{
            pack_sz_rm += packet_size[i];
            printf("incoming packet size: ",packet_size[i]);
            printf("remaining packets: ",pack_sz_rm);
            p_time = rnd(4)*10;
            printf("time left for transmission: ",p_time);
        }
    for(clk=10;clk<=p_time;clk+=10){
        sleep(1);
        if(pack_sz_rm){
            if(pack_sz_rm<=op_rate){
                op=pack_sz_rm;
                pack_sz_rm=0;
            }
            else{
                op=op_rate;
                pack_sz_rm=op_rate;
            }
            printf("packet of size %d transmitted",op);
            printf("remaining bytes: ",pack_sz_rm);
        }
        else{
            printf("time left for transmission: %d",p_time-clk);
        }
    }
    }
}