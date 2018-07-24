
// Program: Creates a stack (implemented w/ linked lists) and tests the stckList_lib.h library.


#include <stdio.h>
#include <stdlib.h>

#include "stckList_lib.h"

// Declaring Stack
node *stack0;


int main(void) {

    stack0 = malloc(sizeof(node));
    if (!stack0) {

        fprintf(stderr, "\nCould not create stack. Out of Memory.\n");
        return 0;
    }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Creating Stack
    stack0 = create(1);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // Print the empty Stack
    printf("\n\n\n\nTEST #1: Print New Created (empty) Stack");
    printStack(stack0);

    // Push a few numbers
    printf("\n\n\n\nTEST #2: Pushing Values to Stack\n\n");
    printf("Pushing: 1, 11, 101, 1001");
    stack0 = push(1, stack0);
    stack0 = push(11, stack0);
    stack0 = push(101, stack0);
    stack0 = push(1001, stack0);
    printStack(stack0);

    // Pop a few numbers
    printf("\n\n\n\nTEST #3: Poping Values from Stack\n\n");
    printf("Poping 2 Values\n\n");
    printf("Pop #1: %i\n", pop(&stack0)); // 1001
    printf("Pop #2: %i\n", pop(&stack0)); // 101
    printStack(stack0);

    // Push and Pop that same value
    printf("\n\n\n\nTEST #4: Push & Pop Values\n\n");
    printf("Pushing & Poping: 2018, 3999\n\n");
    stack0 = push(2018, stack0);
    printStack(stack0);
    printf("Pop value: %i\n", pop(&stack0)); // 2018
    printStack(stack0);
    stack0 = push(3999, stack0);
    printStack(stack0);
    printf("Pop value: %i\n", pop(&stack0)); // 3999
    printStack(stack0);


    // Delete/Destroy the stack
    printf("\n\n\n\nTEST #5: Destroy the stack\n\n");
    destroy(stack0);
    printStack(stack0);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // Success
    return 0;
}
