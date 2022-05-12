#include "BigInteger.h"

// Global Const Variables
const long base = 1000000000;
const int power = 9;


// Constructors ---------------------------------------------------------------

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

    unsigned long i;
    if (isdigit(s[0])) {
        i = 0;
    } else {
        i = 1;
    }

    //std::cout << "I is " << i << std::endl;
    //std::cout << "Str len is " << s.length() << std::endl;
    for (unsigned long ind = i; ind < s.length(); ind++) {
        if (!(isdigit(s[ind]))) {
            //std::cout << "Index " << ind << std::endl;
            //std::cout << "isDigi loop" << std::endl;
            throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
        }
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
            //std::cout << "Sub string of s is: " << str << std::endl;
            digits.insertBefore(stol(str));
        }
    }
    std::cout << "Digits is " << digits << std::endl;
}

BigInteger::BigInteger(const BigInteger& N) {
    signum = N.signum;
    digits = N.digits;
}





// Other Functions ------------------------------------------------------------


