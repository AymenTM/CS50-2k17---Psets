
// PROTOTYPE
int linearSearch(int key, int *array, int sizeOfArray);


// Linear Search
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
