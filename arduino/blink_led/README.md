## Requirements

- **AVR Toolchain**: This project requires the AVR toolchain to compile and upload code to the ATmega328P.

  - Install the necessary packages on Ubuntu:
    ```bash
    sudo apt update
    sudo apt install gcc-avr avr-libc avrdude binutils-avr
    ```
    - **`gcc-avr`**: AVR C compiler.
    - **`avr-libc`**: Standard C library for AVR microcontrollers
    - **`binutils-avr`**: Tools for generating and converting object files (e.g., `objcopy`).
    - **`avrdude`**: Tool for flashing your code onto the AVR microcontroller.

- **Arduino Uno (or compatible board)**: This project assumes you are using an ATmega328P microcontroller, commonly found on Arduino boards like the Arduino Uno.

## How to Build and Upload the Code

- `make` for compiling.
- `make upload` for flashing.
