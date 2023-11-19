/*
 * File:   newmain.c
 * Author: rajesh
 *
 * Created on November 18, 2023, 12:08 AM
 */


#include <xc.h>

#define _XTAL_FREQ 20000000
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


void main(void) {
    TRISD = 0x00;
    TRISC = 0x00;
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB3 = 1;
    unsigned char numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    unsigned char selector[] = {0x0E, 0x0D, 0x0B, 0x07};
    int first = 0, second = 0, third = 0, fourth = 0 ;
    
    while(1){
        PORTC = selector[0];
        PORTD = numbers[fourth];
        __delay_ms(10);
        
        PORTC = selector[1];
        PORTD = numbers[third];
        __delay_ms(10);
        
        PORTC = selector[2];
        PORTD = numbers[second];
        __delay_ms(10);
        
        
        PORTC = selector[3];
        PORTD = numbers[first];
        __delay_ms(10);
        
        if(PORTBbits.RB0 == 1){
            first = first + 1;
            __delay_ms(200);
        }
        if(PORTBbits.RB1 == 1){
            second = second + 1;
            __delay_ms(200);
        }
        if(PORTBbits.RB2 == 1){
            third = third + 1;
            __delay_ms(200);
        }
        if(PORTBbits.RB3 == 1){
            fourth = fourth + 1;
            __delay_ms(200);
        }
         
    }
    return;
}

