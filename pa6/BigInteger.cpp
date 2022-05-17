#include "BigInteger.h"
#include <math.h>

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
    
    if (s[0] == '-') {
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

    // Loops through string, making sure each element is a valid digit.
    bool zero = true;
    for (unsigned long ind = i; ind < s.length(); ind++) {
        if (!(isdigit(s[ind]))) {
            throw std::invalid_argument("BigInteger: Constructor: non-numeric string");
        }
        if (zero && s[ind] == 0) {
            zero = true;
        } else {
            zero = false;
        }
    }

    std::string str;

    //digits.moveFront();
    //for (; i <= s.length(); i++) {  // Grabs power number of digits and places inserts them into digits list
    //for (; i < s.length(); i++) {  // Grabs power number of digits and places inserts them into digits list
     for (int ind = s.length(); ind >= 0; ind -= power) {
        //if (s[i] == 0) {
            //str = std::to_string(s[0]);
            //digits.insertBefore(stol(str));
            ////break;
        //}
         std::cout << "Index is " << ind << std::endl;
         if (ind < power) {
             //ind = ind + power;
             std::cout << "Ind now " << ind << std::endl;
            str = s.substr(0, ind);
         } else {
            str = s.substr(ind - power, power);
         }
         std::cout << "str: " << str << std::endl;
        if (str.length() > 0)
            digits.insertAfter(stol(str));
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


// WILL CHANGE, TO THE LONGER BUT MORE MEMORY EFFICIENT WAY!!!

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


// Manipulation Procedures ----------------------------------------------------

// makeZero()
//  Re-sets this BigInteger to the zero state.
void BigInteger::makeZero() {
    digits.clear();
    signum = 0;
    return;
}


void BigInteger::negate() {
    if (signum == -1) {
        signum = 1;
    } else if (signum == 1) {
        signum = -1;
    }
    return;
}


// BigInteger Arithmetic Helper functions -------------------------------------

// negateList()
// Changes the sign of each integer in List L. Used by sub().
void negateList(List& L) {
    L.moveFront();
    long negateElem;
    while (L.position() < L.length()) {
        negateElem = L.peekNext() * -1;
        L.setAfter(negateElem);
        L.moveNext();
    }
    return;
}


// sumList()
// Overwrites the state of S with A + sgn*B (considered as vectors).
// Used by both sum() and sub().
void sumList(List& S, List A, List B, long sgn) {
    S.moveBack();
    A.moveBack();
    B.moveBack();
    long sum;
    std::cout << "A len " << A.length() << ". B len " << B.length() << std::endl;
    while (A.position() > 0 && B.position() > 0) {
        std::cout << "A Pos " << A.position() << ". B pos " << B.position() << std::endl;
        sum = A.peekPrev() + (sgn * B.peekPrev());
        S.insertAfter(sum);
        A.movePrev();
        B.movePrev();
    }

    while (A.position() > 0) {
        std::cout << "DB1" << std::endl;
        S.insertAfter(A.peekPrev());
        A.movePrev();
    }

    while (B.position() > 0) {
        std::cout << "DB2" << std::endl;
        S.insertAfter(B.peekPrev());
        B.movePrev();
    }

    return;
}


// normalizeList()
// Performs carries from right to left (least to most significant
// digits), then returns the sign of the resulting integer. Used
// by add(), sub() and mult().



int normalizeList(List &L) {
    if (L.front() < 0) {
        std::cout << "Front before: " << L.front() << std::endl;
        negateList(L);
        std::cout << "Front after: " << L.front() << std::endl;
        normalizeList(L);  // Not sure if this will work
    }

    L.moveBack();
    long carry = 0;
    std::cout << "L: " << L <<std::endl;

    double prevTemp;
    double baseTemp;
    long mod;
    while (L.position() > 0) {
        std::cout << "Prev before is " << L.peekPrev() << std::endl;
        L.setBefore(L.peekPrev() + carry);
        prevTemp = L.peekPrev();
        baseTemp = base;
        carry = floor(prevTemp / baseTemp);
        //carry = floor(L.peekPrev() / base);
        std::cout << "Carry is " << carry <<std::endl;
        mod = L.peekPrev() % base;
        if (mod < 0) {
            mod += base;
        }
        L.setBefore(mod);
        //L.setBefore(L.peekPrev() % base);
        std::cout << "Prev now is " << L.peekPrev() << std::endl;
        L.movePrev();
    }

    if (carry != 0) {
        L.insertBefore(carry);
    }

    if (L.front() > 0) {
        return 1;
    } else if (L.front() < 0) {
        return -1;
    }

    return 0;
}


void shiftList(List& L, int p) {
    L.moveFront();
    for (int i = 0; i <= p; i++) {
        L.insertBefore(0);
    }
    return;
}


// BigInteger Arithmetic operations -------------------------------------------

BigInteger BigInteger::add(const BigInteger& N) const {
    BigInteger sum;
    List sum_list;

    if (this->signum == N.signum) {
        sumList(sum_list, this->digits, N.digits, N.signum);
        normalizeList(sum_list);
        //sum.digits = sum_list;
    } else {
        sumList(sum_list, this->digits, N.digits, -1);
        normalizeList(sum_list);
    }
    sum.digits = sum_list;
    //sum.signum = normalizeList(sum.digits);
    sum.signum = sum_list.front();
    std::cout << "sum's list is " << sum.digits << std::endl;
    return sum;
}


BigInteger BigInteger::sub(const BigInteger& N) const {
    BigInteger Diff;
    BigInteger copy;
    copy = N;
    //copy.digits = N.digits;
    //copy.signum = N.signum;
    negateList(copy.digits);
    //copy.negate();
    std::cout << "Signum now is " << copy.sign() << std::endl;
    Diff = this->add(copy);
    return Diff;
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
    //while (digits.peekNext() != digits.back()) {
    while (digits.position() < digits.length()) {
        str += std::to_string(digits.peekNext());
        digits.moveNext();
        std::string zeros;
        if (digits.position() > 1 && digits.position() < digits.length()) {
            std::string padSize = std::to_string(digits.peekNext());
            for (int i = 0; i < power - (padSize.length()); i++) {
                zeros = '0' + zeros;
            }
            str += zeros;
        }
    }

    //str += std::to_string(digits.back());

    //Padding, works I think..
   /* 
    if (str.length() < power) {
        int zeroes_to_add = power - str.length();
        for (int j = 0; j < zeroes_to_add; j++) {
            str.insert(0, 1, '0');
            str = '0' + str;
        }
    }
*/
    return str;
}
