#include "BigInteger.h"
int main(int argc, char **argv) {
    BigInteger A;
    std::string s = "-12345678910111213141516171819202122";
    A = BigInteger(s);
    std::cout << A.to_string() << std::endl;
    return 0;
}
