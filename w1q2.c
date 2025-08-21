#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid=fork();
    if(pid<0){ // fork failed
        printf("Fork failed...");
        return 1;
    } 
    else if(pid==0){ // child process
        printf("This is the child process...\n");
        printf("Process ID of Child: %d\n",getpid());
        printf("Process ID of Parent: %d\n",getppid());
    } 
    else{ // parent process
        printf("This is the parent process...\n");
        printf("Process ID of Parent: %d\n",getpid());
        printf("Process ID  of Child: %d\n",pid);
        wait(NULL); // To void zombie process
    }
    return 0;
}