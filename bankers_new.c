#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct resource{
    int a,b,c;
}resource;


int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int a,b,c;
    printf("Enter currently available resources: ");
    scanf("%d %d %d",&a,&b,&c);
    resource allocated[n],need[n],remain[n];
    bool *completed=(bool *)malloc(n*sizeof(bool));
    int ava=0,avb=0,avc=0;
    printf("Enter currently allocated resources...\n");
    for(int i=0;i<n;i++){
        int a_,b_,c_;
        scanf("%d %d %d",&a_,&b_,&c_);
        allocated[i].a=a_;
        allocated[i].b=b_;
        allocated[i].c=c_;
        completed[i]=false;
        ava+=a_;avb+=b_;avc+=c_;
    }
    printf("Enter max need...\n");
    for(int i=0;i<n;i++){
        int a_,b_,c_;
        scanf("%d %d %d",&a_,&b_,&c_);
        need[i].a=a_;
        need[i].b=b_;
        need[i].c=c_;
    }
    for(int i=0;i<n;i++){
        remain[i].a=need[i].a-allocated[i].a;
        remain[i].b=need[i].b-allocated[i].b;
        remain[i].c=need[i].c-allocated[i].c;
    }
    ava=a-ava;avb=b-avb;avc=c-avc;
    int gantt[n];int idx=0;
    int comp=0;
    while(comp!=n){
        bool resolved=false;
        for(int i=0;i<n;i++){
            if(remain[i].a<=ava && remain[i].b<=avb && remain[i].c<=avc && completed[i]==false){
                ava+=allocated[i].a;
                avb+=allocated[i].b;
                avc+=allocated[i].c;
                gantt[idx++]=i;
                completed[i]=true;
                comp++;
                resolved=true;
                break;
            }
        }
        if(!resolved){
            printf("Deadlock cannot be resolved....");
            return 1;
        }
    }
    for(int i=0;i<n;i++){
        printf("P%d ",gantt[i]);
    }
    return 0;
}