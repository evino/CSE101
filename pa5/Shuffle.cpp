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

    //while (B.peekNext() != B.back()) {
    while (B.position() < B.length()) {
        D.insertBefore(B.peekNext());
        B.moveNext();
        //if (A.peekNext() != A.back()) {
        if (A.position() < A.length()) {
            D.insertBefore(A.peekNext());
            A.moveNext();
        } //else { //Insert back element of A
           //D.insertBefore(A.back());
        //}
    //}
    //D.insertBefore(B.back()); //Insert back elem of B
    }
    return;
}


int main (int argc, char **argv) {
        if (argc != 2) { // One count for program name, and second for argument
        throw std::invalid_argument("Must include one command line arguement.");
    }

    List D;
    List D_Copy;
    int n = std::stoi(argv[1]);

    for (int i = 1; i <= n; i++) {
        D.insertBefore(i);
    }

    D_Copy = D;
    Shuffle(D);

    int shuffleCount = 1;
    while (!(D_Copy.equals(D))) {
        Shuffle(D);
        shuffleCount++;
    }

    std::cout << "Shuffle count is " << shuffleCount << std::endl;


    return 0;
}
