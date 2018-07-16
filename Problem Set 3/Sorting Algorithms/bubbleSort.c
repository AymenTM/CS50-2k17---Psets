
// PROTOTYPES
void bubbleSort(int *array, int sizeOfArray);
void swap(int *var1, int *var2);


// Bubble Sort
void bubbleSort(int *array, int sizeOfArray) {

    int i, j;

        // Scan 1 less element (from the end of the array) after each scan
        for (i = 0; i < sizeOfArray-1; i++)

            // Scan Unsorted Array
            for (j = 0; j < sizeOfArray-i-1; j++)

                // If bigger
                if (array[j] > array[j+1])

                    // Swap
                    swap(&array[j], &array[j+1]);
}


void bubbleSort(int *array, int sizeOfArray);


// Swaps the Contents of two Variables
void swap(int *var1, int *var2) { int tempory = *var1; *var1 = *var2; *var2 = tempory; }
