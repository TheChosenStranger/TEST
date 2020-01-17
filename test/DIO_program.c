#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "DIO_config.h"

void SetPinDir(u8 Port,u8 Pin,u8 Dir)
{
	switch(Port)
	{
		case'A':
			if(Dir==0)
			{
				CLR_BIT(DDRA,Pin);
			}
			else
			{
				SET_BIT(DDRA,Pin);	
			}
			break;
		case'B':
			if(Dir==0)
			{
				CLR_BIT(DDRB,Pin);	
			}
			else
			{
				SET_BIT(DDRB,Pin);	
			}
			break;
		case'C':
			if(Dir==0)
			{
				CLR_BIT(DDRC,Pin);
			}
			else
			{
				SET_BIT(DDRC,Pin);	
			}
			break;
		case'D':
			if(Dir==0)
			{
				CLR_BIT(DDRD,Pin);	
			}
			else
			{
				SET_BIT(DDRD,Pin);	
			}
			break;
	}	
}

void SetPinValue(u8 Port,u8 Pin,u8 Val)
{
	switch(Port)
	{
		case'A':
			if(Val==0)
			{
				CLR_BIT(PORTA,Pin);	
			}
			else
			{
				SET_BIT(PORTA,Pin);	
			}
			break;
		case'B':
			if(Val==0)
			{
				CLR_BIT(PORTB,Pin);	
			}
			else
			{
				SET_BIT(PORTB,Pin);	
			}
			break;
		case'C':
			if(Val==0)
			{
				CLR_BIT(PORTC,Pin);	
			}
			else
			{
				SET_BIT(PORTC,Pin);	
			}
			break;
		case'D':
			if(Val==0)
			{
				CLR_BIT(PORTD,Pin);	
			}
			else
			{
				SET_BIT(PORTD,Pin);	
			}
			break;
	}
}

u8 GetPinValue(u8 Port,u8 Pin) // @suppress("No return")
{
	switch(Port)
	{
		case'A':
			return GET_BIT(PINA,Pin);	
			break;
		case'B':
			return  GET_BIT(PINB,Pin);	
			break;
		case'C':
			return  GET_BIT(PINC,Pin);		
			break;
		case'D':
			return  GET_BIT(PIND,Pin);
			break;
	}
}
