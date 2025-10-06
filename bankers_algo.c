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
    resource allocated[n],max_need[n],remaining[n],available[n];
    int avA=0,avB=0,avC=0;
    bool *iscompleted=(bool *)malloc(n*sizeof(bool));
    printf("Enter Currently Allocated Resources\n");
    for(int i=0;i<n;i++){
        iscompleted[i]=false;
        int a_,b_,c_;
        scanf("%d %d %d",&a_,&b_,&c_);
        allocated[i].A=a_,allocated[i].B=b_,allocated[i].C=c_;
        avA+=a_,avB+=b_,avC+=c_;
    }
    printf("Enter Max Needed Resources\n");
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&max_need[i].A,&max_need[i].B,&max_need[i].C);
    }
    for(int i=0;i<n;i++){
        remaining[i].A=max_need[i].A-allocated[i].A;
        remaining[i].B=max_need[i].B-allocated[i].B;
        remaining[i].C=max_need[i].C-allocated[i].C;
    }
    avA=a-avA,avB=b-avB,avC=c-avC;
    int gantt[n],idx=0;
    int completed=0;
    for(int j=0;j<n;j++){
        bool isdeadlock=true;
        for(int i=0;i<n;i++){
            if(remaining[i].A<=avA && remaining[i].B<=avB && remaining[i].C<=avC && iscompleted[i]==false){
                isdeadlock=false;
                avA+=allocated[i].A;
                avB+=allocated[i].B;
                avC+=allocated[i].C;
                gantt[idx++]=i;
                iscompleted[i]=true;
                completed++;
                available[i].A=avA;
                available[i].B=avB;
                available[i].C=avC;
                break;
            }
        }
        if(isdeadlock){
            printf("There is deadlock");
            return 1;
        }
    }
    printf("\nGantt Chart...\n");
    for(int i=0;i<idx;i++){
        printf("P%d ",gantt[i]);
    }
    printf("\n\nProcess\tAllocated\tMax\t\tNeed\tAvailable After\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d %d %d\t\t%d %d %d\t\t%d %d %d\t%d %d %d\n",i,allocated[i].A,allocated[i].B,allocated[i].C,max_need[i].A,max_need[i].B,max_need[i].C,remaining[i].A,remaining[i].B,remaining[i].C,available[i].A,available[i].B,available[i].C);
    }
    return 0;
}