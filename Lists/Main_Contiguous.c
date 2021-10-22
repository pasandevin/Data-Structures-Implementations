#include "Contiguous_Implementation.h"

int main() {
    List L;
    listEntryType item;

    createList(&L);
    insertLast(&L,1);
    insertLast(&L,3);
    insertList(2,&L,2);
    displayList(&L);

    deleteList(2,&L,&item);
    printf("\nDeleted Element\t:%5d",item);
    displayList(&L);

    retrieveList(1,&L,&item);
    printf("\nThe element at 1st location\t:%5d",item);

    return 0;
}

