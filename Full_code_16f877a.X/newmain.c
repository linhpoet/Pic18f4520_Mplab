
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic18f4520.h>
#include "MyLcd16.h"

#define TMR2PRESCALE    4
#define ppr             24      //pulses per revolution of encoder
long u32TempFrequency;
unsigned int state;

Timer1_Configuration(void)
{   
    T1CON = 0x03;
    TMR1L = 0;                  //clear tmr1l
    TMR1H = 0;                  //clear tmr1h
}

L298_Configuration()
{       
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC4 = 0;
    PORTCbits.RC3 = 0;                      //IN2 ouput = 0
    PORTCbits.RC4 = 1;                      //ENA output = 1
}

void PWM1_Start(void)
{
    //......Mode PWM on CCP1......//
    CCP1M3 = 1;
    CCP1M2 = 1;
    
    if (TMR2PRESCALE == 1)
    {
        T2CKPS0 = 0;
        T2CKPS1 = 0;
    }
    if (TMR2PRESCALE == 4)
    {
        T2CKPS0 = 1;
        T2CKPS1 = 0;
    }
    if (TMR2PRESCALE == 16)
    {
        T2CKPS0 = 1;
        T2CKPS1 = 1;
    }
    TMR2ON = 1;
    TRISC2 = 0;
}

//.........ham tinh PR2(so tick trong 1 chu ky PWM), gia tri vao u32Frequency la tan so mong muon cua PWM.......//
PWM1_Init(long u32Frequency)
{
    PR2 = (_XTAL_FREQ/(u32Frequency*4*TMR2PRESCALE)-1);     //dung cong thuc, 0<=PR2<=255, nen chu y gia tri u32Frequency dua vao
    u32TempFrequency = u32Frequency;                        //luu lai gia tri u32Frequency de dung cho viec tinh Duty cycle
}

PWM1_Duty(unsigned int duty)                //duty dua vao la gia tri PWM mong muon, thi PWM hoat dong voi x=duty*100/1000 (%) 
{
    if (duty<1024)
    {
        duty = ((float)duty/1023)*(_XTAL_FREQ/(u32TempFrequency*TMR2PRESCALE));     //dung cong thuc
        CCP1X = duty & 2;
        CCP1Y = duty & 1;
        CCPR1L = duty >> 2;
    }
}

void Interrupt123_Configuration()
{
    TRISB = 0xff;
    PORTB = 0xff;
    INTCON = 0;
    INTCONbits.GIE = 1;                 //Enable global interrupt
    INTCONbits.INT0IE = 1;              //Enable the INT0 external interrupt
    INTEDG0 = 1;                        //Interrupt falling edge
    
    INTCON3 = 0;
    INTCON3bits.INT1IE = 1;              //Enable the INT0 external interrupt
    INTEDG1 = 1;                        //Interrupt falling edge
    
    INTCON3bits.INT2IE = 1;              //Enable the INT0 external interrupt
    INTEDG2 = 1;                        //Interrupt rising edge
}

void PortB_Int_Configuration()
{
    TRISB = 0xff;
    PORTB = 0xff;
    INTCON = 0;
    INTCONbits.RBIE = 1;                //Enable Port B interrupt
    INTCONbits.GIE = 1;                 //Enable global interrupt
}

void __interrupt() funtion()
{
    if (INTCONbits.RBIF == 1)
    {
        if (PORTBbits.RB4 == 0) 
        {
            RD4 = ~RD4;
            if (state == 0)
            {
                state = 1;
                PWM1_Duty(256);
            } else
            {
                state = 0;
                PWM1_Duty(0);
            }
        }
        if (PORTBbits.RB5 == 0) 
        {   
            RD5 = ~RD5;
            if (state == 1)
            {
                state = 2;
                PWM1_Duty(512);
            } else if (state == 2)
            {
                state = 3;
                PWM1_Duty(1023);
            }
        }
        if (PORTBbits.RB6 == 0) 
        {
            RD6 = ~RD6;
            if (state == 3)
            {
                state = 2;
                PWM1_Duty(512);
            } else if (state == 2)
            {
                state = 1;
                PWM1_Duty(256);
            }
        }
    }
    INTCONbits.RBIF = 0;
}

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
	char x = 0x22;
    lcd_number(x);
	lcd_string(" chuc 23 mung");
}

void main(void) {
    unsigned int cnt_pre, cnt_af, rate;
    LCD_Configuration();  
    Timer1_Configuration();                   
    L298_Configuration();
    PWM1_Init(5000);                        //Pwm period = 1/5000 (s)
    PWM1_Duty(0);                        //duty =1023, PWM 100%
    PWM1_Start();    
    //.........cau hinh nut nhan........//
    //Interrupt_Configuration();
    PortB_Int_Configuration();
    TRISD = 0;
    PORTD = 0;
    
    while (1)
    {   
        cnt_pre = ((TMR1H << 8) | TMR1L);       //ghep 2 thanh ghi high va low vao bien 16bit(unsign int) cnt
        __delay_ms(1000);
        cnt_af = ((TMR1H << 8) | TMR1L);
        rate = (cnt_af - cnt_pre)/ppr;                   //van toc
        lcd_command(Goto2);
        lcd_number(rate);       
    }
        
    return;
}




void main(void) {
    return;
}
