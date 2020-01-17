void delay(u32 value)
{
	u32 counter=(value);
	u32 i;
	for(i=0;i<counter;i++)
	{asm("NOP");}
}