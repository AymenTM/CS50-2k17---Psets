/*

Program: Given ANY name, will store and print out its initials.

--> Initials (More Comfortable)

Website: https://docs.cs50.net/problems/initials/more/initials.html

*/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {

    string name = get_string("\nFull Name: ");
    int c = 0;
    int iniCount = 0;
    char initials[5];
    printf("\nInitials: ---> ");

    // First Initial
    while (isalpha(name[c]) == false) {

        c++;

    }

    initials[iniCount] = name[c];
    iniCount++;


    // Rest of the Initials
    for (int i = c; i < strlen(name); i++) {

        if (isalpha(name[i]) == false)  {

            while (isalpha(name[i]) == false) {

                i++;

            }

            initials[iniCount] = name[i];
            iniCount++;

        }

    }

    initials[iniCount] = '\0';

    printf("\n\n%s\n\n", initials);

}
