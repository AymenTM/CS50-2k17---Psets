
                              //  - - - - - - - - - - - - - - - - -  //
                              //    Tree Library/ToolKit (Header)    //
                              //  - - - - - - - - - - - - - - - - -  //


// =================================================================================================== //
//                                            DECLARATIONS                                             //
// =================================================================================================== //



// Datatype carried by Node(s)
#define VALUE int


// Datatype Structure carried Tree
typedef struct bTreeNode_t {
    VALUE item;
    struct bTreeNode_t *leftChild;
    struct bTreeNode_t *rightChild;
} bTreeNode;


// Variable Type (has double function of storing values + being boolean via pointer)
typedef struct {
    VALUE item;
} boolValue_t;


// Include Library to work w/ Queues
#include "treeQu_lib.h"


// Utility Struct (used for the level_OrderTravBTREE function)
typedef struct lvlOrderUtil_t {
        qNode *qHead;
        qNode *qTail;
        int enQd_bTreeNodes;
        int curLvl_bTreeNodes;
} lvlOrderUtil;




// =================================================================================================== //
//                                             PROTOTYPES                                              //
// =================================================================================================== //

// // HELPERS
// bTreeNode *findMaxBTREE(bTreeNode *root);             // <---             findMaxBST();   Searches & Returns Node w/ Max Value of B-Tree.
// bTreeNode *findMinBTREE(bTreeNode *root);             // <---             findMinBST();   Searches & Returns Node w/ Min Value of B-Tree.
// bTreeNode *findOuterRightBTREE(bTreeNode *root);      // <---    findOuterRightBTREE();   Finds & Returns Pointer to most outer right node.
// bTreeNode *findOuterLeftBTREE(bTreeNode *root);       // <---     findOuterLeftBTREE();   Finds & Returns Pointer to most outer left node.
// bTreeNode *createBST(VALUE item);                     // <---              createBST();   Creates a binary tree (b-Tree) node.

// // BASIC OPERATIONS (for BSTs)
// bTreeNode *searchBST(VALUE item, bTreeNode *root);    // <---              searchBST();   Searches a BST for an element and returns pointer to it.
// bTreeNode *insertBST(VALUE item, bTreeNode *root);    // <---              insertBST();   Inserts a value/node in BST & returns a pointer to it.
// bTreeNode *deleteBST(VALUE item, bTreeNode *root);    // <---              deleteBST();   Deletes a given node from a BST.

// // OTHER
// bTreeNode *getSuccessor(VALUE item, bTreeNode *root); // <---           getSuccessor();   Finds & Returns successor Node of a given node. (INCOMPLETE)
// int _searchBST(VALUE item, bTreeNode *root);          // <---             _searchBST();   Searches a BST for an element and returns a boolean.
// int insertBoolBST(VALUE item, bTreeNode *root);       // <---          insertBoolBST();   Inserts a value/node in BST & returns a bool.
// int isBST(bTreeNode *root, boolValue_t *_state);      // <---                  isBST();   Returns whether or not b-tree is a BST.
// int findHeightBTREE(bTreeNode *root);                 // <---        findHeightBTREE();   Finds & Returns bTreeHeight of the tree.
// void printBTREE(bTreeNode *root);                     // <---             printBTREE();   Prints/Displays a b-tree in order.
// int freeBTREE(bTreeNode *root);                       // <---              freeBTREE();   Frees a b-tree.

// // BINARY TREE TRAVERSALS
// void level_OrderTravBTREE(bTreeNode *root);           // <---   level_OrderTravBTREE();   Traverses tree in level-order.
// void spiral_OrderTravBTREE(bTreeNode *root);          // <---  spiral_OrderTravBTREE();   Traverses tree in a spiral level-order fashion. (INCOMPLETE)
// void in_OrderTravBTREE(bTreeNode *root);              // <---      in_OrderTravBTREE();   Traverses tree in-order.
// void pre_OrderTravBTREE(bTreeNode *root);             // <---     pre_OrderTravBTREE();   Traverses tree in pre-order.
// void post_OrderTravBTREE(bTreeNode *root);            // <---    post_OrderTravBTREE();   Traverses tree in post-order.

