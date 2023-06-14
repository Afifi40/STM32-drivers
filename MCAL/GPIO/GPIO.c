#include "headers\GPIO.h"
#include "headers\GPIO_Types.h"

/*
*param: 
port :is the address of the GPIOx Port(GPIOA,GPIOB,...)
pin	 :corresponds to pin number 0->7
pinIO:the mode of the pin, IN,OUT,HW 0->2
*/
uint32 power(uint32 base, uint8 power){
	uint32 result=0;
	while(power--)
		result += base;

	if (result == 0)
		result = 1;

	return result;
}


struct GPIO * getGPIOBaseAddress(port pN){
    switch (pN){
    case PORTA:
        return (struct GPIO *)&GPIOA;

    case PORTB:
        return (struct GPIO *)&GPIOB;

    case PORTC:
        return (struct GPIO *)&GPIOC;

    case PORTD:
        return (struct GPIO *)&GPIOD;

    case PORTE:
        return (struct GPIO *)&GPIOE;

    default:
        return (struct GPIO *)&GPIOF;
    }
}

void GPIOPortInit(port pN){
	ENABLE_PORT_CLOCK(pN);
}

void GPIODigital_Mode(port portN, pin pinN, bool digital_En){
    struct GPIO* portBase  = getGPIOBaseAddress(portN);
    UNLOCK_PORT_CONFIG(*portBase , pinN);

	if(digital_En)
		DIGITAL_ENABLE(*portBase, pinN);
	else
		DIGITAL_DISABLE(*portBase, pinN);
	LOCK_PORT_CONFIG(*portBase, pinN);
}

void GPIODirModeSet(port portN, pin pinN, pinIO pIO){
    struct GPIO* portBase = getGPIOBaseAddress(portN);
    switch (pIO){
		case GPIO_DIR_MODE_IN:
			DIR_INPUT (*portBase, pinN);
			break;
		
		case GPIO_DIR_MODE_OUT:
			DIR_OUTPUT(*portBase, pinN);
			break;
		
		case GPIO_DIR_MODE_HW:
			break;//What to do here?

	}
		
}

uint32 GPIODirModeGet(port portN, pin pinN){
	return GPIO_DIR_MODE(*getGPIOBaseAddress(portN), pinN);//0->INPUT, 1->OUTPUT, 2->HW
}

void GPIOPinWrite(port portN, pin pinN, pinOP isHigh){
    struct GPIO* portBase = getGPIOBaseAddress(portN);
	if(GPIO_DIR_MODE((*portBase ), pinN)== GPIO_DIR_MODE_OUT)//check if output
	{
		if(!isHigh)
		    LOW_OUTPUT(*portBase, power(2, pinN));
				//WRITE_HIGH(*portBase, pinN);
		else
		    HIGH_OUTPUT(*portBase, power(2, pinN));
				//WRITE_LOW(*portBase, pinN);
	}
	//else if input do something about it ?
}

uint32 GPIOPinRead(port portN, pin pinN){
    struct GPIO* portBase = getGPIOBaseAddress(portN);
	if(GPIO_DIR_MODE(*portBase, pinN)== 0)//check if input
		return READ_PIN(*portBase,pinN);
	return 0;
}
