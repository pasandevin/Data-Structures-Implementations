// Contiguous implementation using arrays
#ifndef CONTIGUOUS_IMPLEMENTATION
#define CONTIGUOUS_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

#define MAXLISTLENGTH 20

typedef int listEntryType;

typedef int Position;

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct list {
    int top_position;
    listEntryType items[MAXLISTLENGTH];
}List;

void createList(List *L) {
    L->top_position = -1;
}

Boolean isListEmpty(List *L) {
    return L->top_position == -1;
}

Boolean isListFull(List *L) {
    return L->top_position == MAXLISTLENGTH - 1;
}

int listSize(List *L) {
    return L->top_position;
}

void insertLast(List *L, listEntryType item) {
    if(isListFull(L)) {
        printf("List is Full");
        exit(1);
    }
    L->items[++L->top_position] = item;
}

void insertList(Position P, List *L, listEntryType item) {
    if(isListFull(L)) {
        printf("List is Full");
        exit(1);
    }
    if((P < 1) || (P > (listSize(L) + 1))) {
        printf("Trying to access a position not in the list");
        exit(1);
    }
    for (int temp_pos = listSize(L) + 1; temp_pos >= P; temp_pos--) {
        L->items[temp_pos] = L->items[temp_pos - 1]; 
    }
    L->items[P - 1] = item;
    L->top_position++;
}

void replaceList(Position P, List *L, listEntryType item) {
    if ((P < 1) || (P > (listSize(L) + 1))) {
        printf("Trying to replace an invalid position");
        exit(1);
    }
    L->items[P - 1] = item;
}

void deleteList(Position P, List *L, listEntryType *item) {
    if (isListEmpty(L)) {
        printf("List is Empty");
        exit(1);
    }
    if ((P < 1) || (P > (listSize(L) + 1))) {
        printf("Trying to delete a position not in the list");
        exit(1);
    }
    *item = L->items[P - 1];
    for (int temp_pos = P - 1; temp_pos < listSize(L); temp_pos++) {
        L->items[temp_pos] = L->items[temp_pos + 1];
    }
    L->top_position--;
}

void retrieveList(Position P, List *L, listEntryType *item) {
    if (isListEmpty(L)) {
        printf("List is Empty");
        exit(1);
    }
    if ((P < 1) || (P > (listSize(L) + 1))) {
        printf("Trying to retrieve from an invalid position");
        exit(1);
    }
    *item = L->items[P - 1];
}

void displayList(List *L) {
    if (isListEmpty(L)) {
        printf("List is Empty");
        exit(1);
    }
    printf("\nList Elements\t:");
    for (int temp_pos = 0; temp_pos <= listSize(L); temp_pos++) {
        printf("%5d",L->items[temp_pos]);
    }
}

#endif