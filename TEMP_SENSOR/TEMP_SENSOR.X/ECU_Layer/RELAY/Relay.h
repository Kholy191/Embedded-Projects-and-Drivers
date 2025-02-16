/* 
 * File:   Relay.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 1, 2023, 3:39 PM
 */

#ifndef RELAY_H
#define	RELAY_H

/* --------------------------------Section : Includes-------------------------------- */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */
#define RELAY_ON 0x01U
#define RELAY_OFF 0x00U
/* --------------------------------Section: Macro Functions Declarations-------------------------------- */

/* --------------------------------Section: Data Type Declarations-------------------------------- */
typedef struct{
    uint8 Relay_Port :4;
    uint8 Relay_Pin :3;
    uint8 Relay_status :1;
    
}RELAY_t;
/* --------------------------------Section: Function Declarations-------------------------------- */
Std_ReturnType relay_initialize(RELAY_t *relay_in);
Std_ReturnType relay_on(RELAY_t *relay_in);
Std_ReturnType relay_off(RELAY_t *relay_in);

#endif	/* RELAY_H */

