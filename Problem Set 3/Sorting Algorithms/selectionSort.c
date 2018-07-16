
// PROTOTYPES
void selectionSort(int *array, int sizeOfArray);
void swap(int *var1, int *var2);


// Selection Sort
void selectionSort(int *array, int sizeOfArray) {

    int i, startIndex = 0, currentSmallest;

        // Increment the index at which we start by 1 After Each Sort
        for (startIndex = 0; startIndex < sizeOfArray - 1; startIndex++) {

            currentSmallest = startIndex;

            // Scan Unsorted Array
            for (i = startIndex + 1; i < sizeOfArray; i++) {

                // If a smaller Int is Found
                if (array[i] < array[currentSmallest])

                    // Keep track of where that smallest int was found
                    currentSmallest = i;
            }

            // Put the smallest int found at the beginning of the sorted list
            swap(&array[startIndex], &array[currentSmallest]);
        }
}


// Swaps the Contents of two Variables
void swap(int *var1, int *var2) { int tempory = *var1; *var1 = *var2; *var2 = tempory; }
