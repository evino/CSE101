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

    D.moveFront();
    std::cout << "D org is " << D << std::endl;
    int A_Val;
    while (D.position() < A_elems) {
        A_Val  = D.peekNext();
        A.insertBefore(A_Val);
        D.moveNext();
    }
    
    int B_Val;
    while (D.position() < D.length()) {
        B_Val = D.peekNext();
        B.insertBefore(B_Val);
        D.moveNext();
    }

    //for (int i = D.peekNext(); D.position() < A_elems; D.moveNext()) {
        //D.moveNext();
        //std::cout << "The next one is " << i << std::endl;
        //A.insertBefore(i);
    //}
    
    //for (int j = D.peekNext(); D.position() < D.length(); D.moveNext()) {
        //B.insertBefore(j);
    //}
    
    std::cout << "A is " << A << std::endl;
    std::cout << "B is " << B << std::endl;


    //std::cout << "A is " << A << std::endl;
    //std::cout << "B is " << B << std::endl;
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
    int n = std::stoi(argv[1]);
    if (!(n > 0)) {
        throw std::range_error("Invalid Deck start.");
    }
    List D;
    List D_Copy;

    std::cout << "DB1" << std::endl;
    for (int i = 1; i <= n; i++) {
        D.insertBefore(i);
    }

    D_Copy = D;
   
    std::cout << "before shuffle" << std::endl;
    Shuffle(D);
    std::cout << D << std::endl;
    if (!(D_Copy.equals(D))) {
        std::cout << "false." << std::endl;
    }

    int shuffleCount = 1;
    //while (!(D_Copy.equals(D))) {
    while (!(D_Copy == D)) {
        Shuffle(D);
        std::cout << "After calling shuffle again (in main's while): " << D << std::endl;
        shuffleCount++;
    }

    //std::cout << "Shuffle count is " << shuffleCount << std::endl;


    return 0;
}