// NOTE: Some utility functions are not included.




// =================================================================================================== //
//                                             FUNCTIONS                                               //
// =================================================================================================== //



// ========================================= HELPERS/OTHER ===========================================

// Finds Biggest Item in B-Tree & Returns its Value
bTreeNode *findMaxBTREE(bTreeNode *root) {

    if (!root) { fprintf(stderr, "\nError. --> Root points to NULL.\n"); return NULL; }

    if (root->rightChild)
        if (root->rightChild->item > root->item)
            root = findMaxBTREE(root->rightChild);

    if (root->leftChild)
        if (root->leftChild->item > root->item)
            root = findMaxBTREE(root->leftChild);

    return root;
}

// Finds Smallest Item in B-Tree & Returns its Value
bTreeNode *findMinBTREE(bTreeNode *root) {

    if (!root) { fprintf(stderr, "\nError. --> Root points to NULL.\n"); return NULL; }

    if (root->leftChild)
        if (root->leftChild->item < root->item)
            root = findMinBTREE(root->leftChild);

    if (root->rightChild)
        if (root->rightChild->item < root->item)
            root = findMinBTREE(root->rightChild);

    return root;
}

// Finds Most Outer Right Node in B-Tree & Returns a Pointer to it
bTreeNode *findOuterRightBTREE(bTreeNode *root) {

    // Error Checking
    if (!root) { fprintf(stderr, "\nError. --> Root points to NULL.\n"); return NULL; }

    // If you have a rightChild
    if (root->rightChild)

        // Go to it
        root = findOuterRightBTREE(root->rightChild);

    // If you found the mostOuterRight Node Return a Pointer to it
    return root;
}

// Finds Most Outer Left Node in B-Tree & Returns its Value
bTreeNode *findOuterLeftBTREE(bTreeNode *root) {

    // Error Checking
    if (!root) { fprintf(stderr, "\nError. --> Root points to NULL.\n"); return NULL; }

    // If you have a leftChild
    if (root->leftChild)

        // Go to it
        root = findOuterLeftBTREE(root->leftChild);

    // If you found the mostOuterLeft Node Return a Pointer to it
    return root;
}



// ======================================== BINARY SEARCH ============================================

// Search that returns a Boolean if Search Successful
int _searchBST(VALUE item, bTreeNode *root) {

    // If item is found
    if (root->item == item) return 0; // true, found

    // If Element Bigger than Root
    else if (item > root->item) {
        if (root->rightChild)
            return _searchBST(item, root->rightChild);
    }

    // If Element Smaller/Equal than/to Root
    else {
        if (root->leftChild)
            return _searchBST(item, root->leftChild);
    }

    // If Not Found
    return 1; // false, not found
}

// Search that returns a pointer to the node
bTreeNode *searchBST(VALUE item, bTreeNode *root) {

    // If item is found
    if (root->item == item) {

        // Successful Search (found)
        return root;
    }

    // If Element Bigger than Root
    else if (item > root->item) {
        if (root->rightChild) {
            root = searchBST(item, root->rightChild);
            return root;
        }
    }

    // If Element Smaller/Equal than/to Root
    else {
        if (root->leftChild) {
            root = searchBST(item, root->leftChild);
            return root;
        }
    }

    // unSuccessful Search (not found)
    return NULL;
}

// Finds and returns a pointer to the successor node of a given node
// bTreeNode *getSuccessor(VALUE item, bTreeNode *root) { skipping it for now }


// ========================================== INSERTION ===============================================

