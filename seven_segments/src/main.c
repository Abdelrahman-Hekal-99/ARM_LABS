/*Header Log File*/

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 30 April ,2023*****************/
/*****************     SWC : Seven Segments              *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU GCC             *****************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "SSD_interface.h"


void main(void)
{
	u8 iterator =0 ;
	MRCC_voidInit();
	MSTK_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1 , RCC_GPIOA);
	MRCC_voidEnablePeripheralClock(RCC_AHB1 , RCC_GPIOB);


	while(1)
	{
		SSD_u8SetNumber(RCC_GPIOA , 1,anode);
		SSD_u8SetNumber(RCC_GPIOB , 0,anode);
		MSTK_voidSetBusyWait(1000);
		SSD_u8SetNumber(RCC_GPIOA , 0,anode);
		for (iterator = 9 ; iterator>=0 ; iterator--)
		{
			SSD_u8SetNumber(RCC_GPIOB , iterator ,anode);
			MSTK_voidSetBusyWait(1000);
		}
	}
}
