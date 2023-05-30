/*Header Log File*/

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 16 May  ,2023*****************/
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
#include "LED_MATRIX_interface.h"

const u8 Animation1_Display1[8] = {28, 32, 66, 64, 64, 66, 32, 28};

void main(void)
{
    MRCC_voidInit();
    MRCC_voidEnablePeripheralClock(RCC_AHB1,MGPIO_PORTA);
    MRCC_voidEnablePeripheralClock(RCC_AHB1,MGPIO_PORTB);
    MSTK_voidInit();
    HLEDMAT_voidInit();

    while(1)
    {
    	HLEDMAT_voidDisplay(&Animation1_Display1);
    }
}
