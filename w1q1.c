#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid=fork();
    printf("Parent Process ID: %d\n",getppid());
    printf("Child Process ID: %d\n",getpid());
    return 0;
}