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

    //if (s[0] != '-' || s[0] != '+' || !isdigit(s[0])) {
        //throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    //}

    if (s[0] == '-') {
        signum = -1;
    } else if (s[0] == '0') {
        signum = 0;
    } else if (s[0] == '+' || isdigit(s[0])) {
        signum = 1;
    } else {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }

    int i;
    if (isdigit(s[0])) {
        i = 0;
    } else {
        i = 1;
    }

    std::string str;

    //digits = List();
    digits.moveFront();
    for (; i <= s.length(); i++) {
        if (i % power == 0 && i >= 9 && digits.peekPrev() != digits.back()) { // Checks if divisble by 9, to put it into node
            digits.moveNext();
        } else {
            str = s.substr(i, 9);
            i += 8;
            std::cout << "Sub string of s is: " << str << std::endl;
            digits.insertBefore(stol(str));
            //digits.insertBefore(stol(s.substr(i, 9)));
        }
    }
    std::cout << "Digits is " << digits << std::endl;
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


