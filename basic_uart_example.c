/*
 * File:   main.c
 * Author: rajesh
 *
 * Created on December 26, 2023, 12:34 PM
 */

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>

#define _XTAL_FREQ 11059200



//void ser_int();
//void tx(unsigned char);
//unsigned char rx();
//void txstr(unsigned char *);
 
void ser_int()
{
    TXSTA=0x20; //BRGH=0, TXEN = 1, Asynchronous Mode, 8-bit mode
    RCSTA=0b10010000; //Serial Port enabled,8-bit reception
    SPBRG=17;           //9600 baudrate for 11.0592Mhz
    TXIF=RCIF=0;
}
    
void tx(unsigned char a)
{
    TXREG=a;
    while(!TXIF);
    TXIF = 0;
}
unsigned char rx()
{
    while(!RCIF);
    RCIF=0;
    return RCREG;
}
void txstr(unsigned char *s)
{
    while(*s) {
        tx(*s++);
    }
}

void main()
{
    TRISC6=0;   //Output (TX)
        TRISC7=1;   //Input (RX)
    ser_int();
    txstr("(EmbeTronicX): Enter the letters in keyboard\n\r\r");
    while(1) {
        tx(rx());
    }   
}  
