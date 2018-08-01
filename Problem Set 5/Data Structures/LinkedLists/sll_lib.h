
                             //  - - - - - - - - - - - - - - - - - - - - - - - //
                             //     Singly-Linked List (SLL) ToolKit (Header)   //
                             //  - - - - - - - - - - - - - - - - - - - - - - - //


// =================================================================================================== //
//                                            DECLARATIONS                                             //
// =================================================================================================== //

// Datatype carried by Node(s)
#define VALUE int


// Datatype Structure carried by List(s)
typedef struct _SLL_node {
    VALUE item;
    struct _SLL_node *next;
} SLL_node;



// =================================================================================================== //
//                                             PROTOTYPES                                              //
// =================================================================================================== //


// BASIC OPERATIONS
// SLL_node *search_SLL(VALUE item, SLL_node *listHead);         //  <---        search_SLL();   Linearly searches listHead for a value and returns a pointer to it.
// int insert_SLL(VALUE item, SLL_node **listHead);             //  <---        insert_SLL();   Inserts given value, makes it head of the listHead and returns a pointer to it.
// int delete_SLL(VALUE item, SLL_node **listHead);             //  <---        delete_SLL();   Deletes node containing given value.

// OTHER
// int create_SLL(VALUE item, **listHead);                     //  <---        create_SLL();   Creates head SLL_node of a singly-linked listHead, returns a pointer to it.
// int insertOnce_SLL(VALUE item, SLL_node **listHead);         //  <---    insertOnce_SLL();   Same as insert() just checks for there are no duplicates before.
// int free_SLL(SLL_node *listHead);                            //  <---          free_SLL();   Destroys/deletes/frees the entire listHead.
// void print_SLL(SLL_node *listHead);                          //  <---         print_SLL();   Prints singly-listHead.




// =================================================================================================== //
//                                             FUNCTIONS                                               //
// =================================================================================================== //


// =========================================== SEARCH ================================================ //

// Linear Search (Sgly/Dbly) Linked List for an Item; Boolean Return & Probe Points to Item ≈ ≈
SLL_node *search_SLL(VALUE item, SLL_node *listHead) {

    if (!listHead) {

        fprintf(stderr, "\nSearch Failed. --> Head points to NULL.\n");
        return NULL;
    }

    // Place Probe at the Beginning of the List
    SLL_node *probe = listHead;

    // Till the Probe Reaches the end of the Linked List
    while (probe) {

        // Check if the Element Matches Key (return true if it does)
        if (probe->item == item) return probe;

        // Else Check next Item in the List
        else probe = probe->next;
    }

    // If Element Does Not Exist
    fprintf(stderr, "\nNot Found.\n"); return NULL;
}


// insertOnce_SLL(); UTILITY
SLL_node *search2_SLL(VALUE item, SLL_node *listHead) {
    if (!listHead) { fprintf(stderr, "\nSearch Failed. --> Head points to NULL.\n"); return NULL;}
    SLL_node *probe = listHead;
    while (probe) { if (probe->item == item) return probe; else probe = probe->next; }
    return NULL;
}

// =========================================== INSERT ================================================ //

// Creates a Singly-Linked List & Returns a Pointer to it
int create_SLL(VALUE item, SLL_node **listHead) {

    // Allocate Space for New Node
    SLL_node *genesis_Node = malloc(sizeof(SLL_node));
    if (!genesis_Node) {

        fprintf(stderr, "\nCreation of Singly-Linked List Failed. --> Could not create genesis node. Out of Memory.\n");
        return 1;
    }

    // Initialize the Node
    genesis_Node->item = item;
    genesis_Node->next = NULL;

    // Update List head
    (*listHead) = genesis_Node;

    // Creation Successful
    return 0;
}


// Inserts a Item in a Singly-Linked List
int insert_SLL(VALUE item, SLL_node **listHead) {

    // If Head List points to nothing then create new node
    if (!(*listHead)) {
        if (create_SLL(item, &(*listHead)) == 0) return 0;
        else return 1;
    }

    // Allocate Space for Node that is to be inserted
    SLL_node *new_Node = malloc(sizeof(SLL_node));
    if (!new_Node) {

        fprintf(stderr, "\nInsertion Failed. --> Could not create new node. Out of Memory.\n");
        return 1;
    }

    // Initialize the Node and make it Point to the CURRENT head of the listHead, making the head of the listHead now 2nd in the listHead and the newly inserted SLL_node the head of the listHead
    new_Node->item = item;
    new_Node->next = (*listHead);

    // Update List head
    (*listHead) = new_Node;

    // Insertion Successful
    return 0;
}


// Inserts ONLY if No Item duplicate(s) exist(s)
int insertOnce_SLL(VALUE item, SLL_node **listHead) {

    // If Head List points to nothing then create new node
    if (!(*listHead)) {
        if (create_SLL(item, &(*listHead)) == 0) return 0;
        else return 1;
    }

    if (search2_SLL(item, *listHead) == NULL) {

        // Allocate Space for Node that is to be inserted
        SLL_node *new_Node = malloc(sizeof(SLL_node));
        if (!new_Node) {

            fprintf(stderr, "\nInsertion Failed. --> Could not create node. Out of Memory.\n");
            return 1;
        }

        new_Node->item = item;
        new_Node->next = (*listHead);

        // Update List head
        (*listHead) = new_Node;

        // Insertion Successful
        return 0;
    }

    // Insertion unSuccessful
    fprintf(stderr, "\nItem duplicate(s) exists.\n");
    return 1;
}


// ============================================= DELETE ============================================== //

// Deletes a given node from the SL
int delete_SLL(VALUE item, SLL_node **listHead) {

    // Error Checking
    if (!(*listHead)) {
        fprintf(stderr, "\nDeletion Failed. --> Head points to NULL.\n");
        return 1;
    }

    SLL_node *deleteNode = NULL;

    // Case 1: If node is first node of the list
    if ((*listHead)->item == item) {

        // Point deleteNode to the node we want to delete
        deleteNode = (*listHead);

        // Update List head to point to next node
        (*listHead) = (*listHead)->next;

        // Free/Delete DeleteNode
        free(deleteNode);
    }

    // Case 2: If node is NOT first or last node of the list
    // Case 3: If node is last node of the list
    else {

        SLL_node *probe = (*listHead);

         while (probe->next) {

            // Find the node previous to the node we want to delete
            if (probe->next->item == item) {

                // Point deleteNode to the node we want to delete
                deleteNode = probe->next;

                // Update Node previous to deleteNode to point to node after next
                probe->next = probe->next->next;

                // Free/Delete DeleteNode
                free(deleteNode);

            }

            // Else Check next Node in the List
            else probe = probe->next;
        }
    }

    return 0;
}




// ============================================= FREE ================================================ //

// Frees the entire (Sgly/Dbly) Linked List
int free_SLL(SLL_node *listHead) {

    if (!listHead) return 0;

    if (listHead->next == NULL) free(listHead);

    else { free_SLL(listHead->next); free(listHead); }

    return 0;
}




// ============================================ PRINT =============================================== //

// Prints a given (Sgly/Dbly) Linked List
void print_SLL(SLL_node *listHead) {

    if (!listHead) {
        fprintf(stderr, "\nPrinting Failed. --> Head node points to NULL.\n");
        return;
    }

    // Iterates through listHead and prints each element
    for (SLL_node *probe = listHead; probe != NULL; probe = probe->next) printf("%d, ", probe->item);

    return;
}
