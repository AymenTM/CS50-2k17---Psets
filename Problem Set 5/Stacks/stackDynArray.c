
// Program: Creates a stack (implemented w/ dynamic arrays) and tests the stckArray_lib.h library.

#include <stdio.h>
#include <stdlib.h>

#include "stckArray_lib.h"


#define CAPACITY 40


int main(void) {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Declaring/Creating Stack & Fixing Top Element
    stack s; s.top = 0; s.array = malloc(sizeof(CAPACITY));

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // Print the empty Stack
    printf("\n\n\n\nTEST #1: Print New Created (empty) Stack");
    printStack(&s);

    // Push a few numbers
    printf("\n\n\n\nTEST #2: Pushing Values to Stack\n\n");
    printf("Pushing: 1, 11, 101, 1001");
    push(1, &s);
    push(11, &s);
    push(101, &s);
    push(1001, &s);
    printStack(&s);

    // Pop a few numbers
    printf("\n\n\n\nTEST #3: Poping Values from Stack\n\n");
    printf("Poping 2 Values\n\n");
    printf("Pop #1: %i\n", pop(&s)); // 1001
    printf("Pop #2: %i\n", pop(&s)); // 101
    printStack(&s);

    // Push and Pop that same value
    printf("\n\n\n\nTEST #4: Push & Pop Values\n\n");
    printf("Pushing & Poping: 2018, 3999\n\n");
    push(2018, &s);
    printStack(&s);
    printf("Pop value: %i\n", pop(&s)); // 2018
    printStack(&s);
    push(3999, &s);
    printStack(&s);
    printf("Pop value: %i\n", pop(&s)); // 3999
    printStack(&s);

    // Free/Delete/Destroy Stack Array
    printf("\n\n\n\nTEST #5: Destroy/Delete Stack Array\n\n");
    free(s.array);
    printStack(&s);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    return 0;
}
