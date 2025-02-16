/* 
 * File:   Motor.c
 * Author: midoa
 *
 * Created on September 3, 2023, 2:24 PM
 */

#include "Motor.h"

Std_ReturnType dc_motor_initialize(Motor_t *motor_config){
    
    Std_ReturnType ret = E_OK;    
    
    if(NULL == motor_config){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_intialize(&(motor_config->motor_pins[0]));
        ret = gpio_pin_direction_intialize(&(motor_config->motor_pins[1]));
    }
    return ret;
}

Std_ReturnType dc_motor_move_forward(Motor_t *motor_config){
    
    Std_ReturnType ret = E_OK;    
    
    if(NULL == motor_config){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(motor_config->motor_pins[0]) , GPIO_HIGH);
        ret = gpio_pin_write_logic(&(motor_config->motor_pins[1]) , GPIO_LOW);
    }
    return ret;
}

Std_ReturnType dc_motor_move_backward(Motor_t *motor_config){
    
    Std_ReturnType ret = E_OK;    
    
    if(NULL == motor_config){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(motor_config->motor_pins[0]) , GPIO_LOW);
        ret = gpio_pin_write_logic(&(motor_config->motor_pins[1]) , GPIO_HIGH);
    }
    return ret;
}

Std_ReturnType dc_motor_stop(Motor_t *motor_config){
    
    Std_ReturnType ret = E_OK;    
    
    if(NULL == motor_config){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(motor_config->motor_pins[0]) , GPIO_LOW);
        ret = gpio_pin_write_logic(&(motor_config->motor_pins[1]) , GPIO_LOW);
    }
    return ret;
}
