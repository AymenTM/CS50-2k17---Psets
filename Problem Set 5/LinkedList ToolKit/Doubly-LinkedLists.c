
// Doubly-Linked List ToolKit (Library)
- - - - - - - - - - - - - - - - - - - - - 


// Datatype carried by Node(s)
#define VALUE int


// Datatype Structure carried by List(s)
typedef struct preNode {
    VALUE item;
    struct preNode *prev;
    struct preNode *next;
} node;


// Global Variable(s)
node *listN = malloc(sizeof(node));
node *probe = malloc(sizeof(node));


// Prototypes
node *create(VALUE item);
void insert(VALUE item, node *list);
void insertOnce(VALUE item, node *list);
bool find(VALUE item, node *list);
void delete(VALUE item, node *list);
void destroy(node *list);
void printList(node *list);



// Creates a Singly-Linked List & Returns a Pointer to it ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈

node *create(VALUE item) {

    // Allocate Space for Node
    node *genesis_Node = malloc(sizeof(node));
    if (!genesis_Node) {

        fprintf(stderr, "\nCould not create genesis node. Out of Memory.\nCreation of Singly-Linked List Failed.\n");
        return NULL;
    }

    // Initialize the Node
    genesis_Node->item = item;
    genesis_Node->next = NULL;

    // Return a Pointer to the Node/List
    return genesis_Node;
}



// Inserts a Item in a Doubly-Linked List ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈

// Inserts whether item duplicate(s) exist(s) or not
void insert(VALUE item, node *list) {

    // Allocate Space for Node
    node *new_Node = malloc(sizeof(node));
    if (!new_Node) {

        fprintf(stderr, "\nCould not create node. Out of Memory.\nInsertion Failed.\n");
        return NULL;
    }

    if (!list) {

        fprintf(stderr, "\nHead node points to NULL.\nInsertion Failed.\n");
        return;
    }

    // Initialize Node Accordingly & Update the Former Head Node
    new_Node->prev = list->prev;
    new_Node->item = item;
    new_Node->next = list;

    // Updating Former Head Node
    list->prev = new_Node;

    // Updating Head Pointer
    list = new_Node;

    // Insertion Successful
    return;
}


// Inserts ONLY if No Item duplicate(s) exist(s)
void insertOnce(VALUE item, node *list) {

    if (find(item, list) == true) {

        // Allocate Space for New Node
        node *new_Node = malloc(sizeof(node));
        if (!new_Node) {

            fprintf(stderr, "\nCould not create node. Out of Memory.\nInsertion Failed.\n");
            return NULL;
        }

        if (!list) {

            fprintf(stderr, "\nHead node points to NULL.\nInsertion Failed.\n");
            return;
        }

        // Initialize Node Accordingly & Update the Former Head Node
        new_Node->prev = list->prev;
        new_Node->item = item;
        new_Node->next = list;

        // Updating Former Head Node
        list->prev = new_Node;

        // Updating Head Pointer
        list = new_Node;

        // Insertion Successful
        return;
    }

    // Insertion unSuccessful
    fprintf(stderr, "\nItem duplicate(s) exists.\nInsertion Failed.\n");
    return;
}



// Linear Search (Sgly/Dbly) Linked List for an Item; Boolean Return & Probe Points to Item ≈ ≈

bool find(VALUE item, node *list) {

    if (!list) {

        fprintf(stderr, "\nHead node points to NULL.\nSearch Failed.\n");
        return;
    }

    // Place Probe at the Beginning of the List
    probe = list;

    // Till the Probe Reaches the end of the Linked List
    while (probe) {

        // Check if the Element Matches Key (return true if it does)
        if (probe->item == item) return true;

        // Else Check next Item in the List
        else probe = probe->next;
    }

    // If Element Does Not Exist
    fprintf(stderr, "\nItem Not Found.\n");
    return false;
}



// Deletes a Specified Item from a Doubly-Linked List ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈

void delete(VALUE item, node *list) {

    if (find(item, list) == true) {

        // Declare DeleteNode that will contain a pointer the node we want to delete
        node *deleteNode = malloc(sizeof(node));
        if (!deleteNode) {

            fprintf(stderr, "\nCould not create node. Out of Memory.\nDeletion Failed.\n");
            return;
        }

        if (!list) {

            fprintf(stderr, "\nHead node points to NULL.\nDeletion Failed.\n");
            return;
        }

        // At this point, probe will point to the node we want to delete, so...
        deleteNode = probe;


        // Only if DeleteNode is the Head node of the list (makes the previous pointer of the node after the head node point to NULL, which after deletion will become the head node)
        if (deleteNode == list) { list = deleteNode->next; }

        // Only Nodes that don't have a next pointer pointing to NULL
        if (deleteNode->next != NULL) { deleteNode->next->prev = deleteNode->prev; }

        // Only last Node of the list (makes the before last node next pointer point to NULL, which after deletion will become the last node of the list)
        if (deleteNode->next == NULL) { deleteNode->prev->next = deleteNode->next; }


        // Delete Node & Return
        free(deleteNode);
        return;
    }

    // If Item isn't found
    fprintf(stderr, "\nItem Not Found.\nDeletion Failed.\n");
    return;
}



// Destroys an entire (Sgly/Dbly) Linked List ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈

// Recursive Implementation
void destroy(node *list) {

    if (!(list->next))
        free(list);

    else
        destroy(list->next);

    return;
}


// Iterative Implementation
void destroy(node *list) {

    if (!list) {

        fprintf(stderr, "\nHead node points to NULL.\nDestruction Failed.\n");
        return;
    }

    node *next = malloc(sizeof(node));
    probe = list;
    next = probe;

    if (!next) {

        fprintf(stderr, "\nCould not create node.\nDestruction Failed.\n");
        return;
    }

    while (probe) {

        next = probe->next;
        free(probe);
        probe = next;
    }

    return;
}



// Prints a given (Sgly/Dbly) Linked List ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈

void printList(node *list) {
    for (probe = list; probe; probe = probe->next) { printf("%.0f, ", probe->item); } return;
}

// ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈
