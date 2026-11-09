// Lab 6: fork() and vfork() (Linux)
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("fork child: pid=%d ppid=%d\n", getpid(), getppid());
        fflush(stdout);
        _exit(0);
    }
    printf("fork parent: pid=%d child=%d\n", getpid(), pid);
    wait(NULL);

    pid = vfork();
    if (pid == 0) {
        printf("vfork child: pid=%d ppid=%d\n", getpid(), getppid());
        fflush(stdout);
        _exit(0);
    }
    printf("vfork parent: pid=%d\n", getpid());
    return 0;
}
