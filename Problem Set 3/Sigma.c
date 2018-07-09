/*

Program: Returns sum of 1 through n.

Description: Adds up all the numbers from 1 to the number provided as input

*/


#include <cs50.h>
#include <stdio.h>

// Prototype
int sigma(int n);


#define MAX 65535

int main(void) {

            int n;

            do {
                n = get_int("\nPositive Integer (between 1-50,000): ");
            } while (n < 1 || n > MAX);

            int answer = sigma(n);
            printf("\nSum: %i\n\n", answer);

}


// Implementation of a function that uses recursion.
int sigma(int num) {

    if (num < 1) {

        return 0;
    }

    else if (num > 1 || num < MAX) {

        return (num + sigma(num-1));   // EQUIV. BUT MORE SUSYNCED THAN: sum = n + sigma(n-1); \n return sum;
    }

}
