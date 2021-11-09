/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 	         							  */
/* !Version     : v1.0									  */
/* !Date        : 5 NOV, 2021                             */
/**********************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidInit(void);
void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8CompareMatchValue);
void TIMERS_voidTimer0SetPreloadValue(u8 Copy_u8PreloadValue);
void TIMERS_voidTimer0CTCSetCallBackFunction(void (*Copy_pvCTCFunction)(void));


#endif