// Creates a new node and returns a pointer to it ---> helper of insertBST();
bTreeNode *createBST(VALUE item) {

    // Allocate Space for Node
    bTreeNode *new_Node = malloc(sizeof(bTreeNode));
    if (!new_Node) {

        fprintf(stderr, "\nFailed to create node. --> Out of Memory. [tree_lib.h:178]\n");
        return NULL;
    }

    // Initialize the Node
    new_Node->item = item;
    new_Node->leftChild = NULL;
    new_Node->rightChild = NULL;

    // Return a Pointer to It
    return new_Node;
}

// Inserts Element into BST ---> helper of insertBST();
bTreeNode *insertBST(VALUE item, bTreeNode *root) {

    // If Tree doesn't exist, make one, and insert in first value 'item'
    if (!root) root = createBST(item);

    // Make sure to insert in rightful place (keeping the BST property)
    else if (item > root->item) root->rightChild = insertBST(item, root->rightChild);
    else root->leftChild = insertBST(item, root->leftChild);

    // Return Pointer to Inserted Node
    return root;
}

// Calls the Insert Function & Returns 0 if Operation was Successful, 1 otherwise
int insertBoolBST(VALUE item, bTreeNode *root) {

    // If Insert Operation was Unsuccessful
    if (!insertBST(item, root)) return 1;

    // If Insert Operation was Successful
    return 0;
}



// ========================================== DELETION ================================================

// Deletes Node from the BST
bTreeNode *deleteBST(VALUE item, bTreeNode *root) {

    // If root points to NULL
    if (!root) return root;

    // Find DeleteNode
    if (item > root->item) root->rightChild = deleteBST(item, root->rightChild);
    else if (item < root->item) root->leftChild = deleteBST(item, root->leftChild);

    // If we found our deleteNode
    else {

        // If deleteNode has no children (leaf)
        if (!(root->rightChild) && !(root->leftChild)) {

            // We free the memory that POINTER 'root' points to (i.e the node to be deleted)
            free(root);

            // Root still being a pointer that points to that area of memory; we assign to it NULL
            root = NULL;

            // Finally we Return it, making it the right/left child of whatever node comes before it
            // return root;
        }

        // If deleteNode has 1 child
        else if (!root->leftChild || !root->rightChild)  {

            if (root->leftChild) {

                // Store Address of DeleteNode
                bTreeNode *deleteNode = root;

                // Store Address of the Child of Root in the Pointer 'root'
                root = root->leftChild;

                // Free/Delete DeleteNode
                free(deleteNode);

                // Return Address to the Child of DeleteNode (making it the child of whatever node comes before it)
                // return root;
            }

            else if (root->rightChild) {
                bTreeNode *deleteNode = root;
                root = root->rightChild;
                free(deleteNode);
                // return root;
            }
        }

        // If deleteNode has 2 children
        else {

            // Find & Store Node with which we will swap values
            bTreeNode *deleteNode = findMaxBTREE(root->leftChild);

            // Replace the Node w/ the biggest Item in the Left Subtree (to keep the BST property)
            root->item = deleteNode->item;

            // Delete the DeleteNode
            root->leftChild = deleteBST(root->item, root->leftChild);
        }

        return root;
    }

    return root;
}



// ==================================== BINARY TREE TRAVERSALS ========================================


// - - - - - - - - - - - - - - - - - - - - - UTILITES - - - - - - - - - - - - - - - - - - - - - - - //

