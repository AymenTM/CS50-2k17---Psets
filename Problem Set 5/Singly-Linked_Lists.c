
// Singly-Linked List ToolKit (Library)



// Datatype carried by Node(s)
#define VALUE int


// Datatype Structure carried by List(s)
typedef struct preNode {
    VALUE item;
    struct preNode *next;
} node;


// Global Variables
node *listN = malloc(sizeof(node));
node *probe = malloc(sizeof(node));


// Prototypes
node *create(VALUE item);
void insert(VALUE item, node *list);
bool find(VALUE item, node *list)
void destroy(node *list);



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



// Inserts a Key in a Singly-Linked List ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈

// Inserts whether item duplicate(s) exist(s) or not
void insert(VALUE item, node *list) {

    // Allocate Space for Node that is to be inserted
    node *new_Node = malloc(sizeof(node));
    if (!new_Node) {

        fprintf(stderr, "\nCould not create new node. Out of Memory.\nInsertion Failed.\n");
        return NULL;
    }

    if (!list) {

        fprintf(stderr, "\nHead node points to NULL.\nInsertion Failed.\n");
        return NULL;
    }

    // Initialize the Node and make it Point to the CURRENT head of the list, making the head of the list now 2nd in the list and the newly inserted node the head of the list
    new_Node->item = item;
    new_Node->next = list;

    // Update Head to Point to New head of the list
    list = new_Node;

    // Insertion Successful
    return;
}


// Inserts ONLY if No Item duplicate(s) exist(s)
void insert(VALUE item, node *list) {

    if (find(item, list) == true) {

        // Allocate Space for Node that is to be inserted
        node *new_Node = malloc(sizeof(node));
        if (!new_Node) {

            fprintf(stderr, "\nCould not create node. Out of Memory.\nInsertion Failed.\n");
            return NULL;
        }

        if (!list) {

            fprintf(stderr, "\nHead node points to NULL.\nInsertion Failed.\n");
            return NULL;
        }

        // Initialize the Node and make it Point to the CURRENT head of the list, making the head of the list now 2nd in the list and the newly inserted node the head of the list
        new_Node->item = item;
        new_Node->next = list;

        // Update Head to Point to New head of the list
        list = new_Node;

        // Insertion Successful
        return;
    }

    // Insertion Unsuccessful
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



// Destroys an entire (Sgly/Dbly) Linked List ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈

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



// Prints a given (Sgly/Dbly) Linked List ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈

void printList(node *list) {
    for (probe = list; probe; probe = probe->next) { printf("%.0f, ", probe->item); } return;
}



// ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈ ≈
