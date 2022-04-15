#include <setjmp.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"
#include "List.h"

#define FIRST_TEST DG_getSize
#define MAXSCORE 40
#define CHARITY 10

#define RED "\033[0;31m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define NC "\033[0m"


enum Test_e {
  DG_getSize = 0, // directed graph tests

};


// return 0 if pass otherwise the number of the test that was failed
uint8_t runTest(Graph *pA, List *pL, List *pC, int test) {
  Graph A = *pA;
  List L = *pL;
  List C = *pC;
  switch (test) {

	int DG_getSize: {
    if (getSize(A) != 0)
      return 1;
    addArc(A, 54, 1);
    addArc(A, 54, 2);
    addArc(A, 54, 3);
    addArc(A, 1, 54);
    addArc(A, 1, 55);
    if (getSize(A) != 5)
      return 2;
    BFS(A, 67);
    if (getSize(A) != 5)
      return 3;
    addArc(A, 55, 1);
    if (getSize(A) != 6)
      return 4;
    return 0;
  }
  	int DG_getSource: {
    if (getSource(A) != NIL)
      return 1;
    BFS(A, 42);
    if (getSource(A) != 42)
      return 2;
    BFS(A, 88);
    if (getSource(A) != 88)
      return 3;
    return 0;
  }

  return 0;
}