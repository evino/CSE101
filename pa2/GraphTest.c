// Evin Odisho
// edodisho
// pa2
// GraphTest.c
//
//

// GraphTest built on top of GraphClient

#include<stdio.h>
#include<stdlib.h>
#include"Graph.h"

int main(int argc, char* argv[]){
   int i, p, s, max, min, d, n=35;
   List  C = newList(); // central vertices 
   List  P = newList(); // peripheral vertices 
   List  E = newList(); // eccentricities 
   List pathList = newList();

   Graph G = NULL;

   // Build graph G 
   G = newGraph(n);
   for(i=1; i<n; i++){
      if( i%7!=0 ) addEdge(G, i, i+1);
      if( i<=28  ) addEdge(G, i, i+7);
   }
   addEdge(G, 9, 31);
   addEdge(G, 17, 13);
   //addEdge(G, 14, 33);
   // OR
   addArc(G, 14, 33);
   addArc(G, 33, 14);
   
   printf("Size of Graph G is %d\n",getSize(G));
   printf("Order of Graph G is %d\n", getOrder(G));
   
   
   // Print adjacency list representation of G
   printGraph(stdout, G);

   // Calculate the eccentricity of each vertex 
   for(s=1; s<=n; s++){
      BFS(G, s);
      max = getDist(G, 1);
      for(i=2; i<=n; i++){
         d = getDist(G, i);
         max = ( max<d ? d : max );
      }
      append(E, max);
   }

   // Determine the Radius and Diameter of G, as well as the Central and 
   // Peripheral vertices.
   append(C, 1);
   append(P, 1);
   min = max = front(E);
   moveFront(E);
   
   
//    //DEBUG:
//    
//    printf("\n");
//    List test1 = newList();
//    List test2 = newList();
//    prepend(test1, 1);
//    prepend(test2, 1);
//    prepend(test1, 2);
//    prepend(test2, 2);
//    printList(stdout, test1);
//        printList(stdout, test2);
//    if (equals(test1, test2)) {
//        printf("Equal for now\n");
//    }
//    deleteBack(test1);
//    if (equals(test1, test2)) {
//         return 1;
//     }
//    deleteBack(test2);
//    printf("List 1: "); printList(stdout, test1);
//    printf("List 2: "); printList(stdout, test2);
//    if (equals(test1, test2) == true) {
//         printf("The lists are equals, as they should be!\n");
//     }


    /*
    List A1 = newList();
    List B1 = newList();
    List C1 = newList();
    prepend(A1, 1);
    prepend(B1, 1);
    prepend(A1, 2);
    prepend(B1, 2);
    deleteBack(A1);
    if (equals(A1, B1))
        printf("A B equal\n");
    deleteBack(B1);
    if (!equals(A1, B1))
        printf("A b not equal\n");
    append(A1, 3);
    append(B1, 3);
    deleteBack(A1);
    deleteBack(B1);
    if (!equals(A1, B1)) 
        printf("Test 3, not equal\n");
    }
*/


   moveNext(E);
   for(i=2; i<=n; i++){
      d = get(E);
      if( d==min ){
         append(C, i);
      }else if( d<min ){
         min = d;
         clear(C);
         append(C, i);
      }
      if( d==max ){
         append(P, i);
      }else if( d>max ){
         max = d;
         clear(P);
         append(P, i);
      }
      moveNext(E);
   }


    Graph A = newGraph(100);
    addEdge(A, 64, 4);
    addEdge(A, 64, 3);
    addEdge(A, 42, 2);
    addEdge(A, 2, 64);
    addEdge(A, 4, 2);
    addEdge(A, 3, 42);
    BFS(A, 3);
    getPath(pathList, A, 64);
    moveBack(pathList);
    if(get(pathList) == -1) {
    	printf("No shortest path exists\n");
    } else {
    	printf("Shortest Path is: "); printList(stdout, pathList);
    }
    if (getSource(A) == -1) {
    	printf("\nMost recent source now is NIL\n");
    } else {
    	printf("\nMost recent source now is: %d\n", getSource(A));
    }
    append(C, 3);
    append(C, 64);
    moveFront(pathList);
    BFS(A, 2);
    getPath(pathList, A, 2);
    append(C, 2);
    moveBack(pathList);
    if(get(pathList) == -1) {
    	printf("No shortest path exists\n");
    } else {
    	printf("Shortest Path is: "); printList(stdout, pathList);
    }
    if (getSource(A) == -1) {
    	printf("\nMost recent source now is NIL\n");
    } else {
    	printf("\nMost recent source now is: %d\n", getSource(A));
    }
    if (getParent(A, 2) == -1) {
    	printf("2's parent is NIL\n");
    } else {
    	printf("2's parent is %d\n", getParent(A, 2));
    }
    
    getPath(pathList, A, 99);
    moveBack(pathList);
    printf("Shortest Path is: "); printList(stdout, pathList);
	if (getSource(A) == -1) {
    	printf("\nMost recent source now is NIL\n");
    } else {
    	printf("\nMost recent source now is: %d\n", getSource(A));
    }
    clear(pathList);
    clear(C);
    append(C, NIL);
    BFS(A, 99);
    
    
    
    

   // Print results 
   printf("\n");
   printf("Radius = %d\n", min);
   printf("Central vert%s: ", length(C)==1?"ex":"ices");
   printList(stdout, C);
   printf("\n");
   printf("Diameter = %d\n", max);
   printf("Peripheral vert%s: ", length(P)==1?"ex":"ices");
   printList(stdout, P);
   printf("\n");

   // Free objects
   freeList(&pathList); 
   freeList(&C);
   freeList(&P);
   freeList(&E);
   freeGraph(&G);
   freeGraph(&A);

   return(0);
}
