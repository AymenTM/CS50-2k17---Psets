
// Program: Sorting algorithms.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void bubbleSort(int *array, int sizeOfArray);
void selectionSort(int *array, int sizeOfArray);
void insertionSort(int *numberArray, int sizeOfArray);
// void mergeSort(int *numberArray, int sizeOfArray);
// void quickSort(int *numberArray, int sizeOfArray);

void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int *randomNumberArrayGenerator(int sizeOfArray, int min, int max);
void swap(int *smaller, int *bigger);


int main() {

// Get an Array to work with - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Specifications for the Array
    int     i,
            sizeOfArray = 10,
            min = 0,
            max = 9,
            *numberArray = randomNumberArrayGenerator(sizeOfArray, min, max);

    // Random Array
    printf("\nRandom Array: --->  "); i = 0; while (i < sizeOfArray - 1 ) { printf("%i, ", numberArray[i]); i++;} printf("%i", numberArray[i]); puts("");



// Print Sorted Arrays - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // // Quick Sort
    // quickSort(numberArray, 0, sizeOfArray);
    // printf("\nQuick Sort: --->  "); i = 0; while (i < sizeOfArray - 1 ) { printf("%i, ", numberArray[i]); i++;} printf("%i", numberArray[i]); puts("");

    // // Merge Sort
    // mergeSort(numberArray, 0, sizeOfArray);
    // printf("\nMerge Sort: --->  "); i = 0; while (i < sizeOfArray - 1 ) { printf("%i, ", numberArray[i]); i++;} printf("%i", numberArray[i]); puts("");

    // // Insertion Sort
    // insertionSort(numberArray, sizeOfArray);
    // printf("\nInsertion Sort: --->  "); i = 0; while (i < sizeOfArray - 1 ) { printf("%i, ", numberArray[i]); i++;} printf("%i", numberArray[i]); puts("");

    // // Selection Sort
    // selectionSort(numberArray, sizeOfArray);
    // printf("\nSelection Sort: --->  "); i = 0; while (i < sizeOfArray - 1 ) { printf("%i, ", numberArray[i]); i++;} printf("%i", numberArray[i]); puts("");

    // // Bubble Sort
    // bubbleSort(numberArray, sizeOfArray);
    // printf("\nBubble Sort: --->  "); i = 0; while (i < sizeOfArray - 1 ) { printf("%i, ", numberArray[i]); i++;} printf("%i", numberArray[i]); puts("");

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    puts("");
    return 0;
}






// QUICK SORT - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #1


// // Function: Implements Quicksort.
// void quickSort(int *array, int sizeOfArray) {

//     TODO
// }


/* This function takes last element as pivot, places
  the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
  to left of pivot and all greater elements to right
  of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
          at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}




// MERGE SORT - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #2


// // Function: Implements merge sort.
// void mergeSort(int *array, int sizeOfArray) {

//     TODO
// }



void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
      are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
      are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
  sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}




// INSERTION SORT - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #3


// Function: Implements insertion sort.
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




// SELECTION SORT - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #4


// // Function: Implements selection sort to sort an inputted array of ints.
void selectionSort(int *array, int sizeOfArray) {

    int i, startIndex = 0, currentSmallest;

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
            swap(&array[startIndex], &array[currentSmallest]);
        }
}




// BUBBLE SORT - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #5


// Function: Implements bubble sort to sort an inputted array of ints.
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




// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - n/a


// Function: Swaps the contents of two variables
void swap(int *smaller, int *bigger) { int temp = *smaller; *smaller = *bigger; *bigger = temp; }



// Function: Generates an array of random integers (within a specified range).
int *randomNumberArrayGenerator(int sizeOfArray, int min, int max) {

    int     n,
            *randIntArray = malloc(sizeOfArray);

    // Seed
    srand(time(NULL));

    // Generates Random Integer & Stores it in Array
    for (int i = 0; i < sizeOfArray; i++) {

        do { n = rand() % (max + 1); } while (n < min || n > max);
        randIntArray[i] = n;
    }

    return (randIntArray);
}
