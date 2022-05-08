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
    int A_Val;
    int B_Val;

    D.moveFront();
    while (D.position() < A_elems) {
        A_Val  = D.peekNext();
        A.insertBefore(A_Val);
        D.moveNext();
    }
    
    while (D.position() < D.length()) {
        B_Val = D.peekNext();
        B.insertBefore(B_Val);
        D.moveNext();
    }

    D.clear();
    A.moveFront();
    B.moveFront();

    while (B.position() < B.length()) {
        D.insertBefore(B.peekNext());
        B.moveNext();
        if (A.position() < A.length()) {
            D.insertBefore(A.peekNext());
            A.moveNext();
        }
    }
    return;
}


int main (int argc, char **argv) {
    if (argc != 2) { // One count for program name, and second for argument
        throw std::invalid_argument("Must include one command line arguement.");
    }
    
    int n = std::stoi(argv[1]);
    if (!(n > 0)) {
        throw std::range_error("Invalid Deck start.");
    }

    List D;
    List D_Copy;

for (int size = 1; size <= n; size++) {
    // clearing lists for each iteration
    D.clear();
    D_Copy.clear();

    for (int i = 1; i <= size; i++) {
        D.insertBefore(i);
    }
    D_Copy = D;
   
    Shuffle(D);  // First and initial shuffle
    int shuffleCount = 1;
    
    while (!(D_Copy == D)) { // Keeps on looping and reshuffling until List D reverts to original sequence. Keeps track of shuffle(s) needed.
        Shuffle(D);
        shuffleCount++;
    }

    std::cout << "Shuffle count is " << shuffleCount << std::endl;
}

    return 0;
}
