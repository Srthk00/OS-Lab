#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct resource{
    int A;
    int B;
    int C;
}resource;

int main(){
    int a,b,c;
    printf("Enter available resources at CPU (A, B, C): ");
    scanf("%d %d %d",&a,&b,&c);
    int n;
    printf("Enter number of Processes: ");
    scanf("%d",&n);
    resource allocated[n],request[n];
    bool *finish=(bool *)malloc(n*sizeof(bool));
    for(int i=0;i<n;i++) finish[i]=false;

    printf("Enter Currently Allocated Resources\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&allocated[i].A,&allocated[i].B,&allocated[i].C);
    }
    printf("Enter Max Needed Resources\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&request[i].A,&request[i].B,&request[i].C);
    }

    resource work={a,b,c};
    int completed=0;
    bool progress=true;

    while(progress){
        progress=false;
        for(int i=0;i<n;i++){
            if(!finish[i] && request[i].A<=work.A && request[i].B<=work.B && request[i].C<=work.C){
                work.A+=allocated[i].A;
                work.B+=allocated[i].B;
                work.C+=allocated[i].C;
                finish[i]=true;
                completed++;
                progress=true;
            }
        }
    }
    if(completed==n){
        printf("\nDeadlock NOT detected...\n");
    }
    else{
        printf("\nDeadlock detected!!!\n");
    }
    return 0;
}