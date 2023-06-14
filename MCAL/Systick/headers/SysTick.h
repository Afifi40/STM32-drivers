

#ifndef _SYSTICK_H_
#define _SYSTICK_H_
#include "..\..\common\MCU_hw.h"
#define CPU_F 16000000

void Systickinit (uint8, uint32);
void SystickDisable(void);

void SystickInterruptEnable (void);
void SystickInterruptDisable(void);
void SystickSetReloadVal(uint32 reloadVal);
uint32 SystickGetCountVal(void);

uint8 SystickIsDone(void);



#endif
