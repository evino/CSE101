# PA5: The Perfect Shuffle

## Files included:

1. README
    - README file written in MarkDown.
2. Makefile
    - Makefile provided by Professor Tantalo on CSE 101 website. Make commands
    are used to compile and create executable files.
3. List.h
    - List ADT header file that contains function prototypes.
4. List.cpp
    - List ADT implementation file writen in C++. Underlying List ADT is a doubly-linked list
    with a vertical cursor.
5. ListTest.cpp
    - Test harness written by me to use for my own tests and debugging.
6. Shuffle.cpp
    - Client-side file that contains main(). Also contains Shuffle() function. Main() allows user to
    run the Shuffle executable and takes in an integer n as a command line argument and calculates number
    of shuffles needed to return to original sequence in deck.


## Design:
Design of the List ADT was fairly straight forward, with lots of similarities to the List ADT that was written
in C. One of the key differences with this ADT compared to the others (besides now using C++) was implementing
a vertical cursor that goes between two nodes, and two dummy nodes that sit at both ends of the list. The most
difficult part of this assignment was the cleanup() function in List.cpp. After getting some help from a tutor,
specifically Vincent, I was able to implement cleanup in an efficient and clear to follow way. The design for
cleanup() is as follows:
    1. Iterate through list L, searching for repeats.
    2. If no repeat found, add it to another list, M
    3. Continue with iterating through List until repeat found.
    4. When repeat is foudn, delete it from the list.
    5. Continue till end/back of list is reached.
