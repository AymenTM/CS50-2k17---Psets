
// Program: Search Algorithms.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function Prototypes
int linearSearch(int key, int *array, int sizeOfArray);
int binarySearch(int key, int *array, int sizeOfArray);

int *randomNumberArrayGenerator(int sizeOfArray, int min, int max);
void insertionSort(int *array, int sizeOfArray);


int main() {

    int     key,
            sizeOfArray = 100,
            min = 0,
            max = 100,
            *numberArray = randomNumberArrayGenerator(sizeOfArray, min, max);
            insertionSort(numberArray, sizeOfArray);

    // Get Key
    printf("\nFind: "); scanf(" %i", &key);

    // // Random Array
    // printf("\nRandom Array: --->  "); i = 0; while (i < sizeOfArray - 1 ) { printf("%i, ", numberArray[i]); i++;} printf("%i", numberArray[i]); puts("\n");

    // // Insertion Sort
    // printf("\nArray: --->  "); int i = 0; while (i < sizeOfArray - 1 ) { printf("%i, ", numberArray[i]); i++;} printf("%i", numberArray[i]); puts("");



// Test Algorithms - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    // Binary Search
    (binarySearch(key, numberArray, sizeOfArray) != -1) ? printf("\n'%i' is at index: %i\n\n", key, binarySearch(key, numberArray, sizeOfArray)) : printf("\nKey not found.\n\n");

    // // Linear Search
    // (linearSearch(key, numberArray, sizeOfArray) != -1) ? printf("'%i' is at index: %i\n\n", key, linearSearch(key, numberArray, sizeOfArray)) : printf("Key not found.\n\n");

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    return 0;
}







// LINEAR SEARCH - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


int linearSearch(int key, int *array, int sizeOfArray) {

        // Go through each element of the array
        for (int i = 0; i < sizeOfArray; i++)

            // If key is found
            if (array[i] == key)

                // Return its index
                return i;
        // Else, signal that key was not found
        return -1;
}




// BINARY SEARCH - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


int binarySearch(int key, int *array, int sizeOfArray) {

    // Define starting index (mid array) & Current Number of Elements
    int index = ceil(sizeOfArray * 0.5) - 1, elements = sizeOfArray;

        // While there still are elements to be investigated
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





// Used Functions - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Function: Generates an array of random integers (within a specified range).
int *randomNumberArrayGenerator(int sizeOfArray, int min, int max) {

    int     n,
            *randIntArray = malloc(sizeOfArray);

    // Seed
    srand(time(NULL));

    for (int i = 0; i < sizeOfArray; i++) {
        do { n = rand() % (max + 1); } while (n < min || n > max);
        randIntArray[i] = n;
    }

    return (randIntArray);
}



void insertionSort(int *array, int sizeOfArray) {
    
        for (int i = 1; i < sizeOfArray; i++) {
            int grab = array[i];
            for (int sortd = i - 1; sortd >= 0 && array[sortd] > grab; sortd--) array[sortd+1] = array[sortd];             
            array[sortd+1] = grab;
        }
}
