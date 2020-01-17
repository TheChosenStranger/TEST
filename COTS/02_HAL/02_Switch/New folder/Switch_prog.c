/*
 * prog.c
 *
 *  Created on: Nov 20, 2018
 *      Author: Moustafa Ghareeb
 */

#include <C:\ECLIPSE_WORK_SPACE\MG2_DIO\DIO_interface.h>
#include "Switch_config.h"
#include "Switch_interface.h"
#include "Switch_private.h"

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

u8 Switch_u8State(u8 pin_num)
{
	if(DIO_u8GetPinValue(pin_num)==1)
	{
		sw_counter_up[pin_num]++;
		sw_counter_down[pin_num] = 0;
	}
	else
	{
		sw_counter_down[pin_num]++;
		sw_counter_up[pin_num] = 0;
	}

	if (sw_counter_up[pin_num]>=9)
	{sw_state[pin_num] = pressed;}
	else if (sw_counter_up[pin_num]>0 && sw_state[pin_num] == released)
	{sw_state[pin_num] = prepressed;}

	if (sw_counter_down[pin_num]>=9)
	{sw_state[pin_num] = released;}
	else if (sw_counter_down[pin_num]>0 && sw_state[pin_num] == pressed)
	{sw_state[pin_num] = prereleased;}

	return sw_state[pin_num];
}
