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
    int A_elems = (length() / 2);
    int B_elems = (length() - A_elems);

    for (int i = 1; i <= A_elems; i++) {
        A.insertBefore(i);
    }

    for (int j = B_elems; j <= length(); j++) {
        B.insertBefore(j);
    }

    std::cout << "List A: " << A.to_string() << std::endl;
    std::cout << "List B: " << B.to_string() << std::endl;

    return;
}


int main (int argc, char **argv) {
    List D;
    List S;
    for (int i = 1; i <= 7; i++) {
        A.insertBefore(i);
    }
    shuffle(A);


    return 0;
}
