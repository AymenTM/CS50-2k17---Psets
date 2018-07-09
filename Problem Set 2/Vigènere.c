/*

Program: Encryption using Vigenère's Cipher Technique.

Description: given a key 'argv', will cipher a given plaintext and output ciphertext
             per Vigenère's cipher technique.

De-cipherer Program: ~cs50/pset2/devigenere k

Website: https://docs.cs50.net/problems/vigenere/vigenere.html

*/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[]) {


                // Wrong Usage --> Error
                if (argc == 1 || argc > 2) {

                    printf("\nERROR - Usage: ./vigenere k\n\n");
                }



                else {

                   // Checks to see if argv[1] is ONLY alphabetic or not
                   string t = argv[1];

                   for (int b = 0; b < strlen(t); b++) {

                        if (isalpha(t[b]) == false) {

                            printf("\nERROR - Usage: ./vigenere k\n\n");
                            return 1;
                        }
                   }


                    // Correct Usage
                    string k = argv[1];
                    int lenk = strlen(k);
                    string p = get_string("\nPlaintext: ");
                    int lenp = strlen(p);
                    int s[lenk];

                    // Mapping each char of string 'k' to corresponding int per vigenere's ciper:
                    for (int ki = 0; ki < lenk; ki++) {

                        if (isupper(k[ki]) == false) {

                            s[ki] = k[ki] - 97;

                        }

                        else if (islower(k[ki]) == false) {

                            s[ki] = k[ki] - 65;

                        }

                    }


// Encryption Key Preview - - - - - - - - - - - - - - - -

                    // printf("\nKey: %i", s[0]);

                    // for (int pri = 1; pri < lenk; pri++) {

                    //     printf(" - %i", s[pri]);

                    // }

                    // printf("\n\n");

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -


                    //Encryption
                    int si = 0;

                    for (int i = 0; i < lenp; i++) {

                        // Not Alphabetic Chars
                        if (isalpha(p[i]) == false) {

                            p[i] = p[i];

                        }

                        // Alphabetic Chars
                        else {

                            // Min. Alpha Exception
                            if (isupper(p[i]) == false && p[i] + s[si % lenk] > 122) {

                                p[i] = 96 + ((p[i] + s[si % lenk]) - 122);

                            }

                            // Cap. Alpha Exception
                            else if (islower(p[i]) == false && p[i] + s[si % lenk] > 90) {

                                p[i] = 64 + ((p[i] + s[si % lenk]) - 90);

                            }

                            else {

                                p[i] = p[i] + s[si % lenk];

                            }

                            si++;

                        }

                    }


                    // Display Ciphertext
                    printf("Ciphertext: %s\n\n", p);

                }

}
