/*Header Log File*/

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 26 May  ,2023*****************/
/*****************     SWC : IR_Sensor              *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU GCC             *****************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "IR_sensor_interface.h"

void main (void)
{
	IR_Sensor_Init();


	while(1)
	{

		IR_Sensor_Program();

	}
}
