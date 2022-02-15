/*
 * File:   newmain.c
 * Author: Linh
 *
 * Created on April 15, 2021, 1:07 AM
 */


// PIC18F4520 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = RCIO6      // Oscillator Selection bits (External RC oscillator, port function on RA6)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF      // MCLR Pin Enable bit (RE3 input pin enabled; MCLR disabled)

// CONFIG4L
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable bit (Stack full/underflow will not cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


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
#include <pic18.h>
#include <stdint.h>
int ledcode[10] = {s0,s1,s2,s3,s4,s5,s6,s7,s8,s9};
unsigned int hangnghin, hangtram, hangchuc, hangdv, tempCTemp;
uint32_t tempC_Ch0, tempC_Ch1;

void Lcd_Display(tempC)
{
    tempCTemp = tempC;
        /*Tim cac chuc so trong bien time*/        
        tempCTemp = tempC;
        hangdv = tempCTemp%10;
        tempCTemp = (tempCTemp - hangdv)/10;
        hangchuc = tempCTemp%10;
        tempCTemp = (tempCTemp - hangchuc)/10;
        hangtram = tempCTemp%10;
        tempCTemp = (tempCTemp - hangtram)/10;
        hangnghin = tempCTemp%10;
        for(int i=0; i<50; i++)
        {
            HangDV(hangdv);
            __delay_ms(5);
            HangChuc(hangchuc);
            __delay_ms(5);
            HangTram(hangtram);
            __delay_ms(5);
            HangNghin(hangnghin);
            __delay_ms(5);
        }
    
}

int HangDV(int hangdv)
{
    PORTD = 0xff;
    PORTDbits.RD3 = 0;
    PORTB = ledcode[hangdv];
}

int HangChuc(int hangchuc)
{   
    PORTD = 0xff;
    PORTDbits.RD2 = 0;
    PORTB = ledcode[hangchuc];
}

int HangTram(int hangtram)
{
    PORTD = 0xff;
    PORTDbits.RD1 = 0;
    PORTB = ledcode[hangtram];
}

int HangNghin(int hangnghin)
{
    PORTD = 0xff;
    PORTDbits.RD0 = 0;
    PORTB = ledcode[hangnghin];
}

void AN0_Config_CH0()
{
    /*ADC enable*/
    ADCON0bits.ADON = 1;
    /*0000 analog channel select bits-AN0*/
    ADCON0 &= ~(1<<2);
    ADCON0 &= ~(1<<3);
    ADCON0 &= ~(1<<4);
    ADCON0 &= ~(1<<5);
    /*ADC in progress*/
    ADCON0 |= 1<<1; 
    /*Port A Analog input*/
    ADCON1 = 0;
    ADCON2bits.ADFM = 1;
}

void AN0_Config_CH1()
{
    /*ADC enable*/
    ADCON0bits.ADON = 1;
    /*0000 analog channel select bits-AN0*/
    ADCON0 |= 1<<2;
    ADCON0 &= ~(1<<3);
    ADCON0 &= ~(1<<4);
    ADCON0 &= ~(1<<5);
    /*ADC in progress*/
    ADCON0 |= 1<<1; 
    /*Port A Analog input*/
    ADCON1 = 0;
    ADCON2bits.ADFM = 1;
}
uint32_t res;
void main(void) 
{
    /*7 SEG port config*/
    TRISB = 0;
    TRISD = 0;
    PORTB = 0;
    PORTD = 0;
    TRISC = 0;
    PORTC = 0;
    
    /*Port A Mode input*/
    TRISA = 0xff;
    ADRESH = 0;
    ADRESL = 0;
    AN0_Config_CH0();
    while(1)
    {
    ADCON0 |= 1<<1;
    while(ADCON0bits.GO_nDONE);
    tempC_Ch0 = ((ADRESH << 8) | ADRESL);
    res=tempC_Ch0*1000/1023;
    Lcd_Display(res);
    }

    return;
}
