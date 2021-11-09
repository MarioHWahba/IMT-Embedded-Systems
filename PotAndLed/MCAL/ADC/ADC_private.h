#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H

#define     ADMUX   *((volatile u8 *)(0x27))
#define     ADMUX_MUX0      0
#define     ADMUX_MUX1      1
#define     ADMUX_MUX2      2
#define     ADMUX_MUX3      3
#define     ADMUX_MUX4      4
#define     ADMUX_ADLAR     5
#define     ADMUX_REFS0     6
#define     ADMUX_REFS1     7

#define     ADCSRA  *((volatile u8 *)(0x26))
#define     ADCSRA_ADPS0    0
#define     ADCSRA_ADPS1    1
#define     ADCSRA_ADPS2    2
#define     ADCSRA_ADIE     3
#define     ADCSRA_ADIF     4
#define     ADCSRA_ADATE    5
#define     ADCSRA_ADSC     6
#define     ADCSRA_ADEN     7

#define     ADCH   *((volatile u8 *)(0x25))
#define     ADCL   *((volatile u8 *)(0x24))
#define     ADC    *((volatile u16 *)(0x24))

#define     AVCC        1

#define     DISABLE     0
#define     ENABLE      1

#define     PRESCALER_DIV_BY_2      1 // 0b00000001
#define     PRESCALER_DIV_BY_64     6 // 0b00000110

#define     ADC_PRESCALER_MASK  0b11111000

#define     CHANNEL_NUMBER_MASK 0b11100000

#endif