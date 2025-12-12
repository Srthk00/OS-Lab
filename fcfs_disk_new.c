#include<stdio.h>
#include<stdlib.h>

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
    int result=0;
    printf("Schedule sequence...\n");
    for(int i=0;i<n;i++){
        printf("%d-> ",head);
        result+=abs(head-nums[i]);
        head=nums[i];
    }
    printf("\nTotal seek time: %d",result);
    return 0;
}