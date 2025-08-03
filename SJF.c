#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

typedef struct process{
    int id;
    int arrival_time;
    int burst;
    int starting_time;
    int completion_time;
    int turn_around;
    int waiting_time;
    int response_time;
}process;

int cmp(const void* a, const void* b){
    process* p1=(process*)a;
    process* p2=(process*)b;
    return p1->burst-p2->burst;
}

int main(){
    int n;
    printf("Enter number of Processes: ");
    scanf("%d",&n);
    bool *iscompleted=(bool)malloc(n*sizeof(bool));
    for(int i=0;i<n;i++)iscompleted[i]=false;
    bool is_first_process=true;
    process P[n];
    printf("Enter Arrival Time: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].arrival_time);
        P[i].id=i;
    }
    printf("Enter Burst Time: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].burst);
    }
    qsort(P,n,sizeof(process),cmp);
    int time=0;
    int completed=0;
    while(completed!=n){
        int min_index=-1;
        int minimum=INT_MAX;
        for(int i=0;i<n;i++){
            if(P[i].arrival_time<=time && !iscompleted[i]){
                if(P[i].burst<minimum){
                    minimum=P[i].burst;
                    min_index=i;
                }
                if(P[i].burst==minimum){
                    if(P[i].arrival_time<P[min_index].arrival_time){
                        minimum=P[i].burst;
                        min_index=i;
                    }
                }
            }
        }
        if(min_index==-1){
            time++;
        }
        else{
            P[min_index].starting_time=time;
            P[min_index].completion_time=P[min_index].starting_time+P[min_index].burst;
            P[min_index].turn_around=P[min_index].completion_time-P[min_index].arrival_time;
            P[min_index].waiting_time=P[min_index].turn_around-P[min_index].burst;
            P[min_index].response_time=P[min_index].waiting_time;
        }
    }
    return 0;
}