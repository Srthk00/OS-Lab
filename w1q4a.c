#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid=fork();
    if(pid>0){  // Parent process
        printf("Parent process executing (PID: %d)\n",getpid());
        exit(0);  // Parent process completes early
    }
    else if(pid==0){  // Child process
        sleep(5);  // make parent process to complete first
        printf("\nChild process executing (CID: %d, PID: %d)",getpid(),getppid());
    }
    else{
        printf("Fork Failed...");
    }
    return 0;
}