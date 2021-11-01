#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "../DIO/DIO_interface.h"
#include "../GIE/GIE_interface.h"

volatile u8 Local_u8PreviousState;
void (*Gloabl_Int0pvNotificationFunction) (void) = NULL;
void (*Gloabl_Int1pvNotificationFunction) (void) = NULL;
void (*Gloabl_Int2pvNotificationFunction) (void) = NULL;

void EXTI_voidIntInit (void)
{
    #if EXTI_INT0_ENABLE == ENABLE
        SET_BIT(GICR,GICR_INT0);
        #if EXTI_INT0_SENSE_CTRL == FALLING_EDGE
            SET_BIT(MCUCR, MCUCR_ISC01);
            CLR_BIT(MCUCR, MCUCR_ISC00);
        #elif EXTI_INT0_SENSE_CTRL == RISING_EDGE
            SET_BIT(MCUCR, MCUCR_ISC01);
            SET_BIT(MCUCR, MCUCR_ISC00);
        #elif EXTI_INT0_SENSE_CTRL == ON_CHANGE
            CLR_BIT(MCUCR, MCUCR_ISC01);
            SET_BIT(MCUCR, MCUCR_ISC00);
        #elif EXTI_INT0_SENSE_CTRL == LOW_LEVEL
            CLR_BIT(MCUCR, MCUCR_ISC01);
            CLR_BIT(MCUCR, MCUCR_ISC00);
        #else
            #error "EXTI_INT0_ENABLE Error Configration"
        #endif
    #elif EXTI_INT0_ENABLE == DISABEL
        CLR_BIT(GICR, GICR_INT0);
    #else 
        #error "EXTI_INT0_ENABLE Error Configration"
    #endif

    #if EXTI_INT1_ENABLE == ENABLE
        SET_BIT(GICR,GICR_INT0);
        #if EXTI_INT1_SENSE_CTRL == FALLING_EDGE
            SET_BIT(MCUCR, MCUCR_ISC11);
            CLR_BIT(MCUCR, MCUCR_ISC10);
        #elif EXTI_INT1_SENSE_CTRL == RISING_EDGE
            SET_BIT(MCUCR, MCUCR_ISC01);
            SET_BIT(MCUCR, MCUCR_ISC00);
        #elif EXTI_INT1_SENSE_CTRL == ON_CHANGE
            CLR_BIT(MCUCR, MCUCR_ISC01);
            SET_BIT(MCUCR, MCUCR_ISC00);
        #elif EXTI_INT1_SENSE_CTRL == LOW_LEVEL
            CLR_BIT(MCUCR, MCUCR_ISC01);
            CLR_BIT(MCUCR, MCUCR_ISC00);
        #else
            #error "EXTI_INT1_ENABLE Error Configration"
        #endif
    #elif EXTI_INT1_ENABLE == DISABEL
        CLR_BIT(GICR, GICR_INT1);
    #else 
        #error "EXTI_INT1_ENABLE Error Configration"
    #endif

    #if EXTI_INT2_ENABLE == ENABLE
        SET_BIT(GICR,GICR_INT0);
        #if EXTI_INT2_SENSE_CTRL == FALLING_EDGE
            CLR_BIT(MCUCR, MCUCR_ISC2);
        #elif EXTI_INT2_SENSE_CTRL == RISING_EDGE
            SET_BIT(MCUCR, MCUCR_ISC2);
        #else
            #error "EXTI_INT2_ENABLE Error Configration"
        #endif
    #elif EXTI_INT2_ENABLE == DISABEL
        CLR_BIT(GICR, GICR_INT2);
    #else 
        #error "EXTI_INT2_ENABLE Error Configration"
    #endif

}

void EXTI_voidInt0SenseControl(u8 Copy_u8SenseControl)
{
    switch(Copy_u8SenseControl)
    {
        case FALLING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC01);
            CLR_BIT(MCUCR, MCUCR_ISC00);
        break;

        case RISING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC01);
            SET_BIT(MCUCR, MCUCR_ISC00);
        break;

        case ON_CHANGE:
            CLR_BIT(MCUCR, MCUCR_ISC01);
            SET_BIT(MCUCR, MCUCR_ISC00);
        break;

        case LOW_LEVEL:
            CLR_BIT(MCUCR, MCUCR_ISC01);
            CLR_BIT(MCUCR, MCUCR_ISC00);
        break;
    }
}

void EXTI_voidInt1SenseControl(u8 Copy_u8SenseControl)
{
    switch(Copy_u8SenseControl)
    {
        case FALLING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC11);
            CLR_BIT(MCUCR, MCUCR_ISC10);
        break;

        case RISING_EDGE:
            SET_BIT(MCUCR, MCUCR_ISC11);
            SET_BIT(MCUCR, MCUCR_ISC10);
        break;

        case ON_CHANGE:
            CLR_BIT(MCUCR, MCUCR_ISC11);
            SET_BIT(MCUCR, MCUCR_ISC10);
        break;

        case LOW_LEVEL:
            CLR_BIT(MCUCR, MCUCR_ISC11);
            CLR_BIT(MCUCR, MCUCR_ISC10);
        break;
    }
}

void EXTI_voidInt2SenseControl(u8 Copy_u8SenseControl)
{
switch(Copy_u8SenseControl)
    {
        case FALLING_EDGE:
            CLR_BIT(MCUCR, MCUCSR_ISC2);
        break;

        case RISING_EDGE:
            SET_BIT(MCUCR, MCUCSR_ISC2);
        break;

        default:

        break;
}
}
void EXTI_voidInt0Control(u8 Copy_u8Int0State)
{
    switch(Copy_u8Int0State)
    {
        case ENABLE:
            SET_BIT(GICR,GICR_INT0);
            break;

        case DISABLE:
            CLR_BIT(GICR, GICR_INT0);
    }
}

void EXTI_voidInt1Control(u8 Copy_u8Int1State)
{
    switch(Copy_u8Int1State)
    {
        case ENABLE:
            SET_BIT(GICR,GICR_INT1);
            break;

        case DISABLE:
            CLR_BIT(GICR, GICR_INT1);
    }
}

void EXTI_voidInt2Control(u8 Copy_u8Int2State)
{
    switch(Copy_u8Int2State)
    {
        case ENABLE:
            SET_BIT(GICR,GICR_INT2);
            break;

        case DISABLE:
            CLR_BIT(GICR, GICR_INT2);
    }
}

void EXTI_voidInt0SetCallBack(void (*Copy_pvNotificationFunction) (void))
{
    Gloabl_Int0pvNotificationFunction = Copy_pvNotificationFunction;
}
void EXTI_voidInt1SetCallBack(void (*Copy_pvNotificationFunction) (void))
{
    Gloabl_Int1pvNotificationFunction = Copy_pvNotificationFunction;
}
void EXTI_voidInt2SetCallBack(void (*Copy_pvNotificationFunction) (void))
{
    Gloabl_Int2pvNotificationFunction = Copy_pvNotificationFunction;
}

void __vector__1 (void) __attributr__((signal));
void __vector__1 (void)
{
    if (Gloabl_Int0pvNotificationFunction) != NULL)
    {Gloabl_Int0pvNotificationFunction();}
    else
    {}
    
}
