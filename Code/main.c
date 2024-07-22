#include <avr/io.h>
#include "button.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

unsigned char counter1;
unsigned char counter2;
unsigned char counter3;
unsigned char counter4;

int main(void)
{
	LCD_DIRECTION();
	BUTTON_direction('B',4);
	BUTTON_direction('B',5);
	BUTTON_direction('B',6);
	BUTTON_direction('B',7);
	BUTTON_direction('B',8);
	LCD_Send_string("Kemo= 0");
	LCD_movecursor(1,10);
	LCD_Send_string("Dev = 0");
	LCD_movecursor(2,1);
	LCD_Send_string("Ali=0");
	LCD_movecursor(2,10);
	LCD_Send_string("Abdo=0");

	while(1)
	{

		if ((BUTTON_reed('B',3)) == 1)
		{
			counter1++;
			LCD_movecursor(1,7);
			LCD_Send_char(counter1 / 10 + 48);
			LCD_movecursor(1,8);
			LCD_Send_char(counter1 % 10 + 48);
			_delay_ms(200);
		}
		else if ((BUTTON_reed('B',4)) == 1)
		{
		 counter2++;
		 LCD_movecursor(1,15);
		 LCD_Send_char(counter2 / 10 + 48);
		 LCD_movecursor(1,16);
		 LCD_Send_char(counter2 % 10 + 48);
		 _delay_ms(200);
		}
		else if ((BUTTON_reed('B',5)) == 1)
		{
		 counter3++;
		 LCD_movecursor(2,5);
		 LCD_Send_char(counter3 / 10 + 48);
		 LCD_movecursor(2,6);
		 LCD_Send_char(counter3 % 10 + 48);
		 _delay_ms(200);
		}
		else if ((BUTTON_reed('B',6)) == 1)
		{
			counter4++;
			LCD_movecursor(2,15);
            LCD_Send_char(counter4 / 10 + 48);
            LCD_movecursor(2,16);
            LCD_Send_char(counter4 % 10 + 48);
            _delay_ms(200);
		}
        else if ((BUTTON_reed('B',7)) == 1)
        {
        	counter1=counter2=counter3=counter4=0;
        	LCD_clearscreen();
        	LCD_Send_string("Kemo= 0");
        	LCD_movecursor(1,10);
        	LCD_Send_string("Dev = 0");
        	LCD_movecursor(2,1);
        	LCD_Send_string("Ali=0");
        	LCD_movecursor(2,10);
        	LCD_Send_string("Abdo=0");
        }
}
}
