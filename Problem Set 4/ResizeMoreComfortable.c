/*

Program: Resizes (i.e., enlarges or shrinks) 24-bit uncompressed BMPs by a factor of 'f'.

---> Resize (More Comfortable)

Website: https://docs.cs50.net/2018/x/psets/4/resize/more/resize.html

*/

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

// Prototypes
int enlarge(FILE *inptr, FILE *outptr, BITMAPINFOHEADER originalBi, float f, int absOriginalBiHeight, int padding2Skip, int padding2Write);
int shrink(FILE *inptr, FILE *outptr, BITMAPINFOHEADER originalBi, BITMAPINFOHEADER newBi, int absOriginalBiHeight, int absNewBiHeight, int padding2Skip, int padding2Write);


int main(int argc, char *argv[]) {



// Check for correct usage at command line - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #1

    if (argc != 4) {

        fprintf(stderr, "Usage: ./resize f infile outfile\n");
        return 1;  // Problem w/ the inputted usage.
    }



// Check if 'f' is within the required bounds - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #2

    // Store 'f'
    float f = atof(argv[1]);

    // Test it
    if (f <= 0.0 || f > 100) {

        fprintf(stderr, "Usage: f between [0.0 - 100.0]\n");
        return 2;  // Problem w/ the inputted factor.
    }



// Translate 'f' into either a call to Enlarge or to Shrink - - - - - - - - - - - - - - - - - - - - - - #3

    int indication;
    if (f >= 1.0) {

        indication = 0; // Enlarge
    }

    else {

        indication = 1; // Shrink
    }



// Remember Filenames, Create in and out FILE Pointers & Create Outfile - - - - - - - - - - - - - - - - #4

    // Store filenames
    char *infile = argv[2],
         *outfile = argv[3];

    // Open infile for reading
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL) {

        fprintf(stderr, "Could not read %s.\n", infile);
        return 3;  // Problem w/ the inputted infile.
    }

    // Create outfile for writing
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL) {

        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;  // Problem w/ the inputted outfile.
    }



