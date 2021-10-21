#include "Contiguous_Implementation.h"
// #include "Dynamic_Implementation.h"


int main() {
    Dequeue DQ;
    deQueueEntryType item;

    createDeQueue(&DQ);
    insertFront(&DQ,5);
    insertFront(&DQ,4);
    insertRear(&DQ,6);
    insertRear(&DQ,7);
    insertFront(&DQ,3);
    display(&DQ);

    deleteFront(&DQ,&item);
    deleteFront(&DQ,&item);
    printf("\ndeleted Item: %d\n",item);
    display(&DQ);

    deleteRear(&DQ,&item);
    printf("\ndeleted Item: %d\n",item);
    display(&DQ);

    return 0;
}