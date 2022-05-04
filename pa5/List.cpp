/*
   Evin Odisho
   edodisho
   PA5
   List.cpp
*/

#include "List.h"
#include <stdexcept>

// Private Constructor --------------------------------------------------------

// Node Constructor
List::Node::Node(ListElement x) {
    data = x;
    next = nullptr;
    prev = nullptr;
}

// Class Constructors & Destructors -------------------------------------------
List::List() {
    frontDummy = new Node (-10000);
    backDummy = new Node (10000);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    // Can have before And after cursor be the front and back dummies
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;
}

// Copy Constructor
List::List(const List& L) {
    // Makes empty List
    frontDummy = new Node(-10000);
    backDummy = new Node(10000);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = nullptr;
    afterCursor = nullptr;
    pos_cursor = 0;
    num_elements = 0;

    Node *N = L.frontDummy->next;
    while (N != nullptr) {
        insertAfter(N->data);
        N = N->next;
    }
}


// Destructor
List::~List() {
    //moveFront();
    while (length() > 0) {
        //eraseAfter();
    }
}

// Access functions

int List::length() const {
    return (num_elements);
}


//ListElement List::front() const {
    //if (length() == 0) {
        //throw std::length_error("List Error: Calling front() on empty list");
    //}

    //// moveFront
    //// peekPrev
    ////return (frontDummy->next->data);
//}


// Do same for back()

int List::position() const {
    if (!(0 <= pos_cursor && pos_cursor <= length())) {
        throw std::length_error("List Error: position() out of bounds");
    }
    return pos_cursor;
}



// Manipulation



// InsertAfter

void List::insertAfter(ListElement x) {
    Node* N = new Node(x);
    if (length() <= 0) {
        frontDummy->next = backDummy->prev = N;
    } else {
        beforeCursor->next = N;
        N->prev = beforeCursor;
        afterCursor->prev = N;
        N->next = afterCursor;
        afterCursor = N;
        num_elements++;
    }
}
