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
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;

    Node *N = L.frontDummy->next;
    while (N != backDummy) {
        insertAfter(N->data);
        N = N->next;
    }
}


// Destructor
List::~List() {
    
    
    std::cout << "\n\n" << std::endl;
    //moveFront();
    std::cout << "value: " << afterCursor->data << "(" << length() << ")" << std::endl;
    clear();
    /*
    while (afterCursor != backDummy) {
       std::cout << "value: " << afterCursor->data << "(" << length() << ")" << std::endl;
        eraseAfter();
    }
    */

    std::cout << "After while" << std::endl;
    beforeCursor = nullptr;
    afterCursor = nullptr;
    delete frontDummy;
    delete backDummy;
    //frontDummy = nullptr;
    //backDummy = nullptr;
}

// Access functions

int List::length() const {
    return (num_elements);
}


ListElement List::front() const {
    if (length() == 0) {
        throw std::length_error("List Error: Calling front() on empty list");
    }
    return (frontDummy->next->data);
}

ListElement List::back() const {
    if (length() == 0) {
        throw std::length_error("List Error: Calling back() on empty list");
    }
    return (backDummy->prev->data);
}


int List::position() const {
    if (!(0 <= pos_cursor && pos_cursor <= length())) {
        throw std::length_error("List Error: position() out of bounds");
    }
    return pos_cursor;
}

ListElement List::peekNext() const {
    if (!(position()<length())) {
        throw std::range_error("List Error: Position out of bounds of list");
    }
    return (afterCursor->data);
}

ListElement List::peekPrev() const {
    if (!(position() < length())) {
        throw std::range_error("List Error: Cursor position out of bounds of list.");
    }
    return (beforeCursor->data);
}



// Manipulation

void List::clear() {
    moveFront();
    while (length() > 0) {
        eraseAfter();
    }

    return;
}

// moveFront()
void List::moveFront() {
    //beforeCursor = frontDummy;
    afterCursor = frontDummy->next;
    pos_cursor = 0;
    return;
}

// moveBack()
void List::moveBack() {
    //afterCursor = backDummy;
    beforeCursor = backDummy->prev;
    pos_cursor = num_elements - 1;
    return;
}

// moveNext()
ListElement List::moveNext() { 
    if (!(position()<length())) {
        throw std::range_error("List Error: Calling moveNext() on out of bounds cursor position");
    }
    Node *N = afterCursor;
    beforeCursor = beforeCursor->next;
    afterCursor = afterCursor->next;
    pos_cursor++;
    return (N->data);
}

ListElement List::movePrev() {
    if (!(position() < length())) {
        throw std::range_error("List Error: Calling movePrev() on out of bounds cursor position");
    }
    Node *N = beforeCursor;
    beforeCursor = beforeCursor->prev;
    afterCursor = afterCursor->prev;
    pos_cursor--;
    return (N->data);
}

// InsertAfter
void List::insertAfter(ListElement x) {
    Node* N = new Node(x);
    //if (length() <= 0) {
        //frontDummy->next = backDummy->prev = N;
    //} else {
        beforeCursor->next = N;
        N->prev = beforeCursor;
        afterCursor->prev = N;
        N->next = afterCursor;
        afterCursor = N;
        //}
    num_elements++;

    std::cout << "Inserting " << x << ". Address is " << &afterCursor << std::endl;
    return;
}

void List::insertBefore(ListElement x) {
    Node *N = new Node(x);
    beforeCursor->next = N;
    N->prev = beforeCursor;
    afterCursor->prev = N;
    N->next = afterCursor;
    beforeCursor = N;
    num_elements++;
    return;
}

void List::setAfter(ListElement x) {
    if (!(position()<length())) {
        throw std::range_error("List Error: calling setAfter on out of bounds cursor position");
    }

    afterCursor->data = x;
    return;
}

void List::setBefore(ListElement x) {
    if (!(position() < length())) {
        throw std::range_error("List Error: Calling setBefore on out of bounds cursor position.");
    }

    beforeCursor->data = x;
    return;
}


// Error when running locally but not on timeshare
void List::eraseAfter() {
    if (!(position()<length())) {
        throw std::range_error("List Error: calling eraseAfter on empty List");
    }

    Node *N = afterCursor;
    /*
    if (length() > 1) {
        afterCursor = afterCursor->next;
        afterCursor->prev = beforeCursor;
        beforeCursor->next = afterCursor;
    } else {
        frontDummy->next = backDummy;
        backDummy->prev = frontDummy;
        beforeCursor = frontDummy;
        afterCursor = backDummy;
    }
    */

    afterCursor = afterCursor->next;
    afterCursor->prev = beforeCursor;
    beforeCursor->next = afterCursor;
    num_elements--;
    delete N;
    
    return;
}

void List::eraseBefore() {
    if (!(position() < length())) {
        throw std::range_error("List Error: Calling eraseBefore() on out of range cursor position.");
    }

    Node *N = beforeCursor;

    beforeCursor = beforeCursor->prev;
    beforeCursor->next = afterCursor;
    afterCursor->prev = beforeCursor;
    num_elements--;
    delete N;
    return;
}

int List::findNext(ListElement x) {
    while (afterCursor != backDummy) {
        if (x == afterCursor->data) {
            return pos_cursor;
        }
        moveNext();
    }
    // returns -1 if x is not found in List
    return -1;
}

int List::findPrev(ListElement x) {
    while (beforeCursor != frontDummy) {
        if (x == beforeCursor->data) {
            return position();
        }
        movePrev();
    }
    return -1;
}
std::string List::to_string() const {
    Node *N = nullptr;
    std::string s = "(";
    for (N = frontDummy->next; N != backDummy->prev; N = N->next) {
        s += std::to_string(N->data) + ", ";
    }
    s += std::to_string(N->data) + ")";

    return s;
}
