/*
 * File:   newmain.c
 * Author: Linh
 *
 * Created on April 16, 2021, 12:28 AM
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
    #define _XTAL_FREQ 4000000


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
unsigned int hangnghin, hangtram, hangchuc, hangdv, tempCTemp;
unsigned int Vol;

void Lcd_Display(Vol)
{
    tempCTemp = Vol;
        /*Tim cac chuc so trong bien time*/        
        tempCTemp = Vol;
        hangdv = tempCTemp%10;
        tempCTemp = (tempCTemp - hangdv)/10;
        hangchuc = tempCTemp%10;
        tempCTemp = (tempCTemp - hangchuc)/10;
        hangtram = tempCTemp%10;
        tempCTemp = (tempCTemp - hangtram)/10;
        hangnghin = tempCTemp%10;
    
            HangDV(hangdv);
            __delay_ms(5);
            HangChuc(hangchuc);
            __delay_ms(5);
            HangTram(hangtram);
            __delay_ms(5);
            HangNghin(hangnghin);
            __delay_ms(5);
    
}

int HangDV(int hangdv)
{
    PORTD = 0xff;
    PORTDbits.RD3 = 0;
    PORTC = ledcode[hangdv];
}

int HangChuc(int hangchuc)
{   
    PORTD = 0xff;
    PORTDbits.RD2 = 0;
    PORTC = ledcode[hangchuc];
}

int HangTram(int hangtram)
{
    PORTD = 0xff;
    PORTDbits.RD1 = 0;
    PORTC = ledcode[hangtram];
}

int HangNghin(int hangnghin)
{
    PORTD = 0xff;
    PORTDbits.RD0 = 0;
    PORTC = ledcode[hangnghin];
}

void AN0_Config()
{
    /*ADC enable*/
    ADCON0bits.ADON = 1;
    /*000 analog channel select bits-AN0*/
    ADCON0 &= ~(1<<3);
    ADCON0 &= ~(1<<4);
    ADCON0 &= ~(1<<5);
    /*ADC in progress*/
    ADCON0 |= 1<<2; 
    /*Port A Analog input*/
    ADCON1 = 0;
}


void main(void) {
    /*7 SEG port config*/
    TRISC = 0;
    TRISD = 0;
    PORTC = 0;
    PORTD = 0;
    
    /*Port A input*/
    TRISA = 0xff;
    
    ADRESH = 0;
    ADRESL = 0;
    while(1)
    {
    /*ADC config-AN0*/
    ADCON0 = 0b00000101;
    /*Wait for AD-conversion complete*/
    while(ADCON0bits.GO_nDONE);
    /*Read ADC value*/
    Vol = ((ADRESH << 8) | ADRESL);
    Lcd_Display(Vol);
    }
    return;
}

