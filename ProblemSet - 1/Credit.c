/*

Program: determines whether a provided credit card number is valid according to Luhn’s algorithm.

Description: given a credit card number, using Luhn's Algorithm, checks whether or not a credit card
number is valid. If valid determines what type of credit card number it is and outputs its type
(AMEX, Mastercard, Visa). If not valid, outputs "INVALID".

*/


#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
bool isnum(string s);
int citoi(char c);

int main(void) {



        // Get Credit Card Number
        string ccNumber;
        ccNumber = get_string("\nNumber: ");
        int len = strlen(ccNumber);

        // Make sure it's a numbers only string
        while (isnum(ccNumber) == false) {
            ccNumber = get_string("\nNumber: ");
        }





        // Check what type of credit card it is or if even a credit card
        string ctype = NULL;

        if (ccNumber[0] == '3' && len == 15) {
                ctype = "AMEX";
        }

        else if (ccNumber[0] == '5' && len == 16) {
                ctype = "MASTERCARD";
        }

        else if (ccNumber[0] == '4') {

                if (len == 13 || len == 16) {
                    ctype = "VISA";
                }

                else {
                    printf("INVALID\n\n");
                    return 1;
                }
        }

        else {
               printf("INVALID\n\n");
               return 1;
        }




        // Luhn's Algorithm

// First SUM - - - - - - - - -

        int sumBuf;
        int sum0 = 0;

        for (int i = 1; i < len ; i = i + 2) {

            sumBuf = citoi(ccNumber[i]) * 2;

            if (sumBuf >= 10) {

                int q = sumBuf / 10;
                int r = sumBuf % 10;

                sum0 = sum0 + q + r;
            }

            else if (sumBuf < 10) {

                sum0 = sum0 + sumBuf;
            }

        }

// Second SUM - - - - - - - - -

        int sumBuffer1;
        int sum1 = 0;

        for (int i = 0; i < len ; i = i + 2) {

            sumBuffer1 = citoi(ccNumber[i]);
            sum1 = sum1 + sumBuffer1;

        }

// Total SUM - - - - - - - - -

        int totMod10 = (sum0 + sum1) % 10;
        
// Return Card Type - - - - - - - - -

        if (totMod10 == 0) {
            printf("%s\n\n", ctype);
        }

        else {
            printf("INVALID\n\n");
        }
}



// Function: Checks if a string is entirely made up of ONLY numbers
bool isnum(string s) {

    int len = strlen(s);

    for (int i = 0; i < len; i++) {

        if (isdigit(s[i]) == false) {
            return false;
        }
    }

    return true;
}


// Function: Converts individual int characters into int datatype
int citoi(char c) {

    int answer = c - '0';
    return answer;
}
