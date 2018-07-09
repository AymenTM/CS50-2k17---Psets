// Helper functions for music

#include <cs50.h>
#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = fraction[0] - '0', y = fraction[2] - '0';

    if (y == 2) {
        x = 4*x;
    }

    else if (y == 4) {
        x = 2*x;
    }

    return x;
}



// Calculates frequency (in Hz) of a note
int frequency(string note)
{

        float      nt = 0.0,
                  oct = 0.0,
                    n = 0.0;


// Converting the string 'note' into simply 'n' (i.e how far the note is from A4)

            // Note.Octave
            if (strlen(note) == 2) {

                if (note[0] == 'A') {                                       // A
                    nt = 0.0;
                }

                else if (note[0] == 'B') {                                  // B
                    nt = 2.0;
                }

                else if (note[0] == 'C') {                                  // C
                    nt = -9.0;
                }

                else if (note[0] == 'D') {                                  // D
                    nt = -7.0;
                }

                else if (note[0] == 'E') {                                  // E
                    nt = -5.0;
                }

                else if (note[0] == 'F') {                                  // F
                    nt = -4.0;
                }

                else if (note[0] == 'G') {                                  // G
                    nt = -2.0;
                }

                oct = note[1] - '0';
                n = (oct - 4.0) * 12.0 + nt;

            }


            // Note.Accidental.Octave
            else if (strlen(note) == 3) {

                if (note[0]+note[1] == 66+98 || note[0]+note[1] == 65+35) {          // Bb || A#
                    nt = 1.0;
                }

                else if (note[0]+note[1] == 68+98 || note[0]+note[1] == 67+35) {     // Db || C#
                    nt = -8.0;
                }

                else if (note[0]+note[1] == 69+98 || note[0]+note[1] == 68+35) {     // Eb || D#
                    nt = -6.0;
                }

                else if (note[0]+note[1] == 71+98 || note[0]+note[1] == 70+35) {     // Gb || F#
                    nt = -3.0;
                }

                else if (note[0]+note[1] == 65+98 || note[0]+note[1] == 71+35) {     // Ab || G#
                    nt = -1.0;
                }

                oct = note[2] - '0';
                n = (oct - 4.0) * 12.0 + nt;

            }


// Calculation --> 2^(n/12) * 440

        float e = round(pow(2.0, n / 12.0) * 440.0);
        int hertz = e;

        return hertz;
}



// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0] == '\0') {

        return true;
    }

    else {

        return false;
    }
}
