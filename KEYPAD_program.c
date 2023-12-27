/***********************************************************************/
/***********************************************************************/
/*****************    AUTHOR: TAHER MOHAMED   **************************/
/*****************    LAYER:  HAL             **************************/
/*****************    SWC:    KEYPAD          **************************/
/*****************    VERSION:1.00            **************************/
/***********************************************************************/
/***********************************************************************/
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "KEYPAD_private.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"


u8 KPD_u8PressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY,Local_u8ColumnIdx,Local_u8RowIdx,Local_u8PinState;
	static u8 Local_u8KPDArray[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;
	static u8 Local_u8KPDColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	
	for (Local_u8ColumnIdx=0;Local_u8ColumnIdx<COLUMN_NUM;Local_u8ColumnIdx++)
	{
		/* ACTIVE CURRENT COLUMN */
		DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_u8PIN_LOW);
		
		for (Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUM;Local_u8RowIdx++)
		{
			/*READ THE CURRENT ROW*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIdx],&Local_u8PinState);
			
			/*CHECK IF Switch is pressed */
			if (DIO_u8PIN_LOW==Local_u8PinState)
			{
				Local_u8PressedKey=Local_u8KPDArray[Local_u8RowIdx][Local_u8ColumnIdx];
				
				/*polling (busy waiting until the key is released)*/
				while (DIO_u8PIN_LOW==Local_u8PinState)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8KPDRowArr[Local_u8RowIdx],&Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
			
		}
		/* DEACTIVE CURRENT COLUMN */
				DIO_u8SetPinValue(KPD_PORT,Local_u8KPDColumnArr[Local_u8ColumnIdx],DIO_u8PIN_HIGH);

	}
	
	
	return Local_u8PressedKey;
}


