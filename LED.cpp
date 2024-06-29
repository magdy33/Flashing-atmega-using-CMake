#include"LED.hpp"
#include<avr/io.h>
#include<util/delay.h>

LED::LED(/* args */)
{
    DDRA = 0xff;
    PORTA= 0x00;
}

void LED::LED_TOGGLE()
{
    _delay_ms(5000);
    PORTA = ~PORTA;
}