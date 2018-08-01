
                             //  - - - - - - - - - - - - - - - - - - - - - - - //
                             //     Singly-Linked List (SL) ToolKit (Header)   //
                             //  - - - - - - - - - - - - - - - - - - - - - - - //


// =================================================================================================== //
//                                            DECLARATIONS                                             //
// =================================================================================================== //


// Datatype carried by Node(s)
#define VALUE int


// Datatype Structure carried by List(s)
typedef struct _SL {
    VALUE item;
    struct _SL *next;
} node_SL;


// Global Variables
node_SL *probe;

// node_SL *listN;
// .
// .
// .




// =================================================================================================== //
//                                             PROTOTYPES                                              //
// =================================================================================================== //


// BASIC OPERATIONS
// node_SL *search_SL(VALUE item, node_SL *listHead);         //  <---        search_SL();   Linearly searches listHead for a value and returns a pointer to it.
// int insert_SL(VALUE item, node_SL **listHead);             //  <---        insert_SL();   Inserts given value, makes it head of the listHead and returns a pointer to it.
// int delete_SL(VALUE item, node_SL **listHead);             //  <---        delete_SL();   Deletes node containing given value.

// OTHER
// int create_SL(VALUE item, **listHead);                     //  <---        create_SL();   Creates head node_SL of a singly-linked listHead, returns a pointer to it.
// int insertOnce_SL(VALUE item, node_SL **listHead);         //  <---    insertOnce_SL();   Same as insert() just checks for there are no duplicates before.
// int free_SL(node_SL *listHead);                            //  <---          free_SL();   Destroys/deletes/frees the entire listHead.
// void print_SL(node_SL *listHead);                          //  <---         print_SL();   Prints singly-listHead.




// =================================================================================================== //
//                                             FUNCTIONS                                               //
// =================================================================================================== //


// =========================================== SEARCH ================================================ //

// Linear Search (Sgly/Dbly) Linked List for an Item; Boolean Return & Probe Points to Item ≈ ≈
node_SL *search_SL(VALUE item, node_SL *listHead) {

    if (!listHead) {

        fprintf(stderr, "\nSearch Failed. --> Head points to NULL.\n");
        return NULL;
    }

    // Place Probe at the Beginning of the List
    probe = listHead;

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


// insertOnce_SL(); UTILITY
node_SL *search2_SL(VALUE item, node_SL *listHead) {
    if (!listHead) { fprintf(stderr, "\nSearch Failed. --> Head points to NULL.\n"); return NULL;}
    probe = listHead;
    while (probe) { if (probe->item == item) return probe; else probe = probe->next; }
    return NULL;
}

// =========================================== INSERT ================================================ //

// Creates a Singly-Linked List & Returns a Pointer to it
int create_SL(VALUE item, node_SL **listHead) {

    // Allocate Space for New Node
    node_SL *genesis_Node = malloc(sizeof(node_SL));
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
int insert_SL(VALUE item, node_SL **listHead) {

    // If Head List points to nothing then create new node
    if (!(*listHead)) {
        if (create_SL(item, &(*listHead)) == 0) return 0;
        else return 1;
    }

    // Allocate Space for Node that is to be inserted
    node_SL *new_Node = malloc(sizeof(node_SL));
    if (!new_Node) {

        fprintf(stderr, "\nInsertion Failed. --> Could not create new node. Out of Memory.\n");
        return 1;
    }

    // Initialize the Node and make it Point to the CURRENT head of the listHead, making the head of the listHead now 2nd in the listHead and the newly inserted node_SL the head of the listHead
    new_Node->item = item;
    new_Node->next = (*listHead);

    // Update List head
    (*listHead) = new_Node;

    // Insertion Successful
    return 0;
}


// Inserts ONLY if No Item duplicate(s) exist(s)
int insertOnce_SL(VALUE item, node_SL **listHead) {

    // If Head List points to nothing then create new node
    if (!(*listHead)) {
        if (create_SL(item, &(*listHead)) == 0) return 0;
        else return 1;
    }

    if (search2_SL(item, *listHead) == NULL) {

        // Allocate Space for Node that is to be inserted
        node_SL *new_Node = malloc(sizeof(node_SL));
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
int delete_SL(VALUE item, node_SL **listHead) {

    // Error Checking
    if (!(*listHead)) {
        fprintf(stderr, "\nDeletion Failed. --> Head points to NULL.\n");
        return 1;
    }

    node_SL *deleteNode = NULL;

    // Case 1: If node is first node of the list
    if ((*listHead)->item == item) {

        // Point deleteNode to the node we want to delete
        deleteNode = (*listHead);

        // Update List head to point to next node
        (*listHead) = (*listHead)->next;

        // Free/Delete DeleteNode
        free(deleteNode);
    }

    else {

        probe = (*listHead);
        while (probe) {

            // Find the node previous to the node we want to delete
            if (probe->next->item == item) {

                // Case 2: If node is NOT first or last node of the list
                // Case 3: If node is last node of the list
                if (!(probe->next->next)) {

                    // Point deleteNode to the node we want to delete
                    deleteNode = probe->next;

                    // Update Node previous to deleteNode to point to node after next
                    probe->next = deleteNode->next;

                    // Free/Delete DeleteNode
                    free(deleteNode);
                }
            }

            // Else Check next Item in the List
            else probe = probe->next;
        }
    }

    return 0;
}




// ============================================= FREE ================================================ //

// Frees the entire (Sgly/Dbly) Linked List
int free_SL(node_SL *listHead) {

    if (listHead->next == NULL) free(listHead);

    else { free_SL(listHead->next); free(listHead); }

    return 0;
}




// ============================================ PRINT =============================================== //

// Prints a given (Sgly/Dbly) Linked List
void print_SL(node_SL *listHead) {

    if (!listHead) {
        fprintf(stderr, "\nPrinting Failed. --> Head node_SL points to NULL.\n");
        return;
    }

    // Iterates through listHead and prints each element
    for (probe = listHead; probe != NULL; probe = probe->next) printf("%d, ", probe->item);

    return;
}
