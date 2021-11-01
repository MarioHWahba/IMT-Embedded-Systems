#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../HAL/LCD/LCD_interface.h"


void Led1 (void);
void Led2 (void);
void Led3 (void);

void main (void)
{
	DIO_voidSetPinDirection(PORTA,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN2,OUTPUT);

	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	DIO_voidSetPinDirection(PORTD,PIN3,INPUT);
	DIO_voidSetPinDirection(PORTB,PIN2,INPUT);

	DIO_voidSetPinValue(PORTD,PIN2,PULLUP);
	DIO_voidSetPinValue(PORTD,PIN3,PULLUP);
	DIO_voidSetPinValue(PORTB,PIN2,PULLUP);

	EXTI_voidInt0SetCallBack(&Led1);
	EXTI_voidInt1SetCallBack(&Led2);
	EXTI_voidInt2SetCallBack(&Led3);

	GIE_voidEnableGlobalInterrupt();

	EXTI_voidIntInit();

	LCD_voidInit();

	while(1)
	{

	}
}

void Led1 (void)
{
static u8 Local_u8Led1State = 0 ;

switch (Local_u8Led1State)
{
case 0 :
	Local_u8Led1State ^= 1 ;
	DIO_voidSetPinValue(PORTA,PIN0 , Local_u8Led1State);
	LCD_voidSendDataString("LED1",4,LCD_ROW0,LCD_COLUMN0);
	LCD_voidSendDataString("ON",2,LCD_ROW1,LCD_COLUMN0);
	break;

case 1 :
	Local_u8Led1State ^= 1 ;
	DIO_voidSetPinValue(PORTA,PIN0 , Local_u8Led1State);
	LCD_voidSendDataString("LED1",4,LCD_ROW0,LCD_COLUMN0);
	LCD_voidSendDataString("OFF",3,LCD_ROW1,LCD_COLUMN0);
	break;

default:

	break;
}


}

void Led2 (void)
{
	static u8 Local_u8Led2State = 0 ;

	switch (Local_u8Led2State)
	{
	case 0 :
		Local_u8Led2State ^= 1 ;
		DIO_voidSetPinValue(PORTA,PIN2 , Local_u8Led2State);
		LCD_voidSendDataString("LED1",4,LCD_ROW0,LCD_COLUMN6);
		LCD_voidSendDataString("ON",2,LCD_ROW1,LCD_COLUMN6);
		break;

	case 1 :
		Local_u8Led2State ^= 1 ;
		DIO_voidSetPinValue(PORTA,PIN2 , Local_u8Led2State);
		LCD_voidSendDataString("LED1",4,LCD_ROW0,LCD_COLUMN6);
		LCD_voidSendDataString("OFF",3,LCD_ROW1,LCD_COLUMN6);
		break;

	default:

		break;
	}


}

void Led3 (void)
{
	static u8 Local_u8Led3State = 0 ;

	switch (Local_u8Led3State)
	{
	case 0 :
		Local_u8Led3State ^= 1 ;
		DIO_voidSetPinValue(PORTA,PIN1 , Local_u8Led3State);
		LCD_voidSendDataString("LED1",4,LCD_ROW0,LCD_COLUMN12);
		LCD_voidSendDataString("ON",2,LCD_ROW1,LCD_COLUMN12);
		break;

	case 1 :
		Local_u8Led3State ^= 1 ;
		DIO_voidSetPinValue(PORTA,PIN1 , Local_u8Led3State);
		LCD_voidSendDataString("LED1",4,LCD_ROW0,LCD_COLUMN12);
		LCD_voidSendDataString("OFF",3,LCD_ROW1,LCD_COLUMN12);
		break;

	default:

		break;
	}



}
