// Lab 7: Mutex, binary semaphore, condition variable (compile with -pthread)
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int shared = 0, ready = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
sem_t sem;

void *mutex_work(void *arg) {
    pthread_mutex_lock(&mutex);
    shared++;
    printf("Mutex: shared=%d\n", shared);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *sem_work(void *arg) {
    sem_wait(&sem);
    printf("Semaphore: critical section\n");
    sem_post(&sem);
    return NULL;
}

void *cond_work(void *arg) {
    pthread_mutex_lock(&mutex);
    while (!ready) pthread_cond_wait(&cond, &mutex);
    printf("Condition: resumed\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    sem_init(&sem, 0, 1);
    pthread_create(&t1, NULL, mutex_work, NULL);
    pthread_create(&t2, NULL, sem_work, NULL);
    pthread_create(&t3, NULL, cond_work, NULL);

    sleep(1);
    pthread_mutex_lock(&mutex);
    ready = 1;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    sem_destroy(&sem);
    return 0;
}
