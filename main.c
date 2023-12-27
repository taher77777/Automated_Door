#include "main.h"

u16 arrofkey[3] = { 0 };
u16 new_password = 0;
u8 Keypad_data = 0;
u8 key_counter = 0;
u8 trial_counter = 0;



void main()
{
	PORT_voidInit();
	SERVO_voidInit();
	CLCD_voidInit();

	CLCD_voidGoToxy(0, 0);
	CLCD_voidSendString("enter password:");
	CLCD_voidGoToxy(1, 0);
	CLCD_voidSendString("3 digit:");

	while (1) {


		//enter key from user

		TakeKeyFromUser(&Keypad_data);


		//if user enter '=' will check password
		if (Keypad_data == '=')
		{
			CheckPassword();
		}
		else
		{
		//if user enter more than 3 keys
		if(key_counter==3)
		{
			WrongPassword();
		}
		else
		{
			SetDataInNewPaswword(Keypad_data);
		}


		}


	}
}


void TakeKeyFromUser(u8 * ptr_u8Key)
{
	do {
		*ptr_u8Key = KPD_u8PressedKey();

		} while (*ptr_u8Key == 0xff);
	if(Keypad_data!='=')
		{
			CLCD_voidDisplayNumber(Keypad_data);

		}
}

void SetDataInNewPaswword(u8 Copy_u8Key)
{
	arrofkey[key_counter] = Keypad_data;
	key_counter++;

}

void CheckPassword(void)
{
	key_counter = 0;
	new_password = (arrofkey[0] *100) + (arrofkey[1]*10 ) + arrofkey[2];

	//if enter password like system password
	if(new_password==DOOR_PASSWORD)
	{
		CorrectPassword();

	}
	//if password not like system password
	else
	{
		WrongPassword();
	}
}

void CorrectPassword(void)
{
	//reset counter
	key_counter=0;

	//display WELCOME on LCD
	CLCD_voidClearDisplay();
	CLCD_voidGoToxy(0, 4);
	CLCD_voidSendString("WELCOME");

	//open door
	SERVO_voidSetAngle(90);
	_delay_ms(3000);
	SERVO_voidSetAngle(0);
}


void WrongPassword(void)
{
	//increment trial_counter
	trial_counter++;
	//reset counter
	key_counter=0;

	//if trial_counter ==3 system will locked
	if(trial_counter==3)
	{
		//reset trial_counter
		trial_counter=0;


		//display System locked on LCD
		CLCD_voidClearDisplay();
		CLCD_voidGoToxy(0, 0);
		CLCD_voidSendString("System locked");

		//open led and puzzer
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN4,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN3,DIO_u8PIN_HIGH);

		//make system locked
		while(1);

	}

	CLCD_voidClearDisplay();
	CLCD_voidGoToxy(0, 0);
	CLCD_voidSendString("Wrong password:");
	CLCD_voidDisplayNumber(trial_counter);
	CLCD_voidGoToxy(1, 0);
	CLCD_voidSendString("Try again");
	_delay_ms(500);
	CLCD_voidClearDisplay();
	CLCD_voidGoToxy(0, 0);
	CLCD_voidSendString("enter password:");
	CLCD_voidGoToxy(1, 0);
	CLCD_voidSendString("3 digit:");
	//start new trial
}
