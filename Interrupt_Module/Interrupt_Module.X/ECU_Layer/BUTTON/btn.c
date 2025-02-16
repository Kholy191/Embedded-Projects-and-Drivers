/* 
 * File:   btn.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 31, 2023, 4:43 PM
 */
#include "btn.h"
Std_ReturnType button_initialize(BUTTON_T *BTN_IN){
    
    Std_ReturnType ret = E_OK;    
    
    if(NULL == BTN_IN){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_intialize(&(BTN_IN->BTN));
    }
    return ret;
}

Std_ReturnType button_read(BUTTON_T *BTN_IN ,BUTTON_Status *BTN_STATUS_IN ){
    
    Std_ReturnType ret = E_OK;  
    logic PIN_STATUS = GPIO_LOW;
    if(NULL == BTN_IN){
        ret = E_NOT_OK;
    }
    else{
        
        ret = gpio_pin_read_logic(&(BTN_IN->BTN) , &PIN_STATUS);
        if(BUTTON_ACTIVE_HIGH == BTN_IN->BTN_CONN_ ){
            if(GPIO_HIGH == PIN_STATUS){
                *BTN_STATUS_IN = BUTTON_PRESSED;
            }
            else{
                *BTN_STATUS_IN = BUTTON_RELEASED;
            }
        }
        if(BUTTON_ACTIVE_LOW == BTN_IN->BTN_CONN_ ){
            if(GPIO_HIGH == PIN_STATUS){
                *BTN_STATUS_IN = BUTTON_RELEASED;
            }
            else{
                *BTN_STATUS_IN = BUTTON_PRESSED;
            }
        }
    }   
    return ret;
}
    

