#include "BigInteger.h"
int main(int argc, char **argv) {
    BigInteger A;
    BigInteger B;
    
    //std::string s = "1";
    ////std::string s2 = "-1";
    //
    //std::string s = "882133";
    //std::string s2 = "659179";

    std::string s = "3";
    std::string s2 = "99";

    //std::string s = "111122223333";
    //std::string s2 = "112122223333";

    //std::string s = "12345678910111213141516171819202123";
    //std::string s2 = "00012345678910111213141516171819202121";
    //std::string s2 = "9876545439000000000000000100000000000006543654365346534";
    //std::string s2 = "0";
    
    //std::string s = "9128734667000004389234563456345619187236478";
    //std::string s2 = "9876545439000000000000000200000000000006543654365346534";


    A = BigInteger(s);
    B = BigInteger(s2);
    //A.makeZero();
    std::cout << "A: " << A.to_string() << std::endl;
    std::cout << "B: " << B.to_string() << std::endl;
    std::cout << A.compare(B) << std::endl;
    std::cout << "A's sign is " << A.sign() << std::endl;

    // add test
    std::cout << "Adding A and B" << std::endl;
    BigInteger sum;
    sum = A.add(B);
    std::cout << sum.to_string() << std::endl;

    std::cout << "Doing diff between  A and B" << std::endl;
    BigInteger diff;
    diff = A.sub(B);
    std::cout << diff.to_string() << std::endl;


    std::cout<< "doing mult() of A and B" << std::endl;
    BigInteger prod;
    prod = A.mult(B);
    std::cout << "Prdouct: " << prod.to_string() << std::endl;


    A.negate();
    std::cout << "After negates, A's sign is " << A.sign() << std::endl;
    return 0;
}
