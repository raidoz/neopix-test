#include <stdio.h>
#include "pico/stdlib.h"

#include "pixels.h"


static void animation1 (void) {
    clear_pixels();
    printf("cleared\n");
    uint8_t brightness = 255;
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
        if (i > 0) set_pixel(i-1, 0, 0, 0);
        set_pixel(i, brightness, 0, 0);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(DELAYVAL); // Pause before next pass through loop
    }
    for(int i=NUMPIXELS-1; i>=0; i--) { // For each pixel...
        if (i < NUMPIXELS-1) set_pixel(i+1, 0, 0, 0);
        set_pixel(i, 0, brightness, 0);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(DELAYVAL); // Pause before next pass through loop
    }
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
        if (i > 0) set_pixel(i-1, 0, 0, 0);
        set_pixel(i, 0, 0, brightness);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(DELAYVAL); // Pause before next pass through loop
    }
    for(int i=NUMPIXELS-1; i>=0; i--) { // For each pixel...
        if (i < NUMPIXELS-1) set_pixel(i+1, 0, 0, 0);
        set_pixel(i, brightness, brightness, brightness);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(DELAYVAL); // Pause before next pass through loop
    }
}

static void animation2 (void) {
    clear_pixels();
    printf("cleared\n");
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
        if (i > 0) set_pixel(i-1, 0, 0, 0);
        set_pixel(i, 255, 80, 0);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(DELAYVAL); // Pause before next pass through loop
    }
}

static void animation3 (void) {
    clear_pixels();
    printf("cleared\n");
    for(int i=0; i<NUMCOLS; i++) { // For each pixel...
        if (i > 0) {
            set_matrix_pixel(2, i-2, 255, 80, 0);
            set_matrix_pixel(1, i, 255, 80, 0);
            set_matrix_pixel(0, i-2, 255, 80, 0);

            set_matrix_pixel(2, i-3, 0, 0, 0);
            set_matrix_pixel(1, i-1, 0, 0, 0);
            set_matrix_pixel(0, i-3, 0, 0, 0);
        }
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(20); // Pause before next pass through loop
    }
}

static void fullpower_orange (void) {
    for(int i=0; i<NUMPIXELS; i++) {
        set_pixel(i, 255, 80, 0);
    }
    show_pixels();
}

void process (void) {
    static int mode = 0;
    for (;;) {
        int c = getchar_timeout_us(0);
        if ((c == '\n')||(c == '\r')) continue;
        if ((c <= 0)||(c >= 255)) {
            break;
        }
        mode = c;
    }

    switch (mode) {
        case 'a':
            animation1();
        break;

        case 'b':
            animation2();
        break;

        case 'c':
            animation3();
        break;

        case 'm':
            fullpower_orange();
        break;

        case 0:
        break;

        default:
            printf("Unknown mode 0x%02x\n", mode);
            mode = 0;
        break;
    }
};

int main() {
    stdio_init_all();

    init_pixels();

    while (true) {
        process();
    }
    return 0;
}
