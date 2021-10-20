// #include "Contiguous_Implementation.h"
// #include "Circular_Contiguous_Implementation.h"
#include "Dynamic_Implementation.h"


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