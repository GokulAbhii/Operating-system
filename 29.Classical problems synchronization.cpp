#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5   // Buffer size
#define NUM_ITEMS 10    // Number of items to produce/consume

int buffer[BUFFER_SIZE]; // Shared buffer
int in = 0, out = 0;    // Buffer pointers

sem_t empty, full;  // Semaphores for synchronization
pthread_mutex_t mutex;  // Mutex for mutual exclusion

// Producer function
void *producer(void *arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        int item = rand() % 100;  // Generate a random item

        sem_wait(&empty);  // Wait if buffer is full
        pthread_mutex_lock(&mutex);  // Lock critical section

        // Produce item
        buffer[in] = item;
        printf("Producer produced: %d at position %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;  // Move pointer

        pthread_mutex_unlock(&mutex);  // Unlock critical section
        sem_post(&full);  // Signal that a new item is available

        sleep(1); // Simulate time taken for production
    }
    pthread_exit(NULL);
}

// Consumer function
void *consumer(void *arg) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&full);  // Wait if buffer is empty
        pthread_mutex_lock(&mutex);  // Lock critical section

        // Consume item
        int item = buffer[out];
        printf("Consumer consumed: %d from position %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;  // Move pointer

        pthread_mutex_unlock(&mutex);  // Unlock critical section
        sem_post(&empty);  // Signal that a new slot is available

        sleep(2); // Simulate time taken for consumption
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t prod, cons;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE); // Start with full empty slots
    sem_init(&full, 0, 0);            // Start with no full slots
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    printf("Producer-Consumer Simulation Completed.\n");
    return 0;
}




