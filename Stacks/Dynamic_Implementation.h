// Dynamic implementation using linked lists
#ifndef DYNAMIC_IMPLEMENTATION
#define DYNAMIC_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>



typedef char stackEntryType;

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct node {
    stackEntryType item;
    struct node *next;
}Node;

typedef struct stack {
    Node *top;
    int no_of_elements;
}Stack;



void createStack(Stack *S) {
    S->top = NULL;
    S->no_of_elements = 0;
}

Boolean isStackEmpty(Stack *S) {
    return S->top == NULL;
}


void push(Stack *S, stackEntryType item) {
    Node *np;
    np = (Node *)malloc(sizeof(Node));

    if (np == NULL) {
        printf("Memory Full");
        exit(1);
    }

    np->item = item;
    np->next = S->top;
    S->top = np;

    S->no_of_elements++;
}


void pop(Stack *S, stackEntryType *item) {

    if (isStackEmpty(S)) {
        printf("Stack is Empty");
        exit(1);
    }

    Node *np;
    np = S->top;
    *item = S->top->item;
    S->top = S->top->next;
    free(np);

    S->no_of_elements--;   
}

#endif
