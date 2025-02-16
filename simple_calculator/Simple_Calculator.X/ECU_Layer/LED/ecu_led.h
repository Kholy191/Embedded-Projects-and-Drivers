/* 
 * File:   ecu_led.h
 * Author: Ahmed El-Kholy
 *
 * Created on August 11, 2023, 9:11 AM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* Section : Includes */

#include "../../MCAL_Layer/GPIO/hal_gpio.h" 

/* Section: Macro Declarations */

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
typedef enum{
    LED_OFF,
    LED_ON
}LED_STATUS;

typedef struct{
    uint8 PORT_NAME_L : 4;
    uint8 LOGIC_L : 1;
    uint8 PIN_L : 3;
}LED;
/* Section: Function Declarations */
Std_ReturnType led_intialize(LED *LED_CONFIG);
Std_ReturnType led_turn_on(LED *LED_CONFIG);
Std_ReturnType led_turn_off(LED *LED_CONFIG);
Std_ReturnType led_toggle(LED *LED_CONFIG);


#endif	/* ECU_LED_H */
