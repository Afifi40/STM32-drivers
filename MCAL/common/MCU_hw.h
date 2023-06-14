/*
 * register.h
 *
 *  Created on: Dec 29, 2021
 *      Author: ahmed afifi
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~((uint32)(1 << BIT))) //had to cast to remove warning
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT)  ((REG >> BIT) & 1)

//typedef unsigned long uint64; // not sure if correct
typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

typedef signed int sint32;

typedef enum {FALSE=0,TRUE=1}bool;
struct GPTM{
    uint32 GPTMCFG     ;
    uint32 GPTMTAMR    ;
    uint32 GPTMTBMR    ;
    uint32 GPTMCTL     ;
    uint32 GPTMSYNC    ;
    uint32 GPTMnon1;
    uint32 GPTMIMR     ;
    uint32 GPTMRIS     ;
    uint32 GPTMMIS     ;
    uint32 GPTMICR     ;
    uint32 GPTMTAILR   ;
    uint32 GPTMTBILR   ;
    uint32 GPTMTAMATCHR;
    uint32 GPTMTBMATCHR;
    uint32 GPTMTAPR    ;
    uint32 GPTMTBPR    ;
    uint32 GPTMTAPMR   ;
    uint32 GPTMTBPMR   ;
    uint32 GPTMTAR     ;
    uint32 GPTMTBR     ;
    uint32 GPTMTAV     ;
    uint32 GPTMTBV     ;
    uint32 GPTMRTCPD   ;
    uint32 GPTMTAPS    ;
    uint32 GPTMTBPS    ;
    uint32 GPTMTAPV    ;
    uint32 GPTMTBPV    ;
};

struct GPIO{
    uint32 GPIODATA[256] ; // 0x0 --
    uint32 GPIODIR  ;      // 0x400
    uint32 GPIOIS   ;
    uint32 GPIOIBE  ;
    uint32 GPIOIEV  ;
    uint32 GPIOIM   ;
    uint32 GPIORIS  ;
    uint32 GPIOMIS  ;
    uint32 GPIOICR  ;
    uint32 GPIOAFSEL;      // 0x420
    uint32 non[55]  ;      // 0x424 -- 500
    uint32 GPIODR2R   ;
    uint32 GPIODR4R   ;
    uint32 GPIODR8R   ;
    uint32 GPIOODR    ;
    uint32 GPIOPUR    ;
    uint32 GPIOPDR    ;
    uint32 GPIOSLR    ;
    uint32 GPIODEN    ;
    uint32 GPIOLOCK   ;
    uint32 GPIOCR     ;
    uint32 GPIOAMSEL  ;
    uint32 GPIOPCTL   ;
    uint32 GPIOADCCTL ;
    uint32 GPIODMACTL ;
};

struct NVIC_R{
    uint32 EN[5];
    uint32 non1[27];
    uint32 DIS[5];
    uint32 non2[27];
    uint32 PEND[5];
    uint32 non3[27];
    uint32 UNPEND[5];
    uint32 non4[27];
    uint32 ACTIVE[5];
    uint32 non5[27];
    uint8 pri[140];
};

struct SysTick_R{
    uint32 STCTRL;
    uint32 STRELOAD;
    uint32 STCURRENT;
};







struct UART{
    uint32 UARTDR; // 0
    uint32 UARTRSR; // 4
    uint32 non1[4];   // 8 12 0 4
    uint32 UARTFR;   // 18
    uint32 non2;     // 1c
    uint32 UARTILPR;  // 20
    uint32 UARTIBRD; // 24
    uint32 UARTFBRD; // 28
    uint32 UARTLCRH; // 2c
    uint32 UARTCTL;
    uint32 UARTIFLS;
    uint32 UARTIM;
    uint32 UARTRIS;
    uint32 UARTMIS;
    uint32 UARTICR;
    uint32 non3[3968];
    uint32 UARTCC;

};

struct I2C{
    uint32 MSA      ;
    uint32 MCS      ;
    uint32 MDR      ;
    uint32 MTPR     ;
    uint32 MIMR     ;
    uint32 MRIS     ;
    uint32 MMIS     ;
    uint32 MICR     ;
    uint32 MCR      ;
    uint32 non4     ;
    uint32 MCLKOCNT ;
    uint32 MBMON    ;
    uint32 non[2]   ;
    uint32 MCR2     ;
    uint32 non1[497];
    uint32 SOAR     ;
    uint32 SCSR     ;
    uint32 SDR      ;
    uint32 SIMR     ;
    uint32 SRIS     ;
    uint32 SMIS     ;
    uint32 SICR     ;
    uint32 SOAR2    ;
    uint32 SACKCTL  ;
    uint32 non2[487] ;
    uint32 PP       ;
    uint32 PC       ;
};

struct PWM{
    uint32 CTL         ;
    uint32 SYNC        ;
    uint32 ENABLE      ;
    uint32 INVERT      ;
    uint32 FAULT       ;
    uint32 INTEN       ;
    uint32 RIS         ;
    uint32 ISC         ;
    uint32 STATUS      ;
    uint32 FAULTVAL    ;
    uint32 ENUPD       ;
    uint32 non[5]      ;

    uint32 _0CTL        ;
    uint32 _0INTEN      ;
    uint32 _0RIS        ;
    uint32 _0ISC        ;
    uint32 _0LOAD       ;
    uint32 _0COUNT      ;
    uint32 _0CMPA       ;
    uint32 _0CMPB       ;
    uint32 _0GENA       ;
    uint32 _0GENB       ;
    uint32 _0DBCTL      ;
    uint32 _0DBRISE     ;
    uint32 _0DBFALL     ;
    uint32 _0FLTSRC0    ;
    uint32 _0FLTSRC1    ;
    uint32 _0MINFLTPER  ;

    uint32 _1CTL        ;
    uint32 _1INTEN      ;
    uint32 _1RIS        ;
    uint32 _1ISC        ;
    uint32 _1LOAD       ;
    uint32 _1COUNT      ;
    uint32 _1CMPA       ;
    uint32 _1CMPB       ;
    uint32 _1GENA       ;
    uint32 _1GENB       ;
    uint32 _1DBCTL      ;
    uint32 _1DBRISE     ;
    uint32 _1DBFALL     ;
    uint32 _1FLTSRC0    ;
    uint32 _1FLTSRC1    ;
    uint32 _1MINFLTPER  ;

    uint32 _2CTL        ;
    uint32 _2INTEN      ;
    uint32 _2RIS        ;
    uint32 _2ISC        ;
    uint32 _2LOAD       ;
    uint32 _2COUNT      ;
    uint32 _2CMPA       ;
    uint32 _2CMPB       ;
    uint32 _2GENA       ;
    uint32 _2GENB       ;
    uint32 _2DBCTL      ;
    uint32 _2DBRISE     ;
    uint32 _2DBFALL     ;
    uint32 _2FLTSRC0    ;
    uint32 _2FLTSRC1    ;
    uint32 _2MINFLTPER  ;

    uint32 _3CTL        ;
    uint32 _3INTEN      ;
    uint32 _3RIS        ;
    uint32 _3ISC        ;
    uint32 _3LOAD       ;
    uint32 _3COUNT      ;
    uint32 _3CMPA       ;
    uint32 _3CMPB       ;
    uint32 _3GENA       ;
    uint32 _3GENB       ;
    uint32 _3DBCTL      ;
    uint32 _3DBRISE     ;
    uint32 _3DBFALL     ;
    uint32 _3FLTSRC0    ;
    uint32 _3FLTSRC1    ;
    uint32 _3MINFLTPER  ;
};



struct ADC{
    uint32 ADCACTSS   ;
    uint32 ADCRIS     ;
    uint32 ADCIM      ;
    uint32 ADCISC     ;
    uint32 ADCOSTAT   ;
    uint32 ADCEMUX    ;
    uint32 ADCUSTAT   ;
    uint32 ADCTSSEL   ;
    uint32 ADCSSPRI   ;
    uint32 ADCSPC     ;
    uint32 ADCPSSI    ;
    uint32 non1       ;
    uint32 ADCSAC     ;
    uint32 ADCDCISC   ;
    uint32 ADCCTL     ;
    uint32 non2       ;
    uint32 ADCSSMUX0  ;
    uint32 ADCSSCTL0  ;
    uint32 ADCSSFIFO0 ;
    uint32 ADCSSFSTAT0;
    uint32 ADCSSOP0   ;
    uint32 ADCSSDC0   ;
    uint32 non3[2]    ;
    uint32 ADCSSMUX1  ;
    uint32 ADCSSCTL1  ;
    uint32 ADCSSFIFO1 ;
    uint32 ADCSSFSTAT1;
    uint32 ADCSSOP1   ;
    uint32 ADCSSDC1   ;
    uint32 non4[2]    ;
    uint32 ADCSSMUX2  ;
    uint32 ADCSSCTL2  ;
    uint32 ADCSSFIFO2 ;
    uint32 ADCSSFSTAT2;
    uint32 ADCSSOP2   ;
    uint32 ADCSSDC2   ;
    uint32 non5[2]    ;
    uint32 ADCSSMUX3  ;
    uint32 ADCSSCTL3  ;
    uint32 ADCSSFIFO3 ; // 0xA8
    uint32 ADCSSFSTAT3;
    uint32 ADCSSOP3   ;
    uint32 ADCSSDC3   ;

    uint32 non6[786]  ;
    uint32 ADCDCRIC   ;
    uint32 non7[63]   ;
    uint32 ADCDCCTL0  ;
    uint32 ADCDCCTL1  ;
    uint32 ADCDCCTL2  ;
    uint32 ADCDCCTL3  ;
    uint32 ADCDCCTL4  ;
    uint32 ADCDCCTL5  ;
    uint32 ADCDCCTL6  ;
    uint32 ADCDCCTL7  ;
    uint32 ADCDCCMP0  ;
    uint32 ADCDCCMP1  ;
    uint32 ADCDCCMP2  ;
    uint32 ADCDCCMP3  ;
    uint32 ADCDCCMP4  ;
    uint32 ADCDCCMP5  ;
    uint32 ADCDCCMP6  ;
    uint32 ADCDCCMP7  ;
    uint32 non8[88]   ;
    uint32 ADCPP      ;
    uint32 ADCPC      ;
    uint32 ADCCC      ;
};

struct SPI{
    uint32 CR0    ;
    uint32 CR1    ;
    uint32 DR     ;
    uint32 SR     ;
    uint32 CPSR   ;
    uint32 IM     ;
    uint32 RIS    ;
    uint32 MIS    ;
    uint32 ICR    ;
    uint32 MACTL ;
};


#define RCGCGPIO  *((volatile uint32 *)0x400fE608)
#define RCGC2GPIO *((volatile uint32 *)0x400fE108)

#define RCGCUART  *((volatile uint32 *)0x400fE618)
#define RCGCI2C   *((volatile uint32 *)0x400fE620)
#define RCGCADC   *((volatile uint32 *)0x400fE638)
#define PRGPIO    *((volatile uint32 *)0x400fEa08)
#define RCGCPWM   *((volatile uint32 *)0x400fE640)
#define RCGCTIMER *((volatile uint32 *)0x400fE604)
#define RCGCSSI   *((volatile uint32 *)0x400fE61c)

#define RCGC1     *((volatile uint32 *)0x400fE104)

#define RCC       *((volatile uint32 *)0x400fE060)
#define I2C_MDR   *((volatile uint32 *)0x40020008)


#define GPIOA (*((volatile struct GPIO *)0x40004000))
#define GPIOB (*((volatile struct GPIO *)0x40005000))
#define GPIOC (*((volatile struct GPIO *)0x40006000))
#define GPIOD (*((volatile struct GPIO *)0x40007000))
#define GPIOE (*((volatile struct GPIO *)0x40024000))
#define GPIOF (*((volatile struct GPIO *)0x40025000))

#define NVIC    (*((volatile struct NVIC_R* )  0xE000E100))

#define SysTick (*((volatile struct SysTick_R*)0xE000E010))

#define UART5 (*((volatile struct UART *)0x40011000))
#define UART0 (*((volatile struct UART *)0x4000C000))

#define I2C0  (*((volatile struct I2C *)0x40020000))
#define I2C1  (*((volatile struct I2C *)0x40021000))
#define I2C2  (*((volatile struct I2C *)0x40022000))
#define I2C3  (*((volatile struct I2C *)0x40023000))

#define GPTM0   (*((volatile struct GPTM *)0x40030000))
#define GPTM1   (*((volatile struct GPTM *)0x40031000))
#define GPTM2   (*((volatile struct GPTM *)0x40032000))
#define GPTM3   (*((volatile struct GPTM *)0x40033000))
#define GPTM4   (*((volatile struct GPTM *)0x40034000))
#define GPTM5   (*((volatile struct GPTM *)0x40035000))

#define PWM0  (*((volatile struct PWM *)0x40028000))
#define PWM1  (*((volatile struct PWM *)0x40029000))

#define ADC0  (*((volatile struct ADC *)0x40038000))
#define ADC1  (*((volatile struct ADC *)0x40039000))

#define SSI0  (*((volatile struct SPI *)0x40008000))
#define SSI1  (*((volatile struct SPI *)0x40009000))
#define SSI2  (*((volatile struct SPI *)0x4000A000))
#define SSI3  (*((volatile struct SPI *)0x4000B000))

#endif /* REGISTER_H_ */
