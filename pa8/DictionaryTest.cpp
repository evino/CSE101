/*
   Evin Odisho
   edodisho
   PA8
   DictionaryTest.cpp
*/

#include "Dictionary.h"
using namespace std;

int main(int argc, char **argv) {
    Dictionary A;
    



    // Remove_Value test. Initially failing test 1.
    A.setValue("d", 1);
    A.setValue("b", 5);
    A.setValue("a", 10);
    A.setValue("c", 15);
    A.setValue("f", 20);
    A.setValue("e", 25);
    A.setValue("g", 30);
    A.begin();
    A.remove("a");
   
    //cout << A.currentVal() << endl;

    if (A.hasCurrent()) {
        cout << "A has current, when it shouldn't" << endl;
    } else {
        cout << "current is undefined";
    }
    
    A.end();
    A.remove("d");


    return EXIT_SUCCESS;
}
