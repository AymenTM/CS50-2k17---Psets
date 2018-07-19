/*

---> "Frequency" is one of the helper functions that were asked to be done, i just made it a program unto itself.

Program: Calculates frequency (in Hz) of a (musical) note.

Description: Takes as input a string a note (e.g., A4) and returns its corresponding
             frequency as an int (in hertz).

             In this program we assume that the note will only be passed as a string
             formatted as such: XY or XMY, whereby X is the letter of the note, M is
             an occasional accidental and Y is the octave number.
             
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void) {

    string s = get_string("\nNote: ");


// - - - - - - - - - - - - - - - - - - - -

        float    note = 0.0,
                  oct = 0.0,
                    n = 0.0;


// Converting the string 'note' into simply 'n' (i.e how far the note is from A4)

            // Note.Octave
            if (strlen(s) == 2) {

                if (s[0] == 'A') {                                       // A
                    note = 0.0;
                }

                else if (s[0] == 'B') {                                  // B
                    note = 2.0;
                }

                else if (s[0] == 'C') {                                  // C
                    note = -9.0;
                }

                else if (s[0] == 'D') {                                  // D
                    note = -7.0;
                }

                else if (s[0] == 'E') {                                  // E
                    note = -5.0;
                }

                else if (s[0] == 'F') {                                  // F
                    note = -4.0;
                }

                else if (s[0] == 'G') {                                  // G
                    note = -2.0;
                }

                oct = s[1] - '0';
                n = (oct - 4.0) * 12.0 + note;

            }


            // Note.Accidental.Octave
            else if (strlen(s) == 3) {

                if (s[0]+s[1] == 66+98 || s[0]+s[1] == 65+35) {          // Bb || A#
                    note = 1.0;
                }

                else if (s[0]+s[1] == 68+98 || s[0]+s[1] == 67+35) {     // Db || C#
                    note = -8.0;
                }

                else if (s[0]+s[1] == 69+98 || s[0]+s[1] == 68+35) {     // Eb || D#
                    note = -6.0;
                }

                else if (s[0]+s[1] == 71+98 || s[0]+s[1] == 70+35) {     // Gb || F#
                    note = -3.0;
                }

                else if (s[0]+s[1] == 65+98 || s[0]+s[1] == 71+35) {     // Ab || G#
                    note = -1.0;
                }

                oct = s[2] - '0';
                n = (oct - 4.0) * 12.0 + note;

            }


// Calculation --> 2^(n/12) * 440

        float e = round(pow(2.0, n / 12.0) * 440.0);
        int hertz = e;

        printf("%i Hz\n\n", hertz);
}
