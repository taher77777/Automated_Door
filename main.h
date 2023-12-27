
#ifndef MAIN_H_
#define MAIN_H_

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER1_interface.h"
#include "SERVO_interface.h"
#include "CLCD_interface.h"
#include "KEYPAD_interface.h"
#include "util/delay.h"


void TakeKeyFromUser(u8 * ptr_u8Key);
void SetDataInNewPaswword(u8 Copy_u8Key);
void CheckPassword(void);
void CorrectPassword(void);
void WrongPassword(void);

#define DOOR_PASSWORD     123

#endif /* MAIN_H_ */
