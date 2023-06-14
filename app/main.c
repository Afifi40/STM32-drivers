#include "..\MCAL\common\MCU_hw.h"
#include "..\MCAL\GPIO\headers\GPIO.h"
#include "..\MCAL\IntCtrl\headers\IntCtrl.h"
#include "..\MCAL\Systick\headers\SysTick.h"
#include "..\MCAL\Timer\headers\Timer.h"
//ASSUME FREQUENCY =  16000000

/*Interrupt Handlers prototypes*/
void TIMER0A_Handler(void);

/*prototype functions*/
void set_on_time_ms(uint32);
void set_off_time_ms(uint32);
/*global variables*/

uint32 on_time;
uint32 off_time;

/*main*/
int main(void){
		set_on_time_ms(1000);
		set_off_time_ms(500);
    GPIOPortInit(PORTF);
    GPIODigital_Mode(PORTF, PIN1, TRUE);
    GPIODirModeSet(PORTF, PIN1, GPIO_DIR_MODE_OUT);
    //Systickinit(1,F_CPU/1000);

    TimerInit(TIMER0, TIMERA, PERIODIC, 63, 253);
    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0, TIMERA_TIME_OUT);


    while(1){} //super loop
}

void set_on_time_ms(uint32 time){
	on_time = time;
}
void set_off_time_ms(uint32 time){
	off_time = time;
}

void TIMER0A_Handler(void){
    static uint32 counter=0;
    static uint8 isOn=0;
    counter++;
    if(isOn && counter >= on_time){
        GPIOPinWrite(PORTF, PIN1, DIGITAL_LOW);
        isOn=0;
        counter=0;
    }
    else if(!isOn && counter >= off_time){
        GPIOPinWrite(PORTF, PIN1, DIGITAL_HIGH);
        isOn=1;
        counter=0;
    }

}
