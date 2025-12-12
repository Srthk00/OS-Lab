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
        for(int i=idx-1;i>=0;i--){
            result+=abs(head-nums[i]);
            head=nums[i];
            printf("%d-> ",head);
        }
        if(idx<n){
            result+=abs(head-nums[n-1]);
            head=nums[n-1];
            printf("%d-> ",head);
            for(int i=n-1;i>=idx;i--){
                result+=abs(head-nums[i]);
                head=nums[i];
                printf("%d-> ",head);
            }
        }
    }
    else{
        for(int i=idx;i<n;i++){
            result+=abs(head-nums[i]);
            head=nums[i];
            printf("%d-> ",head);
        }
        if(idx>0){
            result+=abs(head-nums[0]);
            head=nums[0];
            printf("%d-> ",head);
            for(int i=0;i<idx;i++){
                result+=abs(head-nums[i]);
                head=nums[i];
                printf("%d-> ",head);
            }
        }
    }
    printf("\nTotal seek time: %d",result);
    return 0;
}