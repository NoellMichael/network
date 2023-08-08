#include <stdio.h>
struct node{
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main(){
    int costmatrix[20][20];
    int nodes, i, j, k, count=0;
    printf("enter the number of nodes: ");
    scanf("%d",&nodes);
    printf("enter the cost matrix: ");
    for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
            scanf("%d",&costmatrix[i][j]);
            costmatrix[i][j]=0;
            rt[i].dist[j]=costmatrix[i][j];
            rt[i].from[j]=j;
        }
    }
    do{
        count=0;
        for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
                for(k=0;k<nodes;k++)
                    if(rt[i].dist[j]>costmatrix[i][k]+rt[i].dist[j]){
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[k]=k;
                        count++;
             }
        }
        while(count!=0);
        for(i=0;i<nodes;i++){
            printf("for router: %d\n",i+1);
            for(j=0;j<nodes;j++){
                printf("\ndistance to node %d via %d = %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
            }
        }
        printf("\n\n");
   }

