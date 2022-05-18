#include "BigInteger.h"
int main(int argc, char **argv) {

/*
     * Adding numbers fall into one of 4 cases, denote pos = positive number,
     * neg = negative number
     *
     * pos + pos = pos
     *
     * pos + neg = 0
     *           < 0
     *           > 0
     *
     * neg + pos = 0
     *           < 0
     *           > 0
     *
     * neg + neg = neg
     */
    BigInteger A, B, C, D;
    A = BigInteger("+111122223333");
    B = BigInteger("+222211110000");

    // pos + pos = pos
    D = BigInteger("+333333333333");
    C = A + B;

    std::cout << "C: " << C << std::endl;
    std::cout << "D: " << D << std::endl;

    std::cout << "C's signum is " << C.sign() << std::endl;
    if (!(C == D))
      std::cout << "Bruh" << std::endl;
      return 1;

    // add a positive and a negative integer
    //-> pos + neg = 0
    B = BigInteger("-111122223333");
    C = A + B;
    if (C.sign() != 0)
      return 2;

    //-> pos + neg > 0
    B = BigInteger("-110122223333");
    D = BigInteger("1000000000");
    C = A + B;
    if (C.sign() != 1)
      return 31;
    if (!(C == D))
      return 32;

    //-> pos + neg < 0
    B = BigInteger("-112122223333");
    D = BigInteger("-1000000000");
    C = A + B;
    if (C.sign() != -1)
      return 41;
    if (!(C == D))
      return 42;

    //-> neg + neg = neg
    A = BigInteger("-221211110000");
    D = BigInteger("-333333333333");
    C = A + B;
    if (!(C == D))
      return 5;

    return 0;
  }
    
/*
    A = BigInteger("+111122223333");
    B = BigInteger("+222211110000");

    // pos + pos = pos
    D = BigInteger("+333333333333");
    A += B;

    if (!(A == D))
      return 1;

    // add a positive and a negative integer
    //-> pos + neg = 0

    A = BigInteger("+111122223333");
    B = BigInteger("-111122223333");
    A += B;
    if (A.sign() != 0)
      return 2;

    //-> pos + neg > 0

    A = BigInteger("+111122223333");
    B = BigInteger("-110122223333");
    D = BigInteger("1000000000");
    A += B;
    if (A.sign() != 1)
      return 31;
    if (!(A == D))
      return 32;

    //-> pos + neg < 0
    A = BigInteger("+111122223333");
    B = BigInteger("-112122223333");
    D = BigInteger("-1000000000");
    A += B;
    if (A.sign() != -1)
      return 41;
    if (!(A == D))
      return 42;

    //-> neg + neg = neg
    A = BigInteger("-221211110000");
    B = BigInteger("-112122223333");
    D = BigInteger("-333333333333");
    A += B;
    if (!(A == D))
      return 5;

    return 0;
  }
  */
    /*
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
    */

