/* 
 * File:   ecu_led.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 11, 2023, 9:11 AM
 */

#include "ecu_led.h"


Std_ReturnType led_intialize(LED *LED_CONFIG){
    Std_ReturnType ret = E_OK;    
    if(LED_CONFIG == NULL || (LED_CONFIG->PIN_L > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{
        PIN_CONFIG LED_IN = {
        .PORT = LED_CONFIG->PORT_NAME_L,
        .PIN = LED_CONFIG->PIN_L,
        .Direction = GPIO_DIRECTION_OUTPUT,
        .Logic = LED_CONFIG->LOGIC_L
        };
        
        gpio_pin_intialize(&LED_IN);
        
        
    }
    return ret;
    }


Std_ReturnType led_turn_on(LED *LED_CONFIG){
    Std_ReturnType ret = E_OK;    
    if(LED_CONFIG == NULL || (LED_CONFIG->PIN_L > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{
        PIN_CONFIG LED_IN = {
        .PORT = LED_CONFIG->PORT_NAME_L,
        .PIN = LED_CONFIG->PIN_L,
        .Direction = GPIO_DIRECTION_OUTPUT,
        .Logic = LED_CONFIG->LOGIC_L
        };
        gpio_pin_write_logic(&LED_IN,GPIO_HIGH);        
        
    }
    return ret;
    }


Std_ReturnType led_turn_off(LED *LED_CONFIG){
    Std_ReturnType ret = E_OK;    
    if(LED_CONFIG == NULL || (LED_CONFIG->PIN_L > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{

        PIN_CONFIG LED_IN = {
        .PORT = LED_CONFIG->PORT_NAME_L,
        .PIN = LED_CONFIG->PIN_L,
        .Direction = GPIO_DIRECTION_OUTPUT,
        .Logic = LED_CONFIG->LOGIC_L
        };
        gpio_pin_write_logic(&LED_IN,GPIO_LOW);        
        
    }
    return ret;
    }


Std_ReturnType led_toggle(LED *LED_CONFIG){
    Std_ReturnType ret = E_OK;    
    if(LED_CONFIG == NULL || (LED_CONFIG->PIN_L > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{

        PIN_CONFIG LED_IN = {
        .PORT = LED_CONFIG->PORT_NAME_L,
        .PIN = LED_CONFIG->PIN_L,
        .Direction = GPIO_DIRECTION_OUTPUT,
        .Logic = LED_CONFIG->LOGIC_L
        };
        gpio_pin_toggle(&LED_IN);        
        
    }
    return ret;
    }
