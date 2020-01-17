#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void SetLedOn (void)
{
	SetPinVal(LED_Port,LED_Pin,LED_Mode);
}
void SetLedOff(void)
{
	SetPinVal(LED_Port,LED_Pin,LED_Mode^0x01));
}