# PA8: Red-Black Tree Dictionary ADT

## Files included:

    1. README
       - README file written in MarkDown.
    2. Makefile
        - Makefile built on top of base Makefile provided
        on CSE 101 website. Compiles source code, and builds
        executable file.
    3. Dictionary.h
        - Dictionary ADT using Red-Black Trees header file.
    4. Dictionary.cpp
        - Implementation file for the Dictionary ADT using
        Red Black Trees.
    5. DictionaryTest.cpp
        - Test harness written by me for the Dictionary ADT.
        Includes some test from the Grading Script that I was
        debugging some failures with.
    6. Order.cpp
        - First top-level client file that takes in lines as an input
        and inserts the strings as keys into a Dictionary.
        Contains main function.
    7. WordFrequency.cpp
        - Second top-level client file that reads in lines of a file,
        convert the string to lower-case, and insert each word into the
        dictionary. Each key, will have a corresponding value which
        is the frequency of the key in the Dictionary.


### Design Choice:
For the Red and Black colors,
I chose to define them as integers
with 0 representing BLACK, and 1
representing RED.
