#include "My_Lcd_4bit_lib.h"
#include <xc.h>


void lcd_command(char cmnd)
{
    /*(gui lenh) gui 4 bit co trong so cao(b4-7) ma khong lam anh huong cac bit con lai trong Portdata*/
    PortData =(PortData & 0x0F) | (cmnd & 0xF0);            
    /*RW=0,*/
	CommandPort &= ~(1<<RW);
    /*RS=0, ghi lenh*/
	CommandPort &= ~(1<<RS);			

	/*generate falling edge*/
	CommandPort |= (1<<E);
	__delay_ms(1);
    CommandPort &= ~(1<<E);
	__delay_ms(200);
    
    /*(gui lenh) gui 4 bit co trong so thap*/
    PortData = (PortData & 0x0F) | (cmnd << 4);      
    
    /*generate falling edge*/
	CommandPort |= (1<<E);
	__delay_ms(1);
    CommandPort &= ~(1<<E);
	__delay_ms(3);

}
void lcd_char(char data)
{  
   /*(gui lenh) gui 4 bit co trong so cao(b4-7) ma khong lam anh huong cac bit con lai trong Portdata*/
   PortData =(PortData & 0x0F) | (data & 0xF0);
   /*RW=0*/
    CommandPort &= ~(1<<RW);		
    /*RS=1, ghi du lieu*/
	CommandPort |= (1<<RS);			

	/*generate falling edge */
	CommandPort |= (1<<E);
	__delay_ms(1);
    CommandPort &= ~(1<<E);
	__delay_ms(200);
    
    /*(gui lenh) gui 4 bit co trong so thap*/
    PortData = (PortData & 0x0F) | (data << 4);         
    
    /*generate falling edge*/
	CommandPort |= (1<<E);
	__delay_ms(1);
    CommandPort &= ~(1<<E);
	__delay_ms(3);
}
void lcd_string(char *str)
{
	for(int i=0; i<strlen(str); i++)
	{
		lcd_char(str[i]);
	}
}

void lcd_number(int num)
{   
    /*ban dau = 10000, co the lay lon hon nen num>100.000*/
    int num_div = 10000;                                
    int num_test = num;
    int num_display=0;
    while (num_test/num_div <= 0 )                      
    {   
        /*tim ra so 10xxx < num gan nhat de thuc hien phep chia*/
        num_div /= 10;                                   
    }
    
    do 
    {
        num_display = num_test/num_div;
        lcd_char(num_display + 48U);
        num_test = num_test - num_div*num_display;
        num_div /= 10;
    }
    while (num_div>=1);
}