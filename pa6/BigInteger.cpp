#include "BigInteger.h"

// Global Const Variables
const long base = 1000000000;
const int power = 9;

BigInteger::BigInteger() {
    signum = 0;
    digits = List();
}

BigInteger::BigInteger(std::string s) {
    try {
        std::stol(s[0], nullptr, 10);
    }
    catch (std::invalid_argument) {
        std::cout << "caught" << std::endl;
    }
    std::cout << "After isDig" << std::endl;
    if (s.empty()) {
        throw std::invalid_argument("BigInteger: Constructor: empty string");
    }

    if (s[0] != '-' || s[0] != '+' || !isdigit(s[0])) {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }
    for (int i = 0; i <= s.length(); i++) {
        
        if (!isdigit(s[i])) {
            throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
        }
    }

}
