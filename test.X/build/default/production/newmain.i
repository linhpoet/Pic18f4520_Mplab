# 1 "newmain.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "newmain.c" 2
# 14 "newmain.c"
#pragma config OSC = RCIO6
#pragma config FCMEN = OFF
#pragma config IESO = OFF


#pragma config PWRT = OFF
#pragma config BOREN = OFF
#pragma config BORV = 3


#pragma config WDT = OFF
#pragma config WDTPS = 32768


#pragma config CCP2MX = PORTC
#pragma config PBADEN = OFF
#pragma config LPT1OSC = OFF
#pragma config MCLRE = OFF


#pragma config STVREN = OFF
#pragma config LVP = OFF
#pragma config XINST = OFF


#pragma config CP0 = OFF
#pragma config CP1 = OFF
#pragma config CP2 = OFF
#pragma config CP3 = OFF


#pragma config CPB = OFF
#pragma config CPD = OFF


#pragma config WRT0 = OFF
#pragma config WRT1 = OFF
#pragma config WRT2 = OFF
#pragma config WRT3 = OFF


#pragma config WRTC = OFF
#pragma config WRTB = OFF
#pragma config WRTD = OFF


#pragma config EBTR0 = OFF
#pragma config EBTR1 = OFF
#pragma config EBTR2 = OFF
#pragma config EBTR3 = OFF


#pragma config EBTRB = OFF





# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\xc.h" 1 3
# 18 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\xc.h" 3
extern const char __xc8_OPTIM_SPEED;

extern double __fpnormalize(double);



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\xc8debug.h" 1 3
# 13 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\xc8debug.h" 3
#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 23 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\xc.h" 2 3

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\builtins.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 1 3
# 13 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef signed char int8_t;






typedef signed int int16_t;







typedef __int24 int24_t;







typedef signed long int int32_t;
# 52 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint8_t;





typedef unsigned int uint16_t;






typedef __uint24 uint24_t;






typedef unsigned long int uint32_t;
# 88 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_least8_t;







typedef signed int int_least16_t;
# 109 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_least24_t;
# 118 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef signed long int int_least32_t;
# 136 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint_least8_t;






typedef unsigned int uint_least16_t;
# 154 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_least24_t;







typedef unsigned long int uint_least32_t;
# 181 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef signed char int_fast8_t;






typedef signed int int_fast16_t;
# 200 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef __int24 int_fast24_t;







typedef signed long int int_fast32_t;
# 224 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
# 240 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef __uint24 uint_fast24_t;






typedef unsigned long int uint_fast32_t;
# 268 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef int32_t intmax_t;
# 282 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 3
typedef uint32_t uintmax_t;






typedef int16_t intptr_t;




typedef uint16_t uintptr_t;
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\builtins.h" 2 3



#pragma intrinsic(__nop)
extern void __nop(void);


#pragma intrinsic(_delay)
extern __attribute__((nonreentrant)) void _delay(uint32_t);
#pragma intrinsic(_delaywdt)
extern __attribute__((nonreentrant)) void _delaywdt(uint32_t);
# 24 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\xc.h" 2 3




# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\pic.h" 1 3




# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\htc.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\xc.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\htc.h" 2 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\pic.h" 2 3








# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\pic_chip_select.h" 1 3
# 149 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\pic_chip_select.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 1 3
# 45 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\__at.h" 1 3
# 45 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 2 3








extern volatile unsigned char INDF __attribute__((address(0x000)));

__asm("INDF equ 00h");


typedef union {
    struct {
        unsigned INDF :8;
    };
} INDFbits_t;
extern volatile INDFbits_t INDFbits __attribute__((address(0x000)));
# 73 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile unsigned char TMR0 __attribute__((address(0x001)));

__asm("TMR0 equ 01h");


typedef union {
    struct {
        unsigned TMR0 :8;
    };
} TMR0bits_t;
extern volatile TMR0bits_t TMR0bits __attribute__((address(0x001)));
# 93 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile unsigned char PCL __attribute__((address(0x002)));

