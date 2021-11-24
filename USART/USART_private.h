/**********************************************************/
/* !Author      : Abdullah M. Abdullah			          */
/* !Description : 										  */
/* !Version     : v1.0									  */
/* !Date        : 20 NOV, 2021                            */
/**********************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define UDR             *((volatile u8 *)(0x2C))    // USART Data Register

#define UCSRA           *((volatile u8 *)(0x2B))    // USART Control and Status Register A
#define UCSRA_MPCM      0                           // Multi Processor Communication
#define UCSRA_U2X       1                           // USART Double Speed Mode Bit
#define UCSRA_PE        2                           // USART Parity Error
#define UCSRA_DOR       3                           // USART Data Overrun
#define UCSRA_FE        4                           // USART Frame Error
#define UCSRA_UDRE      5                           // USART Data Register Empty
#define UCSRA_TXC       6                           // USART Transmission Complete
#define UCSRA_RXC       7                           // USART Receive Complete

#define UCSRB           *((volatile u8 *)(0x2A))    // USART Control and Status Register B
#define UCSRB_TXB8      0                           // USART Transmission Bit 8
#define UCSRB_RXB8      1                           // USART Receive Bit 8
#define UCSRB_UCSZ2     2                           // USART Character Size Bit 2
#define UCSRB_TXEN      3                           // USART Transmitter Enable
#define UCSRB_RXEN      4                           // USART Receiver Enable
#define UCSRB_UDRIE     5                           // USART UDR Register Empty Inerrupt Enable
#define UCSRB_TXCIE     6                           // USART Transmission Complete Interrupt Enable
#define UCSRB_RXCIE     7                           // USART Recepition Complete Interrupt Enable

#define UCSRC           *((volatile u8 *)(0x40))    // USART Control and Status Register C
#define UCSRC_UCPOL     0                           // USART Clock Polarity
#define UCSRC_UCSZ0     1                           // USART Character Size bit 0
#define UCSRC_UCSZ1     2                           // USART Character Size bit 1
#define UCSRC_USBS      3                           // USART Stop Bit Size
#define UCSRC_UPM0      4                           // USART Parity Mode bit 0
#define UCSRC_UPM1      5                           // USART Parity Mode bit 1
#define UCSRC_UMSEL     6                           // USART Mode Selection
#define UCSRC_URSEL     7                           // USART Register Select


#define UBRRL           *((volatile u8 *)(0x29))    // USART BaudRate Register Low Byte
#define UBRRH           *((volatile u8 *)(0x40))    // USART BaudRate Register High Byte

#define UBRRH_URSEL     7                           // USART Register Select

#define ENABLE 1
#define DISABLE 0

#define ENABLE_ODD 2
#define ENABLE_EVEN 3

#define ASYNC 1
#define SYNC 2
#define MAXARRAY 3

u8 Private_u8CombineNumbers (u8 * Copy_u8Array, u8 Copy_u8SizeOfArray);
void Private_voidSplitNumbers (u8 Copy_u8NumberToBeDivided, u8 * Copy_u8Array);

#endif