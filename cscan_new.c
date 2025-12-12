#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a,const void *b){
    return (*(int *)a-*(int *)b);
}

int main(){
    int n;
    printf("Enter number of request: ");
    scanf("%d",&n);
    int *nums=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int head=0,SIZE;
    printf("Enter head position: ");
    scanf("%d",&head);
    printf("Enter disk size: ");
    scanf("%d",&SIZE);
    int dir=-1;
    printf("Enter direction (0-left and 1-right): ");
    scanf("%d",&dir);
    int result=0;
    printf("Schedule sequence...\n");
    int idx=0;
    qsort(nums,n,sizeof(int),cmp);
    while(idx<n && nums[idx]<head){idx++;}
    if(dir==0){
        for(int j=idx-1;j>=0;j--){
            printf("%d-> ",nums[j]);
            result+=abs(head-nums[j]);
            head=nums[j];
        }
        if(head!=0){
            result+=(head-0);
            head=0;
        }
        result+=(SIZE-1);
        head=SIZE-1;
        printf("%d-> ",head);
        for(int j=n-1;j>=idx;j--){
            printf("%d-> ",nums[j]);
            result+=abs(head-nums[j]);
            head=nums[j];
        }
    }
    else{
        for(int j=idx;j<n;j++){
            printf("%d-> ",nums[j]);
            result+=abs(head-nums[j]);
            head=nums[j];
        }
        if(head!=SIZE-1){
            result+=abs(head-(SIZE-1));
            head=SIZE-1;
            printf("%d-> ",head);
        }
        result+=(SIZE-1);
        head=0;
        printf("%d-> ",head);
        for(int j=0;j<idx;j++){
            printf("%d-> ",nums[j]);
            result+=abs(head-nums[j]);
            head=nums[j];
        }
    }
    printf("\nTotal seek time: %d",result);
    return 0;
}