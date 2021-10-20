#include "Contiguous_Implementation.h"


int main() {

    Stack S;
    char c;  
    createStack(&S);

    char msg[] = "Hello World";
    printf("The String to push\t: %s", msg);

    for (int i = 0; msg[i] != '\0'; i++) {
        push(&S, msg[i]);
    }

    printf("\n\n");
    printf("The String from Stack\t: ");

    while (!isStackEmpty(&S))
    {
        pop(&S, &c);
        putchar(c);
    }
   
    return 0;
}