#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "Switch_interface.h"
#include "Switch_private.h"
#include "Switch_config.h"

u8 GetSwitchValue (void)
{
	return GetPinValue(Switch_Port,Switch_Pin);
}
