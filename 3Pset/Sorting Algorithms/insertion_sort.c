
// PROTOTYPE
void insertionSort(int *array, int sizeOfArray);


// Insertion Sort
void insertionSort(int *array, int sizeOfArray) {

    int i, grab, sortd;

        // Scan Through Unsorted Array
        for (i = 1; i < sizeOfArray; i++) {

            // Grab element at index 'i'
            grab = array[i];

            // Make place for it in sorted list; move everything by one to the right
            for (sortd = i - 1; sortd >= 0 && array[sortd] > grab; sortd--) array[sortd+1] = array[sortd];

            // Insert element in its rightful place
            array[sortd+1] = grab;
        }
}
