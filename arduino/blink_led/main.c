#include <avr/io.h>
#include <util/delay.h>

typedef enum
{
    READ,
    WRITE
} Mode;

typedef enum
{
    LOW,
    HIGH
} Value;

void pinMode(uint8_t port, Mode mode)
{
    if (mode == WRITE)
        DDRB |= (1 << port);
}

void digital_write(uint8_t port, Value value)
{
    if (value == HIGH)
        PORTB |= (1 << port);
    else
        PORTB &= ~(1 << port);
}

int main()
{

    uint8_t pin = 1;
    pinMode(pin, WRITE);
    while (1)
    {
        digital_write(pin, HIGH);
        _delay_ms(1000);
        digital_write(pin, LOW);
        _delay_ms(1000);
    }
}