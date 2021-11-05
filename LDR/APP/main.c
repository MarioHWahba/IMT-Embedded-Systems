#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"

void main (void)
{
	DIO_voidSetPinDirection (PORTB, PIN0, OUTPUT);
	DIO_voidSetPinDirection (PORTB, PIN1, OUTPUT);
	DIO_voidSetPinDirection (PORTB, PIN2, OUTPUT);
	DIO_voidSetPinDirection (PORTB, PIN3, OUTPUT);
	DIO_voidSetPinDirection (PORTB, PIN4, OUTPUT);
	DIO_voidSetPinDirection (PORTB, PIN5, OUTPUT);
	DIO_voidSetPinDirection (PORTB, PIN6, OUTPUT);
	DIO_voidSetPinDirection (PORTB, PIN7, OUTPUT);

	DIO_voidSetPinDirection (PORTA, PIN0, INPUT);

	ADC_voidInit();

	while(1)
	{

		u8 ReturnedDigital = ADC_u8StartConversionSynchronous(CHANNEL0);

		u8 NumberOfLeds = ((-7/255)*(ReturnedDigital))+8 ;

		DIO_voidSetPortValue (PORTB, LOW);

		for (u8 Copy_u8Counter = 0 ; Copy_u8Counter <= NumberOfLeds ; Copy_u8Counter++)
		{
			DIO_voidSetPinValue(PORTB,Copy_u8Counter,HIGH);
		}

	}
}
