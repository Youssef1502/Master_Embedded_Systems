/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :       LCD Driver
==================================================**/


#ifndef LCD_H_
#define LCD_H_

#include <stdlib.h>
#include <stdio.h>
#include <STM32_F103C6_GPIO_Driver.h>
#include "STM32F103X6.h"

#define LCD_PORT GPIOA
#define RSPIN GPIO_PIN_8
#define RWPIN GPIO_PIN_9
#define ENPIN GPIO_PIN_10

// Define LCD MODES
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define DISABLE_CURSOR   							(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)
#define FOUR_BIT_CONTROL							(0x02)


GPIO_PinConfig_t PinCfg ;

// LCD APIs
void LCD_Init (void);
void LCD_WRITE_COMMAND( unsigned char command );
void LCD_Clear();
void LCD_WRITE_CHAR(unsigned char character);
void LCD_WRITE_STRING(char *string);
void LCD_kick();
void LCD_GOTO_XY(unsigned char line, unsigned char position);
void LCD_Display_Number(int Number);
void LCD_Display_Real_Number(double Number);


#endif /* LCD_H_ */
