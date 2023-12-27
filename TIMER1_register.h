/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER1				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_

#define TCCR1A            *((volatile u8*)0x4F)               //Timer/Counter1 Control Register A
#define TCCR1B            *((volatile u8*)0x4E)               //Timer/Counter1 Control Register B
#define TCNT1             *((volatile u16*)0x4C)

#define TCCR1A_COM1A1    7                                  //Compare Output Mode for Channel A bit1 pin OC1A
#define TCCR1A_COM1A0    6                                  //Compare Output Mode for Channel A bit2 pin OC1A 
#define TCCR1A_COM1B1    5                                  //Compare Output Mode for Channel B bit1 pin OC1B
#define TCCR1A_COM1B0    4                                  //Compare Output Mode for Channel B bit2 pin OC1B

#define TCCR1A_WGM10     0                                  //Waveform Generation Mode Bit1 
#define TCCR1A_WGM11     1                                  //Waveform Generation Mode Bit2 
#define TCCR1B_WGM12     3                                  //Waveform Generation Mode Bit3 
#define TCCR1B_WGM13     4                                  //Waveform Generation Mode Bit4 

#define TCCR1B_CS10      0                                  //Clock Select Bit1
#define TCCR1B_CS11      1                                  //Clock Select Bit1
#define TCCR1B_CS12      2                                  //Clock Select Bit1

#define OCR1A            *((volatile u16*)0x4A)             //The Output Compare Registers contain a 16-bit 
#define OCR1B            *((volatile u16*)0x48)             //The Output Compare Registers contain a 16-bit 
#define ICR1             *((volatile u16*)0x46)             //the new top value register

#define TIMSK			*((volatile u8*)0x59)
#define TIMSK_TICIE1	5									//Input Capture Interrupt Enable
#define TIMSK_OCIE1A    4									//Output Compare A Match Interrupt Enable
#define TIMSK_OCIE1B    3									//Output Compare B Match Interrupt Enable
#define TIMSK_TOIE1     2									//Overflow Interrupt Enable

#define TCCR1B_ICES1    6									//input capture edge select
			

//channel A __ ocIA
//channel A __ ocIB



#endif
