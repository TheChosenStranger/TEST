#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "Switch_interface.h"
#include "Switch_private.h"
#include "Switch_config.h"

volatile u8  sw_state[32],sw_counter_up[32],sw_counter_down[32];

void Switch_voidInitial()
{
	u8 i;
	for (i = 0;i<=31;i++)
	{
		sw_counter_up[i] = 0;
		sw_counter_down[i] = 0;
		sw_state[i] = released;
	}
}

u8 GetSwitchState (void)
{
	if(DIO_u8GetPinValue(Switch_Pin)==1)
	{
		sw_counter_up[Switch_Pin]++;
		sw_counter_down[Switch_Pin] = 0;
	}
	else
	{
		sw_counter_down[Switch_Pin]++;
		sw_counter_up[Switch_Pin] = 0;
	}

	if (sw_counter_up[Switch_Pin]>=9)
	{sw_state[Switch_Pin] = pressed;}
	else if (sw_counter_up[Switch_Pin]>0 && sw_state[Switch_Pin] == released)
	{sw_state[Switch_Pin] = prepressed;}

	if (sw_counter_down[Switch_Pin]>=9)
	{sw_state[Switch_Pin] = released;}
	else if (sw_counter_down[Switch_Pin]>0 && sw_state[Switch_Pin] == pressed)
	{sw_state[Switch_Pin] = prereleased;}

	return sw_state[Switch_Pin];
}
