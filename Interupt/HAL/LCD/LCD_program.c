#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_voidSendCommand(u8 Copy_u8Command)
{
    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,LOW);
    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);

    DIO_voidSetSpecificValue(LCD_DATA_PORT, Copy_u8Command);

    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,HIGH);

    _delay_ms(2);

    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);
    
}

void LCD_voidSendData(u8 Copy_u8Data)
{
    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,HIGH);
    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,LOW);

    DIO_voidSetSpecificValue(LCD_DATA_PORT, Copy_u8Data);

    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,HIGH);

    _delay_ms(2);

    DIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,LOW);

}

void LCD_voidInit(void)
{
    DIO_voidSetPortDirection(LCD_DATA_PORT, OUTPUT);

    DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,OUTPUT);
    DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_EN_PIN,OUTPUT);

    _delay_ms(40);

    LCD_voidSendCommand(0x38);
    LCD_voidSendCommand(0x0F);
    LCD_voidSendCommand(0x01);
    
}

void LCD_voidGoToXY(u8 Copyu8XPosition, u8 Copy_u8YPosition)
{
    u8 Local_u8Address = 0;
    if (Copyu8XPosition == LCD_ROW0)
    {
        Local_u8Address = Copy_u8YPosition;
    }
    else if (Copyu8XPosition == LCD_ROW1)
    {
        Local_u8Address = DDRAM_OFFSET + Copy_u8YPosition;
    }

    SET_BIT(Local_u8Address, 7);

    LCD_voidSendCommand(Local_u8Address);
}

void LCD_voidSendCustomCharacter (u8 * Copy_pu8CharacterArray,u8 Copy_u8PatternNum,u8 Copy_u8XPosition,u8 Copy_u8YPosition)
{
    u8 Local_u8LoopCounter = 0;
    u8 Local_u8CGRAMAddress = 0;

    Local_u8CGRAMAddress = Copy_u8PatternNum * 8 ;

    SET_BIT(Local_u8CGRAMAddress, 6);

    LCD_voidSendCommand(Local_u8CGRAMAddress);

    for(Local_u8LoopCounter =0 ; Local_u8LoopCounter < 8 ; Local_u8LoopCounter++)
    {
        LCD_voidSendData(Copy_pu8CharacterArray[Local_u8LoopCounter]);
    }

    LCD_voidGoToXY(Copy_u8XPosition,Copy_u8YPosition);

    LCD_voidSendData(Copy_u8PatternNum);
}