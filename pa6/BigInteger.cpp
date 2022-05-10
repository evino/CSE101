#include "BigInteger.h"

BigInteger::BigInteger() {
    signum = 0;
    digits = List();
}

BigInteger::BigInteger(std::string s) {
    if (s.empty()) {
        throw std::invalid_argument("BigInteger: Constructor: empty string");
    }
    if (s[0] != '-' || s[0] != '+') {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }
    for (int i = 0; i <= s.length(); i++) {
        if (!isdigit(s[i])) {
            throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
        }
    }

