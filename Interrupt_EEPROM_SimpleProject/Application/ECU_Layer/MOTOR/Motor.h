/* 
 * File:   Motor.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 3, 2023, 2:24 PM
 */

#ifndef MOTOR_H
#define	MOTOR_H

/* --------------------------------Section : Includes-------------------------------- */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */
#define DC_MOTOR_ON_STATUS  0x01U
#define DC_MOTOR_OFF_STATUS 0x00U
/* --------------------------------Section: Macro Functions Declarations-------------------------------- */

/* --------------------------------Section: Data Type Declarations-------------------------------- */

typedef struct{
    PIN_CONFIG motor_pins[2];
}Motor_t;

/* --------------------------------Section: Function Declarations-------------------------------- */
Std_ReturnType dc_motor_initialize(Motor_t *motor_config);
Std_ReturnType dc_motor_move_forward(Motor_t *motor_config);
Std_ReturnType dc_motor_move_backward(Motor_t *motor_config);
Std_ReturnType dc_motor_stop(Motor_t *motor_config);
#endif	/* MOTOR_H */

