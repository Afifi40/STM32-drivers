/*
 * Timer.c
 *
 *  Created on: Sep 26, 2022
 *      Author: ahmed
 */

#include "headers\Timer.h"
#include "headers\Timer_Types.h"


struct GPTM * getTimerAddress(timerNumber tn){
    switch (tn){
    case TIMER0:
        return (struct GPTM *)&GPTM0;

    case TIMER1:
        return (struct GPTM *)&GPTM1;

    case TIMER2:
        return (struct GPTM *)&GPTM2;

    case TIMER3:
        return (struct GPTM *)&GPTM3;

    case TIMER4:
        return (struct GPTM *)&GPTM4;

    default:
        return (struct GPTM *)&GPTM5;
    }
}
void TimerInit (timerNumber tn, timerChannle tCh, timerMode tm, uint32 count, uint16 prescale){
    if(tCh!=TIMERA) tCh=TIMERB;
    if(tm!=ONESHOT)    tm=PERIODIC;
    struct GPTM *base = getTimerAddress(tn);

    ENABLE_TIMER_CLOCK_GATE_CONTROL(tn);
    DISABLE_TIMER(*base, tCh);
    RESET_CONFIG(*base);

    if(tCh == TIMERA){//set Time Parameters for TIMERnB
        SELECT_MODE_A(*base,tm);//select mode of TimerA or TimerB
        SET_RELOAD_COUNT_A(*base,count);
        SET_PRESCALER_A(*base,prescale);
    }
    else{//set Time Parameters for TIMERnB
        SELECT_MODE_B(*base,tm);//select mode of TimerA or TimerB
        SET_RELOAD_COUNT_B(*base,count);
        SET_PRESCALER_B(*base,prescale);
    }

    //(*base).GPTMCTL = tm; // use this to enable / disable other modes.
    ENABLE_TIMER(*base,tCh);
}

void TimerEnable(timerNumber tn, timerChannle tCh){
    SETBIT((*getTimerAddress(tn)).GPTMCTL,tCh);
    ENABLE_TIMER_CLOCK_GATE_CONTROL(tn);
}
void TimerDisable(timerNumber tn, timerChannle tCh){
    DISABLE_TIMER(*getTimerAddress(tn), tCh);
    //CLRBIT(RCGCTIMER,tn); // This shouldn't be exceucted in case another channle is wornking on the same timer.
}

void TimerClockSourceSet (timerNumber tn, timerClockSource cs){
    //(*getTimerAddress(tn)).timerclock_source_register = cs;

}

void TimerConfigure (timerNumber tn, uint8 config){
    CONFIGURE_TIMER(*getTimerAddress(tn), config);
}

void TimerIntEnable (timerNumber tn, timerInterruptType type){
    ENABLE_INTERRUPT(*getTimerAddress(tn), type);
}
void TimerIntDisable (timerNumber tn, timerInterruptType type){
    DISABLE_INTERRUPT(*getTimerAddress(tn), type);
}
void TimerIntClear (timerNumber tn, timerInterruptType type){
    CLEAR_INTERRUPT_FLAG(*getTimerAddress(tn), type);
}

uint32 TimerIntStatus (timerNumber tn, timerInterruptType type){
    return GET_INTERRUPT_STATUS(*getTimerAddress(tn), type);
}
