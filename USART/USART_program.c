/**********************************************************/
/* !Author      : Mario H. Wahba    			  */
/* !Description : 					  */
/* !Version     : v1.0					  */
/* !Date        : 22 NOV, 2021                            */
/**********************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void USART_voidInit(void)
{
    u8 UCSRC_Temp = 0;
    u16 UBRR = 0;


    #if RECIVER_TRANSMITER == ENABLE
            SET_BIT(UCSRB, UCSRB_TXEN);
            SET_BIT(UCSRB, UCSRB_RXEN);
    #elif RECIVER_TRANSMITER == DISABLE
            CLR_BIT(UCSRB, UCSRB_TXEN);
            CLR_BIT(UCSRB, UCSRB_RXEN);
    #else 
            #error "RECIVER_TRANSMITER Error Configration"
    #endif


    #if
    

    #if CHANGE_CONFIGRATION == ENABLE
            SET_BIT(UCSRC_Temp, UCSRC_URSEL);
            #if DATA_SIZE == 5
                    CLR_BIT(UCSRC_Temp, UCSRC_UCSZ0);
                    CLR_BIT(UCSRC_Temp, UCSRC_UCSZ1);
                    CLR_BIT(UCSRB, UCSRB_UCSZ2);
            #elif DATA_SIZE == 6
                    SET_BIT(UCSRC_Temp, UCSRC_UCSZ0);
                    CLR_BIT(UCSRC_Temp, UCSRC_UCSZ1);
                    CLR_BIT(UCSRB, UCSRB_UCSZ2);
            #elif DATA_SIZE == 7        
                    CLR_BIT(UCSRC_Temp, UCSRC_UCSZ0);
                    SET_BIT(UCSRC_Temp, UCSRC_UCSZ1);
                    CLR_BIT(UCSRB, UCSRB_UCSZ2);
            #elif DATA_SIZE == 8
                    SET_BIT(UCSRC_Temp, UCSRC_UCSZ0);
                    SET_BIT(UCSRC_Temp, UCSRC_UCSZ1);
                    CLR_BIT(UCSRB, UCSRB_UCSZ2);
            #else 
                    #error "DATA SIZE Error Configration"
            #endif

            #if STOP_BIT == 1
                    CLR_BIT(UCSRC_Temp, UCSRC_USBS);
            #elif STOP_BIT == 2
                    SET_BIT(UCSRC_Temp, UCSRC_USBS);
            #else 
                    #error "STOP BIT Error Configration"
            #endif

            #if PARITY_MODE == ENABLE_ODD
                    SET_BIT(UCSRC_Temp, UCSRC_UPM0);
                    SET_BIT(UCSRC_Temp, UCSRC_UPM1);
            #elif PARITY_MODE == ENABLE_EVEN
                    CLR_BIT(UCSRC_Temp, UCSRC_UPM0);
                    SET_BIT(UCSRC_Temp, UCSRC_UPM1);               
            #elif PARITY_MODE == DISABLE
                    CLR_BIT(UCSRC_Temp, UCSRC_UPM0);
                    CLR_BIT(UCSRC_Temp, UCSRC_UPM1);
            #else 
                    #error "PARITY MODE Error Configration"
            #endif

            #if USART_MODE == ASYNC
                    CLR_BIT(UCSRC_Temp, UCSRC_USBS);
            #elif USART_MODE == SYNC
                    SET_BIT(UCSRC_Temp, UCSRC_USBS);
            #else 
                    #error "USART MODE Error Configration"
            #endif

            UCSRC = UCSRC_Temp;
    #elif CHANGE_CONFIGRATION == DISABLE
            CLR_BIT(UCSRC_Temp, UCSRC_URSEL);
    #else 
            #error "CONFIGRATION MODE Error Configration"
    #endif
    


    UBRR = (PROCCESSOR_FREQ/(U2X * BAUD_RATE))-1;
    if (UBRR >= 255)
    {
        UBRRL = 255;
        UBRR = UBRR - 255 ;
        CLR_BIT(UBRRH, UBRRH_URSEL);
        UBRRH = UBRR;
    } else
    {
        UBRRL = UBRR;
        CLR_BIT(UBRRH, UBRRH_URSEL);
        UBRRH = 0;
    }

}

void Private_voidSplitNumbers (u8 Copy_u8NumberToBeDivided, u8 * Copy_u8Array)
{
	u8 Local_u8Counter = 0 ;
	while (Copy_u8NumberToBeDivided > 0)
	{
		Copy_u8Array[Local_u8Counter] = Copy_u8NumberToBeDivided % 10 ;
		Copy_u8NumberToBeDivided = Copy_u8NumberToBeDivided / 10 ;
		Local_u8Counter++ ;
	}
}

u8 Private_u8CombineNumbers (u8 * Copy_u8Array, u8 Copy_u8SizeOfArray)
{
	u8 Local_u8Counter = Copy_u8SizeOfArray-1 ;
	u8 Copy_u8CombinedNumber = Copy_u8Array[Local_u8Counter];
	while (Local_u8Counter > 0)
	{
		Copy_u8CombinedNumber = (Copy_u8CombinedNumber * 10) + Copy_u8Array[Local_u8Counter-1];
		Local_u8Counter -- ;
	}
    return Copy_u8CombinedNumber;
}

void USART_voidTransmitData(u8 Copy_u8Data)
{
    while(GET_BIT(UCSRA, UCSRA_UDRE) == 0); 
    UDR = Copy_u8Data;
    while(GET_BIT(UCSRA, UCSRA_TXC) == 0);  
}

void USART_u8ReceiveData(u8 * Copy_pu8ReceivedData)
{
    while(GET_BIT(UCSRA, UCSRA_RXC) == 0);
    *Copy_pu8ReceivedData = UDR;
}

void USART_voidTransmitString(u8 * Copy_u8String)
{
        u8 Local_u8LoopCounter = 0;
	while(Copy_u8String[Local_u8LoopCounter] != '\0')
	{
		USART_voidTransmitData(Copy_pu8String[Local_u8LoopCounter]);
		Local_u8LoopCounter++;
	}
}

void USART_u8ReceiveString(u8 * Copy_u8ReceivedString)
{
    u8 Local_u8LoopCounter = 0;
    u8 Copy_pu8String;

    while(GET_BIT(UCSRA, UCSRA_RXC) == 0);
    while(GET_BIT(UCSRA, UCSRA_RXC) != 0)
     {
             USART_u8ReceiveData(&Copy_u8ReceivedString) ;
             Copy_pu8String[Local_u8LoopCounter] = &Copy_u8ReceivedString ;
             Local_u8LoopCounter++;
     }  
}

void USART_voidTransmitNumber(u8 Copy_u8TransmitNumber)
{
    u8 * Copy_u8Array[MAXARRAY] = 0 ;
    u8 Local_u8LoopCounter = 0;; 

    while(GET_BIT(UCSRA, UCSRA_UDRE) == 0); 
    Private_voidSplitNumbers(Copy_u8TransmitNumber,&Copy_u8Array);
    for ( Local_u8LoopCounter = 0; Local_u8LoopCounter < MAXARRAY ; Local_u8LoopCounter++)
    {
            UDR = Copy_u8Array[Local_u8LoopCounter];
    }
    while(GET_BIT(UCSRA, UCSRA_TXC) == 0);  
}

void USART_u8ReceiveNumber(u8 * Copy_u8ReceivedNumber)
{
    u8 Local_u8LoopCounter = 0;
    u8 Copy_pu8Number;

    while(GET_BIT(UCSRA, UCSRA_RXC) == 0);
    while(GET_BIT(UCSRA, UCSRA_RXC) != 0)
     {
             USART_u8ReceiveData(&Copy_u8ReceivedNumber) ;
             Copy_pu8Number[Local_u8LoopCounter] = &Copy_u8ReceivedNumber ;
             Local_u8LoopCounter++;
     }  
     &Copy_u8ReceivedNumber = Private_u8CombineNumbers (Copy_pu8Number, MAXARRAY) ;
}