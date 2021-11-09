#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"

void GIE_voidEnableGlobalInterrupt(void)
{
    SET_BIT(SREG, SREG_I);
}

void GIE_voidDisableGlobalInterrupt(void)
{
    CLR_BIT(SREG, SREG_I);
}