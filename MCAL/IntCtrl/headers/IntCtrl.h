
#ifndef _INTCTRL_H_
#define _INTCTRL_H_
/*************Library Inclusion************/

#include "..\..\common\MCU_hw.h"

/****************** IVT *******************/
#define INT_GPIOA	0
#define INT_GPIOB   1
#define INT_GPIOC	2
#define INT_GPIOD   3
#define INT_GPIOE	4
#define INT_TIMER0A 19
/*************************/
//void INT_init(void);


void IntDisable   (uint8);
void IntEnable    (uint8);
uint32 IntIsEnabled (uint8);
void IntPendClear (uint8);
void IntPendSet   (uint8);

/**To implement later**/
/*
bool IntMasterDisable (void);
bool IntMasterEnable (void);

sint32 IntPriorityGet (uint8);
uint32 IntPriorityGroupingGet (void);
void IntPriorityGroupingSet (uint8);
uint32 IntPriorityMaskGet (void);
void IntPriorityMaskSet (uint8);
void IntPrioritySet (uint8, uint8);
void IntRegister (uint32 ui32Interrupt, void (*pfnHandler)(void));
void IntTrigger (uint8);
void IntUnregister (uint32 ui32Interrup);
*/

#endif
