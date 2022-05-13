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

    // Making signum correct value, based of what first char of string is
    if (s[0] == '0' || s[1] == '0') {
        signum = 0;
    } else if (s[0] == '-') {
        signum = -1;
    } else if (s[0] == '+' || isdigit(s[0])) {
        signum = 1;
    } else {
        throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
    }

    // If the first digit is a number, then I know that there is no plus sign
    // at the front, and I can start from the 0 character. Otherwise, there is
    // a plus or minus sign at the front, so I must start from character 1 in the
    // string.
    unsigned long i;
    if (isdigit(s[0])) {
        i = 0;
    } else {
        i = 1;
    }

    //std::cout << "I is " << i << std::endl;
    //std::cout << "Str len is " << s.length() << std::endl;

    // Loops through string, making sure each element is a valid digit.
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
    for (; i <= s.length(); i++) {  // Grabs power number of digits and places inserts them into digits list
        if (s[i] == 0) {
            str = std::to_string(s[0]);
            digits.insertBefore(stol(str));
            //break;
        }
        else if (i % power == 0 && i >= 9 && digits.peekPrev() != digits.back()) { // Checks if divisble by 9, to put it into node
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



// Access Functions -----------------------------------------------------------


// Returns a number representing negative (-1), positive (1), zero (0).
int BigInteger::sign() const {
    return signum;
}


// Compare()
// Returns -1, 1 or 0 according to whether this BigInteger is less than N,
// greater than N or equal to N, respectively.
int BigInteger::compare(const BigInteger& N) const {
// maybe strcmp() ???
    int cmp;

    std::string A = this->digits.to_string();
    std::string B = N.digits.to_string();
    if (A < B) {
        cmp = -1;
        std::cout << "A less" << std::endl;
    } else if (A > B) {
        cmp = 1;
        std::cout << "A greater" << std::endl;
    } else {
        std::cout << "equal" << std::endl;
        cmp = 0;
    }

    //if (this->signum < N.signum) {
        //cmp = -1;
    //} else if (this->signum > N.signum) {
        //cmp = 1;
    //} else {
        ////if (this->digits.length() < N.digits.length())
        ////}
    //}



    return cmp;
}

// Other Functions ------------------------------------------------------------

// to_string()
// Returns a string representation of this BigInteger consisting of its
// base 10 digits. If this BigInteger is negative, the returned string
// will begin with a negative sign '-'. If this BigInteger is zero, the
// returned string will consist of the character '0' only.
std::string BigInteger::to_string() {
    std::string str;
    if (this->signum == -1) {
        str = "-";
    } else if (signum == 0) {
        str = "0";
        return str;
    }

    digits.moveFront();
    while (digits.peekNext() != digits.back()) {
        str += std::to_string(digits.peekNext());
        digits.moveNext();
    }
    str += std::to_string(digits.back());

    //Padding, works I think..
/*
    if (str.length() < power) {
        int zeroes_to_add = power - str.length();
        for (int j = 0; j < zeroes_to_add; j++) {
            str.insert(0, 1, '0');
            //str = '0' + str;
        }
    }

    */
    return str;
}