// lvlOrder_treeQ(); Utility function
// Stores the next level, of the tree, in Queue --> Returns Queue
lvlOrderUtil *store_NextLvl(lvlOrderUtil **_qState) {

    // So as to not alter the actual _qState (we make a temporary copy of it)
    qNode *temp_qHead = (*_qState)->qHead;
    int temp_enQd_bTreeNodes = 0;

    // For every node in the previous level, if the node has a left/right Child store a pointer to it in the queue
    for (size_t i = 0; i < (*_qState)->enQd_bTreeNodes; i++) {

        // If bTreeNode has a left Child
        if (temp_qHead->item->leftChild) {

            // Store pointer to it in Queue
            (*_qState)->qTail = enQ(temp_qHead->item->leftChild, (*_qState)->qTail);

            // Increment Number of b-Tree Nodes that we Enqueued
            temp_enQd_bTreeNodes++;
        }

        // If bTreeNode has a right Child
        if (temp_qHead->item->rightChild) {

            // Store pointer to it in Queue
            (*_qState)->qTail = enQ(temp_qHead->item->rightChild, (*_qState)->qTail);

            // Increment Number of b-Tree Nodes that we Enqueued
            temp_enQd_bTreeNodes++;
        }

        // Go to next Node in Queue
        temp_qHead = temp_qHead->next;
    }

    // Updating to the new Number of curLvl b-Tree Nodes
    (*_qState)->curLvl_bTreeNodes = (*_qState)->enQd_bTreeNodes;

    // Updating to the new Number of Enq'd b-Tree Nodes
    (*_qState)->enQd_bTreeNodes = temp_enQd_bTreeNodes;

    return (*_qState);
}

// lvlOrder_treeQ(); Utility function
// Preforms an action on the current level of the tree --> Returns Void
void actionOn_CurLvl(qNode *qHead, int numOf_cur_lvl_nodes) {

    for (size_t i = 0; i < numOf_cur_lvl_nodes; i++) {
        printf("%i, ", qHead->item->item); // or any action
        if (qHead->next) qHead = qHead->next;
    }

    return;
}

// lvlOrder_treeQ(); Utility function
// DeQs/Frees/Deletes Current Level Nodes of Tree
lvlOrderUtil *free_CurLvl(lvlOrderUtil *_qState) {

    // Free Current Level Nodes
    for (size_t i = 0; i < _qState->curLvl_bTreeNodes; i++) {
        deQ(&(_qState->qHead));
    }

    return _qState;
}

// level_OrderTravBTREE(); Utility function
// Level by level (of the tree): stores next level in queue --> preforms action on current level --> frees current level
void lvlOrder_treeQ(lvlOrderUtil *_qState) {

    // Store Nodes of the Next Level of Tree in Queue --> Return Queue
    _qState = store_NextLvl(&(_qState));

    // Perform an action on the Nodes of Current Level of Tree
    actionOn_CurLvl(_qState->qHead, _qState->curLvl_bTreeNodes);

    // Free/DeQ Nodes of Current Level of Tree --> Return Queue (w/ Current lvl nodes deleted & next level remaining)
    _qState = free_CurLvl(_qState);

    // Recursively call function for each level of tree, until none remain
    if (_qState->enQd_bTreeNodes >= 1) lvlOrder_treeQ(_qState);

    // Done
    return;
}


// - - - - - - - - - - - - - - - - - - - - - FUNCTIONS - - - - - - - - - - - - - - - - - - - - - - - //

