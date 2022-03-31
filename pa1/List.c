/*
Evin Odisho
edodisho
pa1
List.c
*/


#include "List.h"
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>

// structs ------------------------------------
// private Node type
typedef struct NodeObj *Node;

// private NodeObj type
typedef struct NodeObj {
    int data;
    Node next;
    Node previous;
} NodeObj;

typedef struct ListObj {
    Node front;
    Node back;
    Node cursor;
    int length;
} ListObj;

// Constructors-Destructors ---------------------

// Returns reference to new node object. Initializes prev/next and data fields.
Node newNode (int data) {
    Node N = malloc(sizeof(NodeObj));
    N->data = data;
    N->previous = NULL;
    N->next = NULL;
    return (N);
}

// Frees heap mem pointed to by *pN, sets *pN to NULL
void freeNode (Node *pN) {
    if (pN != NULL *pN != NULL) {
        free(*pN);
        *pN = NULL;
    }
    return;
}

List newList(void) {
    List L;
    L = malloc(sizeof(ListObj));
    L->front = NULL;
    L->back = NULL;
    L->cursor = NULL;
    L->index = -1;
    L->length = 0;
    return(L);
}

void freeList(List *pL) {
    if(pL != NULL && *pL != NULL) {
        while (!isEmpty(*pL)) {
            delete(*pL);
        }
        free(*pL);
        *pL = NULL;
    }
    return;
}


// Access functions ------------------------------

int length(List L) {
    if (L == NULL) {
        printf("List Error: calling length() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    return (L->length);
}

int index(List L) {
    if (L == NULL) {
        printf("List Error: calling index() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (isEmpty(L)) {
        printf("List Error: calling index() on empty List\n");
        exit(EXIT_FAILURE);
    }
    return (L->index);
}

int front(List L) {
    if (L == NULL) {
        printf("List Error: calling front() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (length(L) < 0) {
        printf("List Error: calling front() on empty List\n");
        exit(EXIT_FAILURE);
    }
    return (L->front->data);
}

int back(List L) {
    if (L == NULL) {
        printf("List Error: calling back() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (length(L) < 0) {
        printf("List Error: calling back() on empty List\n");
        exit(EXIT_FAILURE);
    }
    return(L->back->data);
}


int get(List L) {
    if (L == NULL) {
        printf("List Error: calling get() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (length(L) < 0) {
        printf("List Error: calling get() on empty List\n");
        exit(EXIT_FAILURE);
    }
    if (index(L) <= 0) {
        printf("List Error: calling get() with undefined cursor\n");
        exit(EXIT_FAILURE);
    }
    return (L->cursor->data);
}

bool equals(List A, List B) {
    bool eq = false;
    Node N = NULL;
    Node M = NULL;

    if (A == NULL || B == NULL) {
        printf("List Error: calling equals() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }

    eq = (A->length == B->length);
    N = A->front;
    M = B->front;
    while (eq && N!= NULL) {
        eq = (N->data == M->data);
        N =  N->next;
        M = M->next;
    }
    return eq;
}

bool isEmpty(List L) {
    if (L == NULL) {
        printf("List Error: calling isEmpty() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
       
    return (L->length == 0);
}

// Not fully sure if this works. My logic is that I can just delete/free the list
// from memory, then just 'create' a new list.
void clear(List L) {
    moveFront(L);
    Node N;
    Node temp;
    Node current;
    for (L->current = L->front; L->current <= L->length; L->current++) {
        temp = N->next;
        freeNode(N);
        N = temp;
    }
    L->front = NULL;
    L->back = NULL;
    L->cursor = NULL;
    L->index = -1;
    L->length = 0;
}

void set(List L, int x) {
    if (L == NULL) {
        printf("List Error: calling set() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (length(L) <= 0) {
        printf("List Error: calling set() on an empty List\n");
        exit(EXIT_FAILURE);
    }
    if (index(L) < 0) {
        printf("List Error: calling set() undefined cursor\n");
        exit(EXIT_FAILURE);
    }
    L->cursor->data = x; // Just replaces cursor data with a new int
    return;
}

void moveFront(List L) {
    if (!isEmpty(L)) {
        L->cursor = L->front;
    }
    return;
}

void moveBack(List L) {
    if (!isEmpty(L)) {
        L->cursor = L->back;
    }
    return;
}



