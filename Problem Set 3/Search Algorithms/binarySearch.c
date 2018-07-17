
// PROTOTYPE
int binarySearch(int key, int *array, int sizeOfArray);


// Binary Search
int binarySearch(int key, int *array, int sizeOfArray) {

    // Define starting index (mid array) & Current Number of Elements
    int index = ceil(sizeOfArray * 0.5) - 1, elements = sizeOfArray;

        // While Elements Remain Between Previous & Current Index
        while (elements) {

            // If element matches key --> Return its index
            if (array[index] == key) return index;

            // (Element Bigger than Key); Divide accordingly
            else if (array[index] > key) {

                elements = floor(elements * 0.5) + (elements%2 - 1);
                index = index+1 - ceil(elements/2) + ((elements/2%2) - 1) - 1;
            }

            // (Element Smaller than Key); Divide accordingly
            else (array[index] < key) {

                elements = ceil(elements * 0.5) - (elements%2);
                index = index+1 + ceil(elements/2) - (elements/2%2);
            }
        }
        
        // Else, signal that key was not found        
        return -1;
}
