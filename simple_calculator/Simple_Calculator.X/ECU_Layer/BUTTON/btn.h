/* 
 * File:   btn.h
 * Author: Ahmed El-Kholy
 *
 * Created on August 31, 2023, 4:43 PM
 */

#ifndef BTN_H
#define	BTN_H

/* Section : Includes */

#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */

typedef enum{
    BUTTON_PRESSED=0,
    BUTTON_RELEASED   
}BUTTON_Status;

typedef enum{
    BUTTON_ACTIVE_HIGH,
    BUTTON_ACTIVE_LOW        
}BUTTON_CONNECTION;

typedef struct{
    PIN_CONFIG BTN;
    BUTTON_CONNECTION BTN_CONN_;
    BUTTON_Status BTN_STATUS;
}BUTTON_T;

/* Section: Function Declarations */
Std_ReturnType button_initialize(BUTTON_T *BTN_IN);
Std_ReturnType button_read(BUTTON_T *BTN_IN ,BUTTON_Status *BTN_STATUS_IN );

#endif	/* BTN_H */

