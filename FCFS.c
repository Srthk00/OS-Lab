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
    int util_time;
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
    printf("Enter Burst Time: ");
    for(int i=0;i<n;i++){
        scanf("%d",&P[i].burst);
    }
    qsort(P,n,sizeof(process),cmp);
    int time=0;
    for(int i=0;i<n;i++){
        if(time<P[i].arrival_time){
            time=P[i].arrival_time;
        }
        P[i].starting_time=time;
        P[i].completion_time=time+P[i].burst;
        P[i].turn_around=P[i].completion_time-P[i].arrival_time;
        P[i].util_time=P[i].turn_around-P[i].burst;
        time=P[i].completion_time;
    }
    printf("Gantt Chart...\n");
    printf("Process ID\tArrival\tBurst\tStart\tCompletion\tTAT\tUtility\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t%d\t%d\t%d\t\t%d\t%d\n",P[i].id,P[i].arrival_time,P[i].burst,P[i].starting_time,P[i].completion_time,P[i].turn_around,P[i].util_time);
    }
    return 0;
}