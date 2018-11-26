/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    /* If user inputs a number of arguments that is at the same time <2 AND >3,
       print string notifying user of the correct usage and return '1' signaling an error. */
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Convert the 2nd string argument into an integer
    int n = atoi(argv[1]);

    /* In the eventual case that user enters 3 arguments, call the 'srand48'
       function w/ the 3rd command line argument as argument for the srand48
       function. */
    if (argc == 3) {

        srand48((long int) atoi(argv[2]));
    }

    else {

        srand48((long int) time(NULL));
    }

    /* As long as i < n ('n' being the 2nd command line argument inputted by user), print
       the integer that the function drand48 returns multiplied by 'LIMIT' (65536). */
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
