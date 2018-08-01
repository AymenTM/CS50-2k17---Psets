
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

// node_SL *create_SL(VALUE item)                         //  <---        create_SL();   Creates head node_SL of a singly-linked list, returns a pointer to it.
// node_SL *insert_SL(VALUE item, node_SL *list);         //  <---        insert_SL();   Inserts given value, makes it head of the list and returns a pointer to it.
// node_SL *insertOnce_SL(VALUE item, node_SL *list);     //  <---    insertOnce_SL();   Same as insert() just checks for there are no duplicates before.
// node_SL *search_SL(VALUE item, node_SL *list);         //  <---        search_SL();   Linearly searches list for a value and returns a pointer to it.
// node_SL *search2_SL(VALUE item, node_SL *list)         //  <---       search2_SL();   Used in insertOnce_SL()
// int free_SLDL(node_SL *list);                          //  <---        free_SLDL();   Destroys/deletes/frees the entire list.
// void print_SL(node_SL *list);                          //  <---         print_SL();   Prints singly-list.




// =================================================================================================== //
//                                             FUNCTIONS                                               //
// =================================================================================================== //


// ============================================ CREATE =============================================== //

// Creates a Singly-Linked List & Returns a Pointer to it
node_SL *create_SL(VALUE item) {

    // Allocate Space for Node
    node_SL *genesis_Node = malloc(sizeof(node_SL));
    if (!genesis_Node) {

        fprintf(stderr, "\nCreation of Singly-Linked List Failed. --> Could not create genesis node_SL. Out of Memory.\n");
        return NULL;
    }

    // Initialize the Node
    genesis_Node->item = item;
    genesis_Node->next = NULL;

    // Return a Pointer to the Node/List
    return genesis_Node;
}




// =========================================== SEARCH ================================================ //

// Linear Search (Sgly/Dbly) Linked List for an Item; Boolean Return & Probe Points to Item ≈ ≈
node_SL *search_SL(VALUE item, node_SL *list) {

    if (!list) {

        fprintf(stderr, "\nSearch Failed. --> Head node_SL points to NULL.\n");
        return NULL;
    }

    // Place Probe at the Beginning of the List
    probe = list;

    // Till the Probe Reaches the end of the Linked List
    while (probe) {

        // Check if the Element Matches Key (return true if it does)
        if (probe->item == item) return probe;

        // Else Check next Item in the List
        else probe = probe->next;
    }

    // If Element Does Not Exist
    fprintf(stderr, "\nItem does not exist.\n"); return NULL;
}


// Used in destroy_SL() & insertOnce_SL() to avoid having msg "item not found" printed twice or even printed at all
node_SL *search2_SL(VALUE item, node_SL *list) {
    if (!list) { fprintf(stderr, "\nSearch Failed. --> Head node_SL points to NULL.\n"); return NULL; }
    probe = list;
    while (probe != NULL) {
        if (probe->item == item) return probe;
        else probe = probe->next;
    } return NULL;
}




// =========================================== INSERT ================================================ //

// Inserts a Item in a Singly-Linked List
node_SL *insert_SL(VALUE item, node_SL *list) {

    // Allocate Space for Node that is to be inserted
    node_SL *new_Node = malloc(sizeof(node_SL));

    // Error Checking
    if (!list || !new_Node) {

        if (!list) fprintf(stderr, "\nInsertion Failed. --> Head node_SL points to NULL.\n");
        if (!new_Node) fprintf(stderr, "\nInsertion Failed. --> Could not create new node_SL. Out of Memory.\n");
        return NULL;
    }


    // Initialize the Node and make it Point to the CURRENT head of the list, making the head of the list now 2nd in the list and the newly inserted node_SL the head of the list
    new_Node->item = item;
    new_Node->next = list;

    // Insertion Successful
    return new_Node;
}


// Inserts ONLY if No Item duplicate(s) exist(s)
node_SL *insertOnce_SL(VALUE item, node_SL *list) {

    if (!list) {

        fprintf(stderr, "\nInsertion Failed. --> Head node_SL points to NULL.\n");
        return NULL;
    }

    if (search2_SL(item, list) == NULL) {

        // Allocate Space for Node that is to be inserted
        node_SL *new_Node = malloc(sizeof(node_SL));
        if (!new_Node) {

            fprintf(stderr, "\nInsertion Failed. --> Could not create node_SL. Out of Memory.\n");
            return NULL;
        }

        // Initialize the Node and make it Point to the CURRENT head of the list, making the head of the list now 2nd in the list and the newly inserted node_SL the head of the list
        new_Node->item = item;
        new_Node->next = list;

        // Insertion Successful
        printf("\nInsertion Successful.\n");
        return new_Node;
    }

    // Insertion unSuccessful
    fprintf(stderr, "\nInsertion Failed. --> Item duplicate(s) exists.\n");
    return list;
}



// ============================================= FREE ================================================ //

// Frees the entire (Sgly/Dbly) Linked List
int free_SLDL(node_SL *lists) {

    if (lists->next == NULL) free(lists);

    else { free_SLDL(lists->next); free(lists); }

    return 0;
}




// ============================================ PRINT =============================================== //

// Prints a given (Sgly/Dbly) Linked List
void print_SLDL(node_SL *list) {

    if (!list) {
        fprintf(stderr, "\nPrinting Failed. --> Head node_SL points to NULL.\n");
        return;
    }

    // Iterates through list and prints each element
    for (probe = list; probe != NULL; probe = probe->next) printf("%d, ", probe->item);

    return;
}
