
// Stack Linked List Library/ToolKit (Header)
// - - - - - - - - - - - - - - - - - - - - - -


// Datatype carried by array (int)
#define VALUE int


// Stack Datatype Structure
typedef struct node_t {
        VALUE item;
        struct node_t *next;
} node;


// Prototypes
// node *push(VALUE item, node *stack_head);             //  <--- Push (i.e add a value to the stack).
// VALUE pop(node **stack_head);                       //  <--- Pop (i.e grab the most recent value added to the stack).
// void printStack(node *stack_head);               //  <--- Prints stack that is currently in use.



// Create a Stack; Return a Pointer to it - - - - - - - - - - - - - - - - - - - -

node *create(VALUE item) {

    // Allocate Space
    node *genesis_Node = malloc(sizeof(node));
    if (!genesis_Node) {

        fprintf(stderr, "\nFailed to create stack. --> Could not create genesis node. Out of Memory.\n");
        return NULL;
    }

    // Initialize the Node
    genesis_Node->item = item;
    genesis_Node->next = NULL;

    // Return a Pointer to the Node/List
    return genesis_Node;
}



// Push (i.e add a value to the stack) - - - - - - - - - - - - - - - - - - - - - - - - - - - -

node *push(VALUE item, node *stack_head) {

    node *new_Node = malloc(sizeof(node));
    if (!stack_head || !new_Node) {

        if (!stack_head) fprintf(stderr, "\nPush failed. --> Pointer to stack points to NULL.\n");
        if (!new_Node) fprintf(stderr, "\nPush failed. --> Could not create new node. Out of Memory.\n");
        return stack_head;
    }

    new_Node->item = item;
    new_Node->next = stack_head;

    // Successful Push
    return new_Node;
}



// // Pop (i.e remove/grab the most recent element from the top of the stack) - - - - - - - - - -

VALUE pop(node **stack_head) {

    node *deleteNode = *stack_head;

    if (!*stack_head || !deleteNode) {

        if (!deleteNode) fprintf(stderr, "\nPop failed. --> Could not create new node. Out of Memory.\n");
        if (!*stack_head) fprintf(stderr, "\nPop failed. --> Pointer to stack points to NULL.\n");
        return -1;
    }

    VALUE popped_item = (*stack_head)->item;
    *stack_head = (*stack_head)->next;

    free(deleteNode);
    return popped_item;
}



// Destroys a Stack - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int destroy(node *stack_head) {

    if (stack_head->next == NULL) free(stack_head);

    else { destroy(stack_head->next); free(stack_head); }

    return 0;
}



// Prints Stack - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void printStack(node *stack_head) {

    if (!stack_head) {

        if (!stack_head) fprintf(stderr, "\nPrinting Failed. --> Head node points to NULL.\n");
        return;
    }

    printf("\n\n---> ");
    for (node *probe = stack_head; probe != NULL; probe = probe->next) {

        printf("%d, ", probe->item);
    }
    printf("\n\n");

    return;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
