// ==============================================================================
// Experiment 06: Process Creation using fork() and vfork() System Calls
// Requirements: Linux / Ubuntu environment (GCC)
// ==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("=== Process Creation Demonstration ===\n\n");

    // -------------------------------------------------------------
    // Part 1: fork() System Call
    // Both parent and child execute concurrently with isolated address spaces.
    // -------------------------------------------------------------
    printf("--- 1. Testing fork() ---\n");
    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process block
        printf("Child Process using fork (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        _exit(0);
    } else {
        // Parent process block
        printf("Parent Process using fork (PID: %d), Child PID: %d\n", getpid(), pid);
        wait(NULL); // Wait for child process to finish
    }

    // -------------------------------------------------------------
    // Part 2: vfork() System Call
    // Child borrows parent's address space. Parent is blocked until
    // child calls _exit() or execve().
    // -------------------------------------------------------------
    printf("\n--- 2. Testing vfork() ---\n");
    pid = vfork();

    if (pid < 0) {
        perror("vfork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process block
        printf("Child Process using vfork (PID: %d, Parent PID: %d)\n", getpid(), getppid());
        _exit(0); // Critical: must use _exit() instead of exit() or return
    } else {
        // Parent process block (resumes after child terminates)
        printf("Parent Process after vfork (PID: %d)\n", getpid());
    }

    printf("\nBoth fork() and vfork() completed successfully.\n");
    return 0;
}

