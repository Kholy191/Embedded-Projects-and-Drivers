/* 
 * File:   application.h
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 1:02 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */

#include "ECU_Layer/ecu_initialize.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
extern KeyPad_t keypad_1; 
extern LED led_1;
extern LCD_4bits_t lcd_1;
extern LCD_8bits_t lcd_2;

/* Section: Function Declarations */

Std_ReturnType num_1_read(LCD_4bits_t *lcd, KeyPad_t *keypad, uint8 *str , uint8 *value , uint8 *str_2);
Std_ReturnType operation_read(LCD_4bits_t *lcd, KeyPad_t *keypad, uint8 value);
Std_ReturnType num_2_read(LCD_4bits_t *lcd, KeyPad_t *keypad, uint8 *str);
Std_ReturnType convert_string_to_numbers(uint8 *str , uint8 *value);
Std_ReturnType detect_operation(uint8 *operation_2 , uint8 value__1 , uint8 value__2 , uint8 *result__);
number_8bit_to_string__(uint8 value , uint8 *str);
Std_ReturnType print_result(LCD_4bits_t *lcd , uint8 *result_1_ , uint8 num);
#endif	/* APPLICATION_H */

