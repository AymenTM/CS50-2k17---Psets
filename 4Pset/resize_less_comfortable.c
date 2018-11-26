
// Program: Resizes (i.e., enlarges or shrinks) 24-bit uncompressed BMPs by a factor of 'f' (a positive integer between 0-100).

// ----> Resize (Less Comfortable)

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

int main(int argc, char *argv[]) {

    // Check for correct usage
    if (argc != 4) {

        fprintf(stderr, "\nUsage: ./resize f infile outfile\n\n");
        return 1;
    }

    int     z = 0, // for the while loop
            len = strlen(argv[1]); // length of the string argv[1]

    // Remember 'f' and filenames
    char    *infile = argv[2],
            *outfile = argv[3],
             factor[len]; //used to store the string argv[1]

    sscanf(argv[1], "%s", factor);

    // Checks for f an integer and NOT float
    while (z < len) {

        if (factor[z] == '.') {
            fprintf(stderr, "\nUsage: f must be an integer.\n\n");
            return 6;
        }

        z++;
    }

    int     f = atoi(argv[1]),
            fRound = ceil(f);

    // Checks for 0 < f < 100
    if (f <= 0 || f > 100) {

        fprintf(stderr, "\nUsage: f between ]0 - 100]\n\n");
        return 2;
    }

    // Open infile for reading
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL) {

        fprintf(stderr, "\nCould not read %s.\n\n", infile);
        return 3;
    }

    // Create outfile for writing
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL) {

        fclose(inptr);
        fprintf(stderr, "\nCould not create %s.\n\n", outfile);
        return 4;
    }

    // Read BITMAPFILEHEADER of infile
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read BITMAPFILEHEADER of infile
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // determine padding to skip for infile's scanlines
    int padding2Skip = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }


// Updating HEADERS - - - - - - - - - - - - - - - - - -

    // Read BITMAPFILEHEADER of infile
    BITMAPFILEHEADER rBf = bf;

    // Update BITMAPINFOHEADER of infile
    BITMAPINFOHEADER rBi = bi;

    rBi.biWidth = ceil(bi.biWidth * f);

    if (bi.biHeight < 0) {
        rBi.biHeight = floor(bi.biHeight * f);
    }

    else {
        rBi.biHeight = ceil(bi.biHeight * f);
    }

    // determine padding to write for outfile's scanlines
    int padding2Write = (4 - (rBi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    rBi.biSizeImage = (abs(rBi.biHeight) * (rBi.biWidth + padding2Write)) * 3;
    rBf.bfSize = rBi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);



        // Write BITMAPFILEHEADER to outfile
    fwrite(&rBf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write BITMAPINFOHEADER to outfile
    fwrite(&rBi, sizeof(BITMAPINFOHEADER), 1, outptr);

// Resizing - - - - - - - - - - - - - - - - - - - - -

    int biHeight = abs(bi.biHeight);

    // says: read and print scanlines as many as biHeight
    for (int i = 0; i < biHeight; i++) {

        int cur_line_pos = ftell(inptr);

        // biHeight * f ; print that amount of scanlines as many as f times (vertical resizing)
        for (int outHeight = 0; outHeight < fRound; outHeight++) {

            fseek(inptr, cur_line_pos, SEEK_SET);

            // says: read and print pixels as many as biWidth
            for (int j = 0; j < bi.biWidth; j++) {

                // Buffer for pixel/color info
                RGBTRIPLE triple;

                // Read amd store pixel color
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // biWidth * f ; print that pixel as many as f times (horizontal resizing)
                for (int outWidth = 0; outWidth < fRound; outWidth++) {

                    // Write and store pixel color
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

// CLosing Streams - - - - - - - - - - - - - - - - - - - - -

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // Success
    return 0;
}
