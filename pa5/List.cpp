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
    while (N != L.backDummy) {
        insertBefore(N->data);
        N = N->next;
    }
    
    moveFront();
}


// Destructor
List::~List() {
    moveFront();
    while (length() > 0) {
        eraseAfter();
    }

    beforeCursor = nullptr;
    afterCursor = nullptr;
    delete frontDummy;
    frontDummy = nullptr;
    delete backDummy;
    backDummy = nullptr;
}

// Access functions

int List::length() const {
    return (num_elements);
}


ListElement List::front() const {
    if (length() <= 0) {
        throw std::length_error("List Error: Calling front() on empty list");
    }
    return (frontDummy->next->data);
}

ListElement List::back() const {
    if (length() <= 0) {
        throw std::length_error("List Error: Calling back() on empty list");
    }
    return (backDummy->prev->data);
}


int List::position() const {
    if (!(0 <= pos_cursor && pos_cursor <= length())) {
        throw std::length_error("List Error: Calling position() out of bounds cursor position");
    }
    return pos_cursor;
}

ListElement List::peekNext() const {
    if (!(position()<length())) {
        throw std::range_error("List Error: Calling peekNext() on out of bounds of cursor position");
    }
    return (afterCursor->data);
}

ListElement List::peekPrev() const {
    if (!(position() > 0)) {
        throw std::range_error("List Error: Calling peekPrev() on out of bounds cursor position");
    }
    return (beforeCursor->data);
}



// Manipulation

void List::clear() {
    moveFront();
    while (num_elements > 0) {
        eraseAfter();
    }
    return;
}

// moveFront()
void List::moveFront() {
    beforeCursor = frontDummy;
    afterCursor = frontDummy->next;
    pos_cursor = 0;
    return;
}

// moveBack()
void List::moveBack() {
    afterCursor = backDummy;
    beforeCursor = backDummy->prev;
    pos_cursor = length();
    return;
}

// moveNext()
ListElement List::moveNext() { 
    if (!(position()<length())) {
        throw std::range_error("List Error: Calling moveNext() on out of bounds cursor position");
    }
    Node *N = afterCursor;
    beforeCursor = afterCursor;
    afterCursor = afterCursor->next;
    pos_cursor++;
    return (N->data);
}

ListElement List::movePrev() {
    if (!(position() > 0)) {
        throw std::range_error("List Error: Calling movePrev() on out of bounds cursor position");
    }
    Node *N = beforeCursor;
    afterCursor = beforeCursor;
    beforeCursor = beforeCursor->prev;
    pos_cursor--;
    return (N->data);
}

// InsertAfter
void List::insertAfter(ListElement x) {
    Node* N = new Node(x);
    beforeCursor->next = N;
    N->prev = beforeCursor;
    afterCursor->prev = N;
    N->next = afterCursor;
    afterCursor = N;
    num_elements++;

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
    pos_cursor++;
    return;
}

void List::setAfter(ListElement x) {
    if (!(position()<length())) {
        throw std::range_error("List Error: calling setAfter() on out of bounds cursor position");
    }

    afterCursor->data = x;
    return;
}

void List::setBefore(ListElement x) {
    if (!(position() > 0)) {
        throw std::range_error("List Error: Calling setBefore() on out of bounds cursor position.");
    }

    beforeCursor->data = x;
    return;
}


// Error when running locally but not on timeshare
void List::eraseAfter() {
    if (!(position()<length())) {
        throw std::range_error("List Error: calling eraseAfter() on empty List");
    }

    Node *N = afterCursor->next;
    beforeCursor->next = N;
    N->prev = beforeCursor;
    delete afterCursor;
    afterCursor = N;
    num_elements--;
  
    return;
}

void List::eraseBefore() {
    if (!(position() > 0)) {
        throw std::range_error("List Error: Calling eraseBefore() on out of range cursor position.");
    }
    
    Node *N = beforeCursor->prev;
    N->next = afterCursor;
    afterCursor->prev = N;
    delete beforeCursor;
    beforeCursor = N;
    num_elements--;
    pos_cursor--;
    return;
}

int List::findNext(ListElement x) {
    while (afterCursor != backDummy) {
        if (x == afterCursor->data) {
            moveNext();
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
            movePrev();
            return position();
        }
        movePrev();
    }
    return -1;
}

List List::concat(const List& L) const {
    List J;
    Node *N = this->frontDummy->next;
    Node *M = L.frontDummy->next;
    while (N != backDummy) {
        J.insertAfter(N->data);
        N = N->next;
        J.moveNext();
    }
    while (M != L.backDummy) {
        J.insertAfter(M->data);
        M = M->next;
        J.moveNext();
    }

    J.moveFront();
    return J;
}


std::string List::to_string() const {
    Node *N = nullptr;
    std::string s = "(";
    if (length() <= 0) {
        s = "()";
        return s;
    }
    for (N = frontDummy->next; N != backDummy->prev; N = N->next) {
        s += std::to_string(N->data) + ", ";
    }
    s += std::to_string(N->data) + ")";

    return s;
}

bool List::equals(const List& R) const {
    bool eq = false;
    Node *N = nullptr;
    Node *M = nullptr;

    eq = (this->length() == R.length());
    N = this->frontDummy->next;
    M = R.frontDummy->next;
    while (eq && N!= backDummy) {
        eq = (N->data == M->data);
        N = N->next;
        M = M->next;
    }
    return eq;
}



// Overloaded operators -------------------------------------------------------

// operator<<()
std::ostream& operator<<( std::ostream& stream, const List& L ) {
    return stream << L.List::to_string();
}

// operator==()
bool operator==( const List& A, const List& B ) {
    return A.List::equals(B);
}

// operator=()
List& List::operator=( const List& L ) {
    if (this != &L) {
        List temp = L;

        std::swap(frontDummy, temp.frontDummy);
        std::swap(backDummy, temp.backDummy);
        std::swap(num_elements, temp.num_elements);
    }

    return *this;
}

// Got help with cleanup() pseudocode from tutor Vincent
void List::cleanup() {
    int old_pos = position();
    List M;
    moveFront();
    int x = 0;
    
    // need to moveFront to the front of the List M
    while (afterCursor != backDummy) {
        x = afterCursor->data;
        M.moveFront(); // Added here
        if (M.findNext(x) != -1) {
            eraseAfter();
            if (position() < old_pos) {
                old_pos--;
            }
        } else {
            M.insertAfter(x);
            moveNext();
        }
    }
    moveFront();
    
    for (int i = 1; i <= old_pos; i++) {
        moveNext();
    }
    M.clear();
    return;
}
