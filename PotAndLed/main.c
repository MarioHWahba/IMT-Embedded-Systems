#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/Timers/Timers_interface.h"

u8 Global_u8ReturenedDegital = 0 ;

void ChangeValue ();

void main(void)
{

	DIO_voidSetPinDirection(PORTB,PIN3,OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN0,INPUT);

	TIMERS_voidInit();
	ADC_voidInit();

	while(1)
	{
		Global_u8ReturenedDegital = ADC_voidStartConversionAsynchronous(CHANNEL0,&ChangeValue);
	}
}

void ChangeValue ()
{
	TIMERS_voidTimer0SetCompareMatchValue(Global_u8ReturenedDegital);
}
