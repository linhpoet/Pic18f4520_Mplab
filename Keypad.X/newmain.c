/*
 * File:   newmain.c
 * Author: Linh
 *
 * Created on April 5, 2021, 11:47 PM
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

#include <xc.h>
#include "MyLcd16.h"
#include <string.h>
#define _XTAL_FREQ  8000000
#define TMR2PRESCALE    4
#define Pulses_Per_Revolution 374

char keypad[4][4] = {    {'7','8','9','/'},
                                {'4','5','6','*'},
                                {'1','2','3','-'},
                                {' ','0','#','+'}
                            };
char keypadNum[4][4] = {    {7,8,9,20},
                            {4,5,6,21},
                            {1,2,3,22},
                            {23,0,24,25}
                            };

char colloc, rowloc;
void LCD_Configuration()
{
    DataTrist = 0;
    CommandTrist = 0;
    CommandPort = 0;
    PortData = 0;
    lcd_command(Mode8bit2line);					//8bit, 2 dong
	lcd_command(DisplayOn);						//bat hien thi
	lcd_command(ClearDisplay);					//clear
    
    //.........Test LCD............//

}
int dem;
char Keyfind()
{
    while(1)
    {
        TRISB = 0X0f;
        PORTB = 0XFF;
        
        do
        {
            PORTB = 0X0F;
            colloc = (PORTB & 0x0f);
        }while (PORTB == 0x0f);
        
        /*chong doi phim*/
        do
        {
            do
            {
            __delay_ms(20);
            colloc = PORTB & 0x0f;
            }while(colloc == 0x0f);
        __delay_ms(40);
        colloc = (PORTB & 0x0f);
        }while(colloc == 0x0f);
        
        /*check 1st row*/
        PORTB = 0xef;
        colloc = PORTB & 0x0f;
        if(colloc != 0x0f)
        {
            rowloc = 0;
            break;
        }
            
        /*check 2nd row*/
        PORTB = 0xdf;
        colloc = PORTB & 0x0f;
        if(colloc != 0x0f)
        {
            rowloc = 1;
            break;
        }
        /*check 3rd row*/
        PORTB = 0xbf;
        colloc = PORTB & 0x0f;
        if(colloc != 0x0f)
        {
            rowloc = 2;
            break;
        }
        /*check 4th row*/
        PORTB = 0xef;
        colloc = PORTB & 0x0f;
        if(colloc != 0x0f)
        {
            rowloc = 3;
            break;
        }
    }
    
//    /*check collum*/
//    if(colloc == 0x0e)
//    {
//        return(keypad[rowloc][3]);
//    }
//    else if(colloc == 0x0d)
//    {
//        return(keypad[rowloc][2]);
//    }
//    else if(colloc == 0x0b)
//    {
//        return(keypad[rowloc][1]);
//    }
//    else
//    {
//        return(keypad[rowloc][0]);
//    }
    
    /*check collum*/
    if(colloc == 0x0e)
    {
        return(keypadNum[rowloc][3]);
    }
    else if(colloc == 0x0d)
    {
        return(keypadNum[rowloc][2]);
    }
    else if(colloc == 0x0b)
    {
        return(keypadNum[rowloc][1]);
    }
    else
    {
        return(keypadNum[rowloc][0]);
    }
}

int InputNum = 0, InputNumTemp = 0;
void main(void) {
    
    LCD_Configuration();
    while(1)
    {
        InputNum = Keyfind();
        if(InputNum <= 9)
        {
            lcd_number(InputNum);
            InputNumTemp = InputNumTemp*10 + InputNum;
        }
        else
        {
            InputNum = InputNumTemp;
            InputNumTemp = 0;
            lcd_command(Goto2);
            lcd_number(InputNum+1);
        }
        __delay_ms(100);
        
    }
    return;
}



