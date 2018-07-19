/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include "helpers.h"



// Returns true if value is in array of n values, else false.
// Recursive Binary Search
bool search(int key, int array[], int lowerBound, int upperBound) {

    // While Elements Remain
    while (lowerBound <= upperBound) {

        // Update Middle Index
        int middle = (lowerBound + upperBound) / 2;

        // If Element Matches Key, Return its Index
        if (array[middle] == key) return true;

        // If Element Bigger than Key
        if (array[middle] > key) return search(key, array, lowerBound, middle-1);

        // If Element Smaller than Key
        else return search(key, array, middle+1, upperBound);

    }

    // Key was not found
    return false;
}



// Sorts array of n values.
// Insertion Sort
void sort(int *array, int sizeOfArray) {

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