// Lab 6: POSIX threads (compile with -pthread)
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *work(void *arg) {
    int id = *(int *)arg;
    for (int i = 0; i < 3; i++) {
        printf("Thread %d: %d\n", id, i);
        usleep(1000);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int a = 1, b = 2;
    pthread_create(&t1, NULL, work, &a);
    pthread_create(&t2, NULL, work, &b);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
