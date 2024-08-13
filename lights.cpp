#include <stdio.h>
#include "pico/stdlib.h"

#include "pixels.h"


static void animation0 (void) {
    clear_pixels();
    printf("an0\n");
    uint8_t maxv = 25;
    for (int i=0; i <= maxv; i++) {
        set_pixel(NUMPIXELS-1, 0, i, 0);
        show_pixels();
        sleep_ms(20);
    }
    for (int i=maxv; i >= 0; i--) {
        set_pixel(NUMPIXELS-1, 0, i, 0);
        show_pixels();
        sleep_ms(20);
    }
}

static void animation1 (void) {
    clear_pixels();
    printf("an1\n");
    uint8_t brightness = 255;
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
        if (i > 0) set_pixel(i-1, 0, 0, 0);
        set_pixel(i, brightness, 0, 0);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(LINE_DELAY); // Pause before next pass through loop
    }
    for(int i=NUMPIXELS-1; i>=0; i--) { // For each pixel...
        if (i < NUMPIXELS-1) set_pixel(i+1, 0, 0, 0);
        set_pixel(i, 0, brightness, 0);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(LINE_DELAY); // Pause before next pass through loop
    }
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
        if (i > 0) set_pixel(i-1, 0, 0, 0);
        set_pixel(i, 0, 0, brightness);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(LINE_DELAY); // Pause before next pass through loop
    }
    for(int i=NUMPIXELS-1; i>=0; i--) { // For each pixel...
        if (i < NUMPIXELS-1) set_pixel(i+1, 0, 0, 0);
        set_pixel(i, brightness, brightness, brightness);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(LINE_DELAY); // Pause before next pass through loop
    }
}

static void animation2 (void) {
    clear_pixels();
    printf("an2\n");
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
        if (i > 0) set_pixel(i-1, 0, 0, 0);
        set_pixel(i, 255, 80, 0);
        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(LINE_DELAY); // Pause before next pass through loop
    }
}

static void animation_arr_l (void) {
    clear_pixels();
    printf("an3\n");
    for(int i=0; i<NUMCOLS; i++) {
        set_matrix_pixel(2, i-ARROW_STEP, 255, 80, 0);
        set_matrix_pixel(1, i, 255, 80, 0);
        set_matrix_pixel(0, i-ARROW_STEP, 255, 80, 0);

        set_matrix_pixel(2, i-(ARROW_STEP+1), 0, 0, 0);
        set_matrix_pixel(1, i-1, 0, 0, 0);
        set_matrix_pixel(0, i-(ARROW_STEP+1), 0, 0, 0);

        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(ARROW_DELAY); // Pause before next pass through loop
    }
}

static void animation_arr_r (void) {
    clear_pixels();
    printf("an4\n");
    for(int i=NUMCOLS-1; i>=0; i--) {
        set_matrix_pixel(2, i+ARROW_STEP, 255, 80, 0);
        set_matrix_pixel(1, i, 255, 80, 0);
        set_matrix_pixel(0, i+ARROW_STEP, 255, 80, 0);

        set_matrix_pixel(2, i+(ARROW_STEP+1), 0, 0, 0);
        set_matrix_pixel(1, i+1, 0, 0, 0);
        set_matrix_pixel(0, i+(ARROW_STEP+1), 0, 0, 0);

        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(ARROW_DELAY); // Pause before next pass through loop
    }
}

static void animation_arr2_l (void) {
    clear_pixels();
    printf("an3\n");
    for(int i=0; i<NUMCOLS; i++) {
        set_matrix_pixel(2, i-ARROW_STEP, 255, 80, 0);
        set_matrix_pixel(1, i, 255, 80, 0);
        set_matrix_pixel(0, i-ARROW_STEP, 255, 80, 0);
        set_matrix_pixel(2, i-ARROW_STEP-1, 255, 80, 0);
        set_matrix_pixel(1, i-1, 255, 80, 0);
        set_matrix_pixel(0, i-ARROW_STEP-1, 255, 80, 0);

        set_matrix_pixel(2, i-(ARROW_STEP+2), 0, 0, 0);
        set_matrix_pixel(1, i-2, 0, 0, 0);
        set_matrix_pixel(0, i-(ARROW_STEP+2), 0, 0, 0);
        set_matrix_pixel(2, i-(ARROW_STEP+3), 0, 0, 0);
        set_matrix_pixel(1, i-3, 0, 0, 0);
        set_matrix_pixel(0, i-(ARROW_STEP+3), 0, 0, 0);

        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(ARROW_DELAY); // Pause before next pass through loop
    }
}

