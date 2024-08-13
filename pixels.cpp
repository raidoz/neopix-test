
#include "pixels.h"
#include "Adafruit_NeoPixel.hpp"

#include <stdio.h>

#define PIN       28

static Adafruit_NeoPixel m_ada_pixels;
static uint8_t m_pixels[NUMPIXELS][3];
static uint32_t m_power = 0;


void init_pixels (void) {
    m_ada_pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
//  m_ada_pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
    m_ada_pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}


void set_pixel(uint8_t idx, uint8_t r, uint8_t g, uint8_t b) {
    if (idx < NUMPIXELS) {
        int prevp = m_pixels[idx][0] + m_pixels[idx][1] + m_pixels[idx][2];
        int newp = r + g + b;
        m_pixels[idx][0] = r;
        m_pixels[idx][1] = g;
        m_pixels[idx][2] = b;
        m_power = m_power - prevp + newp;
    }
}

void set_matrix_pixel (uint8_t row, uint8_t col, uint8_t r, uint8_t g, uint8_t b) {
    if ((row < NUMROWS)&&(col < NUMCOLS)) {
        set_pixel(row * NUMCOLS + col, r, g ,b);
    }
}

void show_pixels (void) {
    if (m_power > POWER_LIMIT) { // Too much
        m_ada_pixels.clear();
        printf("ERR: power = %d\n", m_power);
        m_ada_pixels.setPixelColor(0, 50, 0, 0);
        m_ada_pixels.show();
        return;
    }
#if defined(MATRIX153)
    uint8_t segdx[] = {0, 3, 6, 1, 4, 7, 2, 5, 8};
    for (int segment = 0; segment < 9; segment++) {
        for (int idx = 0; idx < 17; idx++) {
            int pix = segment * 17 + idx;
            m_ada_pixels.setPixelColor(segdx[segment] * 17 + idx, m_pixels[pix][0], m_pixels[pix][1], m_pixels[pix][2]);
        }
    }
#elif defined(MATRIX57)
    for (int i = 0; i < NUMCOLS; i++) {
        uint8_t pix = i;
        m_ada_pixels.setPixelColor(0*NUMCOLS + i, m_pixels[pix][0], m_pixels[pix][1], m_pixels[pix][2]);
    }
    for (int i = 0; i < NUMCOLS; i++) {
        uint8_t pix = 2*NUMCOLS-i-1; // Segment 2 runs in reverse
        m_ada_pixels.setPixelColor(1*NUMCOLS + i, m_pixels[pix][0], m_pixels[pix][1], m_pixels[pix][2]);
    }
    for (int i = 0; i < NUMCOLS; i++) {
        uint8_t pix = 2*NUMCOLS+i;
        m_ada_pixels.setPixelColor(2*NUMCOLS + i, m_pixels[pix][0], m_pixels[pix][1], m_pixels[pix][2]);
    }
#else
    for(int i=0; i<NUMPIXELS; i++) {
        m_ada_pixels.setPixelColor(i, m_pixels[i][0], m_pixels[i][1], m_pixels[i][2]);
    }
#endif
    m_ada_pixels.show();
}

void clear_pixels (void) {
    m_ada_pixels.clear(); // Set all pixel colors to 'off'
    for (int i = 0; i < NUMPIXELS; i++) {
        m_pixels[i][0] = 0;
        m_pixels[i][1] = 0;
        m_pixels[i][2] = 0;
    }
    m_power = 0;
}

