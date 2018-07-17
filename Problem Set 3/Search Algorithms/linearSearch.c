
// PROTOTYPE
int linearSearch(int key, int *array, int sizeOfArray);


// LINEAR SEARCH - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


int linearSearch(int key, int *array, int sizeOfArray) {

    int i;

        for (i = 0; i < sizeOfArray; i++)

            if (array[i] == key)

                return i;

        return -1;
}
