.PHONY: all build cmake clean build-type check-cpu format_all

MCU = atmega32
F_CPU = 8000000UL
MY_PROJECT_NAME = my_project
BUILD_TYPE ?= Debug
BUILD_DIR := build

all: build

${BUILD_DIR}/Makefile:
	cmake \
		-B${BUILD_DIR} \
		-DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
		-DMY_PROJECT_NAME=$(MY_PROJECT_NAME) \
		-DMCU=$(MCU) \
		-DF_CPU=$(F_CPU) \
		

cmake: ${BUILD_DIR}/Makefile

build: cmake
	$(MAKE) -C ${BUILD_DIR} --no-print-directory

clean:
	@rm -rf $(BUILD_DIR)

flash: ${BUILD_DIR}/$(MY_PROJECT_NAME).bin
	avrdude -c usbasp -p $(MCU) -U flash:w:$^

# exmple test for makefile syntax)
print: main.c .gitignore
	@echo '|' $@ '|' $^ '|' $< '|'

.PHONY: all clean print
