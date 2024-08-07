cmake_minimum_required(VERSION 3.13)
#enable_language( C CXX ASM )
# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico-sdk/pico_sdk_init.cmake)
#include(pi-pico-adafruit-neopixels/pico_neopixels/pico_sdk_import.cmake)

project(neopix C CXX ASM)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project
add_executable(neopix lights.cpp pixels.cpp)

add_subdirectory(pi-pico-adafruit-neopixels/pico_neopixels)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(neopix pico_stdlib pico_neopixel)

# Enable STDIO over USB
pico_enable_stdio_usb(neopix 1)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(neopix)
