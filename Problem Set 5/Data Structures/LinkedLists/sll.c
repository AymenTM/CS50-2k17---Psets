
// Program: Creates a singly-linked list and fills it with inputted data.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include "sll_lib.h"
node_SL *list;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int main(void) {

    // Intro
    printf("\nLet's make a singly-linked list.\n\n");
    // usleep(1000000);

    // Prompt for the how many values2BeInserted in the Linked List
    int values2BeInserted;
    puts("How many values do you want in your list: ");
    scanf(" %i", &values2BeInserted); fflush(stdin);
    printf("\nOk. ");
    // usleep(1000000);
    puts("Insert values 1 by 1.");
    // usleep(1000000);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Prompts for a Key (that we will insert in the list)
    VALUE insertValue; printf("\nInsert: ") ;scanf(" %d", &insertValue); fflush(stdin);

    // Creates a Linked List and Associates a POINTER TO THE LIST (i.e a pointer that points to the first node_SL of the linked list (i.e the HEAD) allowing us to eventually traverse and have access to the whole linked list)
    list = create_SL(insertValue);

    // Prompt and Insert the rest of the Values
    for (size_t i = 0; i < values2BeInserted-1; i++) {

        // Prompts for a Key (that we will insert in the list)
        printf("\nInsert: "); scanf(" %i", &insertValue); fflush(stdin);

        // Inserts inputted Value in a the Linked List
        list = insert_SL(insertValue, list);
    }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    printf("\n\nHere is your list: ");
    print_SLDL(list);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // TEST THE LIBRARY FUNCTIONS

    printf("\n\n\n\nTest #1: InsertOnce( ) - - - - - - - - - - - - - - - - - - \n\n");
    printf("Inserting 3, 5, 90\n");
    list = insertOnce_SL(3, list); // should give us an error message
    list = insertOnce_SL(5, list); // should give us an error message
    list = insertOnce_SL(90, list); // should give us an error message

    usleep(1000000);

    printf("\n\n\n\nTest #2: Insert( ) - - - - - - - - - - - - - - - - - - - - - \n\n");
    printf("Inserting 2, 101, 92\n");
    list = insert_SL(2, list); // add a 2
    list = insert_SL(101, list); // add a 101
    list = insert_SL(92, list); // add a 92
    print_SLDL(list);

    usleep(1000000);

    printf("\n\n\n\nTest #3: Find( ) - - - - - - - - - - - - - - - - - - - - - - \n\n");
    printf("\nAddress of 2: %p\n", search_SL(2, list));
    printf("\nAddress of 5: %p\n", search_SL(5, list));
    printf("\nAddress of 10: %p\n", search_SL(10, list));
    printf(" Address of 11: %p\n", search_SL(11, list)); // should give error message
    printf("\nAddress of 5 Again: %p", search_SL(5, list));

    usleep(1000000);

    printf("\n\n\n\nTest #4: Free List - - - - - - - - - - - - - - - - - - - - - \n\n");
    printf("%i\n", free_SLDL(list));

    usleep(3000000);

    printf("\n\nTests complete.\n\n");

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Success
    return 0;
}
