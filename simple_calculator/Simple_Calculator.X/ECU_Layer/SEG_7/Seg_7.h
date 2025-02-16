/* 
 * File:   Seg_7.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 3, 2023, 3:58 PM
 */

#ifndef SEG_7_H
#define	SEG_7_H

/* --------------------------------Section : Includes-------------------------------- */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */

/* --------------------------------Section: Macro Functions Declarations-------------------------------- */

/* --------------------------------Section: Data Type Declarations-------------------------------- */
typedef enum{
    Common_Anode,
    Common_Cathode        
}SEG_TYPE;

typedef struct{
    PIN_CONFIG SEG_PINS[4];
    SEG_TYPE seg_type;
}Seg_7_t;

/* --------------------------------Section: Function Declarations-------------------------------- */

Std_ReturnType seg_7_pins_intialize(Seg_7_t *_seg_);
Std_ReturnType seg_7_pins_write(Seg_7_t *_seg_ , uint8 number);


#endif	/* SEG_7_H */

