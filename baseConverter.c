

// Program: Converters any given number (decimal) into any given base.

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#include <stdio.h>

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// DEPENDENCIES: putchar
// Display/Prints Inputted String
void ft_putstr(char *str) { for (int i = 0; str[i]; i++) putchar(str[i]); return; }

// Returns the inputted string in reverse
char *ft_strrev(char *str) {

    // If pointer points to NULL
    if (!str) return NULL;

    // Get Length of String
    int length = 0; for (int i = 0; str[i] != '\0'; i++) length++;

    // Case: length is 1
    if (length <= 1) return str;

    // Make a copy of the string (of same length)
    char strCpy[length];
    for (int i = 0; str[i] != '\0'; i++) strCpy[i] = str[i];

    // Reverse the String
    str[length] = '\0';
    for (int i = 0; str[i] != '\0'; i++) { str[length-1] = strCpy[i]; length--; }

    return str;
}

// Returns number of characters in string
int ft_strlen(char *str) { size_t len; for (len = 0; *str; len++, str++) {} return len; }

// Checks if character is a digit
int ft_is_digit(int c) { if ((c >= '0' && c <= '9')) return 1; return 0; }

// Prints inputted integer
void ft_putnbr(int nb) {

    // Case: Negative Numbers
    if (nb < 0) { nb = -nb; putchar('-'); }

    // Break down the integer till we get to the ones place
	if (nb >= 10) ft_putnbr(nb / 10);

    // Print current digit & Return to previous call
	putchar(nb % 10 + '0');
}

// Convert a string to an integer
int ft_atoi(char *str) {

    // Counter & something to keep track of negatives
    int	i = 0, sign = 1;

    // Case: number is huge
    long long rtrnVal = 0;

    // Skip over any of these characters
    while (str[i] == ' '    ||   str[i] == '\v'   ||   str[i] == '\t'   ||
           str[i] == '\r'   ||   str[i] == '\f'   ||   str[i] == '\n'   ||
           str[i] == '\a'   ||   str[i] == '\b'   ||   str[i] == '+') i++;

    // Case: Number is Negative
	if (str[i] == '-') { sign = -1; i++; }

    // While characters are digits
	while (str[i] >= '0' && str[i] <= '9') {

        // Move the current digit(s) to the left & Insert new digit in ones column
		rtrnVal = rtrnVal*10 + str[i] - '0';
		i++;
	}

	return sign*rtrnVal;
}

