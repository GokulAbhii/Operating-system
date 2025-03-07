#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int shared_resource = 0;

void *process(void *arg) {
    pthread_mutex_lock(&mutex);
    int thread_id = *(int *)arg;
    printf("Thread %d entered critical section.\n", thread_id);
    shared_resource++;
    printf("Thread %d modified shared resource. Value: %d\n", thread_id, shared_resource);

    sleep(1);
    printf("Thread %d exiting critical section.\n", thread_id);
    pthread_mutex_unlock(&mutex); 
    return NULL;
}
int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};

    pthread_mutex_init(&mutex, NULL); 
    for (int i = 0; i < 3; i++)
        pthread_create(&threads[i], NULL, process, &thread_ids[i]);

    for (int i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);
    pthread_mutex_destroy(&mutex);
    printf("Final value of shared resource: %d\n", shared_resource);
    return 0;
}