static void animation_arr2_r (void) {
    clear_pixels();
    printf("an4\n");
    for(int i=NUMCOLS-1; i>=0; i--) {
        set_matrix_pixel(2, i+ARROW_STEP, 255, 80, 0);
        set_matrix_pixel(1, i, 255, 80, 0);
        set_matrix_pixel(0, i+ARROW_STEP, 255, 80, 0);
        set_matrix_pixel(2, i+ARROW_STEP+1, 255, 80, 0);
        set_matrix_pixel(1, i+1, 255, 80, 0);
        set_matrix_pixel(0, i+ARROW_STEP+1, 255, 80, 0);

        set_matrix_pixel(2, i+(ARROW_STEP+2), 0, 0, 0);
        set_matrix_pixel(1, i+2, 0, 0, 0);
        set_matrix_pixel(0, i+(ARROW_STEP+2), 0, 0, 0);
        set_matrix_pixel(2, i+(ARROW_STEP+3), 0, 0, 0);
        set_matrix_pixel(1, i+3, 0, 0, 0);
        set_matrix_pixel(0, i+(ARROW_STEP+3), 0, 0, 0);

        show_pixels();   // Send the updated pixel colors to the hardware.
        sleep_ms(ARROW_DELAY); // Pause before next pass through loop
    }
}

static void animation_blink (uint8_t row) {
    if (row > NUMROWS) return;

    clear_pixels();
    printf("anblink1\n");
    for(int i=0; i<NUMCOLS; i+=2) {
        set_matrix_pixel(row, i, 255, 80, 0);
    }
    show_pixels();   // Send the updated pixel colors to the hardware.
    sleep_ms(1000); // Pause before next pass through loop
    clear_pixels();
    show_pixels();
    sleep_ms(1000);
}

static void animation_blink2 (uint8_t row) {
    if (row > NUMROWS) return;

    clear_pixels();
    printf("anblink1\n");
    for(int i=0; i<NUMCOLS; i++) {
        set_matrix_pixel(row, i, 255, 80, 0);
    }
    show_pixels();   // Send the updated pixel colors to the hardware.
    sleep_ms(1000); // Pause before next pass through loop
    clear_pixels();
    show_pixels();
    sleep_ms(1000);
}

static void fullpower_orange (void) {
    for(int i=0; i<NUMPIXELS; i++) {
        set_pixel(i, 255, 80, 0);
    }
    show_pixels();
    sleep_ms(100);
}

void process (void) {
    static int mode = 'x';
    static int last_mode = 0;
    for (;;) {
        int c = getchar_timeout_us(0);
        if ((c == '\n')||(c == '\r')) continue;
        if ((c <= 0)||(c >= 255)) {
            break;
        }
        mode = c;
    }

    switch (mode) {
        case '.':
            if (last_mode != mode) printf("an: last green\n");
            animation0();
        break;

        case 'a':
            if (last_mode != mode) printf("an: sweep\n");
            animation1();
        break;

        case 'b':
            if (last_mode != mode) printf("an: line\n");
            animation2();
        break;

        case 'c':
            if (last_mode != mode) printf("an: <<<\n");
            animation_arr_l();
        break;

        case 'd':
            if (last_mode != mode) printf("an: >>>\n");
            animation_arr_r();
        break;

        case 'C':
            if (last_mode != mode) printf("an: <<<<<<\n");
            animation_arr2_l();
        break;

        case 'D':
            if (last_mode != mode) printf("an: >>>>>>\n");
            animation_arr2_r();
        break;

        case 'q':
            if (last_mode != mode) printf("an: blink\n");
            animation_blink(0);
        break;
        case 'w':
            if (last_mode != mode) printf("an: blink\n");
            animation_blink(1);
        break;
        case 'e':
            if (last_mode != mode) printf("an: blink\n");
            animation_blink(2);
        break;

        case 'Q':
            if (last_mode != mode) printf("an: blink\n");
            animation_blink2(0);
        break;
        case 'W':
            if (last_mode != mode) printf("an: blink\n");
            animation_blink2(1);
        break;
        case 'E':
            if (last_mode != mode) printf("an: blink\n");
            animation_blink2(2);
        break;


        case 'm':
            if (last_mode != mode) printf("an: fpo\n");
            fullpower_orange();
        break;

        case '0':
            if (last_mode != mode) printf("an: off\n");
            clear_pixels();
            show_pixels();
            mode = 0;
        break;

        case 0:
        break;

        default:
            printf("Unknown mode 0x%02x\n", mode);
            mode = 0;
        break;
    }
    last_mode = mode;
};

int main() {
    stdio_init_all();

    init_pixels();

    while (true) {
        process();
    }
    return 0;
}
