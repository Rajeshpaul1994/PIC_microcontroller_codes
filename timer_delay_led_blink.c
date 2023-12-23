/*
 * File:   main.c
 * Author: rajesh
 *
 * Created on December 24, 2023, 12:02 AM
 */

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF 

#include <xc.h>

unsigned char tcount = 0;

void interrupt timer_0(){
    if( INTCONbits.TMR0IF == 1){
        tcount++;
        INTCONbits.TMR0IF = 0; 
    }
}


void main(void) {
    TRISB0=0;
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.TMR0IE = 1;
    OPTION_REG = 0X07;
    TMR0 = 59;
    while(1){
        if(tcount==0){
            PORTBbits.RB0 = 1;
        }
        if(tcount==100){
            PORTBbits.RB0 = 0;
        }
        if(tcount == 200){
            tcount=0;
        }
    }
    return;
}
