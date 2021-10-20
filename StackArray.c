#include <stdio.h>

#define MAXSTACKSIZE 20

typedef int stackEntryType;
typedef struct Stack
{
    int top;
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


int main() {
    Stack S;
    
    createStack(&S);
    S.data[3] = 3;
    printf("%d",isStackEmpty(&S));
    

    return 0;
}