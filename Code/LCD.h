#ifndef LCD_H_INCLUDED
#define LCD_H_INCLUDED
#include "LCD_config.h"

// COMAND
#define CLR_SCREEN 0x01
#define DISPLAY_ON_CURSOR_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define EIGHT_BITS 0x38
#define FOUR_BITS 0x28
#define EN 0
#define RS 1
#define RW 2
void LCD_DIRECTION(void);
static void ENABLE(void);
void LCD_Send_cmd(char cmd);
void LCD_Send_char(char data);
void LCD_Send_string(char *data);
void LCD_clearscreen();
void LCD_movecursor(char row,char coloumn);
#endif // LCD_H_INCLUDED
