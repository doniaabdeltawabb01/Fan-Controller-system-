#include"lm35_temp_sensor.h"
#include"adc.h"
#include<util/delay.h>
#include"DC_Motor.h"
#include"lcd.h"
#include<util/delay.h>
//prototypes
void display (uint8 temp);

int main(){
	uint8 temp_result=0;
	ADC_ConfigType ADC_Configurations={INTERNAL,DIVISION_FACTOR8};
	DcMotor_Init();
	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Configurations);/* initialize ADC driver */

	LCD_displayString("FAN is  ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp =     C");
	while(1){
		temp_result = LM35_getTemp();
		display(temp_result);

	}
}
void display (uint8 temp){
	if(temp >= 100)
	{
		LCD_moveCursor(1,7);
		LCD_intgerToString(temp);
	}
	else
	{
		LCD_moveCursor(1,7);
		LCD_intgerToString(temp);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}
	if(temp<30){
		DcMotor_Rotate(STOP,SPEED_OFF);
		LCD_moveCursor(0,7);
		LCD_displayString("OFF");
	}
	else if(temp>=30&&temp<60){
		DcMotor_Rotate(CW,SPEED_QAUR);
		LCD_moveCursor(0,7);
		LCD_displayString("ON ");
	}
	else if(temp>=60&&temp<90){
		DcMotor_Rotate(CW,SPEED_HALF);
		LCD_moveCursor(0,7);
		LCD_displayString("ON ");
	}
	else if(temp>=90&&temp<120){
		DcMotor_Rotate(CW ,SPEED_SEMI_FULL);
		LCD_moveCursor(0,7);
		LCD_displayString("ON ");
	}
	else if(temp>=120){
		DcMotor_Rotate(CW,SPEED_FULL);
		LCD_moveCursor(0,7);
		LCD_displayString("ON ");
	}

}
