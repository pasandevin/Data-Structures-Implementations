// Contiguous implementation using arrays
#ifndef CONTIGUOUS_IMPLEMENTATION
#define CONTIGUOUS_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUESIZE 50


typedef char queueEntryType;

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct queue{
    int front;
    int rear;
    int no_of_elements;
    queueEntryType items[MAXQUEUESIZE];
}Queue;


void createQueue(Queue *Q) {
    Q->front = Q->rear = -1;
    Q->no_of_elements = 0;
}

Boolean isQueueEmpty(Queue *Q) {
    return Q->no_of_elements == 0;
}

Boolean isQueueFull(Queue *Q) {
    return Q->rear == MAXQUEUESIZE - 1;
}

void Insert(Queue *Q, queueEntryType item) {
    if (isQueueFull(Q)) {
        printf("Queue is full");
        exit(1);
    }
    if (Q->front == -1) {
        Q->front++;
    }
    Q->items[++Q->rear] = item;
    Q->no_of_elements++;
}

void Remove(Queue *Q, queueEntryType *item) {
    if(isQueueEmpty(Q)) {
        printf("Queue is empty");
        exit(1);
    }
    *item = Q->items[Q->front++];
    if (Q->front > Q->rear) {
        Q->front = Q->rear = -1;
    }
    
    Q->no_of_elements--;
}

#endif