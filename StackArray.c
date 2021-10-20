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


int main() {
    Stack S;
    
    createStack(&S);
    S.data[3] = 3;
    printf("%d",S.data[3]);
    

    return 0;
}