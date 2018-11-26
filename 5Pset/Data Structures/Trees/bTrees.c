
// Program: Creates a Binary Search Tree (BST) & tests tree_lib.h functions with it.


#include <stdio.h>
#include <stdlib.h>

// - - - - - - - - - - - - - //
    #include "tree_lib.h"
// - - - - - - - - - - - - - //


int main(void) {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Create a BST Node Pointer
    bTreeNode *bstRoot_A = NULL;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #1: Insert a bunch of Elements in BST + Print Tree Inorder  [√] Passed

    bstRoot_A = insertBST( 5,  bstRoot_A);
                insertBST(15,  bstRoot_A);
                insertBST( 2,  bstRoot_A);
                insertBST( 8,  bstRoot_A);
                insertBST( 1,  bstRoot_A);
                insertBST( 3,  bstRoot_A);
                insertBST( 7,  bstRoot_A);
                insertBST( 9,  bstRoot_A);
                insertBST( 6,  bstRoot_A);
                insertBST(12,  bstRoot_A);
                insertBST(18,  bstRoot_A);
                insertBST(11,  bstRoot_A);
                insertBST(13,  bstRoot_A);
                insertBST(17,  bstRoot_A);
                insertBST(19,  bstRoot_A);
                insertBST(16,  bstRoot_A);
                insertBST(20,  bstRoot_A);

    // // Print 0 if insert operation was Successful
    // printf("\n%i\n", insertBoolBST(19,  bstRoot_A));
    // printf("\n%i\n\n", insertBoolBST(10,  bstRoot_A));

    // printBTREE(bstRoot_A);
    printf("\n");


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #2: Search Elements in BST                                  [√] Passed

    // Found
    (_searchBST(20, bstRoot_A) == 0)    ?   printf("\nFound.\n") : printf("\nNot Found.\n");
    (_searchBST( 1, bstRoot_A) == 0)    ?   printf("\nFound.\n") : printf("\nNot Found.\n");
    (_searchBST(13, bstRoot_A) == 0)    ?   printf("\nFound.\n") : printf("\nNot Found.\n");
    (_searchBST(15, bstRoot_A) == 0)    ?   printf("\nFound.\n") : printf("\nNot Found.\n");
    (_searchBST(16, bstRoot_A) == 0)    ?   printf("\nFound.\n") : printf("\nNot Found.\n");
    (_searchBST( 6, bstRoot_A) == 0)    ?   printf("\nFound.\n") : printf("\nNot Found.\n");

    // Not found
    (_searchBST( 4, bstRoot_A) == 0)    ?   printf("\nFound.\n") : printf("\nNot Found.\n");
    (_searchBST(29, bstRoot_A) == 0)    ?   printf("\nFound.\n") : printf("\nNot Found.\n");
    (_searchBST(87, bstRoot_A) == 0)    ?   printf("\nFound.\n") : printf("\nNot Found.\n");


    // Address Followed by Dereferenced Value of Pointer
    printf("\nAddress of '20': %p & Dereferenced:", searchBST(20, bstRoot_A));
    printf(" %i\n", (searchBST(20, bstRoot_A)->item));

    printf("\nAddress of '17': %p & Dereferenced:", searchBST(17, bstRoot_A));
    printf(" %i\n", (searchBST(17, bstRoot_A)->item));

    printf("\nAddress of '12': %p & Dereferenced:", searchBST(12, bstRoot_A));
    printf(" %i\n", (searchBST(12, bstRoot_A)->item));


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    /* TEST #3: Find Max/Min Values & Most Outer Right/Left Nodes       [√] Passed
    of Btree */

    // Find Min & Max Values of a Tree
    printf("\n\nMax Value = %i", findMaxBTREE(bstRoot_A)->item);
    printf("\nMin Value = %i\n", findMinBTREE(bstRoot_A)->item);

    // Find & Return Most Outer Right/Left Node (and we ask to print the nodes value)
    printf("\nMost Outer Right Node Value = %i\n", (findOuterRightBTREE(bstRoot_A))->item);
    printf("Most Outer Left Node Value = %i\n\n", (findOuterLeftBTREE(bstRoot_A))->item);


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #5: Check if tree is a Binary Search Tree (BST)             [√] Passed

    if (isBST(bstRoot_A, state) == 0) printf("\nIs a BST.\n\n");


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #6: Delete a bunch of Elements from BST                     [√] Passed
    //
    // printf("\n\n");
    //
    // deleteBST(20, bstRoot_A);
    // deleteBST(13, bstRoot_A);
    // deleteBST(17, bstRoot_A);
    // deleteBST(1, bstRoot_A);
    // deleteBST(8, bstRoot_A);
    // deleteBST(5, bstRoot_A);
    // deleteBST(15, bstRoot_A);
    //
    // printBTREE(bstRoot_A);
    //

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #7: Find Correct Height of a b-Tree                         [√] Passed

    printf("\nHeight of B-Tree: %i.\n\n", findHeightBTREE(bstRoot_A));

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #8: Working Traversals (use alphabetical values in nodes)   [√] Passed

    // In Order
    printf("\nIn Order:\n--> ");
    in_OrderTravBTREE(bstRoot_A);
    printf("\n\n");

    // Pre Order
    printf("\nPre-Order:\n--> ");
    pre_OrderTravBTREE(bstRoot_A);
    printf("\n\n");

    // Post Order
    printf("\nPost-Order:\n--> ");
    post_OrderTravBTREE(bstRoot_A);
    printf("\n");

    // Level Order Traversal Below

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    // TEST #9: Free B-Tree Successfully (i.e without any leaks)        [√] Passed

    // freeBTREE(bstRoot_A);

// HEAP SUMMARY: (valgrind)
// ==15286==     in use at exit: 0 bytes in 0 blocks
// ==15286==   total heap usage: 17 allocs, 17 frees, 408 bytes allocated
// ==15286==
// ==15286== All heap blocks were freed -- no leaks are possible


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    /* TEST #10: Get Level Order Right using a Queue & then Free the    [√] Passed
    whole thing + the tree Successfully (i.e without any leaks) */

    // Level Order
    printf("\nLevel Order:\n--> ");
    level_OrderTravBTREE(bstRoot_A);
    printf("\n");

    if (freeBTREE(bstRoot_A) == 0) printf("\n\nB-tree Successfully Free'd [√]\n\n");

// ==35824== HEAP SUMMARY:
// ==35824==     in use at exit: 0 bytes in 0 blocks
// ==35824==   total heap usage: 35 allocs, 35 frees, 840 bytes allocated
// ==35824==
// ==35824== All heap blocks were freed -- no leaks are possible

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // SCORE: 10/10 [√] Complete Grade !
    return 0;
}
