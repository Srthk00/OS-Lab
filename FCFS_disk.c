#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter number of inputs: ");
    scanf("%d",&n);
    int *nums=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    int disk;
    printf("Enter size of Disk: ");
    scanf("%d",&disk);
    int result=0;
    for(int i=0;i<n-1;i++){
        result+=abs(nums[i]-nums[i+1]);
    }
    printf("Seek Count=%d\n",result);
    return 0;
}