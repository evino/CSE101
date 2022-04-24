# PA3: Graphs and DFS

## Files included:
    1. Makefile
        - Builds and compiles source files
    2. List.h
        - List ADT header
    3. List.c
        - List ADT implementation
    4. Graph.h
        - Graph ADT header
    5. Graph.c
        - Graph ADT implementation
    6. GraphTest.c
        - Graph test file written by me, built off GraphClient.c
    7. FindComponents.c
        - File that contains main function, where its supposed to find SCC

## Design Choices:
    For my stack in DFS(), I chose to may a copy of my list s, and clear it
    to store my stack contents inside of the new list

## Notes:
    I spent hours trying to debug my discover and finish times, and could not solve the issue in time.
    Passes some tests, but fails some specific cases.

