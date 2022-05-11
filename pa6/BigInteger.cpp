#include "BigInteger.h"

// Global Const Variables
const long base = 1000000000;
const int power = 9;

BigInteger::BigInteger() {
    signum = 0;
    //digits = List();
}

BigInteger::BigInteger(std::string s) {
    if (s.empty()) {
        throw std::invalid_argument("BigInteger: Constructor: empty string");
    }

    if (s[0] != '-' || s[0] != '+' || !isdigit(s[0])) {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }
    int i;
    if (isdigit(s[0])) {
        i = 0;
    } else {
        i = 1;
    }
    
    long l;
    //digits = List();
    digits.moveFront();
    for (; i <= s.length(); i++) {
        if (i % power == 0) { // Checks if divisble by 9, to put it into node
            digits.moveNext();
        } else {
            digits.insertBefore(stol(s.substr(i-9, i)));
        }
    }
}

/*
    for (; i <= s.length(); i++) {
        try {
            l = std::stol(s[i]);
        } catch (const std::invalid_argument) {
            throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
        }
        //if (!isdigit(s[i])) {
            //throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
        //}
    }
    */


