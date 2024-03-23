# Color Blindness Simulator

## Purpose

The purpose is to a create a color blindness simulator that allows you to change the colors on an image to have them be in the color scheme someone with color blindness would see them.

## How to Use the Program:

The program would be used by opening the terminal, and navigating to the directory where all the files are stored, and typing make. These steps create an executable colorb.c, that you can input images into ./colorb <-i filename_in -o filename_out>. There is also a iotest.c which when you type make all or make iotest will create an executable file iotest, which you execute by just typing ./iotest and it checks whether io.c functions properly.

## Design: 

The program will iterate through the color code, and change it according to the type of color blindness, and return a file with the altered image. They will all be linked together in a file colorb and turn into the executable, which can input and output files. There is iotest, which is linked to io.c as it tests io.c’s read and write functions. The int main will input the input file name and output file name, then run the BMP functions bmp create, bmp reduce palette, bmp write, and bmp free. Then, at the end of the int main, it will fclose the files.

## Functions

- void read_uint8(FILE *fin, uint8_t *px): inputs the file name and pointer to pixels, and reads the uint 8 values and return fatal error “unable to read” if fatal error
- void read_uint16(FILE *fin, uint16_t *px): inputs the file name and pointer to pixels, and reads the uint 16 values and return fatal error “unable to read” if fatal error
- void read_uint32(FILE *fin, uint32_t *px): inputs the file name and pointer to pixels, and reads the uint 32 values and return fatal error “unable to read” if fatal error
- void write_uint8(FILE *fout, uint8_t x): inputs the file name and pixels, and reads the uint 8 values and return fatal error “unable to write” if fatal error
- void write_uint16(FILE *fout, uint16_t x): inputs the file name and pixels, and reads the uint 16 values and return fatal error “unable to write” if fatal error
- void write_uint32(FILE *fout, uint32_t x): inputs the file name and pixels, and reads the uint 32 values and return fatal error “unable to write” if fatal error
- uint32_t round_up(uint32_t x, uint32_t n): inputs an uint32 x and n, and rounds up the value to the nearest 4 multiple.
- BMP *bmp_create(FILE *fin): inputs a file pointer, creates a bmp struct and returns a pointer to the struct
- void bmp_write(const BMP *pbmp, FILE *fout): inputs memory and the outfile, and writes the memory to the fout image
- void bmp_free(BMP **ppbmp): frees the ppbmp memory
- uint8_t constrain(double x): inputs a double and rounds it to a integer
- void bmp_reduce_palette(BMP *pbmp): inputs memory and changes it to stimulate deuteranopia