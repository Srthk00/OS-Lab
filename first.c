#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    int x=fork();
    printf("%d\n",getppid());
    printf("%d\n",getpid());
    return 0;
}