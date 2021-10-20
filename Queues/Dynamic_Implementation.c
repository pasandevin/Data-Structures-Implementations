#include <stdio.h>
#include <stdlib.h>

typedef char queueEntryType;

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct node
{
    queueEntryType item;
    struct node *next;
}Node;

typedef struct queue
{
    Node *front;
    Node *rear;
    int no_of_elements;
    Boolean full;
}Queue;

void createQueue(Queue *Q) {
    Q->front = Q->rear = NULL;
    Q->no_of_elements = 0;
    Q->full = FALSE;
}

Boolean isQueueEmpty(Queue *Q) {
    return (Q->front == NULL) && (Q->rear == NULL);
}

Boolean isQueueFull(Queue *Q) {
    return Q->full;
}

void Insert(Queue *Q, queueEntryType item) {
    Node *np = (Node *) malloc(sizeof(Node));

    if (np == NULL) {
        printf("Not Enough Memory");
        Q->full = TRUE;
        exit(1);
    }

    np->item = item;
    np->next = NULL;

    if(isQueueEmpty(Q)) {
        Q->front = Q->rear = np;
    }
    else {
        Q->rear->next = np;
        Q->rear = np;
    }
    Q->no_of_elements++;
}

void Remove(Queue *Q, queueEntryType *item) {
    if(isQueueEmpty(Q)) {
        printf("Queue is empty");
        exit(1);
    }
    *item = Q->front->item;
    Node *np = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(np);
    Q->no_of_elements--;
}



int main() {
    Queue Q;
    char c;  
    createQueue(&Q);

    char msg[] = "Hello World";
    printf("The String to insert\t: %s", msg);

    for (int i = 0; msg[i] != '\0'; i++) {
        Insert(&Q, msg[i]);
    }

    printf("\n\n");
    printf("The String from Queue\t: ");

    while (!isQueueEmpty(&Q))
    {
        Remove(&Q, &c);
        putchar(c);
    }
   
    return 0;
}