
// LinkedList Based Queues Library/ToolKit (Header)
// - - - - - - - - - - - - - - - - - - - - - - - -


// ===================================================================================================
//                                         DECLARATIONS
// ===================================================================================================


// Datatype carried by nodes (int)
#define VALUE int


// Queue Node Datatype Structure
typedef struct node_t {
    VALUE item;
    struct node_t *prev;
    struct node_t *next;
} node;


// Prototypes:
// node *createQ(VALUE item);                       //  <--- createQ(); creates a queue and returns a pointer to its head.
// node *enQ(VALUE item, node *qTail);              //  <--- enQ(); adds an element to the queue & returns a pointer to the new tail.
// VALUE deQ(node **qHead);                         //  <--- deQ(); grabs/removes the oldest element of the queue & returns it.
// void printQ(node *qHead);                        //  <--- printQ(); prints/displays queue in its current state.
// int freeQ(node *qHead);                          //  <--- freeQ(); frees up all allocated memory (i.e deletes the queue).


// Note:
/*Declare queue(s) in main, or in global scope & create them in main*/




// ===================================================================================================
//                                           FUNCTIONS
// ===================================================================================================


// Create a Stack; Return a Pointer to it - - - - - - - - - - - - - - - - - - - -

node *createQ(VALUE item) {

    // Allocate Space for Node
    node *genesis_Node = malloc(sizeof(node));
    if (!genesis_Node) {

        fprintf(stderr, "\nFailed to create queue. --> Could not create genesis node. Out of Memory.\n");
        return NULL;
    }

    // Initialize the Node
    genesis_Node->item = item;
    genesis_Node->next = NULL;
    genesis_Node->prev = NULL;

    // Successful Creation
    return genesis_Node;
}



// Enqueues an Item - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

node *enQ(VALUE item, node *qTail) {

    // Allocate Space for Node
    node *new_Tail = malloc(sizeof(node));
    if (!new_Tail || !qTail) {

        if (!qTail) fprintf(stderr, "\nEnqueueing Failed. --> Tail node points to NULL.\n");
        if (!new_Tail) fprintf(stderr, "\nEnqueueing Failed. --> Could not create node. Out of Memory.\n");
        return qTail;
    }

    // Initialize Node
    new_Tail->item = item;
    new_Tail->prev = qTail;
    new_Tail->next = NULL;

    // Updating Former Head Node
    qTail->next = new_Tail;

    // Successful EnQ
    return new_Tail;
}



// Dequeues First Element of Queue - - - - - - - - - - - - - - - - - - - - - - - - -

VALUE deQ(node **qHead) {

    node *deleteNode = *qHead;
    if (!*qHead || !deleteNode) {

        if (!*qHead) fprintf(stderr, "\nDequeueing Failed. --> Head node points to NULL.\n");
        if (!deleteNode) fprintf(stderr, "\nDequeueing Failed. --> Could not create node. Out of Memory.\n");
        return -1;
    }

    // Updating to New Head
    *qHead = (*qHead)->next;
    (*qHead)->prev = NULL;

    // Hold on to value that was deQ'd
    VALUE deQd_item = deleteNode->item;

    // Delete Node
    free(deleteNode);

    // Sucessful DeQ
    return deQd_item;
}



// Prints/Displays Queue  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void printQ(node *qHead) {

    printf("\n\nQueue:\n\n---> ");
    for (node *probe = qHead; probe; probe = probe->next) {

        printf("%d, ", probe->item);
    }
    printf("\n\n");

    return;
}



// Frees/Destroys/Deletes - - - - - - - - - - - - - - - - - - - - - - - - - -

int freeQ(node *qHead) {

    if (qHead->next == NULL) free(qHead);

    else { freeQ(qHead->next); free(qHead); }

    // Successful
    return 0;
}
