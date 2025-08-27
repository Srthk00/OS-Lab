#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid=fork();
    if(pid>0){  // Parent process
        printf("Parent process (PID: %d). Sleeping...\n",getpid());
        sleep(10);  // Keep parent alive, child becomes zombie
    }
    else if(pid==0){  // Child process
        printf("Child process (CID: %d)\n",getpid());
        exit(0);  // Child exits to create zombie
    }
    else{
        printf("fork failed");
    }
    return 0;
}
