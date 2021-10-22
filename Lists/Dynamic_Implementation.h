// Dynamic implementation using linked lists
#ifndef DYNAMIC_IMPLEMENTATION
#define DYNAMIC_IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>

typedef int listEntryType;

typedef int Position;

typedef enum {
    FALSE,
    TRUE
}Boolean;

typedef struct listnode {
    listEntryType item;
    struct listnode *next;
}ListNode;

typedef struct list {
    int count;
    Boolean full;
    ListNode *head;
}List;

void createList (List *L) {
    L->count = 0;
    L->full = FALSE;
    L->head = NULL;
}

Boolean isListEmpty(List *L) {
    return L->head == NULL;
}

Boolean isListFull(List *L) {
    return L->full;
}

int listSize(List *L) {
    return L->count;
}

void insertFront(List *L, listEntryType item) {
    ListNode *ln = (ListNode *)malloc(sizeof(ListNode));
    if (ln == NULL) {
        printf("Not enough Memory");
        L->full = TRUE;
        exit(1);
    }
    ln->item = item;

    ln->next = L->head;
    L->head = ln;

    L->count++;
}

void insertLast(List *L, listEntryType item) {
    ListNode *ln = (ListNode *)malloc(sizeof(ListNode));
    if (ln == NULL) {
        printf("Not enough Memory");
        L->full = TRUE;
        exit(1);
    }

    ln->item = item;
    ln->next = NULL;

    if (L->head == NULL) {
        L->head = ln;
    }
    else {
        ListNode *temp = L->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ln;
    }
    L->count++;
}

void insertList(Position P, List *L, listEntryType item) {
    ListNode *ln = (ListNode *)malloc(sizeof(ListNode));
    if (ln == NULL) {
        printf("Not enough Memory");
        L->full = TRUE;
        exit(1);
    }  
    if (P < 1 || P > L->count) {
        printf("Position is out of the list");
        exit(1);
    } 
    ln->item = item;
    ListNode *temp = L->head;
    for (int temp_pos = 1; temp_pos < P - 1; temp_pos++) {
        temp = temp->next;
    }
    ln->next = temp->next;
    temp->next = ln;
    L->count++;   
}

void deleteFront(List *L, listEntryType *item) {
    if (isListEmpty(L)) {
        printf("List is empty");
        exit(1);
    }
    ListNode *ln = L->head;
    *item = L->head->item;
    L->head = L->head->next;
    free(ln);
    L->count--;
}

void deleteLast(List *L, listEntryType *item) {
    if (isListEmpty(L)) {
        printf("List is empty");
        exit(1);
    }
    ListNode *temp_pointer = L->head;
    if (temp_pointer->next == NULL) {
        *item = temp_pointer->item;
        L->head = NULL;
        free(temp_pointer);
    }
    else {
        while(temp_pointer->next->next != NULL) {
        temp_pointer = temp_pointer->next;
        }
        L->head = temp_pointer;
        *item = temp_pointer->next->item;
        free(temp_pointer->next);
        temp_pointer->next = NULL;
    }
    L->count--;
}

void deleteList(Position P, List *L, listEntryType *item) {
    if (isListEmpty(L)) {
        printf("List is empty");
        exit(1);
    }
    if (P < 1 || P > listSize(L)) {
        printf("Position is out of the list");
        exit(1);
    }
    ListNode *temp_pointer = L->head;
    if (temp_pointer->next == NULL) {
        *item = temp_pointer->item;
        L->head = NULL;
        free(temp_pointer);
    }
    else {
        for (int temp_pos = 1; temp_pos < P - 1; temp_pos++) {
            temp_pointer = temp_pointer->next;
        }
        ListNode *nextNode = temp_pointer->next->next;
        free(temp_pointer->next);
        temp_pointer->next = nextNode;
    }
    L->count--;
}

void displayList(List *L) {
    if (isListEmpty(L)) {
    printf("\nList is empty\n");
    return;
    }
    ListNode *temp_pos = L->head;
    printf("\nList Elements\t:");
    do {
        printf("%5d", temp_pos->item);
        temp_pos = temp_pos->next;
    }while(temp_pos != NULL);   
}

#endif