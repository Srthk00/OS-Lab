#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n;
    printf("Enter number of free blocks: ");
    scanf("%d",&n);    
    int *ram=(int *)malloc(n*sizeof(int));
    printf("Enter RAM blocks...\n");
    for(int i=0;i<n;i++){
        scanf("%d",&ram[i]);
    }
    int p;
    printf("Enter number of Processes: ");
    scanf("%d",&p);
    int *process=(int *)malloc(p*sizeof(int));
    printf("Enter processes...\n");
    for(int i=0;i<p;i++){
        scanf("%d",&process[i]);
    }
    int *result=(int *)malloc(n*sizeof(int));
    int *filled=(int *)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){result[i]=-1;}
    for(int i=0;i<p;i++){
        int pro=process[i];
        for(int j=0;j<n;j++){
            if(ram[j]>=pro && !filled[j]){
                result[j]=pro;filled[j]=1;break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(result[i]==-1){
            printf("Process %d cannot be allocated...\n",i);
        }
        else{
            printf("Process: %d allocated to RAM block(size: %d): %d\n",result[i],ram[i],i);
        }
    }
    return 0;
}
// 5 100 500 200 300 600 4 212 417 112 426