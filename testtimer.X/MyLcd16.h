#include <string.h>
#include <stdio.h>
#include <xc.h>

#define _XTAL_FREQ      8000000

#define Mode8bit2line   0x38
#define DisplayOn       0x0c
#define ClearDisplay    0x01
#define Goto1           0x80
#define Goto2           0xc0

#define RS              3
#define RW              1
#define E               2
#define PortData        PORTD       //PORTB     PORTC
#define CommandPort     PORTC       //PORTC     PORTD
#define DataTrist       TRISD
#define CommandTrist    TRISC
void lcd_command(char cmnd);
void lcd_char(char data);
void lcd_string(char *str);
void lcd_number(int num);