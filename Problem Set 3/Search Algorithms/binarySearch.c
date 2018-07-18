
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

