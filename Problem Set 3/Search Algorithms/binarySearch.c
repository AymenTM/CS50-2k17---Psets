
// PROTOTYPE
int binarySearch(int key, int array[], int sizeOfArray);


// myVariation of Binary Search - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int binarySearch(int key, int array[], int sizeOfArray) {

    // Define starting index (mid array) & Current Number of Elements
    int index = ceil(sizeOfArray * 0.5) - 1, elements = sizeOfArray;

        // While Elements Remain
        while (elements) {

            // If element matches key --> Return its index
            if (array[index] == key) return index;

            // (Element Bigger than Key); Go to new mid Index
            else if (array[index] > key) {

                elements = ceil(elements * 0.5);
                index = index - (elements/2);
                if (elements == 1) return -1;
            }

            // (Element Smaller than Key); Go to new mid Index
            else {

                elements = ceil(elements * 0.5);
                index = index + (elements/2);
                if (elements == 1) index++;
            }
            
        }

        // Else, signal that key was not found
        return -1;
}



// Variation of Binary Search - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
int binarySearch(int key, int array[], int arraySize) {

    if (arraySize <= 0) return false;

    int lowerBound = 0;
        upperBound = arraySize - 1;
        middle;

    // While Elements Remain
    while (lowerBound <= upperBound) {

        // Update Mid Index
        middle = (upperBound + lowerBound) / 2;

        // If Element Matches Key, Return its Index
        if (key == values[middle]) return middle;

        // If Element Bigger than Key
        if (key < values[middle]) upperBound = middle - 1;

        // If Element Smaller than Key
        if (key > values[middle]) lowerBound = middle + 1;

    }

    // Key Not Found
    return -1;
}



// Recursive Variation of Binary Search - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    
int binarySearch(int array[], int lowerBound, int upperBound, int key) {
    
    // While Elements Remain
    if (upperBound >= lowerBound) {
        
        // Update Middle Index
        int middle = lowerBound + (upperBound - lowerBound)/2;
        
        // If Element Matches Key, Return its Index
        if (array[middle] == key) return middle;
        
        // If Element Bigger than Key
        if (array[middle] > key) return binarySearch(array, lowerBound, middle-1, key);

        // Else If Element Smaller than Key
        return binarySearch(array, middle+1, upperBound, key);
   }

    // Key was not found
   return -1;
}

