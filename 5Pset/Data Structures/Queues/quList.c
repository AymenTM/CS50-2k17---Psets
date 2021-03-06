
// Program: Creates queue (implemented as a linked list) and tests the quList_lib.h functions.


#include <stdio.h>
#include <stdlib.h>

#include "quList_lib.h"
qNode *qHead_A = NULL;
qNode *qTail_A = NULL;

int main(void) {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Creating Queue
    qTail_A = qHead_A = enQ(0, qTail_A);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #1: Enqueue a bunch of Values                               [√] Passed

    qTail_A = enQ( 1, qTail_A);
    qTail_A = enQ( 2, qTail_A);
    qTail_A = enQ( 3, qTail_A);
    qTail_A = enQ( 4, qTail_A);
    qTail_A = enQ( 5, qTail_A);
    qTail_A = enQ( 6, qTail_A);
    qTail_A = enQ( 7, qTail_A);
    qTail_A = enQ( 8, qTail_A);
    qTail_A = enQ( 9, qTail_A);
    qTail_A = enQ(10, qTail_A);
    qTail_A = enQ(11, qTail_A);
    qTail_A = enQ(12, qTail_A);
    qTail_A = enQ(13, qTail_A);
    qTail_A = enQ(14, qTail_A);
    qTail_A = enQ(15, qTail_A);
    qTail_A = enQ(16, qTail_A);
    qTail_A = enQ(17, qTail_A);
    qTail_A = enQ(18, qTail_A);
    qTail_A = enQ(19, qTail_A);
    qTail_A = enQ(20, qTail_A);

    printQ(qHead_A);



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #2: Dequeue a bunch of Values                               [√] Passed

    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));
    printf("DeQ: %i\n", deQ(&qHead_A));

    printf("DeQ: %i\n", deQ(&qHead_A));  // last element of the queue

    printQ(qHead_A);



// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #3: Free Queue Successfully (i.e without any leaks)         [√] Passed


        freeQ(qHead_A);

    // ==40924== HEAP SUMMARY:
    // ==40924==     in use at exit: 0 bytes in 0 blocks
    // ==40924==   total heap usage: 21 allocs, 21 frees, 504 bytes allocated
    // ==40924==
    // ==40924== All heap blocks were freed -- no leaks are possible

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    return 0;
}
