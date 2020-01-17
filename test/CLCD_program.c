#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CLCD_interface.h"
#include "CLCD_register.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

#define F_CPU 800000UL
#include <util/delay.h>

void CLCD_voidInitialize(void)
{
	_delay_ms(40);
	CLCD_voidWriteCmd(0b00111100);
	CLCD_voidWriteCmd(0b00001100);
	CLCD_voidWriteCmd(0b00000001);
	_delay_ms(2);
}

void CLCD_voidWriteData(u8 Copy_u8Data)
{
	/*RS = 1*/
	SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
	/*RW = 0*/
	SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
	/*DATA */
	SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,GET_BIT(Copy_u8Data,0));
	SetPinValue(CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,GET_BIT(Copy_u8Data,1));
	SetPinValue(CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,GET_BIT(Copy_u8Data,2));
	SetPinValue(CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,GET_BIT(Copy_u8Data,3));
	SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,GET_BIT(Copy_u8Data,4));
	SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,GET_BIT(Copy_u8Data,5));
	SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,GET_BIT(Copy_u8Data,6));
	SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,GET_BIT(Copy_u8Data,7));
	/*E pulse*/
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(2);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(2);
}

void CLCD_voidWriteCmd(u8 Copy_u8Command)
{
	/*RS = 0*/
	SetPinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
	/*RW = 0*/
	SetPinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
	/*Command */
	SetPinValue(CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,GET_BIT(Copy_u8Command,0));
	SetPinValue(CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,GET_BIT(Copy_u8Command,1));
	SetPinValue(CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,GET_BIT(Copy_u8Command,2));
	SetPinValue(CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,GET_BIT(Copy_u8Command,3));
	SetPinValue(CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,GET_BIT(Copy_u8Command,4));
	SetPinValue(CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,GET_BIT(Copy_u8Command,5));
	SetPinValue(CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,GET_BIT(Copy_u8Command,6));
	SetPinValue(CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,GET_BIT(Copy_u8Command,7));
	/*E pulse*/
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	_delay_ms(2);
	SetPinValue(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	_delay_ms(2);
}

void CLCD_voidCursorPosition(u8 row, u8 column)
{
	u8 cursor_position= (0b10000000|(row<<6)|(column));
	CLCD_voidWriteCmd(cursor_position);
}

void LCD_voidWriteString(u8 data_string[16])
{
	u8 i ;
	for(i = 0;i <= 15;i++)
	{
		if (data_string[i] != '\0')
		{CLCD_voidWriteData(data_string[i]);}
		else
		{return;}
	}
}
