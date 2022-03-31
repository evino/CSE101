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
} ListObj;

// Constructors-Destructors ---------------------


