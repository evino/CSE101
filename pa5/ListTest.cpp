/*
    Evin Odisho
    edodisho
    PA5
    ListTest.cpp
*/

#include "List.h"

int main(int argc, char **argv) {
    List A;
    std::cout << "List A made" << std::endl;
    std::cout << "(EMPTY LIST) A's length is " << A.length() << std::endl;
    std::cout << "Inserting 5 after cursor" << std::endl;
    A.insertAfter(5);
    A.insertAfter(6);
    A.insertAfter(7);
    std::cout << "A's front value is " << A.front() << std::endl;
    A.moveFront();
    std::cout << "Front peek next is " << A.peekNext() << std::endl;
    A.setAfter(1);
    std::cout << "Calling moveNext on front " << A.moveNext() << std::endl;
    std::cout << "A's pos currently is " << A.position() << std::endl;
    std::cout << "A's length now is " << A.length() << std::endl;
    std::cout << "A's front value now is " << A.front() << std::endl;

    A.eraseAfter();
    std::cout << "A's length now is " << A.length() << std::endl;
    std::cout << "\nBefore return" << std::endl;
    return EXIT_SUCCESS;
}
