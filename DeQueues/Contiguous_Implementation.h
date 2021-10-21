// Contiguous implementation using arrays
#ifndef CONTIGUOUS_IMPLEMENTATION
#define CONTIGUOUS_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define MAXDEQUEUESIZE 20

typedef int deQueueEntryType;

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct dequeue
{
    int front;
    int rear;
    int no_of_elements;
    deQueueEntryType items[MAXDEQUEUESIZE];
}Dequeue;

void createDeQueue(Dequeue *DQ) {
    DQ->front = DQ->rear = -1;
    DQ->no_of_elements = 0;
}

Boolean isDeQueueEmpty(Dequeue *DQ) {
    return DQ->front == -1;
}

Boolean isDeQueueFull(Dequeue *DQ) {
    return (((DQ->front == 0) && (DQ->rear == MAXDEQUEUESIZE - 1)) || (DQ->front == DQ->rear + 1));
}

void insertRear(Dequeue *DQ, deQueueEntryType item) {
    if (isDeQueueFull(DQ)) {
        printf("DeQueue is Full");
        exit(1);
    }
    if (isDeQueueEmpty(DQ)) {
        DQ->front = DQ->rear = 0;
    }
    else {
        DQ->rear = (DQ->rear + 1) % MAXDEQUEUESIZE;
    }
    DQ->items[DQ->rear] = item;
    DQ->no_of_elements++;
}

void insertFront(Dequeue *DQ, deQueueEntryType item) {
    if(isDeQueueFull(DQ)) {
        printf("DeQueue is Full");
        exit(1);
    }
    if (isDeQueueEmpty(DQ)) {
        DQ->front = DQ->rear = 0;
    }
    else {
        if (DQ->front == 0)
            DQ->front = MAXDEQUEUESIZE -1;
        else
            DQ->front--;
    }
    DQ->items[DQ->front] = item;
    DQ->no_of_elements++;
}

void deleteFront(Dequeue *DQ, deQueueEntryType *item) {
    if (isDeQueueEmpty(DQ)) {
        printf("DeQueue is empty");
        exit(1);
    }
    *item = DQ->items[DQ->front];
    if (DQ->front == DQ->rear) {
        DQ->front = DQ->rear = -1;
    }
    else {
        DQ->front = (DQ->front + 1) % MAXDEQUEUESIZE;
    }
    DQ->no_of_elements--;
}

void deleteRear(Dequeue *DQ, deQueueEntryType *item) {
    if (isDeQueueEmpty(DQ)) {
        printf("DeQueue is empty");
        exit(1);
    }
    *item = DQ->items[DQ->rear];
    if (DQ->front == DQ->rear) {
        DQ->front = DQ->rear = -1;
    }
    else {
        if (DQ->rear == 0)
            DQ->rear = MAXDEQUEUESIZE -1;
        else
            DQ->rear--;
    }
    DQ->no_of_elements--;
}

void display(Dequeue *DQ) {
    if (isDeQueueEmpty(DQ)) {
        printf("DeQueue is empty");
        exit(1);  
    }
    int front_pos = DQ->front, rear_pos = DQ->rear;
    printf("Queue Elements\t:");

    if(front_pos <= rear_pos) {
        while (front_pos <= rear_pos) {
            printf("%5d",DQ->items[front_pos]);
            front_pos++;
        }      
    }
    else {
        while (front_pos < MAXDEQUEUESIZE ) {
            printf("%5d",DQ->items[front_pos]);
            front_pos++;
        }
        front_pos =0;
        while (front_pos <= rear_pos) {
            printf("%5d",DQ->items[front_pos]);
            front_pos++;
        }
      
    }

}

#endif


