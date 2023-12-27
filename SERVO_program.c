/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: HAL				**************/
/********************		SWC: SERVO				**************/
/********************		Version: 1.00			**************/
/********************		Date: 29-10-2023		**************/
/*****************************************************************/
/*****************************************************************/

/**************** INCLUDES *******************/
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "TIMER1_interface.h"


void SERVO_voidInit(void)
{
	TIMER1_voidInit();
}


/*angle from -90 to +90*/
void SERVO_voidSetAngle(f32 Copy_f32Angle)
{
	f32 local_f32duty=0;

/*first set frequency*/
	TIMER1_Set_Freq_HZ_mode_14(50);

/*Set Duty
 * 0--->7.5%D
 * 90-->5%D
 * -90-->10%D
 * angle=36*duty-270
 * Duty = (angle+270)/36
 * */
	local_f32duty=(270+Copy_f32Angle)/36;
	TIMER1_Set_duty_mode_14(local_f32duty);

	/*enable Timer1*/
	TIMER1_voidSTART();

}
