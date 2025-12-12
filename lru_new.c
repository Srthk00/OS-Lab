#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter size of input string: ");
    scanf("%d",&n);
    int *nums=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int p;
    printf("Enter size of page array: ");
    scanf("%d",&p);
    int *page=(int *)malloc(p*sizeof(int));
    for(int i=0;i<p;i++){page[i]=-1;}
    int *index=(int *)malloc(p*sizeof(int));
    for(int i=0;i<p;i++){index[i]=-1;}
    double hit=0.00,miss=0.00;
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<p;j++){
            if(page[j]==nums[i]){
                index[j]=i;
                found=1;
                hit++;
                break;
            }
        }
        if(found==0){
            miss++;
            int minvalue=1000000; 
            int minindex=-1;  
            for(int j=0;j<p;j++){
                if(index[j]<minvalue){
                    minvalue=index[j];  
                    minindex=j;       
                }
            }
            page[minindex]=nums[i];
            index[minindex]=i;
        }
        for(int j=0;j<p;j++){
            if(page[j]==-1){
                printf("[-]");
            }
            else{
                printf("[%d]",page[j]);
            }
        }
        printf("\n");
    }
    double attempts=hit+miss;
    hit=hit/attempts;
    miss=miss/attempts;
    printf("Total Attempts: %.2f\n",attempts);
    printf("Hit Ratio: %.2f\n",hit);
    printf("Miss Ratio: %.2f\n",miss);
    return 0;
}

//2 3 2 1 5 2 4 5 3 2 5 2