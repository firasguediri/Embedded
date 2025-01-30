MCU = atmega328p
F_CPU = 16000000UL
USB = /dev/ttyACM0
CC = avr-gcc
CFLAGS = -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU)
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
PROGRAMMER = -F -v -c arduino -p $(MCU) -P $(USB) 

all: main.hex

main.hex: main.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

main.elf: main.o
	$(CC) $(CFLAGS) -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

upload: main.hex
	$(AVRDUDE) $(PROGRAMMER) -U flash:w:$<:i

clean:
	rm -f main.o main.elf main.hex