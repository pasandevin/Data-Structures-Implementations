// Contigous implementation using arrays
#ifndef CONTIGUOUS_IMPLEMENTATION
#define CONTIGUOUS_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define MAXSTACKSIZE 20


typedef char stackEntryType;

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct Stack
{
    int top;
    int no_of_elements;
    stackEntryType data[MAXSTACKSIZE];
}Stack;


void createStack(Stack *S) {
    S->top = -1;
}

Boolean isStackEmpty(Stack *S) {
    return S->top == -1;
}

Boolean isStackFull(Stack *S) {
    return S->top == MAXSTACKSIZE - 1;
}

void push(Stack *S, stackEntryType item) {
    if (isStackFull(S)) {
        printf("Stack is Full");
        exit(1);
    }
    S->data[++S->top] = item;
    S->no_of_elements++;
}

void pop(Stack *S, stackEntryType *item) {
    if (isStackEmpty(S)) {
        printf("Stack is Empty");
        exit(1);
    }
    *item = S->data[S->top--];
    S->no_of_elements--;
}

#endif