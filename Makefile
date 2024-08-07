# Makefile for doing the setup and build of the project

PICOTOOL_UDEV_RULES = /etc/udev/rules.d/99-picotool.rules

build/neopix.bin: build
	make -C build neopix

build: pico-sdk/pico_sdk_init.cmake
	mkdir build
	cd build && cmake ..

pico-sdk/pico_sdk_init.cmake:
	git submodule init
	git submodule update
	cd pico-sdk && git submodule init
	cd pico-sdk && git submodule update

deinit:
	git submodule deinit --all -f

clean:
	rm -R build

picotool: picotool/build/picotool

picotool/build/picotool:
	cd picotool && mkdir -p build
	cd picotool/build && PICO_SDK_PATH=../../pico-sdk cmake ..
	cd picotool/build && make

install: picotool $(PICOTOOL_UDEV_RULES)
	picotool/build/picotool load build/neopix.bin -f

$(PICOTOOL_UDEV_RULES):
	sudo cp udev/99-picotool.rules $@

.PHONY: build/neopix.bin
