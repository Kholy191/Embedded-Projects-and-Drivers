/* 
 * File:   Lcd.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 7, 2023, 4:34 PM
 */

#ifndef LCD_H
#define	LCD_H


/* --------------------------------Section : Includes-------------------------------- */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */
#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0x02
#define _LCD_ENTRY_MODE_DEC_SHIFT_OFF   0x04
#define _LCD_ENTRY_MODE_DEC_SHIFT_ON    0x05
#define _LCD_ENTRY_MODE_INC_SHIFT_OFF   0x06
#define _LCD_ENTRY_MODE_INC_SHIFT_ON    0x07
#define _LCD_CURSOR_MOVE_SHIFT_LEFT     0x10
#define _LCD_CURSOR_MOVE_SHIFT_RIGHT    0x14
#define _LCD_DISPLAY_SHIFT_LEFT         0x18
#define _LCD_DISPLAY_SHIFT_RIGHT        0x1C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF 0x0C
#define _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_ON  0x0D
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_OFF  0x0E
#define _LCD_DISPLAY_ON_UNDERLINE_ON_CURSOR_ON   0x0F
#define _LCD_DISPLAY_OFF_CURSOR_OFF              0x08
#define _LCD_8BIT_MODE_2_LINE           0x38
#define _LCD_4BIT_MODE_2_LINE           0x28

#define _LCD_CGRAM_START                0x40
#define _LCD_DDRAM_START                0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4

#define LCD_8_BITS 8
#define LCD_4_BITS 4

/* --------------------------------Section: Macro Functions Declarations-------------------------------- */

/* --------------------------------Section: Data Type Declarations-------------------------------- */
typedef struct{
    PIN_CONFIG DATA_BITS[4];
    PIN_CONFIG RS_REG;
    PIN_CONFIG EN_BIT;
}LCD_4bits_t;

typedef struct{
    PIN_CONFIG DATA_BITS[8];
    PIN_CONFIG RS_REG;
    PIN_CONFIG EN_BIT;
}LCD_8bits_t;
/* --------------------------------Section: Function Declarations-------------------------------- */

               /*4 Bits LCD Functions*/
Std_ReturnType lcd_4bits_initialze(const LCD_4bits_t *lcd);
Std_ReturnType lcd_4bits_send_command(const LCD_4bits_t *lcd , uint8 command);
Std_ReturnType lcd_4bits_send_char(const LCD_4bits_t *lcd , uint8 data);
Std_ReturnType lcd_4bits_send_char_pos(const LCD_4bits_t *lcd , uint8 data , uint8 ROW , uint8 COLUMN);
Std_ReturnType lcd_4bits_send_string(const LCD_4bits_t *lcd , uint8 *data);
Std_ReturnType lcd_4bits_send_string_pos(const LCD_4bits_t *lcd , uint8 *data , uint8 ROW , uint8 COLUMN);
Std_ReturnType lcd_4bits_send_custom_char(const LCD_4bits_t *lcd, uint8 row, uint8 column, 
                                         const uint8 _chr[], uint8 mem_pos);
               /*8 Bits LCD Functions*/
Std_ReturnType lcd_8bits_initialze(const LCD_8bits_t *lcd);
Std_ReturnType lcd_8bits_send_command(const LCD_8bits_t *lcd , uint8 command);
Std_ReturnType lcd_8bits_send_char(const LCD_8bits_t *lcd , uint8 data);
Std_ReturnType lcd_8bits_send_char_pos(const LCD_8bits_t *lcd , uint8 data , uint8 ROW , uint8 COLUMN);
Std_ReturnType lcd_8bits_send_string(const LCD_8bits_t *lcd , uint8 *data);
Std_ReturnType lcd_8bits_send_string_pos(const LCD_8bits_t *lcd , uint8 *data , uint8 ROW , uint8 COLUMN);
Std_ReturnType lcd_8bits_send_custom_char(const LCD_8bits_t *lcd, uint8 row, uint8 column, 
                                         const uint8 _chr[], uint8 mem_pos);

Std_ReturnType number_8bit_to_string(uint8 value , uint8 *str);
Std_ReturnType number_16bit_to_string(uint16 value , uint8 *str);
Std_ReturnType number_32bit_to_string(uint32 value , uint8 *str);







#endif	/* LCD_H */

