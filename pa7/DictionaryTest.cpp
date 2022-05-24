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

    if(B.contains("par")) {
        cout << "B containing 'par' is true!" << endl;
    }

    cout << "Copy constructor called" << endl;
    cout << "B's size: " << B.size() << endl;

    return EXIT_SUCCESS;
}
