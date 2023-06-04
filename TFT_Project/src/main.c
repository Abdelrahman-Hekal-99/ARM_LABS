/*Header Log File*/

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 4 June ,2023  *****************/
/*****************     SWC : Display Image Using TFT *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU GCC             *****************/
/*********************************************************************/
/*********************************************************************/

#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "image.h"



void main (void)
{
	MRCC_voidInit();

	MGPIO_voidSetPinMode(MGPIO_PORTA,PIN0, GPIO_OUTPUT_MODE); // PA0 A0
	// MGPIO_voidSetPinMode(HTFT_CS_PORT_PIN, GPIO_OUTPUT_MODE); // PA1 CS
	MGPIO_voidSetPinMode(MGPIO_PORTA,PIN1, GPIO_OUTPUT_MODE); // PA1 CS
	MRCC_voidEnablePeripheralClock(RCC_AHB1 , RCC_GPIOA);
	MRCC_voidEnablePeripheralClock(RCC_APB2 , RCC_SPI1);
	MSPI_voidInit();
	HTFT_voidInit();
	HTFT_voidDisplayImage(Arr);

	while(1)
	{

	}
}
