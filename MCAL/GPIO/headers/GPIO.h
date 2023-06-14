#ifndef GPIO_H_
#define GPIO_H_
#include "..\..\common\MCU_hw.h"
//don't forget to use GPIO.GPIOPUR , GPIO,GPIOPDR IF THERE WILL BE AN INPUT. AND USE UNLOCK AND LOCK WITH THEM.
typedef enum {
GPIO_DIR_MODE_IN=0,
GPIO_DIR_MODE_OUT=1,
GPIO_DIR_MODE_HW=2}pinIO ;

typedef enum {PORTA=0, PORTB=1, PORTC=2, PORTD=3, PORTE=4, PORTF=5}port;

typedef enum{PIN0=0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7}pin;
typedef enum{DIGITAL_HIGH, DIGITAL_LOW}pinOP;

/*
*param:
port :is the address of the GPIOx Port(GPIOA,GPIOB,...)
pin  :corresponds to pin number 0->7
pinIO:the mode of the pin, IN,OUT,HW 0->2
*/

void GPIOPortInit(port pN);

void GPIODigital_Mode(port portN, pin pinN, bool digital_En);

void GPIODirModeSet (port portN, pin pinN, pinIO pIO);

uint32 GPIODirModeGet (port portN, pin pinN);

void GPIOPinWrite (port portN, pin pinN, pinOP isHigh);

uint32 GPIOPinRead (port portN, pin pinN);


uint32 power(uint32 base, uint8 power);

struct GPIO * getGPIOBaseAddress(port pN);



	
/***** TO IMPLEMENT LATER *****/
/*
void GPIOIntEnable (volatile struct GPIO*, uint32);
void GPIOIntClear (volatile struct GPIO*, uint32);
void GPIOIntDisable (volatile struct GPIO*, uint32);
void GPIOPinConfigure (uint32 ui32PinConfig);

void GPIOADCTriggerDisable (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOADCTriggerEnable (uint32_t ui32Port, uint8_t ui8Pins)

void GPIODMATriggerDisable (uint32_t ui32Port, uint8_t ui8Pins)
void GPIODMATriggerEnable (uint32_t ui32Port, uint8_t ui8Pins)


void GPIOIntRegister (uint32_t ui32Port, void (*pfnIntHandler)(void))
void GPIOIntRegisterPin (uint32_t ui32Port, uint32_t ui32Pin, void (*pfnIntHandler)(void))
uint32_t GPIOIntStatus (uint32_t ui32Port, bool bMasked)
uint32_t GPIOIntTypeGet (uint32_t ui32Port, uint8_t ui8Pin)
void GPIOIntTypeSet (uint32_t ui32Port, uint8_t ui8Pins, uint32_t ui32IntType)


void GPIOPinTypeADC (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeCAN (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeComparator (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeComparatorOutput (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeDIVSCLK (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeEPI (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeEthernetLED (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeEthernetMII (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeGPIOInput (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeGPIOOutput (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeGPIOOutputOD (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeHibernateRTCCLK (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeI2C (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeI2CSCL (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeLCD (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeOneWire (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypePWM (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeQEI (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeSSI (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeTimer (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeTrace (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeUART (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeUSBAnalog (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeUSBDigital (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeWakeHigh (uint32_t ui32Port, uint8_t ui8Pins)
void GPIOPinTypeWakeLow (uint32_t ui32Port, uint8_t ui8Pins)
uint32_t GPIOPinWakeStatus (uint32_t ui32Port)
void GPIOUnlockPin (uint32 ui32Port, uint8 ui8Pins);
*/


#endif
