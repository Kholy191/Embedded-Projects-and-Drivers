/* 
 * File:   KeyPad.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 7, 2023, 12:21 PM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

/* --------------------------------Section : Includes-------------------------------- */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */
#define KEYPAD_ROWS_NUM    4
#define KEYPAD_COLUMNS_NUM 4
/* --------------------------------Section: Macro Functions Declarations-------------------------------- */

/* --------------------------------Section: Data Type Declarations-------------------------------- */
typedef struct{
    PIN_CONFIG rows[KEYPAD_ROWS_NUM];
    PIN_CONFIG columns[KEYPAD_COLUMNS_NUM];
}KeyPad_t;
/* --------------------------------Section: Function Declarations-------------------------------- */
Std_ReturnType keypad_initialize(KeyPad_t *key_pad);
Std_ReturnType keypad_read_value(KeyPad_t *key_pad , uint8 *value);

#endif	/* KEYPAD_H */