// Read and Store BMP Infile Headers (we'll call them the original ones) - - - - - - - - - - - - - - - - #5

    // Read BITMAPFILEHEADER of infile
    BITMAPFILEHEADER originalBf;
    fread(&originalBf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read BITMAPFILEHEADER of infile
    BITMAPINFOHEADER originalBi;
    fread(&originalBi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure that Infile is a 24-bit uncompressed BMP 4.0
    if (originalBf.bfType != 0x4d42 || originalBf.bfOffBits != 54 || originalBi.biSize != 40 ||
        originalBi.biBitCount != 24 || originalBi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;  // Problem w/ the inputted bmp file.
    }



// Create & Store Outfile Headers (we'll call these the new ones) - - - - - - - - - - - - - - - - - - - - #6

    // Create BITMAPFILEHEADER of outfile and store in a BITMAPFILEHEADER struct variable
    BITMAPFILEHEADER newBf = originalBf;

    // Create BITMAPINFOHEADER of outfile and store in a BITMAPINFOHEADER struct variable
    BITMAPINFOHEADER newBi = originalBi;

    // Calculate New Width
    newBi.biWidth = ceil((float)originalBi.biWidth * (f));

    /* Because the height could be negative    ---   and the problem is that the rounding functions would be different for a neg. number
                                                     and a pos. number... so i just seperated them. Read about the functions ceil(), floor()
                                                     and round() for more info. */
    if (originalBi.biHeight < 0) {

        // Calculate New Height if Neg.
        newBi.biHeight = floor((float)originalBi.biHeight * (f));
    }

    else {

        // Calculate New Height if Pos.
        newBi.biHeight = ceil((float)originalBi.biHeight * (f));
    }

    // Calculate padding to skip for infile's scanlines
    int padding2Skip = (4 - (originalBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Calculate padding to write for outfile's scanlines
    int padding2Write = (4 - (newBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Calculate new Size of Image (in Bytes)
    newBi.biSizeImage = (abs(newBi.biHeight) * (newBi.biWidth + padding2Write)) * 3;

    // Calculate new Size of entire BMP File (in Bytes)
    newBf.bfSize = newBi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // Write BITMAPFILEHEADER to outfile
    fwrite(&newBf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write BITMAPINFOHEADER to outfile
    fwrite(&newBi, sizeof(BITMAPINFOHEADER), 1, outptr);

    int     absOriginalBiHeight = abs(originalBi.biHeight),
            absNewBiHeight = abs(newBi.biHeight);



// Enlarge || Shrink According to Indication - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #7


    if (indication == 0) { // Enlarge

        enlarge(inptr, outptr, originalBi, f, absOriginalBiHeight, padding2Skip, padding2Write);

        if (enlarge(inptr, outptr, originalBi, f, absOriginalBiHeight, padding2Skip, padding2Write) == 0) {

            printf("\nENLARGING SUCCESSFUL.\n\n");
            printf("Open file --->  %s\n\n", outfile);
        }
    }


    else { // Shrink

        shrink(inptr, outptr, originalBi, newBi, absOriginalBiHeight, absNewBiHeight, padding2Skip, padding2Write);

        if (shrink(inptr, outptr, originalBi, newBi, absOriginalBiHeight, absNewBiHeight, padding2Skip, padding2Write) == 0) {

            printf("\nSHRINKING SUCCESSFUL.\n\n");
            printf("Open file --->  %s\n\n", outfile);
        }
    }



// CLose Streams - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #8

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // Success
    return 0;

}



// Function: Enlarges a bmp format image by a factor of 'f'
int enlarge(FILE *inptr, FILE *outptr, BITMAPINFOHEADER originalBi, float f, int absOriginalBiHeight, int padding2Skip, int padding2Write) {

    // Buffer for pixel/color info
    RGBTRIPLE triple;

    // says: read and print scanlines as many as Original Height times
    for (int scanlinesReadCount = 0; scanlinesReadCount < absOriginalBiHeight; scanlinesReadCount++) {

        int cur_line_pos = ftell(inptr);

        // biHeight * f ; print that amount of scanlines as many as f times (vertical resizing)
        for (int scanlineMultiplierCount = 0; scanlineMultiplierCount < ceil(f); scanlineMultiplierCount++) {

            fseek(inptr, cur_line_pos, SEEK_SET);

            // says: read and print pixels as many as Original width times
            for (int pixelsReadCount = 0; pixelsReadCount < originalBi.biWidth; pixelsReadCount++) {

                // Read amd store pixel color
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // biWidth * f ; print that pixel as many as f times (horizontal resizing)
                for (int pixelsMultiplierCount = 0; pixelsMultiplierCount < ceil(f); pixelsMultiplierCount++) {

                    // Write pixel
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }

            }

            // Skip padding if any
            fseek(inptr, padding2Skip, SEEK_CUR);

            // Add padding to outfile
            for (int k = 0; k < padding2Write; k++) {

                fputc(0x00, outptr);
            }

        }

    }

    return 0;

}



// Function: Shrinks a bmp format image by a factor of 'f'
int shrink(FILE *inptr, FILE *outptr, BITMAPINFOHEADER originalBi, BITMAPINFOHEADER newBi, int absOriginalBiHeight, int absNewBiHeight, int padding2Skip, int padding2Write) {

        // Buffer for pixel/color info
        RGBTRIPLE triple;

        // Interval to skip After Each Scanline Read
        int verticalInterval2Skip = ((absOriginalBiHeight / absNewBiHeight) - 1) * (originalBi.biWidth * sizeof(RGBTRIPLE) + padding2Skip);

        // Interval to skip After Each Pixel Read
        int horizontalInterval2Skip = ((originalBi.biWidth / newBi.biWidth) - 1) * sizeof(RGBTRIPLE);


        // New.Height Loop
        for (int verticalScanlineCount = 0; verticalScanlineCount < absNewBiHeight; verticalScanlineCount++) {

            // New.Width Loop
            for (int horizontalPixelCount = 0; horizontalPixelCount < newBi.biWidth; horizontalPixelCount++) {

                // Read amd store pixel
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // Write pixel
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

                // Interval to skip after having read that pixel
                fseek(inptr, horizontalInterval2Skip, SEEK_CUR);

            }

            // Skip padding if any
            fseek(inptr, padding2Skip, SEEK_CUR);

            // Add padding to outfile
            for (int k = 0; k < padding2Write; k++) {

                fputc(0x00, outptr);
            }

            // Interval to skip after having read a scanline
            fseek(inptr, verticalInterval2Skip, SEEK_CUR);

        }

    return 0;
}
