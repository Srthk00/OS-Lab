#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter RAM size: ");
    scanf("%d",&n);
    int *ram=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&ram[i]);
    }
    int *filled=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        filled[i]=-1;
    }
    int p;
    printf("Enter number of processes: ");
    scanf("%d",&p);
    int *pro=(int *)malloc(p*sizeof(int));
    for(int i=0;i<p;i++){
        scanf("%d",&pro[i]);
    }
    int idx=0;
    for(int i=0;i<p;i++){
        int temp=n;
        while(temp-->0){
            if(ram[idx]>=pro[i] && filled[idx]==-1){
                filled[idx]=i;
                idx++;
                idx=idx%n;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(filled[i]==-1){
            printf("RAM block %d is empty\n",i);
        }
        else{
            printf("RAM block %d(%d) is occupied by: %d(%d)\n",i,ram[i],filled[i],pro[filled[i]]);
        }
    }
    return 0;
}