//JIVAJ BRAR colorb.c

#include "bmp.h"
#include "io.h"

#include <ctype.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HELPMESSAGE "Usage: colorb -i infile -o outfile\n       colorb -h\n"

int main(int argc, char **argv) {
    FILE *fin = NULL, *fout = NULL;
    char options[] = "i:o:h";
    int userinp;
    while (-1 != (userinp = getopt(argc, argv, options))) {
        switch (userinp) {
        case 'i':
            fin = fopen(optarg, "rb"); // Use "rb" to open a binary file for reading.
            if (fin == NULL) {
                /* can't open the input file; report a fatal error */
                fprintf(stderr, "cannot open read-file");
                exit(1);
            }
            break;
        case 'o':
            fout = fopen(optarg, "wb"); // Use "wb" to open a binary file for writing.
            if (fout == NULL) {
                /* can't open the output file; report a fatal error */
                fprintf(stderr, "cannot open write-file");
                exit(1);
            }
            break;
        case 'h': fprintf(stdout, HELPMESSAGE); exit(0);
        }
    }
    if (fin == NULL || fout == NULL) {
        fprintf(stderr, "colorb:  -i and -o are required");
        fprintf(stdout, HELPMESSAGE);
        exit(1);
    }

    //initialize BMP
    BMP *image = bmp_create(fin);

    //perform actions
    bmp_reduce_palette(image);
    bmp_write(image, fout);

    //free and close files
    bmp_free(&image);
    fclose(fin);
    fclose(fout);

    return 0;
}
