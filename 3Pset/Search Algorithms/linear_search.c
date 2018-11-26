
// PROTOTYPE
int linearSearch(int key, int *array, int sizeOfArray);


// Linear Search
int linearSearch(int key, int *array, int sizeOfArray) {
        
        // Go through each element of the array individually
        for (int i = 0; i < sizeOfArray; i++) 
            
            // Check if element matches key
            if (array[i] == key)
            
                // If so return its index
                return i;
        
        // Else, signal that key was not found
        return -1;
}
