
//   Doubly-Linked List ToolKit (Header)
// - - - - - - - - - - - - - - - - - - - - -


// Datatype carried by Node(s)
#define VALUE int


// Datatype Structure carried by List(s)
typedef struct preNode {
    VALUE item;
    struct preNode *prev;
    struct preNode *next;
} node;


// Global Variable(s)
node *probe;

// node *listN;
// .
// .
// .


// // Prototypes
// node *create(VALUE item);
// int insert(VALUE item, node *list);
// int insertOnce(VALUE item, node *list);
// int find(VALUE item, node *list);
// int delete(VALUE item, node *list);
// int destroy(node *list);
// void printList(node *list);



// Creates a Singly-Linked List & Returns a Pointer to it ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈

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
    genesis_Node->prev = NULL;

    // Return a Pointer to the Node/List
    return genesis_Node;
}



// Linear Search (Sgly/Dbly) Linked List for an Item; Boolean Return & Probe Points to Item - - -

node *find(VALUE item, node *list) {

    if (!list) {

        fprintf(stderr, "\nSearch Failed. --> Head node points to NULL.\n");
        return NULL;
    }

    // Place Probe at the Beginning of the List
    probe = list;

    // Till the Probe Reaches the end of the Linked List
    while (probe != NULL) {

        // Check if the Element Matches Key (return true if it does)
        if (probe->item == item) return probe;

        // Else Check next Item in the List
        else probe = probe->next;
    }

    // If Element Does Not Exist
    fprintf(stderr, "\nItem Not Found.\n");
    return NULL;
}


// Used in del(), same as find() except doesn't print to stderr that item wasnt found, cuz del() prints it instead, otherwise it would print the msg twice
node *dfind(VALUE item, node *list) {
    if (!list) { fprintf(stderr, "\nSearch Failed. --> Head node points to NULL.\n"); return NULL; }
    probe = list;
    while (probe != NULL) {
        if (probe->item == item) return probe;
        else probe = probe->next;
    } return NULL;
}



// Inserts a Item in a Doubly-Linked List - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Inserts whether item duplicate(s) exist(s) or not
node *insert(VALUE item, node *list) {

    // Allocate Space for Node
    node *new_Node = malloc(sizeof(node));
    if (!new_Node) {

        fprintf(stderr, "\nInsertion Failed. --> Could not create node. Out of Memory.\n");
        return list;
    }

    if (!list) {

        fprintf(stderr, "\nInsertion Failed. --> Head node points to NULL.\n");
        return list;
    }

    // Initialize Node Accordingly & Update the Former Head Node
    new_Node->prev = list->prev;
    new_Node->item = item;
    new_Node->next = list;

    // Updating Former Head Node
    list->prev = new_Node;

    // Insertion Successful
    return new_Node;
}


// Inserts ONLY if No Item duplicate(s) exist(s) - - - - - - - - - - - - - - - - - - - - - - - - -
node *insertOnce(VALUE item, node *list) {

    if (find(item, list) == 0) {

        // Allocate Space for New Node
        node *new_Node = malloc(sizeof(node));
        if (!new_Node) {

            fprintf(stderr, "\nInsertion Failed. --> Could not create node. Out of Memory.\n");
            return list;
        }

        if (!list) {

            fprintf(stderr, "\nInsertion Failed. --> Head node points to NULL.\n");
            return list;
        }


        // Initialize Node Accordingly & Update the Former Head Node
        new_Node->prev = list->prev;
        new_Node->item = item;
        new_Node->next = list;

        // Updating Former Head Node
        list->prev = new_Node;

        // Insertion Successful
        return new_Node;
    }

    // Insertion unSuccessful
    fprintf(stderr, "\nInsertion Failed. --> Item duplicate(s) exists.\n");
    return list;
}



// Deletes a Specified Item from a Doubly-Linked List - - - - - - - - - - - - - - - - - - - - - -

int del(VALUE item, node *list) {

    if (list == NULL) {

        fprintf(stderr, "\nDeletion Failed. --> Head node points to NULL.\n");
        return 1;
    }

    if (dfind(item, list) == NULL) {

        fprintf(stderr, "\nDeletion Failed. --> Item Not Found.\n");
        return 2;
    }

    node *deleteNode = probe;

    if (deleteNode == NULL) {

        fprintf(stderr, "\nDeletion Failed. --> Could not create deleteNode. Out of Memory.\n");
        return 3;
    }


    // Only Nodes that don't have a next & a prev pointer pointing to NULL
    if (deleteNode->next != NULL && deleteNode->prev != NULL) {

        deleteNode->next->prev = deleteNode->prev;
        deleteNode->prev->next = deleteNode->next;
    }

    // Only if DeleteNode is the Head node of the list (makes the previous pointer of the node after the head node point to NULL, which after deletion will become the head node)
    if (deleteNode == list) {
        list = deleteNode->next; deleteNode->next->prev = deleteNode->prev;
    }

    // Only last Node of the list (makes the before last node next pointer point to NULL, which after deletion will become the last node of the list)
    if (deleteNode->next == NULL) {
        deleteNode->prev->next = deleteNode->next;
    }


    // Delete Node & Return
    free(deleteNode);
    return 0;
}



// Destroys an entire (Sgly/Dbly) Linked List - - - - - - - - - - - - - - - - - - - - - - - - - -

// Recursive Implementation
int destroy(node *list) {

    if (list->next == NULL) free(list);

    else { destroy(list->next); free(list); }

    // Deletion Successful
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

// // Deletion Successful
//     return 0;
// }



// Prints a given (Sgly/Dbly) Linked List  - - - - - - - - - - - - - - - - - - - - - - - - - - -

void printList(node *list) {

    printf("\n\n---> ");
    for (probe = list; probe != NULL; probe = probe->next) {

        printf("%d, ", probe->item);
    }
    printf("\n\n");

    return;
}

//  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
