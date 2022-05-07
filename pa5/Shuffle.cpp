/*
 * Evin Odisho
 * edodisho
 * PA5
 * Shuffle.c
*/


#include "List.h"
#include <fstream>

// void shuffle()
// This function will alter its List reference arguement by performing one shuffle opertation.
// The function will be called in main(), and will be used as many times as neccessary, until
// shuffled list returns to original order.
void Shuffle(List& D) {
    List A;
    List B;
    int A_elems = (D.length() / 2);
    int B_elems = (D.length() - A_elems);

    for (int i = 1; i <= A_elems; i++) {
        A.insertBefore(i);
    }

    for (int j = B_elems; j <= D.length(); j++) {
        B.insertBefore(j);
    }

    D.clear();
    A.moveFront();
    B.moveFront();

    while (B.peekNext() != B.back()) {
        D.insertBefore(B.peekNext());
        B.moveNext();
        // Can use if statement instead since only going through once
        if (A.peekNext() != A.back()) {
            //D.insertBefore(B.peekNext());
            D.insertBefore(A.peekNext());
            A.moveNext();
            //B.moveNext();
        }
    }

    std::cout << "List A: " << A.to_string() << std::endl;
    std::cout << "List B: " << B.to_string() << std::endl;
    std::cout << "D: " << D.to_string() << std::endl;

    return;
}


int main (int argc, char **argv) {
    List D;
    List S;
    for (int i = 1; i <= 7; i++) {
        D.insertBefore(i);
    }
    Shuffle(D);


    return 0;
}
