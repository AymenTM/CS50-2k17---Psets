
//   Singly-Linked List Library/ToolKit (Header) 
// - - - - - - - - - - - - - - - - - - - - -


// Datatype carried by Node(s)
#define VALUE int


// Datatype Structure carried by List(s)
typedef struct preNode {
    VALUE item;
    struct preNode *next;
} node;


// Global Variables
node *probe;

// node *listN;
// .
// .
// .


// // Prototypes
// node *create(VALUE item)
// node *insert(VALUE item, node *list);
// node *insertOnce(VALUE item, node *list);
// node *find(VALUE item, node *list);
// int destroy(node *list);
// void printList(node *list)


// Creates a Singly-Linked List & Returns a Pointer to it - - - - - - - - - - - - - - - - - - - -

node *create(VALUE item) {

    // Allocate Space for Node
    node *genesis_Node = malloc(sizeof(node));
    if (!genesis_Node) {

        fprintf(stderr, "\nCreation of Singly-Linked List Failed. --> Could not create genesis node. Out of Memory.\n");
        return NULL;
    }

    // Initialize the Node
    genesis_Node->item = item;
    genesis_Node->next = NULL;

    // Return a Pointer to the Node/List
    return genesis_Node;
}



// Linear Search (Sgly/Dbly) Linked List for an Item; Boolean Return & Probe Points to Item ≈ ≈

node *find(VALUE item, node *list) {

    if (!list) {

        fprintf(stderr, "\nSearch Failed. --> Head node points to NULL.\n");
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
    fprintf(stderr, "\nItem does not exist."); return NULL;
}



// Inserts a Item in a Singly-Linked List - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Inserts whether item duplicate(s) exist(s) or not
node *insert(VALUE item, node *list) {

    // Allocate Space for Node that is to be inserted
    node *new_Node = malloc(sizeof(node));
    if (!new_Node) {

        fprintf(stderr, "\nInsertion Failed. --> Could not create new node. Out of Memory.\n");
        return NULL;
    }

    if (!list) {

        fprintf(stderr, "\nInsertion Failed. --> Head node points to NULL.\n");
        return NULL;
    }

    // Initialize the Node and make it Point to the CURRENT head of the list, making the head of the list now 2nd in the list and the newly inserted node the head of the list
    new_Node->item = item;
    new_Node->next = list;

    // Insertion Successful
    return new_Node;
}


// Inserts ONLY if No Item duplicate(s) exist(s)
node *insertOnce(VALUE item, node *list) {

    if (!list) {

        fprintf(stderr, "\nInsertion Failed. --> Head node points to NULL.\n");
        return NULL;
    }

    if (find(item, list) == NULL) {

        // Allocate Space for Node that is to be inserted
        node *new_Node = malloc(sizeof(node));
        if (!new_Node) {

            fprintf(stderr, "\nInsertion Failed. --> Could not create node. Out of Memory.\n");
            return NULL;
        }

        // Initialize the Node and make it Point to the CURRENT head of the list, making the head of the list now 2nd in the list and the newly inserted node the head of the list
        new_Node->item = item;
        new_Node->next = list;

        // Insertion Successful
        return new_Node;
    }

    // Insertion unSuccessful
    fprintf(stderr, "\nInsertion Failed. --> Duplicate(s) of %i exist(s).\n", item);
    return list;
}



// Destroys an entire (Sgly/Dbly) Linked List - - - - - - - - - - - - - - - - - - - - - - - - - -

// Recursive Implementation
int destroy(node *list) {

    if (list->next == NULL) free(list);

    else { destroy(list->next); free(list); }

    return 0;
}


// // Iterative Implementation
// int destroy(node *list) {

//     if (!list) {

//         fprintf(stderr, "\nDestruction Failed. --> Head node points to NULL.\n");
//         return 1;
//     }

//     probe = list;

//     while (list != NULL) {

//         probe = list->next;
//         free(list);
//         list = probe;

//     }

//     return 0;
// }



// Prints a given (Sgly/Dbly) Linked List - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void printList(node *list) {

    if (!list) {

        fprintf(stderr, "\nPrinting Failed. --> Head node points to NULL.\n");
        return;
    }

    printf("\n\n---> ");
    for (probe = list; probe != NULL; probe = probe->next) {

        printf("%d, ", probe->item);
    }
    printf("\n\n");

    return;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
