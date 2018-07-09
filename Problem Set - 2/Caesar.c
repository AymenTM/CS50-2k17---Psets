/*

Program: Encryption w/ Caesar's Cipher Technique.

Description: given a key 'argv[1]', will cipher a given plaintext and output
             ciphertext per Caesar's cipher technique.

Website: https://docs.cs50.net/problems/caesar/caesar.html

*/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) {

            // Wrong Usage
            if (argc == 1)
                {
                    printf("\nUsage: ./caesar k.\n\n1\n\n");
                }

            else if (argc > 2)
                {
                    printf("\n\nUsage: ./caesar k.\n\n1\n\n");
                }

            // Correct Usage
            else
                {

                    int k = atoi(argv[1]);
                    int r = k % 26;
                    string p = get_string("Plaintext: ");
                    int lenp = strlen(p);


                    // Encryption:
                    for (int i = 0; i < lenp; i++) {


                        // Not Alphabetic Chars
                        if (isalpha(p[i]) == false) {

                            p[i] = p[i];

                        }


                        // Alphabetic Chars
                        else {


                            // Cap. Letters
                            if (islower(p[i]) == false) {

                                if ((p[i] + r) > 90) {

                                    p[i] = 64 + (p[i] + r - 90);

                                }


                                else {

                                    p[i] = p[i] + r;

                                }

                            }

                            // Min. Letters
                            else if (isupper(p[i]) == false) {

                                if ((p[i] + r) > 122) {

                                    p[i] = 96 + (p[i] + r - 122);

                                }

                                else {

                                p[i] = p[i] + r;

                                }

                            }

                        }

                    }

            // Output Ciphertext
            printf("Ciphertext: %s \n\n", p);

            }
}
