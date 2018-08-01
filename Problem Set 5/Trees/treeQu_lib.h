              // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
              //  LinkedList Based Queues Library/ToolKit Modified for Trees (Header)  //
              // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //


// =================================================================================================== //
//                                          DECLARATIONS                                               //
// =================================================================================================== //


// Datatype carried by nodes (int)
#define VALU bTreeNode*


// Queue Node Datatype Structure
typedef struct qNode_t {
    VALU item;
    struct qNode_t *prev;
    struct qNode_t *next;
} qNode;




// =================================================================================================== //
//                                           PROTOTYPES                                                //
// =================================================================================================== //

// qNode *createQ(VALU item);                  //  <---  createQ();  creates a queue and returns a pointer to its head.
// qNode *enQ(VALU item, qNode *qTail);        //  <---      enQ();  adds an element to the queue & returns a pointer to the new tail.
// VALU deQ(qNode **qHead);                    //  <---      deQ();  grabs/removes the oldest element of the queue & returns it.
// void printQ(qNode *qHead);                   //  <---   printQ();  prints/displays queue in its current state.
// int freeQ(qNode *qHead);                     //  <---    freeQ();  frees up all allocated memory (i.e deletes the queue).


// Note:
/*Declare queue(s) in main, or in global scope & create them in main*/




// =================================================================================================== //
//                                           FUNCTIONS                                                 //
// =================================================================================================== //


// Create a Queue & Return a Pointer to it - - - - - - - - - - - - - - - - - - - -

qNode *createQ(VALU item) {

    // Allocate Space for Node
    qNode *genesis_Node = malloc(sizeof(qNode));
    if (!genesis_Node) {

        fprintf(stderr, "\nFailed to create queue. --> Could not create genesis qNode. Out of Memory.\n");
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

qNode *enQ(VALU item, qNode *qTail) {

    if (!qTail) return createQ(item);

    // Allocate Space for Node
    qNode *new_Tail = malloc(sizeof(qNode));
    if (!new_Tail || !qTail) {

        if (!qTail) fprintf(stderr, "\nEnqueueing Failed. --> Tail qNode points to NULL.\n");
        if (!new_Tail) fprintf(stderr, "\nEnqueueing Failed. --> Could not create qNode. Out of Memory.\n");
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

VALU deQ(qNode **qHead) {

    qNode *deleteNode = *qHead;
    if (!(*qHead)) {

        if (!*qHead) fprintf(stderr, "\nDequeueing Failed. --> Head qNode points to NULL.\n");
        return NULL;
    }

    // If its the first or last node of the queue, then nullify pointer to queue
    if (!((*qHead)->prev) && !((*qHead)->next)) (*qHead) = NULL;

    // If its any other node
    else {

        if (((*qHead)->next) != NULL) *qHead = (*qHead)->next;
        if (((*qHead)->prev) != NULL) (*qHead)->prev = NULL;
    }

    // Hold on to value that was deQ'd
    VALU deQd_item = deleteNode->item;

    // Delete Node
    free(deleteNode);

    // Sucessful DeQ
    return deQd_item;
}



// Prints/Displays Queue  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void printQ(qNode *qHead) {

    printf("\n");
    for (qNode *probe = qHead; probe; probe = probe->next) {

        // Prints Address of bTreeNode + Value of its Item
        // printf("%p --> %i\n", probe, probe->item->item);

        // Prints Value found in bTreeNode
        printf("%i, ", probe->item->item);
    }
    printf("\n\n");

    return;
}



// Frees/Destroys/Deletes - - - - - - - - - - - - - - - - - - - - - - - - - -

int freeQ(qNode *qHead) {

    if (!qHead) return 0;

    if (qHead->next == NULL) free(qHead);

    else { freeQ(qHead->next); free(qHead); }

    // Successful
    return 0;
}
