 /*
 * File:   Relay.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 1, 2023, 3:39 PM
*/

#include "Relay.h"

Std_ReturnType relay_initialize(RELAY_t *relay_in){
    
    
    Std_ReturnType ret = E_OK;    
    if(relay_in == NULL){
        ret = E_NOT_OK;
    }
    else{
       PIN_CONFIG rel_pin = {
            .PORT = relay_in->Relay_Port,
            .PIN = relay_in->Relay_status,
            .Logic = relay_in->Relay_status,
            .Direction = GPIO_DIRECTION_OUTPUT
        };
        
        ret = gpio_pin_intialize(&rel_pin);
        
        
    }
    return ret;
}

Std_ReturnType relay_on(RELAY_t *relay_in){
    
    Std_ReturnType ret = E_OK;    
    if(relay_in == NULL){
        ret = E_NOT_OK;
    }
    else{
        
        PIN_CONFIG rel_pin = {
            .PORT = relay_in->Relay_Port,
            .PIN = relay_in->Relay_status,
            .Logic = relay_in->Relay_status,
            .Direction = GPIO_DIRECTION_OUTPUT
        };
        
        ret = gpio_pin_write_logic(&rel_pin , GPIO_HIGH);
        
        
    }
      
    return ret;
}

Std_ReturnType relay_off(RELAY_t *relay_in){
    
    Std_ReturnType ret = E_OK;    
    if(relay_in == NULL){
        ret = E_NOT_OK;
    }
    else{
        PIN_CONFIG rel_pin = {
            .PORT = relay_in->Relay_Port,
            .PIN = relay_in->Relay_status,
            .Logic = relay_in->Relay_status,
            .Direction = GPIO_DIRECTION_OUTPUT
        };
        
        ret = gpio_pin_write_logic(&rel_pin , GPIO_LOW);
        
        
    }
    return ret;
}