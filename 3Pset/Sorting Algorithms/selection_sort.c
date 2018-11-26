
// PROTOTYPE
void selectionSort(int *array, int sizeOfArray);


// Selection Sort
void selectionSort(int *array, int arraySize) {

    int i, strtInd, curSmlst, temp;

        // Increment the index at which we start by 1 After Each Sort
        for (strtInd = 0; strtInd < arraySize - 1; strtInd++) {

            // Store the Index of the Current Smallest Value
            curSmlst = strtInd;

            // Scan Unsorted Array
            for (i = strtInd; i < arraySize; i++) {

                // If a smaller Value is Found
                if (array[i] < array[curSmlst])

                    // Keep track of its index
                    curSmlst = i;
            }

            // Swap the smallest value found with whatever is at the Start Index
            temp = array[strtInd];
            array[strtInd] = array[curSmlst];
            array[curSmlst] = temp;
        }
}
