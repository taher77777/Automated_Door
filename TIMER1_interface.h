/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER1				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/
#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_



/*init timer1*/
void TIMER1_voidInit(void);
void TIMER1_voidSTART(void);
void TIMER1_voidSTOP(void);
void Timer1_voidSetChannelBCompValue(u16 u16_CopyValue);
void Timer1_voidSetChannelACompValue(u16 u16_CopyValue);
void Timer1_voidSetTopValue(u16 u16_CopyValue);
void TIMER1_Set_duty_mode_14(f32 f32_CopyValue);
void TIMER1_Set_Freq_HZ_mode_14(u16 u16_CopyValue);

/***************** ICU *******************/
#define ICU_RISING_EDGE        1
#define ICU_FALLING_EDGE       2

void ICU_voidInit(void);
void ICU_voidSetTriggerEdge(u8 Copy_edge);
void ICU_EnableINT(void);
void ICU_DisableINT(void);
u16 ICU_u16ReadInputCapture(void);
void ICU_voidSetCallBack(void (*copy_pvCallBackFunc)(void));







#endif

