/*
 * File:   newmain.c
 * Author: Linh
 *
 * Created on June 13, 2021, 3:53 PM
 */


// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define     s0   0x3F
#define     s1   0x06
#define     s2   0x5B
#define     s3   0x4F
#define     s4   0x66
#define     s5   0x6D
#define     s6   0x7D
#define     s7   0x07
#define     s8   0x7F
#define     s9   0x6F

#define _XTAL_FREQ  20000000

#include <xc.h>

int ledcode[10] = {s0,s1,s2,s3,s4,s5,s6,s7,s8,s9};

int HangDV(int hangdv)
{
    PORTC = 0xff;
    PORTCbits.RC3 = 0;
    PORTB = ledcode[hangdv];
}

int HangChuc(int hangchuc)
{   
    PORTC = 0xff;
    PORTCbits.RC2 = 0;
    PORTB = ledcode[hangchuc];
}

int HangTram(int hangtram)
{
    PORTC = 0xff;
    PORTCbits.RC1 = 0;
    PORTB = ledcode[hangtram];
}

int HangNghin(int hangnghin)
{
    PORTC = 0xff;
    PORTCbits.RC0 = 0;
    PORTB = ledcode[hangnghin];
}

void main(void) 
{
    TRISC = 0;
    PORTC = 0xff;
    TRISB = 0;
    
    int time = 0;
    int hangnghin, hangtram, hangchuc, hangdv, timeTemp;
    timeTemp = time;
    while (1)
    {
        /*Tim cac chuc so trong bien time*/
        time++;        
        if (time == 10000) time = 0;
        timeTemp = time;
        hangdv = timeTemp%10;
        timeTemp = (timeTemp - hangdv)/10;
        hangchuc = timeTemp%10;
        timeTemp = (timeTemp - hangchuc)/10;
        hangtram = timeTemp%10;
        timeTemp = (timeTemp - hangtram)/10;
        hangnghin = timeTemp%10;
        
        /*Dem du 1s = 1000ms = 25*40 */
        for(int i = 0; i<25; i++)
        {
            HangDV(hangdv);
            __delay_ms(10);
            HangChuc(hangchuc);
            __delay_ms(10);
            HangTram(hangtram);
            __delay_ms(10);
            HangNghin(hangnghin);
            __delay_ms(10);
        }
        
    }
    
    return;
}
