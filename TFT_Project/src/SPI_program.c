/*Header Log File/*

/*********************************************************************/
/*********************************************************************/
/*****************     Auother : Abdelrahman Hekal   *****************/
/*****************     Creation Date : 30 may ,2023   *****************/
/*****************     SWC : SPI                     *****************/
/*****************     Version:1.00                  *****************/
/*****************     Compiler: GNU ARM GCC         *****************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"


#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void MSPI_voidInit(void)
{
    MGPIO_voidSetPinMode(MSPI1_MOSI_PORTPIN, GPIO_AF_MODE); // PA7 MOSI
	MGPIO_voidSetPinMode(MSPI1_SCK_PORTPIN, GPIO_AF_MODE);  // PA5 SCK

	MGPIO_voidSetPinOutputSpeed(MSPI1_MOSI_PORTPIN, GPIO_OUTPUT_LOW_SPEED);
	MGPIO_voidSetPinOutputSpeed(MSPI1_SCK_PORTPIN, GPIO_OUTPUT_LOW_SPEED);

	MGPIO_voidSetAlternativeFunction(MSPI1_MOSI_PORTPIN, 5);
	MGPIO_voidSetAlternativeFunction(MSPI1_SCK_PORTPIN, 5);

	MGPIO_voidSetPinMode(MSPI1_NSS_PORTPIN, GPIO_AF_MODE);	// PA4 NSS
	MGPIO_voidSetPinOutputPUPD(MSPI1_NSS_PORTPIN, GPIO_OUTPUT_PULL_UP);
	MGPIO_voidSetAlternativeFunction(MSPI1_NSS_PORTPIN, 5);

    /*Set The CPHA = 1, Write of the leading edge */
    SPI1 -> CR1 = 0x0347;    
}

u8 MSPI_u8TrancieveSynchronous (u8 Copy_u8Data ,u8 * Copy_pu8RescevedData)
{
    /*SET THE DATA TO BE TRANSMITED IN DATA REGISTER (DR)*/
    SPI1 ->DR =Copy_u8Data ;

    /*Wait For SPI1 Not Busy*/

    while (GET_BIT(SPI1 ->SR , SR_BSY) == 1);

    /*Return The Received Data*/
    return Copy_pu8RescevedData;
    
}