__asm("PCL equ 02h");


typedef union {
    struct {
        unsigned PCL :8;
    };
} PCLbits_t;
extern volatile PCLbits_t PCLbits __attribute__((address(0x002)));
# 113 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile unsigned char STATUS __attribute__((address(0x003)));

__asm("STATUS equ 03h");


typedef union {
    struct {
        unsigned C :1;
        unsigned DC :1;
        unsigned Z :1;
        unsigned nPD :1;
        unsigned nTO :1;
        unsigned PA0 :1;
        unsigned CWUF :1;
        unsigned GPWUF :1;
    };
    struct {
        unsigned CARRY :1;
        unsigned :1;
        unsigned ZERO :1;
    };
} STATUSbits_t;
extern volatile STATUSbits_t STATUSbits __attribute__((address(0x003)));
# 190 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile unsigned char FSR __attribute__((address(0x004)));

__asm("FSR equ 04h");


typedef union {
    struct {
        unsigned FSR :8;
    };
} FSRbits_t;
extern volatile FSRbits_t FSRbits __attribute__((address(0x004)));
# 210 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile unsigned char OSCCAL __attribute__((address(0x005)));

__asm("OSCCAL equ 05h");


typedef union {
    struct {
        unsigned :1;
        unsigned CAL :7;
    };
    struct {
        unsigned :1;
        unsigned CAL0 :1;
        unsigned CAL1 :1;
        unsigned CAL2 :1;
        unsigned CAL3 :1;
        unsigned CAL4 :1;
        unsigned CAL5 :1;
        unsigned CAL6 :1;
    };
} OSCCALbits_t;
extern volatile OSCCALbits_t OSCCALbits __attribute__((address(0x005)));
# 276 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile unsigned char GPIO __attribute__((address(0x006)));

__asm("GPIO equ 06h");


typedef union {
    struct {
        unsigned GP :6;
    };
    struct {
        unsigned GP0 :1;
        unsigned GP1 :1;
        unsigned GP2 :1;
        unsigned GP3 :1;
        unsigned GP4 :1;
        unsigned GP5 :1;
    };
} GPIObits_t;
extern volatile GPIObits_t GPIObits __attribute__((address(0x006)));
# 334 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile unsigned char CM1CON0 __attribute__((address(0x007)));

__asm("CM1CON0 equ 07h");


typedef union {
    struct {
        unsigned nC1WU :1;
        unsigned C1PREF :1;
        unsigned C1NREF :1;
        unsigned C1ON :1;
        unsigned nC1T0CS :1;
        unsigned C1POL :1;
        unsigned nC1OUTEN :1;
        unsigned C1OUT :1;
    };
} CM1CON0bits_t;
extern volatile CM1CON0bits_t CM1CON0bits __attribute__((address(0x007)));
# 396 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile unsigned char ADCON0 __attribute__((address(0x008)));

__asm("ADCON0 equ 08h");


typedef union {
    struct {
        unsigned ADON :1;
        unsigned GO_nDONE :1;
        unsigned CHS :2;
        unsigned ADCS :2;
        unsigned ANS :2;
    };
    struct {
        unsigned :1;
        unsigned GO :1;
        unsigned CHS0 :1;
        unsigned CHS1 :1;
        unsigned ADCS0 :1;
        unsigned ADCS1 :1;
        unsigned ANS0 :1;
        unsigned ANS1 :1;
    };
    struct {
        unsigned :1;
        unsigned nDONE :1;
    };
} ADCON0bits_t;
extern volatile ADCON0bits_t ADCON0bits __attribute__((address(0x008)));
# 494 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile unsigned char ADRES __attribute__((address(0x009)));

__asm("ADRES equ 09h");


typedef union {
    struct {
        unsigned ADRES :8;
    };
} ADRESbits_t;
extern volatile ADRESbits_t ADRESbits __attribute__((address(0x009)));
# 514 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile __control unsigned char OPTION __attribute__((address(0x000)));



