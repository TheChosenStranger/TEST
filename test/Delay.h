
void delay(u32 value)
{

	u32 counter=((f32)value - (0.634125f))/(0.00539875f);
	u32 i;
	for(i=0;i<counter;i++)
	{asm("NOP");}

}
