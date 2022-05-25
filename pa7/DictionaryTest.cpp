/*
   Evin Odisho
   edodisho
   PA7
   DictionaryTest.cpp
*/


#include "Dictionary.h"
using namespace std;


int main(int argc, char **argv) {
    cout << "First call of constructor" << endl;
    Dictionary A;
    string S[] = {"first", "second", "third", "fourth", "fifth"};
    for (int i = 0; i < 5; i++) {
        //cout << "I = " << i << endl;
        A.setValue(S[i], i);
    }

    cout << "Calling pre_string() on A: " << A.pre_string() << endl;
    cout << "A's size: " << A.size() << endl;

    string test[] = {"one", "two", "foo", "bar", "happy", "is", "three", "par"};
    
    Dictionary B;

    for (int i = 0; i < 8; i++) {
        B.setValue(test[i], i+1);
    }

    std::cout << "B to_string()" << endl;
    cout << "B size: " << B.size() << endl;
    cout << B.to_string() << endl;


    cout << "\n\nB's size: " << B.size() << endl;
    std::cout << "\n" << B.pre_string() << endl;

    //std::cout << B.getValue("foo") << endl;

    if(B.contains("four")) {
        cout << "B containing 'par' is true!" << endl;
    } else {
        cout << "Doesn't contain it" << endl;
    }



    cout << "Copy constructor called" << endl;
    cout << "B's size: " << B.size() << endl;


    // empty_traverse debug
    A.clear();
    A.setValue("a", 1);
    A.setValue("b", 2);
    A.setValue("c", 3);
    A.setValue("e", 5);
    A.begin();
    cout << A.currentVal() << endl;
    A.next();
    cout << A.currentVal() << endl;
    if (A.hasCurrent() == true) {
        cout << "true" << endl;
    } else {
        cout << "False" << endl;
    }
    A.next();
    A.next();
    // 5 is expected
    cout << A.currentVal() << endl;
    if (A.hasCurrent() == true) {
        cout << "True" << endl;
    } else {
        cout << "false" << endl;
    }

    Dictionary C = B;
    C.end();
    cout << "C's to_string: " << C << endl;


    cout << "Clearing C" << endl;
    C.clear();

    C.setValue("one", 1);
    C.setValue("two", 2);
    C.setValue("three", 3);
    C.setValue("four", 4);
    C.setValue("five", 5);

    cout << "C's to_string now is: " << C << endl;

    cout << "Calling set value with duplicate kay" << endl;

    C.setValue("one", 25);
    cout << "After overwriting value of one of the node, C nos is: \n" << C << endl;

    C.end();
    cout << "C's end value is: " << C.currentVal() << endl;
    cout << "C's end key is: " << C.currentKey() << endl;

    C.prev();
    cout << "C's value now is: " << C.currentVal() << endl;

    C.begin();
    cout << "C's front value is: " << C.currentVal() << endl;
    cout << "C's front key is: " << C.currentKey() << endl;
    
    cout << "After calling next on C, C's value is: " << C.currentVal() << endl;

    cout << "C's get value at key 'three' returns: " << C.getValue("three") << endl;

    
    if (A == C) {
        cout << "A & C are equal" << endl;
    } else {
        cout << "A & C are NOT equal" << endl;
    }


    return EXIT_SUCCESS;
}