extern volatile __control unsigned char TRIS __attribute__((address(0x006)));



extern volatile __control unsigned char TRISGPIO __attribute__((address(0x006)));
# 545 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\proc\\mcv08a.h" 3
extern volatile __bit ADCS0 __attribute__((address(0x44)));


extern volatile __bit ADCS1 __attribute__((address(0x45)));


extern volatile __bit ADON __attribute__((address(0x40)));


extern volatile __bit ANS0 __attribute__((address(0x46)));


extern volatile __bit ANS1 __attribute__((address(0x47)));


extern volatile __bit C1NREF __attribute__((address(0x3A)));


extern volatile __bit C1ON __attribute__((address(0x3B)));


extern volatile __bit C1OUT __attribute__((address(0x3F)));


extern volatile __bit C1POL __attribute__((address(0x3D)));


extern volatile __bit C1PREF __attribute__((address(0x39)));


extern volatile __bit CAL0 __attribute__((address(0x29)));


extern volatile __bit CAL1 __attribute__((address(0x2A)));


extern volatile __bit CAL2 __attribute__((address(0x2B)));


extern volatile __bit CAL3 __attribute__((address(0x2C)));


extern volatile __bit CAL4 __attribute__((address(0x2D)));


extern volatile __bit CAL5 __attribute__((address(0x2E)));


extern volatile __bit CAL6 __attribute__((address(0x2F)));


extern volatile __bit CARRY __attribute__((address(0x18)));


extern volatile __bit CHS0 __attribute__((address(0x42)));


extern volatile __bit CHS1 __attribute__((address(0x43)));


extern volatile __bit CWUF __attribute__((address(0x1E)));


extern volatile __bit DC __attribute__((address(0x19)));


extern volatile __bit GO __attribute__((address(0x41)));


extern volatile __bit GO_nDONE __attribute__((address(0x41)));


extern volatile __bit GP0 __attribute__((address(0x30)));


extern volatile __bit GP1 __attribute__((address(0x31)));


extern volatile __bit GP2 __attribute__((address(0x32)));


extern volatile __bit GP3 __attribute__((address(0x33)));


extern volatile __bit GP4 __attribute__((address(0x34)));


extern volatile __bit GP5 __attribute__((address(0x35)));


extern volatile __bit GPWUF __attribute__((address(0x1F)));


extern volatile __bit PA0 __attribute__((address(0x1D)));


extern volatile __bit ZERO __attribute__((address(0x1A)));


extern volatile __bit nC1OUTEN __attribute__((address(0x3E)));


extern volatile __bit nC1T0CS __attribute__((address(0x3C)));


extern volatile __bit nC1WU __attribute__((address(0x38)));


extern volatile __bit nDONE __attribute__((address(0x41)));


extern volatile __bit nPD __attribute__((address(0x1B)));


extern volatile __bit nTO __attribute__((address(0x1C)));
# 149 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\pic_chip_select.h" 2 3
# 13 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\pic.h" 2 3
# 76 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\pic.h" 3
__attribute__((__unsupported__("The " "FLASH_READ" " macro function is no longer supported. Please use the MPLAB X MCC."))) unsigned char __flash_read(unsigned short addr);

__attribute__((__unsupported__("The " "FLASH_WRITE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_write(unsigned short addr, unsigned short data);

__attribute__((__unsupported__("The " "FLASH_ERASE" " macro function is no longer supported. Please use the MPLAB X MCC."))) void __flash_erase(unsigned short addr);



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\eeprom_routines.h" 1 3
# 83 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\pic.h" 2 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\pic.h" 3
extern __bank0 unsigned char __resetbits;
extern __bank0 __bit __powerdown;
extern __bank0 __bit __timeout;
# 28 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\xc.h" 2 3
# 71 "newmain.c" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdint.h" 1 3
# 72 "newmain.c" 2


void main(void)
{

}
