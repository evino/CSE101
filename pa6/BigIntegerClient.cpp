#include "BigInteger.h"
int main(int argc, char **argv) {
    BigInteger A;
    BigInteger B;
    std::string s = "12345678910111213141516171819202123";
    std::string s2 = "12345678910111213141516171819202121";
    //std::string s2 = "9876545439000000000000000100000000000006543654365346534";
    //std::string s2 = "0";
    A = BigInteger(s);
    B = BigInteger(s2);
    std::cout << "A: " << A.to_string() << std::endl;
    std::cout << "B: " << B.to_string() << std::endl;
    std::cout << A.compare(B) << std::endl;
    return 0;
}
