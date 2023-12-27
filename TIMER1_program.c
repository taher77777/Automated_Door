//LIB
#include "STD_TYPE.h"
#include "BIT_MATH.h"
//MCAL
#include "TIMER1_register.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"
#include "TIMER1_interface.h"

static void (*ICU_pvCallBackFunc)(void)=NULL;

void TIMER1_voidInit(void)
{
	// select mode
#if TIMER1_MODE==TEMAR1_FAST_PWM_MODE_14
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);
	// select PWM MODE
#if TIMER1_PWM_MODE == TEMAR1_PWM_INVERTING
	SET_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
#elif TIMER1_PWM_MODE == TEMAR1_PWM_NONINVERTING
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
#endif
#elif TIMER1_MODE==TEMAR1_NORMAL_MODE_0
	//normal mode
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TCCR1B,TCCR1B_WGM12);
	CLR_BIT(TCCR1B,TCCR1B_WGM13);

	//enable interrupt
	//SET_BIT(TIMSK,TIMSK_TOIE1);
#endif

}
void TIMER1_voidSTART(void)
{
#if TIMER1_CLK_PRE == TIMER1_NO_SOURCE
	CLR_BIT(TCCR1B,TCCR1B_CS10); CLR_BIT(TCCR1B,TCCR1B_CS11); CLR_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_CLK_PRE == TEMAR1_PRESCALER_1
    // Select Prescaler Value = 1
	SET_BIT(TCCR1B,TCCR1B_CS10); CLR_BIT(TCCR1B,TCCR1B_CS11); CLR_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_CLK_PRE == TEMAR1_PRESCALER_8
    // Select Prescaler Value = 8
	CLR_BIT(TCCR1B,TCCR1B_CS10); SET_BIT(TCCR1B,TCCR1B_CS11); CLR_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_CLK_PRE == TEMAR1_PRESCALER_64
    // Select Prescaler Value = 64
	SET_BIT(TCCR1B,TCCR1B_CS10); SET_BIT(TCCR1B,TCCR1B_CS11); CLR_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_CLK_PRE == TEMAR1_PRESCALER_256
    // Select Prescaler Value = 256
	CLR_BIT(TCCR1B,TCCR1B_CS10); CLR_BIT(TCCR1B,TCCR1B_CS11); SET_BIT(TCCR1B,TCCR1B_CS12);
#elif TIMER1_CLK_PRE == TEMAR1_PRESCALER_1024
    // Select Prescaler Value = 1024
	SET_BIT(TCCR1B,TCCR1B_CS10); CLR_BIT(TCCR1B,TCCR1B_CS11); SET_BIT(TCCR1B,TCCR1B_CS12);
#endif
}
void TIMER1_voidSTOP(void)
{
	CLR_BIT(TCCR1B,TCCR1B_CS10); CLR_BIT(TCCR1B,TCCR1B_CS11); CLR_BIT(TCCR1B,TCCR1B_CS12);
}

void Timer1_voidSetChannelBCompValue(u16 u16_CopyValue)
{
	OCR1B=u16_CopyValue;
}

void Timer1_voidSetChannelACompValue(u16 u16_CopyValue)
{
	OCR1A=u16_CopyValue;
}

void Timer1_voidSetTopValue(u16 u16_CopyValue)
{
	ICR1=u16_CopyValue;
}

/*calculate dydy for 8000000HZ and 16000000HZ */
void TIMER1_Set_duty_mode_14(f32 f32_CopyValue)
{
	if(f32_CopyValue<=100)
	{
#if CLK==CLK_16

#if TIMER1_PWM_MODE == TEMAR1_PWM_INVERTING
		f32_CopyValue=100-f32_CopyValue;
		OCR1A=((ICR1+1)/100)-1;
#elif TIMER1_PWM_MODE == TEMAR1_PWM_NONINVERTING
		OCR1A=(((ICR1+1)*f32_CopyValue)/100)-1;
#endif

#elif CLK==CLK_8
#if TIMER1_PWM_MODE == TEMAR1_PWM_INVERTING
		f32_CopyValue=100-f32_CopyValue;
		OCR1A=((ICR1+1)/100)-1;
#elif TIMER1_PWM_MODE == TEMAR1_PWM_NONINVERTING
		OCR1A=(((ICR1+1)*f32_CopyValue)/100)-1;
#endif
#endif
	}
}

/*calculate ICR1 for 8000000HZ and 16000000HZ */
void TIMER1_Set_Freq_HZ_mode_14(u16 u16_CopyValue)
{
#if CLK==CLK_16
	// under condition tick time 4 uS "CLK/64" prescaler=64
	ICR1=(((1000000UL)/(u16_CopyValue*4))-1);
#elif CLK==CLK_8
	// under condition tick time 8 uS "CLK/64" prescaler=64
	ICR1=(((1000000UL)/(u16_CopyValue*8))-1);

#endif
}



void ICU_voidInit(void)
{
	//sense to rising edge
	SET_BIT(TCCR1B,TCCR1B_ICES1);
	//enable ICU
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void ICU_voidSetTriggerEdge(u8 Copy_edge)
{
	if(Copy_edge==ICU_RISING_EDGE)
	{
		SET_BIT(TCCR1B,TCCR1B_ICES1);
	}
	else if(Copy_edge==ICU_FALLING_EDGE)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICES1);
	}
}

void ICU_EnableINT(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}

void ICU_DisableINT(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}

u16 ICU_u16ReadInputCapture(void)
{
	return ICR1;
}
void ICU_voidSetCallBack(void (*copy_pvCallBackFunc)(void))
{
	ICU_pvCallBackFunc=copy_pvCallBackFunc;
}


void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(ICU_pvCallBackFunc!=NULL)
	{
		ICU_pvCallBackFunc();
	}
}
