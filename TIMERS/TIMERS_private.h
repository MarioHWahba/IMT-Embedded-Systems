/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 5 NOV, 2021                             */
/**********************************************************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H


#define		TCCR0		*((volatile u8 *)(0x53))	// Timer/Counter 0 Control Register
#define		TCCR0_CS00	0							// Prescaler Bit 0
#define		TCCR0_CS01	1							// Prescaler Bit 1
#define		TCCR0_CS02	2							// Prescaler Bit 2
#define		TCCR0_WGM01	3							// Wave Generation Mode Bit 1
#define		TCCR0_COM00	4							// 
#define		TCCR0_COM01	5							// 
#define		TCCR0_WGM00	6							// Wave Generation Mode Bit 0
#define		TCCR0_FOC0	7							// Force Output Compare

#define		TCNT0		*((volatile u8 *)(0x52))	// Timer/Counter 0 Register

#define		OCR0		*((volatile u8 *)(0x5C))	// Output Compare Timer 0 Register

#define		TIMSK		*((volatile u8 *)(0x59))	// Timer/Counter 0 Interrupt Mask Register
#define 	TIMSK_TOIE0	0							// Timer Overflow Interrupt Enable
#define 	TIMSK_OCIE0	1							// Timer Output Compare Interrupt Enable

#define		TIFR		*((volatile u8 *)(0x58))	// Timer/Counter 0 Interrupt Flag Register
#define 	TIFR_TOV0	0							// Timer Overflow Flag
#define 	TIFR_OCF0	1							// Timer Output Compare Flag





#endif