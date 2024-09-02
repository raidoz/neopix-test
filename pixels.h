#ifndef PIXELS_H_
#define PIXELS_H_

//#define MATRIX153
//#define MATRIX57
#define LINE57

#if defined(MATRIX153)
    #define ARROW_STEP 2
    #define NUMROWS 3
    #define NUMCOLS 51
    #define LINE_DELAY 10
    #define ARROW_DELAY 25
    #define POWER_LIMIT 18000
#elif defined(MATRIX57)
    #define ARROW_STEP 1
    #define NUMROWS 3
    #define NUMCOLS 19
    #define LINE_DELAY 100
    #define ARROW_DELAY 50
    #define POWER_LIMIT 7000
#elif defined(LINE57)
    #define ARROW_STEP 1
    #define NUMROWS 1
    #define NUMCOLS 57
    #define LINE_DELAY 100
    #define ARROW_DELAY 50
    #define POWER_LIMIT 9200
#else
    #define ARROW_STEP 1
    #define NUMROWS 1
    #define NUMCOLS 17
    #define LINE_DELAY 50
    #define ARROW_DELAY 50
    #define POWER_LIMIT 6000
#endif
#define NUMPIXELS (NUMROWS*NUMCOLS)

#include <stdint.h>

void init_pixels (void);
void set_pixel (uint8_t idx, uint8_t r, uint8_t g, uint8_t b);
void set_matrix_pixel (uint8_t row, uint8_t col, uint8_t r, uint8_t g, uint8_t b);
void show_pixels (void);
void clear_pixels (void);

#endif//PIXELS_H_
