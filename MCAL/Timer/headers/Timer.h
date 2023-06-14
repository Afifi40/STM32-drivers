/*
 * Timer.h
 *
 *  Created on: Sep 26, 2022
 *      Author: ahmed
 */

#ifndef TIMER_H_
#define TIMER_H_
#include "..\..\common\MCU_hw.h"

typedef enum {TIMER0=0, TIMER1=1, TIMER2=2, TIMER3=3, TIMER4=4, TIMER5=5}timerNumber;
typedef enum {ONESHOT=1, PERIODIC=2}timerMode;
typedef enum {TIMERA=0, TIMERB=8}timerChannle ;
typedef enum {TIMER_CLOCK_SYSTEM, TIMER_CLOCK_PIOSC}timerClockSource ;
typedef enum {TIMERA_TIME_OUT=0, TIMERA_CAPTURE, TIMERA_CAPTURE_EVENT, RTC, TIMERA_MATCH,
                         TIMERB_TIME_OUT=8, TIMERB_CAPTURE, TIMERB_CAPTURE_EVENT ,TIMERB_MATCH}timerInterruptType ;
struct GPTM * getTimerAddress(timerNumber tn);

void TimerInit (timerNumber, timerChannle, timerMode , uint32 , uint16 );
void TimerEnable  (timerNumber , timerChannle);
void TimerDisable (timerNumber, timerChannle);

void TimerClockSourceSet (timerNumber , timerClockSource);
void TimerConfigure (timerNumber, uint8);


void TimerIntEnable (timerNumber, timerInterruptType );
void TimerIntClear (timerNumber, timerInterruptType );
void TimerIntDisable (timerNumber, timerInterruptType );





/*
uint32_t TimerADCEventGet (uint32_t ui32Base);
void TimerADCEventSet (uint32_t ui32Base, uint32_t ui32ADCEvent);
uint32_t TimerClockSourceGet (uint32_t ui32Base);
void TimerControlEvent (timerNumber ui32Base, uint32_t ui32Timer, uint32_t ui32Event);//rtos?


void TimerControlLevel (uint32_t ui32Base, uint32_t ui32Timer, bool bInvert);
void TimerControlStall (uint32_t ui32Base, uint32_t ui32Timer, bool bStall);
void TimerControlTrigger (uint32_t ui32Base, uint32_t ui32Timer, bool bEnable);
void TimerControlWaitOnTrigger (uint32_t ui32Base, uint32_t ui32Timer, bool bWait);

uint32_t TimerDMAEventGet (uint32_t ui32Base);
void TimerDMAEventSet (uint32_t ui32Base, uint32_t ui32DMAEvent);
uint32_t TimerLoadGet (uint32_t ui32Base, uint32_t ui32Timer);
uint64_t TimerLoadGet64 (uint32_t ui32Base);
void TimerLoadSet (uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Value);
void TimerLoadSet64 (uint32_t ui32Base, uint64_t ui64Value);
uint32_t TimerMatchGet (uint32_t ui32Base, uint32_t ui32Timer);
uint64_t TimerMatchGet64 (uint32_t ui32Base);
void TimerMatchSet (uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Value);
void TimerMatchSet64 (uint32_t ui32Base, uint64_t ui64Value);
uint32_t TimerPrescaleGet (uint32_t ui32Base, uint32_t ui32Timer);
uint32_t TimerPrescaleMatchGet (uint32_t ui32Base, uint32_t ui32Timer);
void TimerPrescaleMatchSet (uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Value);

void TimerRTCDisable (uint32_t ui32Base);
void TimerRTCEnable (uint32_t ui32Base);
void TimerSynchronize (uint32_t ui32Base, uint32_t ui32Timers);
void TimerUpdateMode (uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Config);
uint32_t TimerValueGet (uint32_t ui32Base, uint32_t ui32Timer);
uint64_t TimerValueGet64 (uint32_t ui32Base);
uint32_t TimerIntStatus (uint32_t ui32Base, bool bMasked);
void TimerIntUnregister (uint32_t ui32Base, uint32_t ui32Timer);
*/

#endif /* TIMER_H_ */
