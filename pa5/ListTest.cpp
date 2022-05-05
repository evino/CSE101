/*
    Evin Odisho
    edodisho
    PA5
    ListTest.cpp
*/

#include "List.h"

int main(int argc, char **argv) {
    //List A;
    //A.insertAfter(5);
    //A.insertAfter(2);
    //A.insertAfter(15);
    //A.eraseAfter();
    List A;
    List B;
    //std::cout << "List A made" << std::endl;
    //std::cout << "(EMPTY LIST) A's length is " << A.length() << std::endl;
    //std::cout << "Inserting 5 after cursor" << std::endl;
    A.insertAfter(5);
    A.insertAfter(6);
    A.insertAfter(7);
    B.insertAfter(5);
    B.insertAfter(6);
    B.insertAfter(7);
    B.eraseAfter();

    if (A.equals(B) == true) {
        std::cout << "True!!" << std::endl;
    } else {
        std::cout << "False!" << std::endl;
    }
    //std::cout << "A's front value is " << A.front() << std::endl;
    A.moveFront();
    std::cout << "Pos is " << A.position() << std::endl;
    //std::cout << "Front peek next is " << A.peekNext() << std::endl;
    A.setAfter(1);
    std::cout << "A: " << A.to_string() << std::endl;
    std::cout << "Pos is " << A.position() << std::endl;
    //std::cout << "Front peek next is " << A.peekNext() << std::endl;

    //std::cout << "A now is: " << A.to_string() << std::endl;
    std::cout << "6 found at position " << A.findNext(6) << std::endl;
    std::cout << "Pos is " << A.position() << std::endl;
    //std::cout << "A's pos is " << A.position() << std::endl;
    //std::cout << "A len: " << A.length() << std::endl;
    std::cout << "Calling moveNext on front. returning: " << A.moveNext() << std::endl;
    std::cout << "A's pos currently is " << A.position() << std::endl;
    //std::cout << "A's length now is " << A.length() << std::endl;
    //std::cout << "A's front value now is " << A.front() << std::endl;

    //std::cout << "DB1" << std::endl;
    std::cout << "A: " << A.to_string() << std::endl;
    std::cout << "Peeknext() gets: " << A.peekNext() << std::endl;
    A.eraseAfter();
    std::cout << "after eraseAfter() A is: " << A.to_string() << std::endl;
    //std::cout << "DB2" << std::endl;
    ////A.eraseAfter();
    //std::cout << "A's length now is " << A.length() << std::endl;
    //std::cout << "\nBefore return" << std::endl;
    return EXIT_SUCCESS;
}
