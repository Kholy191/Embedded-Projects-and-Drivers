/* 
 * File:   Seg_7.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 3, 2023, 3:58 PM
 */

#include "Seg_7.h"


Std_ReturnType seg_7_pins_intialize(Seg_7_t *_seg_){
    
    Std_ReturnType ret = E_OK;    
    
    if(NULL == _seg_){
        ret = E_NOT_OK;
    }
    else{
        
        ret = gpio_pin_intialize(&(_seg_->SEG_PINS[0]));
        ret = gpio_pin_intialize(&(_seg_->SEG_PINS[1]));
        ret = gpio_pin_intialize(&(_seg_->SEG_PINS[2]));
        ret = gpio_pin_intialize(&(_seg_->SEG_PINS[3]));
        
    }
    return ret;
}

Std_ReturnType seg_7_pins_write(Seg_7_t *_seg_ , uint8 number){
    
    Std_ReturnType ret = E_OK;    
    
    if(NULL == _seg_ || (number > 9)){
        ret = E_NOT_OK;
    }
    else{
     
        ret = gpio_pin_write_logic(&(_seg_->SEG_PINS[0]) , number & 0x01);                            
        ret = gpio_pin_write_logic(&(_seg_->SEG_PINS[1]) , (number>>1) & 0x01);
        ret = gpio_pin_write_logic(&(_seg_->SEG_PINS[2]) , (number>>2) & 0x01);
        ret = gpio_pin_write_logic(&(_seg_->SEG_PINS[3]) , (number>>3) & 0x01);
               
    }
    return ret;
}