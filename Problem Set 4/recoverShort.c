#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

        // Ensure proper usage
        if (argc != 2) {
            fprintf(stderr, "Usage: ./recover image");
            return 1;
        }

        // Assign Infilename, Allocate Memory for Outfile & Create a 512 Byte Buffer
        char *infile = argv[1], *outfile = malloc(8); unsigned char buffer[512];

        // Open Infile & Error Check
        FILE *inptr = fopen(infile, "r"), *outptr;
        if (inptr == NULL) {
            free(infile); free(outfile);
            fprintf(stderr, "Could not open %s\n", infile);
            return 2;
        }

        int serialCount = 0, first_JPEG_found = 0;

        // Extraction Process
        while (fread(buffer, 1, 512, inptr) > 0) {

            // Check for the JPEG signature
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && 0xe0 <= buffer[3] && buffer[3] <= 0xef ) {

                (first_JPEG_found) ? fclose(outptr) : first_JPEG_found++;

                // Create Outfile & Error Check
                sprintf(outfile, "%.3i.jpeg", serialCount); serialCount++;
                outptr = fopen(outfile, "w");
                if (outptr == NULL) {
                    fclose(inptr); fclose(outptr); free(infile); free(outfile);
                    fprintf(stderr, "Could not create %s\n", outfile);
                    return 2;
                }

                fwrite(buffer, 1, 512, outptr);
            }

            else if (first_JPEG_found) fwrite(buffer, 1, 512, outptr);
        }

    // Close Streams & Allocated Memory
    fclose(inptr); fclose(outptr); free(outfile);

    return 0;
}
