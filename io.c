// JIVAJ BRAR io.c
#include "io.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

void read_uint8(FILE *fin, uint8_t *px) {
    int result = fgetc(fin);
    if (result == EOF) {
        fprintf(stderr, "failed read_uint8\n");
    } else {
        *px = (uint8_t) result;
    }
}
void read_uint16(FILE *fin, uint16_t *px) {
    int result1 = fgetc(fin);
    int result2 = fgetc(fin);

    if (result1 == EOF || result2 == EOF) {
        fprintf(stderr, "failed read_uint16\n");
    } else {
        *px = (uint16_t) (result2 << 8 | result1);
    }
}

void read_uint32(FILE *fin, uint32_t *px) {
    int result = fgetc(fin);
    int result1 = fgetc(fin);
    int result2 = fgetc(fin);
    int result3 = fgetc(fin);

    if (result == EOF || result1 == EOF || result2 == EOF || result3 == EOF) {
        fprintf(stderr, "failed read_uint32\n");
    } else {
        *px = (uint32_t) ((result3 << 24) | (result2 << 16) | (result1 << 8) | result);
    }
}

void write_uint8(FILE *fout, uint8_t x) {
    int result = fputc((int) x, fout);
    if (result == EOF) {
        fprintf(stderr, "failed write_uint8\n");
    }
}
void write_uint16(FILE *fout, uint16_t x) {
    int result = fputc(x & 0xFF, fout);
    int result1 = fputc((x >> 8) & 0xFF, fout);

    if (result == EOF || result1 == EOF) {
        fprintf(stderr, "failed write_uint16\n");
    }
}

void write_uint32(FILE *fout, uint32_t x) {
    int result = fputc(x & 0xFF, fout);
    int result1 = fputc((x >> 8) & 0xFF, fout);
    int result2 = fputc((x >> 16) & 0xFF, fout);
    int result3 = fputc((x >> 24) & 0xFF, fout);

    if (result == EOF || result1 == EOF || result2 == EOF || result3 == EOF) {
        fprintf(stderr, "failed write_uint32\n");
    }
}
