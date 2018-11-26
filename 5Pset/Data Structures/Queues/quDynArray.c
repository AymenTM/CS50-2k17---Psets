
// Program: Creates queue (implemented as a dynamic array) and tests the quDynArray_lib.h functions.


#include <stdio.h>
#include <stdlib.h>

#include "quDynArray_lib.h"
queue *q;

int main(void) {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Creating Queue
    q = createQ(10);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // TEST #1: Enqueue & Dequeue a Series of Values    [√ Passed]

    enQ(1, q);
    enQ(2, q);
    enQ(3, q);
    enQ(4, q);
    enQ(5, q);
    enQ(6, q);
    enQ(7, q);
    enQ(8, q);
    enQ(9, q);
    enQ(10, q);

    printf("\n\nDeleted: %i\n", deQ(q));
    enQ(11, q);

    printf("Deleted: %i\n", deQ(q));
    printf("Deleted: %i\n", deQ(q));
    printf("Deleted: %i\n\n\n", deQ(q));
    enQ(12, q);
    enQ(13, q);
    enQ(14, q);
    enQ(15, q);
    

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
    
    // TEST #2: Free Queue Successfully (i.e without any leaks)           [√] Passed

    printQ(q);
    freeQ(&q);


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    return 0;
}
