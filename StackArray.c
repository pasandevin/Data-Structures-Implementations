#include <stdio.h>
#include <stdlib.h>

#define MAXSTACKSIZE 20

typedef char stackEntryType;
typedef struct Stack
{
    int top;
    int no_of_elements;
    stackEntryType data[MAXSTACKSIZE];
}Stack;

void createStack(Stack *S) {
    S->top = -1;
}

int isStackEmpty(Stack *S) {
    return S->top == -1;
}

int isStackFull(Stack *S) {
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

int main() {
    Stack S;
    char c;
    
    createStack(&S);

    char msg[] = "Hello World";

    printf("The Array to push to the Stack is :\t%s", msg);

    for (int i = 0; msg[i] != '\0'; i++) {
        push(&S, msg[i]);
    }
    printf("\n\n");

    for (int i = 0; msg[i] != 'k'; i++) {
        pop(&S, &c);
        putchar(c);
    }

    // while (isStackEmpty(&S))
    // {
    //     /* code */
    // }
    




    

    return 0;
}