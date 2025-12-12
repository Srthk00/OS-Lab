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
    int idx=0;
    double hit=0.00,miss=0.00;
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<p;j++){
            if(page[j]==nums[i]){
                hit++;
                found=1;
                break;
            }
        }
        if(found==0){
            miss++;
            page[idx++]=nums[i];
            idx=idx%p;
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
    printf("Miss Ratio: %.2f",miss);
    return 0;
}