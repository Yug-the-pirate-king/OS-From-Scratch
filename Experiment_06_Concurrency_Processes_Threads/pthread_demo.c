// ==============================================================================
// Experiment 06: Multithreading with POSIX Threads (pthreads)
// Requirements: Linux / GCC with -pthread flag
// ==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Thread routine executed concurrently by threads
void* thread_func(void* arg) {
    char* thread_name = (char*)arg;
    for (int i = 0; i < 3; i++) {
        printf("[%s] Thread running iteration %d\n", thread_name, i);
        usleep(50000); // 50ms pause to observe interleaved execution
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    printf("=== POSIX Multithreading Demonstration ===\n");

    // Creating thread 1 and thread 2
    if (pthread_create(&t1, NULL, thread_func, "Thread 1") != 0) {
        perror("Failed to create Thread 1");
        return 1;
    }

    if (pthread_create(&t2, NULL, thread_func, "Thread 2") != 0) {
        perror("Failed to create Thread 2");
        return 1;
    }

    // Wait for both threads to finish execution
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread completed\n");
    return 0;
}

