
// PROTOTYPE
void selectionSort(int *array, int sizeOfArray);


// Selection Sort
void selectionSort(int *array, int sizeOfArray) {

    int i, startIndex = 0, currentSmallest, temporary;

        // Increment the index at which we start by 1 After Each Sort
        for (startIndex = 0; startIndex < sizeOfArray - 1; startIndex++) {

            currentSmallest = startIndex;

            // Scan Unsorted Array
            for (i = startIndex + 1; i < sizeOfArray; i++) {

                // If a smaller Int is Found
                if (array[i] < array[currentSmallest])

                    // Keep track of where the smallest int was found
                    currentSmallest = i;
            }

            // Put the smallest int found at the beginning
            temporary = array[startIndex]; 
            array[startIndex] = array[currentSmallest];
            array[currentSmallest] = temporary;
        }
}
