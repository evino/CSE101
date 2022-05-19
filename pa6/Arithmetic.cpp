/*
   Evin Odisho
   edodisho
   PA6
   Arithmetic.cpp
*/


#include "BigInteger.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main(int argc, char * argv[]){

    ifstream in;
    ofstream out;
    string line1, blankLine, line3;

    // check command line for correct number of arguments
    if( argc != 3 ){
        cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
        return(EXIT_FAILURE);
    }

    // open files for reading and writing 
    in.open(argv[1]);
    if( !in.is_open() ){
        cerr << "Unable to open file " << argv[1] << " for reading" << endl;
        return(EXIT_FAILURE);
    }

    out.open(argv[2]);
    if( !out.is_open() ){
        cerr << "Unable to open file " << argv[2] << " for writing" << endl;
        return(EXIT_FAILURE);
    }

    getline(in, line1);
    getline(in, blankLine);
    getline(in, line3);

    BigInteger A;
    A = BigInteger(line1);
    BigInteger B;
    B = BigInteger(line3);
    
    out << A << endl;
    out << B << endl;

    out << A + B << endl;
    out << A - B << endl;
    out << A - A << endl;

    BigInteger A_mult1;
    A_mult1 = BigInteger("3");
    BigInteger B_mult1;
    B_mult1 = BigInteger("2");
    out << (A_mult1 * A) - (B_mult1 * B) << endl;

    out << A * B << endl;
    out << A * A << endl;
    out << B * B << endl;

    BigInteger A_mult2;
    A_mult2 = BigInteger("9");
    BigInteger B_mult2;
    B_mult2 = BigInteger("16");
    BigInteger A_pow_4;
    A_pow_4 = A * A * A * A;
    BigInteger B_pow_5;
    B_pow_5 = B * B * B * B * B;
    out << (A_mult2 * A_pow_4) + (B_mult2 * B_pow_5) << endl;


    // close files
   in.close();
   out.close();

   return EXIT_SUCCESS;
}
