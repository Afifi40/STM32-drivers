#include "headers\IntCtrl.h"
#include "headers\IntCtrl_Types.h"


void IntEnable (uint8 int_num){
    INTERRUPT_ENABLE(int_num);
}

void IntDisable (uint8 int_num){
    INTERRUPT_DISABLE(int_num);
}

uint32  IntIsEnabled (uint8 int_num){
	return INTERRUPT_ENABLE_READ(int_num);
}

void IntPendClear (uint8 int_num){
	INTERRUPT_UNPEND(int_num);
}

void IntPendSet (uint8 int_num){
    INTERRUPT_PEND(int_num);
}

/*
void INT_init(void){
    NVIC_APINT = 0x05FA0000 | 3;

}

void IntDisable (u32 ui32Interrupt){
        *(&NVIC_DIS0 + ui32Interrupt)=1;
}
*/