// Level-Order Traversal
void level_OrderTravBTREE(bTreeNode *root) {

    // Error Checking
    if (!root) { fprintf(stderr, "\nError. --> Root points to NULL.\n"); return; }


    // Declaring Struct Pointers
    qNode *tree_qHead = NULL; // Memory for queue is Allocated in the Enq(); function below
    qNode *tree_qTail = NULL; // Memory for queue is Allocated in the Enq(); function below
    lvlOrderUtil *qState = malloc(sizeof(lvlOrderUtil));

    // Store Root Node in Queue (Memory is Allocated for the Queue in the EnQ(); function)
    tree_qHead = tree_qTail = enQ(root, tree_qTail);

    // Store Queue Info in Struct
    qState->qHead = tree_qHead;
    qState->qTail = tree_qTail;
    qState->enQd_bTreeNodes = 1;
    qState->curLvl_bTreeNodes = 0;


    // Note: for other actions change the lvlOrder_treeQ(); function
    // Store Nodes of Tree, in level order, in a Queue --> Print (or any action) Queue --> Return Void
    lvlOrder_treeQ(qState);

    // Free Utility Struct
    free(qState);

    // Done
    return;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

// Pre-Order Traversal (B-Trees ONLY)
void pre_OrderTravBTREE(bTreeNode *root) {

    if (!root) { fprintf(stderr, "\nFailed. --> Root points to NULL.\n"); return; }

    printf("%i, ", root->item); // Or any action
    if (root->leftChild) pre_OrderTravBTREE(root->leftChild);
    if (root->rightChild) pre_OrderTravBTREE(root->rightChild);

    return;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

// In-Order Traversal (B-Trees ONLY)
void in_OrderTravBTREE(bTreeNode *root) {

    if (!root) { fprintf(stderr, "\nFailed. --> Root points to NULL.\n"); return; }

    if (root->leftChild) in_OrderTravBTREE(root->leftChild);
    printf("%i, ", root->item); // Or any action
    if (root->rightChild) in_OrderTravBTREE(root->rightChild);

    return;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

// Post-Order Traversal (B-Trees ONLY)
void post_OrderTravBTREE(bTreeNode *root) {

    if (!root) { fprintf(stderr, "\nFailed. --> Root points to NULL.\n"); return; }

    if (root->leftChild) post_OrderTravBTREE(root->leftChild);
    if (root->rightChild) post_OrderTravBTREE(root->rightChild);
    printf("%i, ", root->item); // Or any action

    return;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

/* Spiral Level-Order Traversal
void spiral_OrderTravBTREE(bTreeNode *root) {

    ---> not tht important skipping it for now.

    return;
} */




// ======================================= IS TREE A BST ? ============================================

// Traverses Tree Making Sure every node respects the BST property (utility function for isBST();)
boolValue_t *BST_propertyCheck(bTreeNode *root, boolValue_t *_state) {

    // Goto Left Child
    if (root->leftChild) _state = BST_propertyCheck(root->leftChild, _state);


        // If BST Property has and is still being Respected
        if (_state) {

            // Checking if Node Respects BST Property
            if (_state->item <= root->item) _state->item = root->item;

            // If not Respected Signal it; NULL signaling a breach of the BST property
            else return NULL;
        }

        // Else just Immediatly Return NULL
        else return NULL;


    // Goto Right Child
    if (root->rightChild) _state = BST_propertyCheck(root->rightChild, _state);

    // Done Return
    return _state;
}

// Declaration of Helper Variable (used in isBST();)
boolValue_t *state; // Pass this in the "isBST" function.

// Calls the Operation Function & Returns the Verdict (mySolution to isBST)
int isBST(bTreeNode *root, boolValue_t *_state) {

    _state = malloc(sizeof(boolValue_t));
    if (!_state) {

        fprintf(stderr, "\nFunction Failed. --> Could not create variable. Out of Memory.\n");
        return 2; // Out of memory Error
    }

    _state->item = 0; // <-------------------------------- Define your MINIMUM VALUE HERE !


    if (!(BST_propertyCheck(root, _state))) {

        // False (i.e is not a BST)
        free(_state);
        return 1;
    }

    // True (i.e is a BST)
    free(_state);
    return 0;
}

// Variation of isBST
// int isBST(bTreeNode *root) {
//
//     bTreeNode *prev = NULL;
//
//     // Traverse Tree Inorder and Keep track of Previous node
//     if (root) {
//
//         if(!isBST(root->leftChild)) return 1; // false
//
//         // Allows for duplicates (for distinct change the '<' into '<=')
//         if (!prev && root->item < prev->item) return 1; // false
//
//         prev = root;
//
//         return isBST(root->rightChild);
//     }
//
//     return 0; // True (is a BST)
// }



// ======================================== HEIGHT OF TREE =============================================

// - - - - - - - - - - - - - - - - - - - - - - UTILITIES - - - - - - - - - - - - - - - - - - - - - - //

// findLvlsBTREE(); Utility Fucntion
lvlOrderUtil *enQ_NxtLvl(lvlOrderUtil **_qState) {

    qNode *temp_qHead = (*_qState)->qHead;
    int temp_enQd_bTreeNodes = 0;

    for (size_t i = 0; i < (*_qState)->enQd_bTreeNodes; i++) {

        if (temp_qHead->item->leftChild) {

            (*_qState)->qTail = enQ(temp_qHead->item->leftChild, (*_qState)->qTail);
            temp_enQd_bTreeNodes++;
        }

        if (temp_qHead->item->rightChild) {

            (*_qState)->qTail = enQ(temp_qHead->item->rightChild, (*_qState)->qTail);
            temp_enQd_bTreeNodes++;
        }

        temp_qHead = temp_qHead->next;
    }

    (*_qState)->curLvl_bTreeNodes = (*_qState)->enQd_bTreeNodes;
    (*_qState)->enQd_bTreeNodes = temp_enQd_bTreeNodes;

    return (*_qState);
}

// findLvlsBTREE(); Utility Fucntion
lvlOrderUtil *deQ_CurLvl(lvlOrderUtil *_qState) {

    for (size_t i = 0; i < _qState->curLvl_bTreeNodes; i++) {

        deQ(&(_qState->qHead));
    }

    return _qState;
}

// findHeightBTREE(); Utility Fucntion
int findLvlsBTREE(lvlOrderUtil *_qState, int bTreeHeight) {

    // Discover New Level & Free Current Level
    _qState = enQ_NxtLvl(&(_qState));
    _qState = deQ_CurLvl(_qState);

    // For each level of tree discovered, Increment Height of tree by 1 & recursively call function
    if (_qState->enQd_bTreeNodes >= 1) {

        bTreeHeight++;
        bTreeHeight = findLvlsBTREE(_qState, bTreeHeight);
    }

    // Once all levels were discovered return number of levels found
    return bTreeHeight;
}


// - - - - - - - - - - - - - - - - - - - - - - FUNCTION - - - - - - - - - - - - - - - - - - - - - - //

// Breadth First Search to Find Height of a given Binary Tree
int findHeightBTREE(bTreeNode *root) {

    // Error Checking
    if (!root) { fprintf(stderr, "\nError. --> Root points to NULL.\n"); return -1; }


    // Declaring Struct Pointers
    qNode *tree_qHead = NULL; // Memory for queue is Allocated in the Enq(); function below
    qNode *tree_qTail = NULL; // Memory for queue is Allocated in the Enq(); function below
    lvlOrderUtil *qState = malloc(sizeof(lvlOrderUtil));

    // Store Root Node in Queue (Memory is Allocated for the Queue in the EnQ(); function)
    tree_qHead = tree_qTail = enQ(root, tree_qTail);

    // Store Queue Info in Struct
    qState->qHead = tree_qHead;
    qState->qTail = tree_qTail;
    qState->enQd_bTreeNodes = 1;
    qState->curLvl_bTreeNodes = 0;


    int bTreeHeight = 0;
    bTreeHeight = findLvlsBTREE(qState, bTreeHeight);


    // Free Utility Struct
    free(qState);

    // Done
    return bTreeHeight;
}




// ================================= PRINT/DISPLAY B-TREE IN ORDER =====================================

// Prints/Displays B-TREES (inOrderTrav) (useful to view a BST in order)
void printBTREE(bTreeNode *root) {

    if (!root) { fprintf(stderr, "\nFailed. --> Root points to NULL.\n"); return; }

    if (root->leftChild) printBTREE(root->leftChild);
    printf("%i, ", root->item); // Or any action
    if (root->rightChild) printBTREE(root->rightChild);

    return;
}



// ==================================== FREE/DESTROY B-TREE ===========================================

// Frees/Destroys/Deletes B-Trees (postOrderTrav)
int freeBTREE(bTreeNode *root) {

    if (!root) { fprintf(stderr, "\nFailed to free Tree. --> Root points to NULL.\n"); return 1; }

    if (root->leftChild) freeBTREE(root->leftChild);
    if (root->rightChild) freeBTREE(root->rightChild);
    free(root);

    return 0;
}
