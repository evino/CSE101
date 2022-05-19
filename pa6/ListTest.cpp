/*
    Evin Odisho
    edodisho
    PA6
    ListTest.cpp
*/


// My test harness for PA6's List ADT in C++. Harness shares a few lines
// with the ListClient.cpp file, but has more simplified tests that were used
// throughout ADT development and testing. As each new function was implemented,
// the function was called within this file to test it.

#include "List.h"

int main(int argc, char **argv) {
    List A;
    List B;
    std::cout << "List A made" << std::endl;
    //std::cout << "(EMPTY LIST) A's length is " << A.length() << std::endl;
    std::cout << "Inserting 5 after cursor" << std::endl;
    A.insertAfter(5);
    A.insertAfter(6);
    A.insertAfter(7);
    B.insertAfter(5);
    B.insertAfter(6);
    B.insertAfter(7);
    B.eraseAfter();
    std::cout << "A: " << A.to_string() << std::endl;
    
    if (A.equals(B) == true) {
        std::cout << "True!!" << std::endl;
    } else {
        std::cout << "False!" << std::endl;
    }
    std::cout << "A's front value is " << A.front() << std::endl;
    A.moveFront();
    std::cout << "Pos is " << A.position() << std::endl;
    std::cout << "Front peek next is " << A.peekNext() << std::endl;
    A.setAfter(1);
    std::cout << "A: " << A.to_string() << std::endl;
    std::cout << "Pos is " << A.position() << std::endl;

    std::cout << "A now is: " << A.to_string() << std::endl;
    std::cout << "6 found at position " << A.findNext(6) << std::endl;
    std::cout << "Pos is " << A.position() << std::endl;
    std::cout << "A len: " << A.length() << std::endl;
    std::cout << "Calling moveNext on front. returning: " << A.moveNext() << std::endl;
    std::cout << "A's pos currently is " << A.position() << std::endl;
    std::cout << "A's front value now is " << A.front() << std::endl;

    //std::cout << "DB1" << std::endl;
    std::cout << "A: " << A.to_string() << std::endl;
    //std::cout << "Peeknext() gets: " << A.peekNext() << std::endl;
    A.insertAfter(12);
    A.eraseAfter();
    A.insertAfter(9);
    A.insertAfter(6);
    A.insertAfter(7);
    A.insertAfter(1);
    A.insertAfter(7);
    std::cout << "bef A.clear()" << std::endl;
    A.moveNext();
    std::cout << A.to_string() << std::endl;
    std::cout << "Cursor position is " << A.position() << std::endl;
    std::cout << "Peeknext() gets: " << A.peekNext() << std::endl;
    std::cout << "A length: " << A.length() << std::endl;
    //A.clear();

    A.cleanup();
    std::cout << "after cleanup() A is: " << A.to_string() << std::endl;
    //std::cout << "DB2" << std::endl;
    ////A.eraseAfter();
    //std::cout << "A's length now is " << A.length() << std::endl;



 
    // Replicating Cleanup_size test 1 (DEBUG):
    std::cout << "\n\nCleanup_size test 1:" << std::endl;
    A.clear();
    A.insertAfter(1);
    A.insertAfter(2);
    A.insertAfter(3);
    A.insertAfter(1);
    A.insertAfter(2);
    A.insertAfter(1);

    std::cout << "A now before cleanup is: " << A.to_string() << std::endl;

    A.cleanup();
    std::cout << "A now after cleanup now is: " << A.to_string() << std::endl;

    List C = B;
    C.moveBack();
    std::cout << "List C: " << C << std::endl;

    if (C == B) {
        std::cout << "Lists B & C are equal" << std::endl;
    } else {
        std::cout << "Lists B & C are NOT equal" << std::endl;
    }

    std::cout << "Inserting (";
    for (int to_insert = 15; to_insert <= 20; to_insert++) {
        C.insertAfter(to_insert);
        std::cout << to_insert << " ";
    }
    
    std::cout << ") Into list C" << std::endl;
    std::cout << "List C now is: " << C << std::endl;
    std::cout << "B is: " << B.to_string() << std::endl;

    if (!(B == C)) { // Should not be equal
        std::cout << "There for B & C are NOT equal now." << std::endl;
    } else {
        std::cout << "The two are equal" << std::endl;
    }

    C.clear();
    std::cout << "Calling clear() on List C" << std::endl;
    std::cout << "C now is " << C << std::endl;

    B.clear();
    A.clear();
    std::cout << "Clearing A and B now" << std::endl;
    std::cout << "List B: " << B << std::endl;
    std::cout << "List A: " << A << std::endl;

    if ((A == B) && (A == C)) {
        std::cout << "All Lists now are clear and empty, and equal." << std::endl;
    } else {
        std::cout << "All the lists are not equal" << std::endl;
    }

    std::cout << "A's length is: " << A.length() << std::endl;
    std::cout << "B's length is: " << B.length() << std::endl;
    std::cout << "C's length is: " << C.length() << std::endl;

    std::cout << "\n\n END OF TEST REACHED" << std::endl;
    return EXIT_SUCCESS;
}
