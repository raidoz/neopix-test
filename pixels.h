#ifndef PIXELS_H_
#define PIXELS_H_

#define MATRIX153
#ifdef MATRIX153
    #define NUMROWS 3
    #define NUMCOLS 51
    #define DELAYVAL 10
#else
    #define NUMROWS 1
    #define NUMCOLS 17
    #define DELAYVAL 25
#endif
#define NUMPIXELS (NUMROWS*NUMCOLS)

#include <stdint.h>

void init_pixels (void);
void set_pixel (uint8_t idx, uint8_t r, uint8_t g, uint8_t b);
void set_matrix_pixel (uint8_t row, uint8_t col, uint8_t r, uint8_t g, uint8_t b);
void show_pixels (void);
void clear_pixels (void);

#endif//PIXELS_H_
