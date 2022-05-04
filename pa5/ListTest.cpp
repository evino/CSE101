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
    std::cout << "A's length is " << A.length() << std::endl;
    std::cout << "Inserting 5 after cursor" << std::endl;
    A.insertAfter(5);
    std::cout << "A's pos currently is " << A.position() << std::endl;
    std::cout << "A's length is " << A.length() << std::endl;
    std::cout << "A's front value is " << A.front() << std::endl;

    A.eraseAfter();
    std::cout << "A's length now is " << A.length() << std::endl;
    std::cout << "\nBefore return" << std::endl;
    return EXIT_SUCCESS;
}
