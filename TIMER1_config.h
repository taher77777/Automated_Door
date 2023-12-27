/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER1				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_
#define CLK_8        1
#define CLK_16       2
#define CLK          CLK_8
/* this driver for:
 * 	1-Mode 14 to generate frequency 50hz for servo motor
 * 	2-Normal Mode when use ICU
 */

/*
 * options
 *
 * 1-TEMAR1_NORMAL_MODE_0
 * 2-TEMAR1_FAST_PWM_MODE_14
 */

#define TIMER1_MODE                  TEMAR1_FAST_PWM_MODE_14


/* TIMER1 PWM Mode options
 * 1-TEMAR1_PWM_INVERTING
 * 2-TEMAR1_PWM_NONINVERTING
 * */

#define TIMER1_PWM_MODE               TEMAR1_PWM_NONINVERTING



	/*
	 * presaler options
	 *
	 	1-TIMER1_NO_SOURCE
		2-TEMAR1_PRESCALER_1
		3-TEMAR1_PRESCALER_8
		4-TEMAR1_PRESCALER_64		-->if work with 16MHZ or 8MHZ in case servo motor
		5-TEMAR1_PRESCALER_256
		6-TEMAR1_PRESCALER_1024
	   `						*/
#define TIMER1_CLK_PRE                TEMAR1_PRESCALER_64
				
#endif
