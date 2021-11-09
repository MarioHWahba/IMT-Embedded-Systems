#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


/*
KPD Column Pins :
    PA, PA1, PA2, PA3
KPD Rows Pins :
    PA4, PA5, PA6, PA7
*/

void KPD_voidInit (void)
{
    DIO_voidSetPinDirection(KPD_COLUMN_PORT, KPD_COLUMN0_PIN, OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMN_PORT, KPD_COLUMN1_PIN, OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMN_PORT, KPD_COLUMN2_PIN, OUTPUT);
    DIO_voidSetPinDirection(KPD_COLUMN_PORT, KPD_COLUMN3_PIN, OUTPUT);

    DIO_voidSetPinValue(KPD_COLUMN_PORT, KPD_COLUMN0_PIN, HIGH);
    DIO_voidSetPinValue(KPD_COLUMN_PORT, KPD_COLUMN1_PIN, HIGH);
    DIO_voidSetPinValue(KPD_COLUMN_PORT, KPD_COLUMN2_PIN, HIGH);
    DIO_voidSetPinValue(KPD_COLUMN_PORT, KPD_COLUMN3_PIN, HIGH);

    DIO_voidSetPinDirection(KPD_ROW_PORT, KPD_ROW0_PIN,INPUT);
    DIO_voidSetPinDirection(KPD_ROW_PORT, KPD_ROW1_PIN,INPUT);
    DIO_voidSetPinDirection(KPD_ROW_PORT, KPD_ROW2_PIN,INPUT);
    DIO_voidSetPinDirection(KPD_ROW_PORT, KPD_ROW3_PIN,INPUT);

    DIO_voidSetPinValue(KPD_ROW_PORT,KPD_ROW0_PIN,PULLUP);
    DIO_voidSetPinValue(KPD_ROW_PORT,KPD_ROW1_PIN,PULLUP);
    DIO_voidSetPinValue(KPD_ROW_PORT,KPD_ROW2_PIN,PULLUP);
    DIO_voidSetPinValue(KPD_ROW_PORT,KPD_ROW3_PIN,PULLUP);


}

u8 KPD_u8GetPressedKey (void)
{
    u8 Local_u8ColumnsIndex ;
    u8 Local_u8RowsIndex ;
    u8 Local_u8PinState;
    u8 Local_u8PressedKey = KPD_NO_PRESSEDKEY;
    u8 Local_u8ColumnsArray[4]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
    u8 Local_u8RowsArray[4]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
    u8 Local_u8KeysArray[4][4]=KPD_KEYSARRAY_VALUES;
    for(Local_u8ColumnsIndex = 0 ; Local_u8ColumnsIndex < 4 ; Local_u8ColumnsIndex++)
    {
        DIO_voidSetPinValue (KPD_COLUMN_PORT,Local_u8ColumnsArray[Local_u8ColumnsIndex],LOW);

        for(Local_u8RowsIndex=0 ; Local_u8RowsIndex < 4; Local_u8RowsIndex++)
        {
            Local_u8PinState = DIO_u8GetPinValue(KPD_ROW_PORT,Local_u8RowsArray[Local_u8RowsIndex]);

            if(Local_u8PinState == 0)
            {
                Local_u8PressedKey = Local_u8KeysArray[Local_u8RowsIndex][Local_u8ColumnsIndex];
                while(Local_u8PinState == 0)
                {
                    Local_u8PinState = DIO_u8GetPinValue(KPD_ROW_PORT,Local_u8RowsArray[Local_u8RowsIndex]);        
                }
                return Local_u8PressedKey;
            }
        }
        DIO_voidSetPinValue(KPD_COLUMN_PORT,Local_u8ColumnsArray[Local_u8ColumnsIndex],HIGH);
    }
    return Local_u8PressedKey;
}
