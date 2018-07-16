
// PROTOTYPE
void insertionSort(int *array, int sizeOfArray);


// Insertion Sort
void insertionSort(int *array, int sizeOfArray) {

    int i, grab, sortd;

        // Scan Through Unsorted Array
        for (i = 1; i < sizeOfArray; i++) {

            // Grab value at index 'i'
            grab = array[i];

            // Make place for value at index 'i' in sorted list
            for (sortd = i - 1; sortd >= 0 && array[sortd] > grab; sortd--)

                array[sortd+1] = array[sortd];

            // Insert value at index 'i'
            array[sortd+1] = grab;
        }
}
