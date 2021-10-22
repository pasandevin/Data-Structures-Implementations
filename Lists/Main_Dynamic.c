#include "Dynamic_Implementation.h"

int main() {
    List L;
    listEntryType item;

    createList(&L);

    insertFront(&L,0);
    displayList(&L);
    printf("\n");
    /*List = 0*/

    insertFront(&L,1);
    displayList(&L);
    printf("\n");
    /**List = 1, 0*/


    insertLast(&L,2);
    displayList(&L);
    printf("\n");
    /*List = 1, 0, 2*/

    deleteList(2,&L,&item);
    printf("\nDeleted Element\t:%5d",item);
    displayList(&L);
    printf("\n");
    /*List = 1, 2*/

    deleteLast(&L,&item);
    printf("\nDeleted Element\t:%5d",item);
    displayList(&L);
    printf("\n");
    /*List = 1*/

    deleteLast(&L,&item);
    printf("\nDeleted Element\t:%5d",item);
    displayList(&L);
    printf("\n");
    /*List is empty*/

    insertFront(&L,1);
    displayList(&L);
    printf("\n");
    /*List = 1*/

    insertFront(&L,2);
    displayList(&L);
    printf("\n");
    /*List = 2, 1*/

    insertList(2,&L,3);
    displayList(&L);
    printf("\n");
    /*List = 2, 3, 1*/

    deleteFront(&L,&item);
    printf("\nDeleted Element\t:%5d",item);
    displayList(&L);
    printf("\n");
    /*List = 3, 1*/

    deleteFront(&L,&item);
    printf("\nDeleted Element\t:%5d",item);
    displayList(&L);
    printf("\n");
    /*List = 1*/

    deleteLast(&L,&item);
    printf("\nDeleted Element\t:%5d",item);
    displayList(&L);
    printf("\n");
    /*List is empty*/

    insertLast(&L,1);
    displayList(&L);
    printf("\n");
    /*List = 1*/

    return 0;
}