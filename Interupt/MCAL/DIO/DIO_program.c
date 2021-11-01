#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_interface.h"


void DIO_voidSetPinDirection (u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
			switch(Copy_u8PinState)
			{
				case INPUT:
					CLR_BIT(DIO_DDRA,Copy_u8PinNumber);
				break;
				case OUTPUT:
					SET_BIT(DIO_DDRA,Copy_u8PinNumber);
				break;
			}
		break;

		case PORTB:
			switch(Copy_u8PinState)
			{
				case INPUT:
					CLR_BIT(DIO_DDRB,Copy_u8PinNumber);
				break;
				case OUTPUT:
					SET_BIT(DIO_DDRB,Copy_u8PinNumber);
				break;
			}
		break;

		case PORTC:
			switch(Copy_u8PinState)
			{
				case INPUT:
					CLR_BIT(DIO_DDRC,Copy_u8PinNumber);
				break;
				case OUTPUT:
					SET_BIT(DIO_DDRC,Copy_u8PinNumber);
				break;
			}
		break;

		case PORTD:
			switch(Copy_u8PinState)
			{
				case INPUT:
					CLR_BIT(DIO_DDRD,Copy_u8PinNumber);
				break;
				case OUTPUT:
					SET_BIT(DIO_DDRD,Copy_u8PinNumber);
				break;
			}
		break;
					
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
	if(Copy_u8PinNumber>=0 && Copy_u8PinNumber<=7)
	{switch(Copy_u8PortName)
	 {
		case PORTA:
	 		switch(Copy_u8PinValue)
	 		{
	 			case HIGH:
	 				SET_BIT(DIO_PORTA, Copy_u8PinNumber);
	 			break;
	 		
	 			case LOW:
	 				CLR_BIT(DIO_PORTA, Copy_u8PinNumber);
	 			break;
			}
		break;
		case PORTB:
	 		switch(Copy_u8PinValue)
	 		{
	 			case HIGH:
	 				SET_BIT(DIO_PORTB, Copy_u8PinNumber);
	 			break;
	 		
	 			case LOW:
	 				CLR_BIT(DIO_PORTB, Copy_u8PinNumber);
	 			break;
			}
		break;
		case PORTC:
	 		switch(Copy_u8PinValue)
	 		{
	 			case HIGH:
	 				SET_BIT(DIO_PORTC, Copy_u8PinNumber);
	 			break;
	 		
	 			case LOW:
	 				CLR_BIT(DIO_PORTC, Copy_u8PinNumber);
	 			break;
			}
		break;
		case PORTD:
	 		switch(Copy_u8PinValue)
	 		{
	 			case HIGH:
	 				SET_BIT(DIO_PORTD, Copy_u8PinNumber);
	 			break;
	 		
	 			case LOW:
	 				CLR_BIT(DIO_PORTD, Copy_u8PinNumber);
	 			break;
			}
		break;
	 }
	}
	else
	{
		/*Do Nothing*/
	}
					
		
	
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	if(Copy_u8PinNumber>=0 && Copy_u8PinNumber<=7)
	{switch(Copy_u8PortName)
	 {
		case PORTA:
			if ((GET_BIT(DIO_PINA, Copy_u8PinNumber)) == HIGH)
			{
				return HIGH;
			}
			else
			{
				return LOW ;
			}
		break;
		case PORTB:
			if ((GET_BIT(DIO_PINB, Copy_u8PinNumber)) == HIGH)
			{
				return HIGH;
			}
			else
			{
				return LOW ;
			}
		break;
		case PORTC:
			if ((GET_BIT(DIO_PINC, Copy_u8PinNumber)) == HIGH)
			{
				return HIGH;
			}
			else
			{
				return LOW ;
			}
		break;
		case PORTD:
			if ((GET_BIT(DIO_PIND, Copy_u8PinNumber)) == HIGH)
			{
				return HIGH;
			}
			else
			{
				return LOW ;
			}
		break;
	 }
	}
		}

void DIO_voidSetPortDirection (u8 Copy_u8PortName, u8 Copy_u8PortState)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
			switch(Copy_u8PortState)
			{
				case INPUT:
					CLR_BYTE(DIO_DDRA);
				break;
				case OUTPUT:
					SET_BYTE(DIO_DDRA);
				break;
			}
		break;
		case PORTB:
			switch(Copy_u8PortState)
			{
				case INPUT:
					CLR_BYTE(DIO_DDRB);
				break;
				case OUTPUT:
					SET_BYTE(DIO_DDRB);
				break;
			}
		break;
		case PORTC:
			switch(Copy_u8PortState)
			{
				case INPUT:
					CLR_BYTE(DIO_DDRC);
				break;
				case OUTPUT:
					SET_BYTE(DIO_DDRC);
				break;
			}
		break;
		case PORTD:
			switch(Copy_u8PortState)
			{
				case INPUT:
					CLR_BYTE(DIO_DDRD);
				break;
				case OUTPUT:
					SET_BYTE(DIO_DDRD);
				break;
			}
		break;
}}

void DIO_voidSetPortValue (u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
			switch(Copy_u8PortValue)
			{
				case LOW:
					CLR_BYTE(DIO_PORTA);
				break;
				case HIGH:
					SET_BYTE(DIO_PORTA);
				break;
			}
		break;
		case PORTB:
			switch(Copy_u8PortValue)
			{
				case LOW:
					CLR_BYTE(DIO_PORTB);
				break;
				case HIGH:
					SET_BYTE(DIO_PORTB);
				break;
			}
		break;
		case PORTC:
			switch(Copy_u8PortValue)
			{
				case LOW:
					CLR_BYTE(DIO_PORTC);
				break;
				case HIGH:
					SET_BYTE(DIO_PORTC);
				break;
			}
		break;
		case PORTD:
			switch(Copy_u8PortValue)
			{
				case LOW:
					CLR_BYTE(DIO_PORTD);
				break;
				case HIGH:
					SET_BYTE(DIO_PORTD);
				break;
			}
		break;
}}

u8 DIO_u8GetPortValue (u8 Copy_u8PortName)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
		return DIO_PINA ;
		break;

		case PORTB:
		return DIO_PINB;
		break;

		case PORTC:
		return DIO_PINC;
		break;

		case PORTD:
		return DIO_PIND;
		break;
}}

void DIO_voidSetSpecificDirection (u8 Copy_u8PortName, u8 Copy_u8PortDirection)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
		DIO_DDRA = Copy_u8PortDirection;
		break;

		case PORTB:
		DIO_DDRB = Copy_u8PortDirection;
		break;

		case PORTC:
		DIO_DDRC = Copy_u8PortDirection;
		break;

		case PORTD:
		DIO_DDRD = Copy_u8PortDirection;
		break;
	}
}

void DIO_voidSetSpecificValue (u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
	switch(Copy_u8PortName)
	{
		case PORTA:
		DIO_PORTA = Copy_u8PortValue;
		break;

		case PORTB:
		DIO_PORTB = Copy_u8PortValue;
		break;

		case PORTC:
		DIO_PORTC = Copy_u8PortValue;
		break;

		case PORTD:
		DIO_PORTD = Copy_u8PortValue;
		break;
	}
}