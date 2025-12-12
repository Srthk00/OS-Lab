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
    int p;
    printf("Enter number of processes: ");
    scanf("%d",&p);
    int *pro=(int *)malloc(p*sizeof(int));
    for(int i=0;i<p;i++){
        scanf("%d",&pro[i]);
    }
    int *filled=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){filled[i]=-1;}
    for(int i=0;i<p;i++){
        int best=-1;
        for(int j=0;j<n;j++){
            if(ram[j]>=pro[i] && filled[j]==-1 && (best==-1 || ram[j]<ram[best])){
                best=j;
            }
        }
        if(best!=-1){
            filled[best]=i;
        }
    }
    for(int i=0;i<n;i++){
        if(filled[i]==-1){
            printf("Block %d is empty\n",i);
        }
        else{
            printf("Block %d(%d) is occupied by: %d(%d)\n",i,ram[i],filled[i],pro[filled[i]]);
        }
    }
    return 0;
}