// Returns 'n' to the power 'p'
long long ft_pwr(int nb, int power) {

    // Case: power is lower than 0
    if (power < 0) return 0;

    // Case: power is 0
    if (!power) return 1;

    // Case: power is 1
    if (power == 1) return nb;

    int sign = 1;

    // Case: int is negative
    if (nb < 0) { nb = -nb; sign = -1; }

    // nbˆ1
    long long returnValue = nb;

    // Calculate rest of the powers
    for (int i = 1; i < power; i++) returnValue *= nb;

    return sign * returnValue;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Returns the bit string represention of given int/char
char *ft_dec2bin(int n, char *buf) {

    // Case: 'buf' is null pointer
    if (!buf) return NULL;

    // Case: int is 0
    if (!n) { buf[0] = '0'; buf[1] = '\0'; return buf; }

    // Counter
    int i;

    // As long as 'n' > 0  &&  as long as we still have room in the string; do the following...

    /*In effect we are grabbing the binary representation of 'nbr', 1 bit at a time, from right to left (i.e in order), (till
    there is no more bits to grab (i.e 'nbr' is now = to 0), OR till there is no more memory space to store more bits); and
    storing it in our string from left to right (i.e in reverse order)

    Btw why hardcode 32 ? because in this function that we're doing we know its an int (i.e 4 bytes, 32 bits); we could of
    made the function ask as parameter buf_size and had that -1 (for the '\0') instead of 32, that would generalize it to
    whatever is needed */
    for (i = 0; n && i < 32; i++) {

    /*  1#  Grab the right most bit from 'nbr' (i.e the string of bits that represent 'nbr' --> (110101000101))..
                                                                                                           ˆ
        2#  and store it's literal value (i.e the actual integer by doing + '0') in our string at whatever index
            our pointer currently points to
        3#  Finally after that operation, increment index at which pointer points to by 1                         */
        buf[i] = (n & 1) + '0';


    /*  Shift 'nbr's string of bits by 1 to the right i.e going from --> 110101000101 --> to ---> 011010100010
                                                                                       ˆ                        ˆ
        notice how we added a 0 to the beginning of the bit string and got rid of the 1 that was at the end of it */
        n >>= 1;
    }

    // Null terminate the string because we're done with representing the integer and don't want any extra values
    buf[i] = '\0';

    // Finally we reverse the bit string to get it in order; & we return it
    return ft_strrev(buf);

    /* Also a great advantage of this is that this function works as well with positives as it does
       with negatives.

       Also we don't have to worry about any sort of different bit-size representation differences; we start off
       at 32 bits and only keep as much as we need (we cut off the rest by null terminating at the index we finished)
       off at.

       Also to note we don't have to worry about any two's complementing, binary arithmetic or
       anything... */
}

// Assuming string will be a base radix; parses string and returns the radix
int parse_baseRadix(char *base) {

    // Check for correct usage (i.e a valid 'base' argument) (check if string is valid)

    // Check if 'base' is empty, more than 2 or less than 1 chars in length
    if ( !base || ft_strlen(base) < 1 || ft_strlen(base) > 2) return 0;

    // Check if 'base' consists of only numerical chars
    for (int i = 0; base[i]; i++) if (!ft_is_digit(base[i])) return 0;

    int radix = ft_atoi(base);

    // Check if the base is <= 1
    if (radix <= 1) return 0;

    // Now we know for sure that 'base' is 2 digits, that are equal more than 1, we can...
    // Return the radix
    return radix;
}

// LogN(n) for ints; not precise if answer has decimals
int ft_aproxLogN(long long nbr, int N) {

    int i; long long sum = 0;

    for (i = 0; sum < nbr-1; i++) sum += ft_pwr(N, i);

    return i;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Displays number in any given base
void ft_putnbr_base(int nbr, char *base) {

    // Get radix if correct; Else return nothing
    int radix = parse_baseRadix(base); if (!radix) return;

    // Will take care of all bases except 2, 8, 16 (we'll let the 2nd function take care of those);
    // Works only for positives (as in it will only put a '-' neg_sign for negatives)
    if (radix != 2 && radix != 8 && radix != 16) {

        // To deal with negatives
        int sign = 0; if (nbr < 0) { nbr = -nbr; sign = 1; }

        // Int holder for the remainder
        int i, rmndr = 0;

        // String of size 'what ever amount of bits we need in that base to rep. INT_MAX; +1 to round up; +1 for '\0' char'
        char baseRep[ft_aproxLogN(2147483647, radix)+2];

        for (i = 0; nbr; i++) {

            rmndr = nbr % radix;
            nbr = nbr / radix;

            if (rmndr < 10) baseRep[i] = rmndr + '0';
            else baseRep[i] = (rmndr + '7');

        } baseRep[i] = '\0';

        if (sign) putchar('-'); ft_putstr(ft_strrev(baseRep)); }

    // Deals with bases 2, 8, 16 in both positives and negatives (uses two's complement)
    else {

        // String to store the binary representation of 'nbr'
        char bitString[33]; bitString[32] = '\0';

        // Calculate how many bits we need to represent ('base' - 1) (y? because thats the max we can rep in base 'base') in base 'base'
        int bitsNeeded = ft_aproxLogN(radix, 2), buf_size = ft_aproxLogN(2147483647, radix)+2;

        // Calculate how many bits/digits we need to represent the biggest int in base 'base'
        char baseStr[buf_size]; baseStr[buf_size-1] = '\0';

        // Counters, Holder & Len (converts the number to binary represenation and stores it in a string and then gets len of it -1)
        int i, indx = 0, sum, len = ft_strlen(ft_dec2bin(nbr, bitString)) - 1;

        while (len >= 0) { sum = 0;

            // For every 'bitNeeded' elements of bitString do ...; till we finish iterating through the entire bitstring
            for (i = 0; i < bitsNeeded && len >= 0; i++, len--) {

                // Sum up the the bits (from binary) to decimal
                if (bitString[len] == '1') sum += ft_pwr(2, i);
            }

            // Store value in baseString (accordingly)
            if (sum >= 10) {
                    baseStr[indx] = (sum + '7'); indx++; }
            else {
                baseStr[indx] = (sum + '0'); indx++; }
        }

        // Terminate string when done
        baseStr[indx] = '\0';

        // It's in reverse order so reverse it and return it
        ft_putstr(ft_strrev(baseStr)); }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Main
int main(void) {

    int n; printf("Int: "); scanf(" %i", &n); fflush(stdin);
    char b[3]; printf("Base: "); scanf(" %s", b); fflush(stdin);
    ft_putnbr_base(n, b); printf("\n");


    // printf("\n- - - - - - - \nPositives:\n\n");
    // ft_putnbr_base(n, "2"); printf("\n");
    // ft_putnbr_base(n, "8"); printf("\n");
    // ft_putnbr_base(n, "10"); printf("\n");
    // ft_putnbr_base(n, "16");
    //
    // printf("\n\n- - - - - - - \nNegatives:\n\n");
    // ft_putnbr_base(-n, "2"); printf("\n");
    // ft_putnbr_base(-n, "8"); printf("\n");
    // ft_putnbr_base(-n, "10"); printf("\n");
    // ft_putnbr_base(-n, "16"); printf("\n\n");


// // - - - - - - - - - - - -
//
//
//     char bin[33]; bin[32] = '\0';
//     char bin1[33]; bin[32] = '\0';
//
//
//
//     printf("\n- - - - - - - \nBinary:\n\n");
//
//         if (n > 0) { ft_dec2bin(n, bin); printf("%i: %s\n", n, bin); }
//         else { ft_dec2bin(n, bin1); printf("%i: %s\n", n, bin1); }
//         ft_dec2bin(-n, bin1); printf("%i: %s\n\n", -n, bin1);
//
//         printf("Your %i: ", n); ft_putnbr_base(n, "2"); printf("\n");
//         printf("Your %i: ", -n); ft_putnbr_base(-n, "2"); printf("\n\n");
//
// // - - - - - - - - - - - -
//
//     printf("\n- - - - - - - \nDecimal:\n\n");
//
//         if (n < 0) printf("%i: %i\n", -n, n);
//         else printf("%i: %i\n", n, n);
//         printf("%i: %i\n\n", -n, -n);
//
//         printf("Your %i: ", n); ft_putnbr_base(n, "10"); printf("\n");
//         printf("Your %i: ", -n); ft_putnbr_base(-n, "10"); printf("\n\n");
//
// // - - - - - - - - - - - -
//
//     printf("\n- - - - - - - \nOctal:\n\n");
//
//         if (n < 0) printf("%i: %o\n", -n, n);
//         else printf("%i: %o\n", n, n);
//         printf("%i: %o\n\n", -n, -n);
//
//         printf("Your %i: ", n); ft_putnbr_base(n, "8"); printf("\n");
//         printf("Your %i: ", -n); ft_putnbr_base(-n, "8"); printf("\n\n");
//
// // - - - - - - - - - - - -
//
//     printf("\n- - - - - - - \nHexa:\n\n");
//
//         if (n < 0) printf("%i: %x\n", -n, n);
//         else printf("%i: %x\n", n, n);
//         printf("%i: %x\n\n", -n, -n);
//
//         printf("Your %i: ", n); ft_putnbr_base(n, "16"); printf("\n");
//         printf("Your %i: ", -n); ft_putnbr_base(-n, "16"); printf("\n\n");
//
// // - - - - - - - - - - - -

    return 0;

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

NOTE(s):

We are using two's complement to get our negative values.

An int is 32-bits (i.e 4 bytes) so the array to hold the Ri's is at most 32 in length.



        Example: 76 (base 10) to base 3:


                             2 2 1 1 (base 3)
                             ^ ^ ^ ^
                             | | | |
                   0 rem 2 --+ | | |
                 ----          | | |
               3 ) 2 rem 2 ----+ | |
                -----            | |
              3 )  8 rem 1 ------+ |
               ------              |
             3 )  25 rem 1 --------+
              -------
            3 )   76 (base 10)







