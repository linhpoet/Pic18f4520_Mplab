# 1 "newAsmTemplate.asm"
# 1 "<built-in>" 1
# 1 "newAsmTemplate.asm" 2
PROCESSOR PIC18F4520
 #INCLUDE <P18F4520.INC>

__CONFIG _HS_OSC&_WDT_OFF&_CP_OFF&_BODEN_OFF&_PWRTE_OFF&_WRT_OFF&_CPD_OFF&_LVP_OFF
    DEM EQU 0X20
    ORG 0X00

    GOTO MAIN
    MAIN
    BANKSEL TRISB
    CLRF TRISB
    BANKSEL TRISB
    CLRF DEM
    MOVF DEM, 0
    CALL MANG_MA

    MANG_MA
    ADD
