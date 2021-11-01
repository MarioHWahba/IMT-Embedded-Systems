#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define MCUCR *((volatile u8 *)0x55)
#define MCUCR_ISC00 0 
#define MCUCR_ISC01 1
#define MCUCR_ISC10 2
#define MCUCR_ISC11 3

#define MCUCSR *((volatile u8 *)0x54)
#define MCUCSR_ISC2 6

#define GICR *((volatile u8 *)0x5B)
#define GICR_INT0 6
#define GICR_INT1 7
#define GICR_INT2 5

#define GIFR *((volatile u8 *)0x5A)
#define GIFR_INT0 6
#define GIFR_INT1 7
#define GIFR_INT2 5

#define ENABLE 1
#define DISABLE 0

#define FALLING_EDGE 0
#define RISING_EDGE 1
#define ON_CHANGE 2
#define LOW_LEVEL 3 

#define NULL (void *)0

#endif