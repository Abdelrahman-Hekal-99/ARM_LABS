/*Header Log File*/

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 30 April ,2023*****************/
/*****************     SWC : IR_Sensor              *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU GCC             *****************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"


void main(void)
{
	MRCC_voidInit();
	MSTK_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1 , RCC_GPIOA);
	MGPIO_voidSetPinMode(MGPIO_PORTA , PIN0 , GPIO_OUTPUT_MODE);
	MGPIO_voidSetPinOutputType(MGPIO_PORTA , PIN0 , GPIO_OUTPUT_PUSH_PULL);
	MGPIO_voidSetPinOutputSpeed(MGPIO_PORTA , PIN0 , GPIO_OUTPUT_LOW_SPEED);

	while(1)
	{
		MGPIO_voidSetPinValue(MGPIO_PORTA , PIN0 , LOW);
		MSTK_voidSetBusyWait(1000);
		MGPIO_voidSetPinValue(MGPIO_PORTA , PIN0 , HIGH);
		MSTK_voidSetBusyWait(1000);
	}

}
