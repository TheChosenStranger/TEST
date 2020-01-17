#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "Keypad_interface.h"
#include "Keypad_private.h"
#include "Keypad_config.h"

/**/
u8 Keypad_ROWS_PORT[KEYPAD_ROW_NUM] = {KEYPAD_R0_PORT,KEYPAD_R1_PORT,KEYPAD_R2_PORT,KEYPAD_R3_PORT};
u8 Keypad_ROWS_PIN[KEYPAD_ROW_NUM] = {KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN};
u8 Keypad_COLS_PORT[KEYPAD_COL_NUM] = {KEYPAD_C0_PORT,KEYPAD_C1_PORT,KEYPAD_C2_PORT,KEYPAD_C3_PORT};
u8 Keypad_COLS_PIN[KEYPAD_COL_NUM] = {KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN};
u8 Keypad_output[KEYPAD_ROW_NUM][KEYPAD_COL_NUM] = KEYPAD_KEYS;

u8 Keypad_GetKey ()
{
	u8 i,j;
	for(i = 0;i<KEYPAD_ROW_NUM;i++)
	{
		SetPinValue(Keypad_ROWS_PORT[i],Keypad_ROWS_PIN[i],0);
		for(j = 0;j<KEYPAD_COL_NUM;j++)
		{
			if(!GetPinValue(Keypad_COLS_PORT[j],Keypad_COLS_PIN[j]))
				{return Keypad_output[i][j];}
		}
	}
	return 0;
}
