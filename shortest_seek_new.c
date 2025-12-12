#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter size of input string: ");
    scanf("%d",&n);
    int *nums=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int *completed=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){completed[i]=-1;}
    int head,SIZE;
    printf("Enter head position: ");
    scanf("%d",&head);
    printf("Enter Size of disk: ");
    scanf("%d",&SIZE);
    int result=0;
    int temp=n;
    while(temp-->0){
        int minindex=0,minvalue=1e9;
        for(int j=0;j<n;j++){
            int diff=abs(head-nums[j]);
            if(diff<minvalue && completed[j]==-1){
                minvalue=diff;
                minindex=j;
            }
        }
        completed[minindex]=1;
        result+=abs(head-nums[minindex]);
        head=nums[minindex];
        printf("%d-> ",head);
    }
    printf("\nTotal Seek Time: %d",result);
    return 0;
}