#include "BigInteger.h"
#include <math.h>

// Global Const Variables
const long base = 1000000000;
const int power = 9;
//const long base = 100;  // CHANGE WHEN DONE
//const int power = 2;

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
    //unsigned long i;
    
    if (s[0] == '-' || s[0] == '+') {
        s = s.substr(1, s.length() -1);
    }

    /*
    if (isdigit(s[0])) {
        i = 0;
    } else {
        i = 1;
    }
    */

    // Loops through string, making sure each element is a valid digit.
    bool zero = true;
    for (unsigned long ind = 0; ind < s.length(); ind++) {
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

     for (int ind = s.length(); ind >= 0; ind -= power) {
         if (ind < power) {
            str = s.substr(0, ind);
         } else {
            str = s.substr(ind - power, power);
         }
        if (str.length() > 0) {
            digits.insertAfter(stol(str));
        }

    }
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
    BigInteger A = *this;
    BigInteger B = N;
    if (A.signum > B.signum) {
        return 1;
    } else if (A.signum < B.signum) {
        return -1;
    } else if (A.signum == 0 && B.signum == 0) {
        return 0;
    }
    
    // Implied that signums are equal at this point
    if (A.signum == 1) {
        if (A.digits.length() > B.digits.length()) {
            return 1;
        } else if (A.digits.length() < B.digits.length()) {
            return -1;
        } else if (A.digits.length() == B.digits.length()){
            A.digits.moveBack();
            B.digits.moveBack();
            while (A.digits.position() > 0 && B.digits.position() > 0) {
                if (A.digits.peekPrev() > B.digits.peekPrev()) {
                    return 1;
                } else if (A.digits.peekPrev() < B.digits.peekPrev()) {
                    return -1;
                }
                A.digits.movePrev();
                B.digits.movePrev();
            }
        }
    } else if (A.signum == -1) {
        if (A.digits.length() < B.digits.length()) {
            return 1;
        } else if (A.digits.length() > B.digits.length()) {
            return -1;
        } else if (A.digits.length() == B.digits.length()) {
            A.digits.moveBack();
            B.digits.moveBack();
            while (A.digits.position() > 0 && B.digits.position() > 0) {
                if (A.digits.peekPrev() > B.digits.peekPrev()) {
                    return 1;
                } else if (A.digits.peekPrev() < B.digits.peekPrev()) {
                    return -1;
                }
                A.digits.movePrev();
                B.digits.movePrev();
            }
        }
    }

    return 0;
}



// Manipulation Procedures ----------------------------------------------------

