/*
todo:
*/
#include "common.h"
#include <util/delay.h>

/*
volatile uint8_t counter = 0; 
volatile bool counting = false;
volatile bool move_pen = false;
volatile bool pen_up = false;
bool pen_state;

*/

//pins
#define LED_STAT PB0
#define TRIAC PB1
#define LED_RUN PB2
#define TEMP PB3
#define CURRENT PB4

int main()
{

    //setup
	cli();

    setbit(DDRB,LED_STAT); //led
    setbit(DDRB,LED_RUN);  //led
    setbit(DDRB,TRIAC);//triac

    clearbit(PORTB,LED_RUN);
    clearbit(PORTB,TRIAC);

    //flash led on powerup
    for( int i = 0; i < 4; i++ )
    {
        clearbit(PORTB,LED_STAT); //turn off led
        _delay_ms(100);
        setbit(PORTB,LED_STAT);
        _delay_ms(100);
    }
    clearbit(PORTB,LED_STAT); //turn off led

    //ADC code from http://avrbasiccode.wikispaces.com/
    ADCSRA |= (1 << ADEN)| // Analog-Digital enable bit
    (1 << ADPS1)| // set prescaler to 8 (clock / 8)
    (1 << ADPS0); // set prescaler to 8 (clock / 8)

    ADMUX |= (1 << ADLAR)| // AD result store in (more significant bit in ADCH)
    (1 << MUX1); // Choose AD input AD2 (BP 4)

    for (;;)
    {

    ADCSRA |= (1 << ADEN); // Analog-Digital enable bit
    ADCSRA |= (1 << ADSC); // Discard first conversion

    while (ADCSRA & (1 << ADSC)); // wait until conversion is done

    ADCSRA |= (1 << ADSC); // start single conversion

    while (ADCSRA & (1 << ADSC)) // wait until conversion is done

    ADCSRA &= ~(1<<ADEN); // shut down the ADC

    //----------Show ADCH Byte in Led variable brightness indicator---------
    }

}

//timer 0 is used to measure amount of time between power on and pulse over power line
ISR(TIM0_OVF_vect)
{
    //comms counter
//////////////////    counter ++;
}

