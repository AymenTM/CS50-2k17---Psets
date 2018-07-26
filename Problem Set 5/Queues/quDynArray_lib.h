
// Dynamic Queue Arrays Library/ToolKit (Header)
// - - - - - - - - - - - - - - - - - - - - - - - -


// ===================================================================================================
//                                         DECLARATIONS
// ===================================================================================================


// Datatype carried by array (int)
#define VALUE int


// Queue Datatype Structure
typedef struct {
    VALUE *array;
    int front;
    int size;
    int capacity;
} queue;


// Prototypes:
// queue *createQ(void);                    //  <--- createQ(); creates a queue and returns a pointer to it.
// int isFull(queue *q)                     //  <--- isFull(); checks whether or not the queue is full.
// int enQ(VALUE item, queue *q);           //  <--- enQ(); adds an element to the queue.
// VALUE deQ(queue *q);                     //  <--- deQ(); grabs/removes the oldest element of the queue & returns it.
// void printQ(queue *q);                   //  <--- printQ(); prints queue in its current state.


// Note:
/*Declare queue(s) in main, or in global scope & create them in main*/




// ===================================================================================================
//                                           FUNCTIONS
// ===================================================================================================



// Creates a queue & returns a pointer to it - - - - - - - - - - - - - - - - - - - - - - - - - - - -

queue *createQ(capacity) {

    // Declare a Pointer to a Queue & Allocate memory for a queue
    queue *new_Queue = malloc(sizeof(queue));

    // Error Checking
    if (!new_Queue) {

        fprintf(stderr, "Could not create new queue. --> Out of memory.\n");
        return NULL;
    }

    // Initializing Queue
    new_Queue->front = 0;
    new_Queue->size = 0;
    new_Queue->capacity = capacity;
    new_Queue->array = malloc(sizeof(VALUE) * capacity);

    // Successful
    return new_Queue;
}



// Checks to see if Queue is full - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int isFull(queue *q) {

    if ((q)->size >= (q)->capacity) {
        return 1; // (i.e  yes, queue is full)
    }

    return 0; // (i.e  no, there's still some place(s) )
}



// Enqueues a given value (i.e adds a value) in a given queue - - - - - - - - - - - - - - - - - - - -

int enQ(VALUE item, queue *q) {

    // Error Checking
    if (!q) { fprintf(stderr, "Enqueueing failed. --> Pointer points to NULL.\n"); return 1;}

    // Making sure there's room for new value OR you can at this point REALLOCATE more space
    if (isFull(q)) {

        fprintf(stderr, "Enqueueing failed. --> Queue at full capacity.\n");
        return 1;
    }

    // EnQ'ing the item at index ...
    (q)->array[((q)->size + (q)->front) % (q)->capacity] = item;

    // Incrementing size; keeping track of size of the queue
    (q)->size = (q)->size + 1;

    // Successful enQ
    return 0;
}



// Dequeues (i.e removes/grabs) the oldest (i.e the last) element from the queue & returns it - - - - -

VALUE deQ(queue *q) {

    // Error Checking
    if (!q) { fprintf(stderr, "Dequeueing failed. --> Pointer points to NULL.\n"); return 1; }

    // deQ'd Item Stored
    VALUE deQd_element = (q)->array[(q)->front];

    // Update Counters
    (q)->front = (q)->front + 1 % (q)->capacity;
    (q)->size = (q)->size - 1;

    // Return deQ'd Element
    return deQd_element;
}



// Prints Queue - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void printQ(queue *q) {

    if (!q) { fprintf(stderr, "Printing failed. --> Pointer points to NULL.\n"); return; }

    int index = q->front;
    printf("\n\nQueue:\n\n---> ");
    for (size_t i = 0; i < q->size; i++) {

        printf("%i, ", q->array[index]);
        index = (index+1) % q->capacity;
    }
    printf("\n\n");

    return;
}



// Frees/Deletes Queue - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void freeQ(queue **q) {

  free((*q) -> array);
  free(*q);
}
