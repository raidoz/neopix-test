#ifndef PIXELS_H_
#define PIXELS_H_

//#define MATRIX153
#define MATRIX57

#if defined(MATRIX153)
    #define ARROW_STEP 2
    #define ARROW_DIRECTION (1)
    #define NUMROWS 3
    #define NUMCOLS 51
    #define LINE_DELAY 10
    #define ARROW_DELAY 25
#elif defined(MATRIX57)
    #define ARROW_STEP 1
    #define ARROW_DIRECTION (-1)
    #define NUMROWS 3
    #define NUMCOLS 19
    #define LINE_DELAY 100
    #define ARROW_DELAY 50
#else
    #define NUMROWS 1
    #define NUMCOLS 17
    #define LINE_DELAY 50
    #define ARROW_DELAY 50
#endif
#define NUMPIXELS (NUMROWS*NUMCOLS)

#include <stdint.h>

void init_pixels (void);
void set_pixel (uint8_t idx, uint8_t r, uint8_t g, uint8_t b);
void set_matrix_pixel (uint8_t row, uint8_t col, uint8_t r, uint8_t g, uint8_t b);
void show_pixels (void);
void clear_pixels (void);

#endif//PIXELS_H_