// makeZero()
//  Re-sets this BigInteger to the zero state.
void BigInteger::makeZero() {
    digits.clear();
    signum = 0;
    //return;
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
    ListElement negateElem;
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
void sumList(List& S, List A, List B, int sgn) {
    S.moveBack();
    A.moveBack();
    B.moveBack();
    long sum;

    while (A.position() > 0 && B.position() > 0) {
        sum = A.peekPrev() + (sgn * B.peekPrev());
        S.insertAfter(sum);
        A.movePrev();
        B.movePrev();
    }

    while (A.position() > 0) {
        S.insertAfter(A.peekPrev());
        A.movePrev();
    }

    while (B.position() > 0) {
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
        negateList(L);
        normalizeList(L);  // Not sure if this will work
    }

    L.moveBack();
    long carry = 0;

    double prevTemp;
    double baseTemp;
    long mod;
    while (L.position() > 0) {
        L.setBefore(L.peekPrev() + carry);
        prevTemp = L.peekPrev();
        baseTemp = base;
        carry = floor(prevTemp / baseTemp);
        mod = L.peekPrev() % base;
        if (mod < 0) {
            mod += base;
        }
        L.setBefore(mod);
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
    for (int ind = 0; ind < p; ind++) {
        L.insertBefore(0);
    }
    return;
}


void scalarMultList(List& L, ListElement m) {
    L.moveBack();
    ListElement m_copy;
    while (L.position() > 0) {
        m_copy = L.peekPrev() * m;

        L.movePrev();
        L.setAfter(m_copy);
    }
    return;
}


// BigInteger Arithmetic operations -------------------------------------------

BigInteger BigInteger::add(const BigInteger& N) const {
    BigInteger sum;
    List sum_list;

    if (this->signum == N.signum) {
        sumList(sum_list, this->digits, N.digits, 1);
        sum.signum = signum * normalizeList(sum_list);
        //normalizeList(sum_list);
        //sum.digits = sum_list;
    } else if (this->signum < N.signum) {
        sumList(sum_list, N.digits, this->digits, -1);
        sum.signum = sum_list.front() * normalizeList(sum_list);
    } else {
        sumList(sum_list, this->digits, N.digits, -1);
        sum.signum = sum_list.front() * normalizeList(sum_list);
    }
    
    if (sum.signum < 0) {
        sum.signum = -1;
    } else if (sum.signum > 0) {
        sum.signum = 1;
    } else {
        sum.signum = 0;
    }

    //normalizeList(sum_list);
    sum.digits = sum_list;
    //sum.signum = normalizeList(sum.digits);
    //sum.signum = sum_list.front();
    /*
    if (sum_list.front() > 0) {
        sum.signum = 1;
    } else if (sum_list.front() < 0) {
        sum.signum = -1;
    } else if (sum_list.front() == 0) {
        sum.signum = 0;
    }
    */
    //std::cout << "sum's list is " << sum.digits << std::endl;
    //normalizeList(sum_list);
    return sum;
}


BigInteger BigInteger::sub(const BigInteger& N) const {
    BigInteger Diff;
    BigInteger copy;
    copy = N;
    //copy.digits = N.digits;
    //copy.signum = N.signum;
    //egateList(copy.digits);
    copy.negate();
    Diff = this->add(copy);
    return Diff;
}

BigInteger BigInteger::mult(const BigInteger& N) const {
    BigInteger product;
    BigInteger A = *this;
    BigInteger B = N;
    BigInteger tmp;
    B.digits.moveBack();
    for (int i = 0; B.digits.position() > 0; i++) {
        tmp.digits = A.digits;
        tmp.signum = A.signum;
        //scalarMultList(A.digits, B.digits.movePrev());
        //scalarMultList(tmp.digits, B.digits.movePrev());
        scalarMultList(tmp.digits, B.digits.peekPrev());
        B.digits.movePrev();
        shiftList(tmp.digits, i); // might need to iterate
        product += tmp;
        //sumList(sum, sum, tmp.digits, 1);
        //normalizeList(sum);
    }

    // Gets products's signum
    int sign;
    sign = A.signum * B.signum;
    if (sign > 0) {
        product.signum = 1;
    } else if (sign < 0) {
        product.signum = -1;
    } else {
        product.signum = 0;
    }
    //product.signum = A.signum;
    return product;
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
        if (digits.position() >= 1 && digits.position() < digits.length()) {
            std::string padSize = std::to_string(digits.peekNext());
            for (int i = 0; i < power - (padSize.length()); i++) {
                zeros = "0" + zeros;
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



std::ostream& operator<<( std::ostream& stream, BigInteger N) {
    return stream << N.BigInteger::to_string();
}

bool operator==( const BigInteger& A, const BigInteger& B) {
    // Need to fix compare first
    if (A.compare(B) == 0) {
        return true;
    } else {
        return false;
    }
}

bool operator<( const BigInteger& A, const BigInteger& B ) {
    if (A.compare(B) == -1) {
        return true;
    } else {
        return false;
    }
}

bool operator<=( const BigInteger& A, const BigInteger& B ) {
    if (A.compare(B) == -1 || A.compare(B) == 0) {
        return true;
    } else {
        return false;
    }
}

bool operator>( const BigInteger& A, const BigInteger& B ) {
    if (A.compare(B) == 1) {
        return true;
    }
    else {
        return false;
    }
}

bool operator>=( const BigInteger& A, const BigInteger& B ) {
    if (A.compare(B) == 1 || A.compare(B) == 0) {
        return true;
    } else {
        return false;
    }
}

BigInteger operator+( const BigInteger& A, const BigInteger& B ) {
    return A.add(B);
}

BigInteger operator+=( BigInteger& A, const BigInteger& B ) {
    A = A.add(B);
    return A;
}

BigInteger operator-( const BigInteger& A, const BigInteger& B ) {
    return A.sub(B);
}

BigInteger operator-=( BigInteger& A, const BigInteger& B ) {
    A = A.sub(B);
    return A;
}

BigInteger operator*( const BigInteger& A, const BigInteger& B ) {
    //return A;
    return A.mult(B);
}

BigInteger operator*=( BigInteger& A, const BigInteger& B ) {
    A = A.mult(B);
    return A;
}
