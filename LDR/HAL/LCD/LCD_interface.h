#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit(void);
void LCD_voidGoToXY(u8 Copyu8XPosition, u8 Copy_u8YPosition);
void LCD_voidSendCustomCharacter (u8 * Copy_pu8CharacterArray,
                                  u8 Copy_u8PatternNum,
                                  u8 Copy_u8XPosition,
                                  u8 Copy_u8YPosition);
void LCD_voidSendDataString(u8 * Copy_pu8String, u8 Copy_u8NumberOfChar, u8 Copy_u8XPosition,u8 Copy_u8YPosition);

    #define LCD_ROW0 0
    #define LCD_ROW1 1

    #define LCD_COLUMN0 0
    #define LCD_COLUMN1 1
    #define LCD_COLUMN2 2
	#define LCD_COLUMN3 3
	#define LCD_COLUMN4 4
	#define LCD_COLUMN5 5
	#define LCD_COLUMN6 6
	#define LCD_COLUMN7 7
	#define LCD_COLUMN8 8
	#define LCD_COLUMN9 9
	#define LCD_COLUMN10 10
	#define LCD_COLUMN11 11
	#define LCD_COLUMN12 12
	#define LCD_COLUMN13 13
	#define LCD_COLUMN14 14
	#define LCD_COLUMN15 15
	#define LCD_COLUMN16 16
	#define LCD_COLUMN17 17

#endif
