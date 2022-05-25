#include "Dictionary.h"
#include<fstream>

using namespace std;

int main(int argc, char **argv) {
	ifstream in;
    ofstream out;

    string str;

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


    Dictionary D;
    for (int lineCount = 0 ; getline(in, str); lineCount++) {
    	D.setValue(str, lineCount);
    }

    out << D << endl;
    out << D.pre_string();

    in.close();
    out.close();

}