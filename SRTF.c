#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct process{
    int id;
    int arrival_time;
    int burst;
    int starting_time;
    int completion_time;
    int turn_around;
    int waiting_time;
    int remaining_time;
}process;

int cmp(const void* a, const void* b){
    process* p1=(process*)a;
    process* p2=(process*)b;
    return p1->arrival_time-p2->arrival_time;
}

int main(){
    int n;
    printf("Enter the number of Processes: ");
    scanf("%d",&n);
    process P[n];
    printf("Enter Arrival Time: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].arrival_time);
        P[i].id=i;
    }
    int remaining[n];
    printf("Enter Burst Time: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].burst);
        P[i].remaining_time=P[i].burst;
    }
    int time=0;
    int completed=n;
    qsort(P,n,sizeof(process),cmp);
    while(completed){
        int min_index=-1;
        for(int i=0;i<n;i++){
            if(P[i].arrival_time<=time && P[i].remaining_time>0 && (min_index==-1 || P[i].remaining_time<P[min_index].remaining_time)){
                min_index=i;
            }
        }
        if(min_index!=-1){
            P[min_index].remaining_time--;
            time++;
            
            if(P[min_index].remaining_time==0){
                completed--;
                P[min_index].completion_time=time;
                P[min_index].turn_around=time-P[min_index].arrival_time;
                P[min_index].waiting_time=P[min_index].turn_around-P[min_index].burst;
            }
        }
        else{
            time++;
        }
    }
    double avgwait=0.0,avgtat=0.0;
    for(int i=0;i<n;i++){
        avgwait+=P[i].waiting_time;
        avgtat+=P[i].turn_around;
    }
    avgwait=avgwait/n;
    avgtat=avgtat/n;
    printf("Gantt Chart...\n");
    printf("Process ID\tArrival\tBurst\tStart\tCompletion\tTAT\tWaiting\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t%d\t%d\t%d\t\t%d\t%d\n",P[i].id,P[i].arrival_time,P[i].burst,P[i].starting_time,P[i].completion_time,P[i].turn_around,P[i].waiting_time);
    }
    printf("Average Waiting Time: %.2f\n",avgwait);
    printf("Average Turn Around Time: %.2f\n",avgtat);
    return 0;
}