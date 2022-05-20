#include "Dictionary.h"

using namespace std;
int main(int argc, char **argv) {
    cout << "First call of constructor" << endl;
    Dictionary A;
    Dictionary B = Dictionary(A);
    cout << "Copy constructor called" << endl;

    return EXIT_SUCCESS;
}
