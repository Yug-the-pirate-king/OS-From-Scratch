// ==============================================================================
// Experiment 07: Synchronization Mechanisms (Mutex, Semaphore, Condition Variable)
// Requirements: Linux / GCC with -pthread flag
// ==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Shared resource
int shared = 0;

// Synchronization primitives
pthread_mutex_t mutex;
pthread_cond_t cond;
sem_t sem;

// Thread 1: Critical section protected by Mutex Lock
void* mutex_example(void* arg) {
    pthread_mutex_lock(&mutex); // Acquire lock
    shared++;
    printf("Mutex Lock: shared = %d\n", shared);
    pthread_mutex_unlock(&mutex); // Release lock
    return NULL;
}

// Thread 2: Signaling & mutual exclusion via Semaphore
void* semaphore_example(void* arg) {
    sem_wait(&sem); // Decrement semaphore (wait)
    printf("Semaphore: Thread inside critical section\n");
    sem_post(&sem); // Increment semaphore (signal)
    return NULL;
}

// Thread 3: Waiting on Condition Variable
void* condition_example(void* arg) {
    pthread_mutex_lock(&mutex);
    printf("Condition Variable: Waiting...\n");
    // Releases mutex and blocks until signaled
    pthread_cond_wait(&cond, &mutex);
    printf("Condition Variable: Thread resumed\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    // Initialize synchronization primitives
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    sem_init(&sem, 0, 1); // Binary semaphore (initial value = 1)

    printf("=== Process Synchronization Mechanisms ===\n\n");

    // Create threads
    pthread_create(&t1, NULL, mutex_example, NULL);
    pthread_create(&t2, NULL, semaphore_example, NULL);
    pthread_create(&t3, NULL, condition_example, NULL);

    // Sleep briefly to ensure Thread 3 reaches wait state
    sleep(1);

    // Signal condition variable to wake up waiting Thread 3
    pthread_mutex_lock(&mutex);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    // Wait for all threads to terminate
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    // Clean up resources
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    sem_destroy(&sem);

    printf("\nAll threads finished cleanly. Synchronization demo complete.\n");
    return 0;
}

