#include "headers\SysTick.h"
#include "headers\SysTick_Types.h"

void Systickinit (uint8 IntEn, uint32 reloadVal){
	SYSTICK_DISABLE;
	if(IntEn)
			SYSTICK_INTERRUPT_ENABLE;
	else
			SYSTICK_INTERRUPT_DISABLE;
	SET_RELOAD_VAL(reloadVal);
	SYSTICK_ENABLE;
}

void SystickDisable(void){
	SYSTICK_DISABLE;
}

void SystickInterruptEnable(void){
	SYSTICK_INTERRUPT_ENABLE;
}

void SystickInterruptDisable(void){
	SYSTICK_INTERRUPT_DISABLE;
}

uint8 SystickIsDone(void){
	return (bool)GET_COUNT_STATUS;
}

void SystickSetReloadVal(uint32 reloadVal){
	SYSTICK_ENABLE;
	SET_RELOAD_VAL(reloadVal);
	SYSTICK_DISABLE;
}


uint32 SystickGetCountVal(void){
	return GET_COUNT_VAL;
}

