// Program that prints out a double half-pyramid of a specified height. 

// ---> Mario (More Comfortable)

#include <cs50.h>
#include <stdio.h>

int main(void)

{

// 1) Intro --------------------------------------------------------------------- 1

    printf("\nHi there, let's build two half pyramids.\n\n");



// 2) Prompt for Height --------------------------------------------------------- 2

    int h, l, space, hash, space1, hash1;

    do
    {
        h = get_int("Pick a height between [0-23]\n: ");
    }
    while (h < 0 || h > 23);

    printf("\n");



// 3) Print Pyramid ------------------------------------------------------------- 3


    // Prints a line
    for (l = 1; l <= h; l++)
    {

        // Prints " "
        for (space = l; space < h; space++)
        {
            printf(" ");
        }

        // Prints "#"
        for (hash = 0; hash < l; hash++)
        {
            printf("#");
        }

        // Prints " " n.2
        for (space1 = 2; space1 > 0; space1--)
        {
            printf(" ");
        }

        // Prints "#" n.2
        for (hash1 = 0; hash1 < l; hash1++)
        {
            printf("#");
        }

        printf("\n");

    }

    printf("\n\nEt Voila !\n");
}
