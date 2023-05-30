#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"

void Toggle_Led (void);
void main (void)
{
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1 , RCC_GPIOA);
	MGPIO_voidSetPinMode(MGPIO_PORTA , PIN0 , GPIO_INPUT_MODE);
	MGPIO_voidSetPinOutputPUPD(MGPIO_PORTA , PIN0 ,GPIO_OUTPUT_PULL_UP);
	MNVIC_voidInit();
	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);
	MEXTI_voidEnableInterrupt(MEXTI_LINE0);
	MEXTI_voidChangeSenseMode(MEXTI_LINE0 , MEXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(MEXTI_LINE0 , &Toggle_Led);

	MEXTI_voidEnableInterrupt(MEXTI_LINE0);
	while(1)
	{

	}
}

void Toggle_Led (void)
{

}
