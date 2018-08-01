
// Program: Creates a singly-linked list and fills it with inputted data.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include "sll_lib.h"
SLL_node *list;

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
    insert_SLL(insertValue, &list);

    // Prompt and Insert the rest of the Values
    for (size_t i = 0; i < values2BeInserted-1; i++) {

        // Prompts for a Key (that we will insert in the list)
        printf("\nInsert: "); scanf(" %i", &insertValue); fflush(stdin);

        // Inserts inputted Value in a the Linked List
        insert_SLL(insertValue, &list);
    }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    printf("\n\nList:\n--> ");
    print_SLL(list);

// // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // TEST THE LIBRARY FUNCTIONS

    printf("\n\n\n\nTest #1: InsertOnce( ) - - - - - - - - - - - - - - - - - - \n\n");
    printf("Inserting 3, 5, 90\n");
    insertOnce_SLL(3, &list); // should give us an error message
    insertOnce_SLL(5, &list); // should give us an error message
    insertOnce_SLL(90, &list); // should give us an error message

    usleep(1000000);

    printf("\n\n\n\nTest #2: Insert( ) - - - - - - - - - - - - - - - - - - - - - \n\n");
    printf("Inserting 2, 101, 92\n");
    insert_SLL(2, &list); // add a 2
    insert_SLL(101, &list); // add a 101
    insert_SLL(92, &list); // add a 92
    print_SLL(list);

    usleep(1000000);

    printf("\n\n\n\nTest #3: Find( ) - - - - - - - - - - - - - - - - - - - - - - \n\n");
    printf("\nAddress of 2: %p\n", search_SLL(2, list));
    printf("\nAddress of 5: %p\n", search_SLL(5, list));
    printf("\nAddress of 10: %p\n", search_SLL(10, list));
    printf(" Address of 11: %p\n", search_SLL(11, list)); // should give error message
    printf("\nAddress of 5 Again: %p", search_SLL(5, list));

    usleep(1000000);

    // printf("\n\n\n\nTest #4: Free List - - - - - - - - - - - - - - - - - - - - - \n\n");
    // printf("%i\n", free_SLL(list));
    //
    // usleep(3000000);
    //
    // printf("\n\nTests complete.\n\n");

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    printf("\n\n");

    printf("%i\n", delete_SLL(1, &list));
    printf("%i\n", delete_SLL(3, &list));
    printf("%i\n", delete_SLL(5, &list));
    printf("%i\n", delete_SLL(7, &list));
    printf("%i\n", delete_SLL(9, &list));
    printf("%i\n", delete_SLL(10, &list));
    printf("%i\n", delete_SLL(8, &list));
    printf("%i\n", delete_SLL(6, &list));
    printf("%i\n", delete_SLL(4, &list));
    printf("%i\n", delete_SLL(2, &list));

    // printf("\nAfter Deletion:\n--> ");
    printf("\n");
    print_SLL(list);
    printf("\n\n");
    printf("%i\n", free_SLL(list));

    // Success
    return 0;
}
