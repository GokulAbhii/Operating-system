#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void *threadFunction(void *arg) {
    int id = *((int *)arg);
    printf("Thread %d: Running...\n", id);
    sleep(2);  // Simulating work
    printf("Thread %d: Exiting...\n", id);
    pthread_exit(NULL);  // Explicit thread exit
}

int main() {
    pthread_t thread1, thread2;  // Thread identifiers
    int id1 = 1, id2 = 2;
    int status;

    // (i) Create threads
    status = pthread_create(&thread1, NULL, threadFunction, &id1);
    if (status != 0) {
        perror("Error creating thread1");
        exit(EXIT_FAILURE);
    }

    status = pthread_create(&thread2, NULL, threadFunction, &id2);
    if (status != 0) {
        perror("Error creating thread2");
        exit(EXIT_FAILURE);
    }

    // (iii) Check if threads are equal
    if (pthread_equal(thread1, thread2)) {
        printf("Threads are equal.\n");
    } else {
        printf("Threads are NOT equal.\n");
    }

    // (ii) Join threads (wait for them to finish)
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have finished execution.\n");
    return 0;
}

