#include "Dictionary.h"

using namespace std;
int main(int argc, char **argv) {
    cout << "First call of constructor" << endl;
    Dictionary A;
    string S[] = {"first", "second"};
    for (int i = 0; i < 2; i++) {
        cout << "I = " << i << endl;
        A.setValue(S[i], i+1);
    }

    cout << "Calling pre_string() on A: " << A.pre_string() << endl;
    cout << "A's size: " << A.size() << endl;

    Dictionary B = Dictionary(A);
    cout << "Copy constructor called" << endl;
    cout << "B's size: " << B.size() << endl;

    return EXIT_SUCCESS;
}
