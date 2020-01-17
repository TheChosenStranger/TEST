/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 14-1-2020        */
/******************************/
void CLCD_voidInitialize(void);
void CLCD_voidWriteData(u8 Copy_u8Data);
void CLCD_voidWriteCmd(u8 Copy_u8Command);
void CLCD_voidCursorPosition(u8 row, u8 column);
void LCD_voidWriteString(u8 data_string[16]);
