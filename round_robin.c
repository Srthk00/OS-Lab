#include <stdio.h>
#include <stdlib.h>
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
    int remaining_time;
    int response_time;
    bool started;
}process;

int findmax(int a,int b){
    return a>b?a:b;
}

int main(){
    int n;
    printf("Enter number of Processes: ");
    scanf("%d",&n);
    process P[n];
    printf("Enter Arrival Time: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].arrival_time);
        P[i].id=i;
        P[i].started=false;
    }
    printf("Enter Burst Time: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].burst);
        P[i].remaining_time=P[i].burst;
    }
    int tq;
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int time=0,completed=0;
    int queue[10000],front=-1,rear=-1;
    bool inqueue[n];
    for(int i=0;i<n;i++) inqueue[i]=false;
    float sum_tat=0,sum_wt=0,sum_rt=0;
    bool first_process=true;
    int total_idle=0;

    int gantt[10000],idx=0;

    queue[++rear]=0;
    inqueue[0]=true;

    while(completed<n){
        int cur=queue[++front];
        if(P[cur].remaining_time==P[cur].burst){
            P[cur].starting_time=findmax(time,P[cur].arrival_time);
            if(first_process) total_idle=0;
            else total_idle+=P[cur].starting_time-time;
            time=P[cur].starting_time;
            P[cur].response_time=P[cur].starting_time-P[cur].arrival_time;
            P[cur].started=true;
            first_process=false;
        }
        int run=(P[cur].remaining_time<tq)?P[cur].remaining_time:tq;
        for(int k=0;k<run;k++){
            gantt[idx++]=cur;
            time++;
            for(int i=0;i<n;i++){
                if(P[i].remaining_time>0 && P[i].arrival_time<=time && !inqueue[i]){
                    queue[++rear]=i;
                    inqueue[i]=true;
                }
            }
        }
        P[cur].remaining_time-=run;
        if(P[cur].remaining_time==0){
            completed++;
            P[cur].completion_time=time;
            P[cur].turn_around=P[cur].completion_time-P[cur].arrival_time;
            P[cur].waiting_time=P[cur].turn_around-P[cur].burst;
            sum_tat+=P[cur].turn_around;
            sum_wt+=P[cur].waiting_time;
            sum_rt+=P[cur].response_time;
        }
        else{
            queue[++rear]=cur;
        }
        if(front>rear){
            for(int i=0;i<n;i++){
                if(P[i].remaining_time>0){
                    queue[++rear]=i;
                    inqueue[i]=true;
                    break;
                }
            }
        }
    }

    int max_completion=INT_MIN;
    for(int i=0;i<n;i++) if(P[i].completion_time>max_completion) max_completion=P[i].completion_time;
    int length_cycle=max_completion-P[0].arrival_time;
    float cpu_util=(float)(length_cycle-total_idle)/length_cycle;

    printf("\nGantt Chart...\n");
    for(int i=0;i<idx;i++){
        if(i==0||gantt[i]!=gantt[i-1]){
            printf("P%d ",gantt[i]);
        }
    }
    printf("\n");

    printf("Process ID\tArrival\tBurst\tStart\tCompletion\tResponse\tTAT\tWaiting\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n",
            P[i].id,P[i].arrival_time,P[i].burst,
            P[i].starting_time,P[i].completion_time,
            P[i].response_time,P[i].turn_around,P[i].waiting_time);
    }
    printf("\nAverage Turn Around time= %.2f",(float)sum_tat/n);
    printf("\nAverage Waiting Time= %.2f",(float)sum_wt/n);
    printf("\nAverage Response Time= %.2f",(float)sum_rt/n);
    printf("\nThroughput= %.2f",n/(float)length_cycle);
    printf("\nCPU Utilization(Percentage)= %.2f",cpu_util*100);
    return 0;
}