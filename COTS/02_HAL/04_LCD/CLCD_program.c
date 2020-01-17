#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CLCD_interface.h"
#include "CLCD_register.h"
#include "CLCD_config.h"
#include "CLCD_private.h"


void CLCD_voidInitialize(void)
{
	delay(40);
	CLCD_voidWriteCmd(0b00111000);
	CLCD_voidWriteCmd(0b00001100);
	CLCD_voidWriteCmd(0b00000001);
	delay(2);
}

void CLCD_voidWriteData(u8 Copy_u8Data)
{
	/*RS = 1*/
	DIO_SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
	/*RW = 0*/
	DIO_SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
	/*DATA */
	DIO_SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,GET_BIT(Copy_u8Data,0));
	DIO_SetPinValue(CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,GET_BIT(Copy_u8Data,1));
	DIO_SetPinValue(CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,GET_BIT(Copy_u8Data,2));
	DIO_SetPinValue(CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,GET_BIT(Copy_u8Data,3));
	DIO_SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,GET_BIT(Copy_u8Data,4));
	DIO_SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,GET_BIT(Copy_u8Data,5));
	DIO_SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,GET_BIT(Copy_u8Data,6));
	DIO_SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,GET_BIT(Copy_u8Data,7));
	/*E pulse*/
	DIO_SetPinValue(CLCD_u8_E_PORT,CLCD_u8_RW_PIN,1);
	delay(1);
	DIO_SetPinValue(CLCD_u8_E_PORT,CLCD_u8_RW_PIN,0);
	delay(1);
}

void CLCD_voidWriteCmd(u8 Copy_u8Command)
{
	/*RS = 0*/
	DIO_SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
	/*RW = 0*/
	DIO_SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
	/*Command */
	DIO_SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,GET_BIT(Copy_u8Command,0));
	DIO_SetPinValue(CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,GET_BIT(Copy_u8Command,1));
	DIO_SetPinValue(CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,GET_BIT(Copy_u8Command,2));
	DIO_SetPinValue(CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,GET_BIT(Copy_u8Command,3));
	DIO_SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,GET_BIT(Copy_u8Command,4));
	DIO_SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,GET_BIT(Copy_u8Command,5));
	DIO_SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,GET_BIT(Copy_u8Command,6));
	DIO_SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,GET_BIT(Copy_u8Command,7));
	/*E pulse*/
	DIO_SetPinValue(CLCD_u8_E_PORT,CLCD_u8_RW_PIN,1);
	delay(1);
	DIO_SetPinValue(CLCD_u8_E_PORT,CLCD_u8_RW_PIN,0);
	delay(1);
}