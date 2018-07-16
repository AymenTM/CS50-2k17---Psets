
// PROTOTYPE
void bubbleSort(int *array, int sizeOfArray);


// Bubble Sort
void bubbleSort(int *array, int sizeOfArray) {

    int i, j, temporary;

        // Scan 1 less element (from the end of the array) after each scan
        for (i = 0; i < sizeOfArray-1; i++)

            // Scan Unsorted Array
            for (j = 0; j < sizeOfArray-i-1; j++)

                // If bigger
                if (array[j] > array[j+1])

                    // Swap
                    { temporary = array[j]; array[j] = array[j+1]; array[j+1] = temporary; }
}
