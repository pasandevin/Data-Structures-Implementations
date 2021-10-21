// Dynamic implementation using linked lists
#ifndef DYNAMIC_IMPLEMENTATION
#define DYNAMIC_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

typedef int deQueueEntryType;

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct node{
    deQueueEntryType item;
    struct node *next;
    struct node *prev;
}Node;

typedef struct dequeue{
    Node *front;
    Node *rear;
    int no_of_elements;
    Boolean full;
}Dequeue;

void createDeQueue(Dequeue *DQ) {
    DQ->front = DQ->rear = NULL;
    DQ->no_of_elements = 0;
    DQ->full = FALSE;
}

Boolean isDeQueueEmpty(Dequeue *DQ) {
    return DQ->front == NULL;
}

Boolean isDeQueueFull(Dequeue *DQ) {
    return DQ->full;
}

void insertRear(Dequeue *DQ, deQueueEntryType item) {
    Node *np;
    np = (Node *)malloc(sizeof(Node));
    if (np == NULL) {
        DQ->full = TRUE;
        printf("Not enough Memory");
        exit(1);
    }

    np->item = item;
    
    if (isDeQueueEmpty(DQ)) {
        DQ->front = DQ->rear = np;
        np->next = np->prev = NULL;
    }
    else {
        DQ->rear->next = np;
        np->prev = DQ->rear;
        DQ->rear = np;
        np->next = NULL;
    }
    DQ->no_of_elements++;
}

void insertFront(Dequeue *DQ, deQueueEntryType item) {
    Node *np;
    np = (Node *)malloc(sizeof(Node));
    if (np == NULL) {
        DQ->full = TRUE;
        printf("Not enough Memory");
        exit(1);
    }

    np->item = item;

    if(isDeQueueEmpty(DQ)) {
        DQ->front = DQ->rear = np;
        np->prev = np->next = NULL;
    }
    else {
        DQ->front->prev = np;
        np->next = DQ->front;
        DQ->front = np;
        np->prev = NULL;
    }
    DQ->no_of_elements++;
}

void deleteFront(Dequeue *DQ, deQueueEntryType *item) {
    if (isDeQueueEmpty(DQ)) {
        printf("DeQueue is empty");
        exit(1);
    }

    *item = DQ->front->item;
    Node *np;
    np = DQ->front;
    DQ->front = DQ->front->next;

    if(DQ->front == NULL) {
        DQ->rear = NULL;
    }
    else {
        DQ->front->prev = NULL;
    } 

    free(np);
    DQ->no_of_elements--;
}

void deleteRear(Dequeue *DQ, deQueueEntryType *item) {
    if(isDeQueueEmpty(DQ)) {
        printf("DeQueue is empty");
        exit(1);
    }

    *item = DQ->rear->item;
    Node *np = DQ->rear;
    DQ->rear = DQ->rear->prev;

    if (DQ->rear == NULL) {
        DQ->front = NULL;
    }
    else {
        DQ->rear->next = NULL;
    }

    free(np);
    DQ->no_of_elements--;
}

void display(Dequeue *DQ) {
    if (isDeQueueEmpty(DQ)) {
        printf("DeQueue is empty");
        exit(1);
    }

    Node *front = DQ->front;
    printf("Queue Elements\t:");
    
    while (front != NULL) {
        printf("%5d",front->item);
        front = front->next;
    }
}

#endif