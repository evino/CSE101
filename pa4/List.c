/*
Evin Odisho
edodisho
pa3
List.c
*/


#include "List.h"

// structs ------------------------------------
// private Node type
typedef struct NodeObj *Node;

// private NodeObj type
typedef struct NodeObj {
    void* data;
    Node next;
    Node previous;
} NodeObj;

typedef struct ListObj {
    Node front;
    Node back;
    Node cursor;
    int length;
    int index;
} ListObj;

// Constructors-Destructors ---------------------

// Returns reference to new node object. Initializes prev/next and data fields.
Node newNode (void *data) {
    Node N = malloc(sizeof(NodeObj));
    N->data = data;
    N->previous = NULL;
    N->next = NULL;
    return (N);
}

// Frees heap mem pointed to by *pN, sets *pN to NULL
void freeNode (Node *pN) {
    if (pN != NULL && *pN != NULL) {
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
    if (pL == NULL || *pL == NULL) {
        printf("List Error: calling freeList() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if(pL != NULL && *pL != NULL) {
        while (!isEmpty(*pL)) {
            deleteFront(*pL);
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
    if (L->cursor == NULL || isEmpty(L)) {
        L->index = -1;
    }
    return (L->index);
}

void *front(List L) {
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

void *back(List L) {
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


void *get(List L) {
    if (L == NULL) {
        printf("List Error: calling get() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
   
    if (L->length <= 0) {
        printf("List Error: calling get() on empty List\n");
        exit(EXIT_FAILURE);
    }
    
    if (L->index < 0 || L->cursor == NULL) {
        printf("List Error: calling get() with undefined cursor\n");
        exit(EXIT_FAILURE);
    }
    return L->cursor->data;
}


bool isEmpty(List L) {
    if (L == NULL) {
        printf("List Error: calling isEmpty() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    return (L->length == 0);
}

void clear(List L) {
    if (L == NULL) {
        printf("Calling clear() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    moveFront(L);
    Node N;
    Node temp;
    for (N = L->front; N != NULL;) {
        temp = N->next;
        freeNode(&N);
        N = temp;
    }
    L->front = NULL;
    L->back = NULL;
    L->cursor = NULL;
    L->index = -1;
    L->length = 0;
}

void set(List L, void *x) {
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
    if (L == NULL) {
        printf("List Error: Calling moveFront() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (!isEmpty(L)) {
        L->cursor = L->front;
    }
    L->index = 0;
    return;
}

void moveBack(List L) {
    if (L == NULL) {
        printf("List Error: Calling moveBack() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (!isEmpty(L)) {
        L->cursor = L->back;
    }
    L->index = (L->length - 1);
    return;
}

void movePrev(List L) {
    if (L == NULL) {
        printf("List Error: Calling movePrevious() on NULL List reference\n");
    }
    if (L->cursor != NULL && L->cursor != L->front) {
        L->cursor = L->cursor->previous;
        L->index--;
    } else if (L->cursor != NULL && L->cursor == L->front) {
        L->cursor = NULL;
        L->index = -1;
    }
    return;
}

void moveNext(List L) {
    if (L == NULL) {
        printf("List Error: Calling moveNext() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (L->cursor != NULL && L->cursor != L->back) {
        L->cursor = L->cursor->next;
        L->index++;
    } else if (L->cursor != NULL && L->cursor == L->back) {
        L->cursor = NULL;
        L->index = -1;
    }
    return;
}

void prepend(List L, void *x) {
    Node N = newNode(x);
    if (L == NULL) {
        printf("List Error: Calling prepend() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (!isEmpty(L)) {
        L->front->previous = N;
        N->next = L->front;
        N->previous = NULL;
        L->front = N;
    } else {
        L->front = N;
        L->back = N;
        L->front->previous = L->back->next = NULL;
    }
    L->index++;
    L->length++;
    return;
}

void append(List L, void *x) {
    if (L == NULL) {
        printf("List Error: Calling append() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    Node N = newNode(x);
    if (!isEmpty(L)) {
        L->back->next = N;
        N->previous = L->back;
        L->back = N;
        L->back->next = NULL; // Added this in, since I think this should be done
                             // just in case.
    } else {
        L->front = N;
        L->back = N;
        L->front->previous = L->back->next = NULL;
    }
    L->length++;
    return;
}


void insertBefore(List L, void *x) {
    if (isEmpty(L)) {
        printf("List Error: calling insertBefore() on empty list\n");
        exit(EXIT_FAILURE);
    }
    if (L->index < 0) {
        printf("List Error: calling insertBefore() on undefined cursor\n");
        exit(EXIT_SUCCESS);
    }
    if (L == NULL) {
        printf("List Error: calling insertBefore() on NULL List reference\n");
    }

    Node N = newNode(x);
    if (L->cursor == L->front) {
        N->previous = NULL;
        N->next = L->cursor;
        L->cursor->previous = N;
        L->front = N;
    } else {
        N->previous = L->cursor->previous;
        N->next = L->cursor;
        L->cursor->previous->next = N;
        L->cursor->previous = N;
    }
    L->length++;
    L->index++;
    return;
}

void insertAfter(List L, void *x) {
    if (isEmpty(L)) {
        printf("List Error: calling insertAfter() on empty list\n");
        exit(EXIT_FAILURE);
    }
    if (L->index < 0) {
        printf("List Error: calling insertAfter() on undefined cursor\n");
        exit(EXIT_SUCCESS);
    }
    if (L == NULL) {
        printf("List Error: calling insertAfter() on NULL List reference\n");
    }
    Node N = newNode(x);
    if (L->cursor == L->back) {
        N->previous = L->cursor;
        N->next = NULL;
        L->cursor->next = N;
        L->back = N;
    } else {
        N->previous = L->cursor;
        N->next = L->cursor->next;
        L->cursor->next->previous = N;
        L->cursor->next = N;
    }
    L->length++;
    return;
}

void deleteFront(List L) {
    Node N = NULL;
    if (L == NULL) {
        printf("List Error: Calling deleteFront() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (isEmpty(L)) {
        printf("List Error: Calling deleteFront() on empty list\n");
        exit(EXIT_FAILURE);
    }
    N = L->front;
    if (L->cursor == L->front) {
        L->cursor = NULL;
        L->index = -1;
    }
    if (L->length > 1) {
       L->front = L->front->next;
    } 
    else {
        L->front = L->back = NULL;
    }
    L->length--;
    L->index--;
    freeNode(&N);
    return;
}

void deleteBack(List L) {
    Node N = NULL;
    if (L == NULL) {
        printf("List Error: Calling deleteBack() on NULL List Reference\n");
        exit(EXIT_FAILURE);
    }
    if (isEmpty(L)) {
        printf("List Error: Calling deleteBack() on empty list\n");
        exit(EXIT_FAILURE);
    }
    N = L->back;
    if (L->cursor == L->back) {
        L->cursor = NULL;
        L->index = -1;
    }
    if (L->length > 1) {
        L->back = L->back->previous;
    }
    else {
        L->front = L->back = NULL;
    }
    L->length--;
    freeNode(&N);
    return;
}

void delete(List L) {
    Node N = NULL;
    if (L == NULL) {
        printf("List Error: calling delete() on NULL List reference\n");
        exit(EXIT_FAILURE);
    }
    if (L->length <= 0) {
        printf("List Error: calling delete() on empty list\n");
        exit(EXIT_FAILURE);
    }
    if (L->index < 0 || L->cursor == NULL) {
        printf("List Error: calling delete() on undefined cursor\n");
        exit(EXIT_FAILURE);
    }
    N = L->cursor;
    
    /*
    if (L->cursor == L->front) {
        L->front = L->cursor->next;
        L->cursor->next->previous = NULL;
    }
    
    else if (L->cursor == L->back) {
        L->back = L->cursor->previous;
        L->cursor->previous->next = NULL;
    }
    */

    if (index(L) == 0) {
        printf("Del front\n");
        deleteFront(L);
        return;
    }

    else if(index(L) == length(L) -1) {
        printf("Del back\n");
        deleteBack(L);
        return;
    }

    else {
        L->cursor->previous->next = L->cursor->next;
        L->cursor->next->previous = L->cursor->previous;
    }
    L->length--;
    L->cursor = NULL;
    L->index = -1;
    freeNode(&N);
    return;
}

