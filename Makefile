# Ustawienia mikrokontrolera Atmega32A
MCU = atmega32a
F_CPU = 8000000UL

# Nazwa twojego pliku źródłowego (bez rozszerzenia)
TARGET = my_program

PROJECT_DIR = PROJECT

# Katalog docelowy, gdzie mają być umieszczone pliki wyjściowe
BUILD_DIR = build

# # Ścieżka do avr-gcc
# AVR_GCC_PATH = /ścieżka/do/twojego/avr-gcc

# Opcje kompilatora
CC = avr-gcc
CFLAGS = -g -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)

# Lista plików źródłowych
SRCS = PROJECT/main.c

# Domyślny cel kompilacji
all: $(BUILD_DIR)/$(TARGET).hex 

${BUILD_DIR}:
	cmake \
		-B${BUILD_DIR} \
		-DPROJECT_NAME=$(TARGET)\
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON

$(BUILD_DIR)/$(TARGET).hex: $(BUILD_DIR) $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)


clean:
	@rm -rf $(BUILD_DIR)

flash: $(BUILD_DIR)/$(TARGET).hex
	avrdude -c usbasp -p $(MCU) -U flash:w:$^

# exmple test for makefile syntax)
print: main.c .gitignore
	@echo '|' $@ '|' $^ '|' $< '|'

.PHONY: all clean print
