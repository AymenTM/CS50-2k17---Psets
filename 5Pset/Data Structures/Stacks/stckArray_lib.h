
// Stack Array Library/ToolKit (Header)
// - - - - - - - - - - - - - - - -


// Datatype carried by array (int)
#define VALUE int
#define CAPACITY 10


// Stack Datatype Structure
typedef struct {
    VALUE array[CAPACITY];
    int top;
} stack;


// Prototypes
// int push(VALUE val, stack *ptr);             //  <--- Push (i.e add a value to the stack).
// VALUE pop(stack *ptr);                       //  <--- Pop (i.e grab the most recent value added to the stack).
// void printStack(stack *stack)                //  <--- Prints stack that is currently in use.



// Push (i.e add a value to the stack) - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int push(VALUE item, stack *stack) {

    if (!stack) {

        fprintf(stderr, "\nPush failed. --> Pointer to stack points to NULL.\n");
        return 1;
    }

    stack->array[stack->top] = item;
    stack->top++;

    // Successful Push
    return 0;
}



// Pop (i.e remove/grab the most recent element from the top of the stack) - - - - - - - - - -

VALUE pop(stack *stack) {

    stack->top--;
    return stack->array[stack->top];
}



// Prints Stack - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void printStack(stack *stack) {

    if (!stack) {

        fprintf(stderr, "\nPrinting failed. --> Pointer to stack points to NULL.\n");
        return;
    }

    printf("\n\nStack: ");
    for (size_t i = 0; i < stack->top; i++) {

        printf("%i, ", stack->array[i]);
    } printf("\n\n");

    return;
}