There are two ways (that i know of) to go from BASE(10) (decimal) to any base:
Video: https://www.youtube.com/watch?v=-PI7ZX3UiXA


    –––––––––––– MINUTE 5:34 ––––––––––––––––

    #1: ex:    209 (base 10) =  21202 (base 3)

        // Get the lowest power of 'base' that is greater than 'number'
        while (powr(3, i) < 209) i++;  -->   i = 4

        // Iteratively or Recursively Implement this

        r1 = number;

        R1 = r1 / 3ˆi = 2
         r2 = 47                        (remainder)
            i = i - 1;   (i.e 3)

        R2 = r2 / 3ˆi = 1
         r3 = 20                        (remainder)
            i = i - 1;   (i.e 2)

        R3 = r3 / 3ˆi = 2
         r4 = 2                         (remainder)
            i = i - 1;   (i.e 1)

        R4 = r4 / 3ˆi = 0
         r5 = 2                         (remainder)
            i = i - 1;   (i.e 0)

        R5 = r5 / 3ˆi = 2
         r6 = 0                         (remainder)
            i = i - 1;   (i.e -1) (we're done)


        Visual Representation:
        ==========================================
        |                                        |
        |     R1     R2     R3     R4     R5     |
        |    -----  -----  -----  -----  -----   |
        |     3ˆ4    3ˆ3    3ˆ2    3ˆ1    3ˆ0    |
        |     81     27      9      3      1     |
        |                                        |
        ==========================================



    –––––––––––– MINUTE 7:50 ––––––––––––––––

    #2:      209 (base 10) =  21202 (base 3)


             3 |
               | 209    R5 = 2  (remainder)
               |_______
               3 |
                 |  69    R4 = 0  (remainder)
                 |_______
                   3 |
                     |  23    R3 = 2  (remainder)
                     |_______
                       3 |
                         |  7     R2 = 1  (remainder)
                         |_______
                           3 |
                             |  2     R1 = 2  (remainder)
                             |_______
                               3 |
                                 |  0     --->   0 ! so we're done
                                 |_______



                                 Visual Representation: (reverse of #1)
                                 ==========================================
                                 |                                        |
                                 |     R5     R4     R3     R2     R1     |
                                 |    -----  -----  -----  -----  -----   |
                                 |     3ˆ0    3ˆ1    3ˆ2    3ˆ3    3ˆ4    |
                                 |      1      3      9      27     81    |
                                 |                                        |
                                 ==========================================
                                 Then you would ofc reverse the order of Ri's
                                 (the sequence)




         Last Step:

         Map the Ri's to their representations
         (same as decimal if under 10, else you
         know 10, 11, 12, 13, 14, 15... is
         ABCDEF... and so on)

         Et VOILA !







    int2bin function taken from:
        ---> https://stackoverflow.com/questions/1024389/print-an-int-in-binary-representation-using-c
        ---> answer 1 - Adam Markowitz






        ARCHIVE:


====================================================================================================================
+++++++++++++++++++++++ WORKS FOR NEGATIVES & POSITIVES BUT ONLY WORKS FOR BASES 2, 8, 10, 16 ++++++++++++++++++++++
====================================================================================================================


            // If 'base' is 10 (decimal)
            if (radix == 10) { ft_putnbr(nbr); return; }

            // String to store the binary representation of 'nbr'
            char bitString[33]; bitString[32] = '\0';

            // If 'base' is 2 (binary); return the bit string of 'nbr'
            if (radix == 2) ft_putstr(ft_dec2bin(nbr, bitString));

            // If 'base' is 8 (octal)
            if (radix == 8) {

                int i, o = 0, sum = 0, len = ft_strlen(ft_dec2bin(nbr, bitString)) - 1; // -1 cuz its going to be used as
                char octStr[12];                                                                an index so starts from 0


                while (len >= 0) { sum = 0;

                    for (i = 0; i < 3 && len >= 0; i++, len--) {

                        if (bitString[len] == '1') sum += ft_pwr(2, i);
                    } octStr[o] = (sum + '0'); o++;
                } octStr[o] = '\0';

                // Print/Display octal representation
                ft_putstr(ft_strrev(octStr));
            }

            // If 'base' is 16 (hexadecimal)
            if (radix == 16) {

                int i, x = 0, sum = 0, len = ft_strlen(ft_dec2bin(nbr, bitString)) - 1;
                char hexStr[9];

                while (len >= 0) { sum = 0;

                    for (i = 0; i < 4 && len >= 0; i++, len--) {

                        if (bitString[len] == '1') sum += ft_pwr(2, i);
                    }

                    if (sum < 10) { hexStr[x] = (sum + '0'); x++; }
                    else { hexStr[x] = (sum + '7'); x++; }
                } hexStr[x] = '\0';

                // Print/Display hexadecimal representation
                ft_putstr(ft_strrev(hexStr));
            }













====================================================================================================================
+++++++++++++++++++++++++++++++++++ WORKS FOR ALL BASES BUT, ONLY FOR POSITIVES ++++++++++++++++++++++++++++++++++++
====================================================================================================================


                // To deal with negatives
                int sign = 0; if (nbr < 0) sign = 1;

                // Int holder for the remainder
                int i, rmndr = 0;

                // String of size 'what ever amount of bits we need in that base to rep. INT_MAX; +1 to round up; +1 for '\0' char'
                char baseRep[ft_aproxLogN(2147483647, radix)+2];

                for (i = 0; nbr; i++) {

                    rmndr = nbr % radix;
                    nbr = nbr / radix;

                    if (rmndr < 10) baseRep[i] = rmndr + '0';
                    else baseRep[i] = (rmndr + '7');

                } baseRep[i] = '\0';

                 // What we're doing:
                 //
                 //    Example: 76 (base 10) to base 3:
                 //
                 //
                 //                         2 2 1 1 (base 3)
                 //                         ^ ^ ^ ^
                 //                         | | | |
                 //               0 rem 2 --+ | | |
                 //             ----          | | |
                 //           3 ) 2 rem 2 ----+ | |
                 //            -----            | |
                 //          3 )  8 rem 1 ------+ |
                 //           ------              |
                 //         3 )  25 rem 1 --------+
                 //          -------
                 //        3 )   76 (base 10)



                // Representation in the string is currently in reverse order; so we'll reverse it to get it in order & then..
                // Print/Display it
                if (sign) putchar('-'); ft_putstr(ft_strrev(baseRep));












====================================================================================================================
+++++++++++++++++++++++++++++++++++++++++++ ATTEMPT OF 1 THAT WORKS FOR ALL ++++++++++++++++++++++++++++++++++++++++
====================================================================================================================



                // Checksum - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

                    int sum1 = 0, rmndr;

                    // Sum up the baseStr (from base 'base') to decimal
                    for (i = 0; i < indx; i++) {
                        if (baseStr[i] != '0')
                            sum1 += ft_pwr(radix, i) * (baseStr[i] - '0');
                    }

                    // If Correct; Return it
                    if (sum1 == nbr) { ft_putstr(ft_strrev(baseStr)); return; }

                    // Correct it (accordingly); then Return it
                    else {

                        // // Get rid of the '\0' character
                        // baseStr[indx] = '0';

                        // Find how much is missing
                        sum1 = nbr - sum1;

                        // Find at what column to start distributing 'sum1'
                        for (i = 0; sum1 > ft_pwr(radix, i); i++) {}




                        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

                        The problem is that with bases not powers of 2, sometimes
                        the number is off by some range, it's because we take 'x'
                        bits and with those 'x' bits we can represent upto whatever
                        the 'base' is but also more, so sometimes a bit is turned on
                        when it should be off making a difference at the end in the
                        result gotten. Here we try to correct that off balance by
                        getting the differnce between 'nbr' the number we are supposed
                        to output the representation of and the number we currently
                        got with the off balance that we have. So far with this code
                        we have the difference between the actual 'nbr' and the one
                        we generate. Also we have the index at which to start; we
                        need to redistribute correctly among the columns the difference
                        between 'nbr' and the number we've currently obtained.

                        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


                        // NEEDS FIXING !!!!!
                        // // Divide and distribute to correct columns
                        // while (sum1) {
                        //
                        //     rmndr = sum1 % ft_pwr(radix, i);
                        //     sum1 = sum1 /  ft_pwr(radix, i);
                        //
                        //     baseStr[i] += sum1;
                        // }


                        // NEEDS FIXING !!!!!
                        // int fals = 1;
                        // while (fals) { fals = 0;
                        //
                        //     for (int k = 0; k < indx+1; k++) {
                        //
                        //         if (baseStr[k] - '0' == ft_pwr(radix, k+1)) {
                        //
                        //             baseStr[i] = '0';
                        //             baseStr[i+1]++;
                        //             fals = 1;
                        //         }
                        //     }
                        // }

                        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


                        // Terminate the string
                        baseStr[indx] = '\0';
                    }


*/
