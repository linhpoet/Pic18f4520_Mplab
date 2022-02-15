
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "MyLcd16.h"

void main(void) {
    unsigned int cnt = 0;
    DataTrist = 0;
    CommandTrist = 0;
    CommandPort = 0;
    PortData = 0;
    lcd_command(Mode8bit2line);					//8bit, 2 dong
	lcd_command(DisplayOn);						//bat hien thi
	lcd_command(ClearDisplay);					//clear
	lcd_number(0);
	lcd_string(" chuc 3 mung");
    
    while (1)
    {   cnt = ((TMR1H << 8) | TMR1L);       //ghep 2 thanh ghi high va low vao bien 16bit(unsign int) cnt
        lcd_command(Goto2);
        lcd_number(cnt);
    }
        
    return;
}

Timer1_Configuration(void)
{
    PIE1bits.TMR1IE = 0;        //disable interrupt
    
    T1CONbits.TMR1ON = 1;      //enable timer        
    T1CONbits.TMR1CS = 1;       //1 = External clock from pin RC0/T1OSO/T13CKI (on the rising edge)
    
    //prescale 1:1  
    T1CONbits.T1CKPS0 = 0;
    T1CONbits.T1CKPS1 = 0;
    
    //clock of timer1 =5M -> Number of stick: 2^16 -5000 = 60536 stick
    TMR1L = 0;
    TMR1H = 0;
}

