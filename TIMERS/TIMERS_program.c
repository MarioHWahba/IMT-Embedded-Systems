 /**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 5 NOV, 2021                             */
/**********************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"

void (*Global_pvCTCFunction)(void) = NULL;

void TIMERS_voidInit(void)
{
	/*Set CTC Mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
	/*Enable Output Compare Interrupt*/
	SET_BIT(TIMSK, TIMSK_OCIE0);
	
	/*Prescaler = 8*/
	TCCR0 &= 0b11111000;
	TCCR0 |= 0b00000010;	
}

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue)
{
	/*Set Compare Match Value To The OCR0 Register*/
	OCR0 = Copy_u8CompareMatchValue;
}

void TIMERS_voidTimer0SetPreloadValue(u8 Copy_u8PreloadValue)
{
	/*Set Compare Match Value To The OCR0 Register*/
	TCNT0 = Copy_u8PreloadValue;
}



void TIMERS_voidTimer0CTCSetCallBackFunction(void (*Copy_pvCTCFunction)(void))
{
	Global_pvCTCFunction = Copy_pvCTCFunction;
}

/*ISR For Timer 0 Compare Match*/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if(Global_pvCTCFunction != NULL)
	{
		Global_pvCTCFunction();
	}
	else
	{
		/*Do Nothing*/
	}
}


void TIMERS_voidSetBusyWait(u16 Copy_u16Time_mS)
{

	TIMERS_voidTimer0SetCompareMatchValue(250);

	u32 Local_u32Time_US = Copy_u16Time_mS * 1000 ;
	u16 Local_u16CompareMatchTime = 1 * 250 ;
	u32 Local_u32NumberOfItteration = Local_u32Time_US / Local_u16CompareMatchTime ;

	

	SET_BIT(TIFR, TIFR_OCF0);

	for(u16 Local_u16Counter = 0 ; Local_u16Counter < Local_u32NumberOfItteration ; Local_u16Counter++)
	{
		while (GET_BIT(TIFR, TIFR_OCF0) == 0);

		SET_BIT(TIFR, TIFR_OCF0);
	}

}

