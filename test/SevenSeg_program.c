#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SevenSeg_interface.h"
#include "SevenSeg_private.h"
#include "SevenSeg_config.h"

#if 	SEG_Mode == 1
	u8	SevenSeg_arr[19]= {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,A,B,C,D,D,E,F,A,G};
#elif SEG_Mode == 0
	u8	SevenSeg_arr[19]= {ZERO^0xff,ONE^0xff,TWO^0xff,THREE^0xff,FOUR^0xff,FIVE^0xff,SIX^0xff,SEVEN^0xff,EIGHT^0xff,NINE^0xff,A^0xff,B^0xff,C^0xff,D^0xff,D^0xff,E^0xff,F^0xff,A^0xff,G^0xff};
#endif
u8 SEVENSEEG_EnablePorts[SEVENSEG_NUMBER]={SEG_Port_common1};
u8 SEVENSEEG_EnablePins[SEVENSEG_NUMBER]={SEG_Pin_common1};
u8 last_value[SEVENSEG_NUMBER]={ONE};
void SevenSeg_Enable(u8 SEG_NUMBER)
{
	SetPinValue(SEVENSEEG_EnablePorts[SEG_NUMBER],SEVENSEEG_EnablePins[SEG_NUMBER],SEG_Mode);
	SevenSeg_SetNumber (ZERO,SEG_NUMBER);
}
void SevenSeg_Disable(u8 SEG_NUMBER)
{
	SetPinValue(SEVENSEEG_EnablePorts[SEG_NUMBER],SEVENSEEG_EnablePins[SEG_NUMBER],SEG_Mode^0x01);
}

void SevenSeg_SetNumber (u8 number , u8 seg_select)
{
	last_value[seg_select] = number;
	SetPinValue(SEG_Port_a,SEG_Pin_a,GET_BIT(SevenSeg_arr[number],0));
	SetPinValue(SEG_Port_b,SEG_Pin_b,GET_BIT(SevenSeg_arr[number],1));
	SetPinValue(SEG_Port_c,SEG_Pin_c,GET_BIT(SevenSeg_arr[number],2));
	SetPinValue(SEG_Port_d,SEG_Pin_d,GET_BIT(SevenSeg_arr[number],3));
	SetPinValue(SEG_Port_e,SEG_Pin_e,GET_BIT(SevenSeg_arr[number],4));
	SetPinValue(SEG_Port_f,SEG_Pin_f,GET_BIT(SevenSeg_arr[number],5));
	SetPinValue(SEG_Port_g,SEG_Pin_g,GET_BIT(SevenSeg_arr[number],6));
	SetPinValue(SEG_Port_h,SEG_Pin_h,GET_BIT(SevenSeg_arr[number],7));
}
