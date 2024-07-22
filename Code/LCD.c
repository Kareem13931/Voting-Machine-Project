#include <stdio.h>
#include <stdlib.h>
#include "dio.h"
#include "LCD.h"
#define  F_CPU 8000000UL
#include <util/delay.h>

void LCD_DIRECTION(void)
{
	_delay_ms(100);
	#if defined eight_bits_mode
	DIO_direction_port('A',0XFF);
	DIO_set_direction_pin('B',EN,1);
	DIO_set_direction_pin('B',RW,1);
	DIO_set_direction_pin('B',RS,1);
	LCD_Send_cmd(EIGHT_BITS); //8 bit mode
	_delay_ms(1);
	LCD_Send_cmd(DISPLAY_ON_CURSOR_ON);//display on cursor on
	_delay_ms(1);
	LCD_Send_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_Send_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);

	#elif defined four_bits_mode
	DIO_set_direction_pin('A',4,1);
	DIO_set_direction_pin('A',5,1);
	DIO_set_direction_pin('A',6,1);
	DIO_set_direction_pin('A',7,1);
	DIO_set_direction_pin('B',EN,1);
	DIO_set_direction_pin('B',RW,1);
	DIO_set_direction_pin('B',RS,1);
	LCD_Send_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	LCD_Send_cmd(FOUR_BITS); //4bit mode
	_delay_ms(1);
	LCD_Send_cmd(DISPLAY_ON_CURSOR_ON);//display on cursor on
	_delay_ms(1);
	LCD_Send_cmd(CLR_SCREEN);//clear the screen
	_delay_ms(10);
	LCD_Send_cmd(ENTRY_MODE); //entry mode
	_delay_ms(1);
	#endif
}


static void ENABLE(void)
{
	DIO_WRITE_PIN('B',EN,1);
	_delay_ms(2);
	DIO_WRITE_PIN('B',EN,0);
	_delay_ms(2);
}
void LCD_Send_cmd(char cmd)
{
	#if defined eight_bits_mode
	DIO_write_port('A',cmd);
	DIO_WRITE_PIN('B',RS,0);
	ENABLE();

	#elif defined four_bits_mode
	write_hight_nibble('A',cmd>>4);
	DIO_WRITE_PIN('B',RS,0);
	ENABLE();
	write_hight_nibble('A',cmd);
	DIO_WRITE_PIN('B',RS,0);
	ENABLE();
	#endif
	_delay_ms(1);
}

void LCD_Send_char(char data)
{
	#if defined eight_bits_mode
	DIO_write_port('A',data);
	DIO_WRITE_PIN('B',RS,1);
    ENABLE();

	#elif defined four_bits_mode
	write_hight_nibble('A',data>>4);
	DIO_WRITE_PIN('B',RS,1);
	ENABLE();
	write_hight_nibble('A',data);
	DIO_WRITE_PIN('B',RS,1);
	ENABLE();
	#endif
	_delay_ms(1);
}


void LCD_Send_string(char *data)
{
	while((*data)!='\0')
	{
		LCD_Send_char(*data);
		data++;
	}
}
void LCD_clearscreen()
{
	LCD_Send_cmd(CLR_SCREEN);
	_delay_ms(10);
}
void LCD_movecursor(char row,char coloumn)
{
	char data ;
	if(row>2||row<1||coloumn>16||coloumn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if (row==2)
	{
		data=0xc0+coloumn-1;
	}
	LCD_Send_cmd(data);
	_delay_ms(1);
}
