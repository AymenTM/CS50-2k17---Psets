
// PROTOTYPE
int binarySearch(int key, int array[], int arraySize);


// myVariation of Binary Search - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

int binarySearch(int key, int array[], int arraySize) {

    // Define starting index (mid array) & Current Number of Elements
    int index = ceil(arraySize * 0.5) - 1, elements = arraySize;

        // While Elements Remain
        while (elements) {

            // If element matches key --> Return its index
            if (array[index] == key) return index;

            // If Element Bigger than Key
            else if (array[index] > key) {

                elements = ceil(elements * 0.5);
                index = index - (elements/2);
                if (elements == 1) return -1;
            }

            // If Element Smaller than Key
            else {

                elements = ceil(elements * 0.5);
                index = index + (elements/2);
                if (elements == 1) index++;
            }
            
        }

        // Else, signal that key was not found
        return -1;
}



// Variation of Binary Search - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    
int binarySearch(int key, int array[], int arraySize) {

    // If No Elements
    if (arraySize <= 0) return -1;

    // Define Bounds
    int lowerBound = arraySize - arraySize,
        upperBound = arraySize - 1,
        middle;

    // While Elements Remain
    while (lowerBound <= upperBound) {

        // Update Mid Index
        middle = (upperBound + lowerBound) / 2;

        // If Element Matches Key, Return its Index
        if (key == array[middle]) return middle;

        // If Element Bigger than Key
        if (key < array[middle]) upperBound = middle - 1;

        // If Element Smaller than Key
        else lowerBound = middle + 1;

    }

    // Key Not Found
    return -2;
}



// Recursive Variation of Binary Search - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
    
int binarySearch(int key, int *array, int lowerBound, int upperBound) {

    // While Elements Remain
    while (lowerBound <= upperBound) {
        
        // Update Middle Index
        int middle = (lowerBound + upperBound) / 2;

        // If Element Matches Key, Return its Index
        if (array[middle] == key) return middle;

        // If Element Bigger than Key
        if (array[middle] > key) return binarySearch(key, array, lowerBound, middle-1);

        // If Element Smaller than Key   
        else return binarySearch(key, array, middle+1, upperBound);

    }

    // Key was not found
    return -1;
}



// Binary Search Trees - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int binarySearch(int key, node *tree) {
       
    // Make sure the tree Exists
    if (!tree) return -1;

        // If Element Matches Key, Return its Index
        else if (tree->element == key) return tree;
            
            // If Element Bigger than Key --> Go to Left Child ELSE Go to Right Child
            else (tree->element > key) ? binarySearch(key, tree->left) : binarySearch(key, tree->right);

}
