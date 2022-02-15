/*
 * File:   newmain.c
 * Author: Linh
 *
 * Created on March 28, 2021, 1:27 AM
 */


// PIC18F4520 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
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
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
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

void main(void) {
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
        /*dem len 59s thi ve lai 0, hang tram tang them 1*/
        if (hangchuc*10 + hangdv == 59) time+=40;
        /*dem len 60phut thi ve lai 0, vi co +40 o tren nen la 99 o 2 so cuoi*/
        if (time == 5999) time = 0;
    }
    
    return;
}
