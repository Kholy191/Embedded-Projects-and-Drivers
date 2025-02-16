/* 
 * File:   hal_gpio.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 1:05 PM
 */

#include "hal_gpio.h"

volatile uint8 *LAT_REG[] = {&LATA , &LATB , &LATC , &LATD , &LATE};

volatile uint8 *TRIS_REG[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};

volatile uint8 *PORT_REG[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};


/*PIN FUNCTIONS*/


Std_ReturnType gpio_pin_direction_intialize(const PIN_CONFIG *str){
    
    Std_ReturnType ret = E_OK;
    
    if(str == NULL || (str->PIN > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{
        if(GPIO_DIRECTION_OUTPUT == str->Direction){
            
            CLEAR_BIT(*TRIS_REG[str->PORT],str->PIN);
        }
            else if(GPIO_DIRECTION_INPUT == str->Direction){
            
            SET_BIT(*TRIS_REG[str->PORT],str->PIN);
        }
            else{
                ret = E_NOT_OK;
        }
    }
    return ret;
}


Std_ReturnType gpio_pin_get_direction(const PIN_CONFIG *str, DIRECTON *direction ){
    
    Std_ReturnType ret = E_OK;
    
    if(str == NULL || (str->PIN > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{
        *direction = READ_BIT(*TRIS_REG[str->PORT],str->PIN);
    }
    return ret;
}


Std_ReturnType gpio_pin_write_logic(const PIN_CONFIG *str , logic LOG ){
    
    Std_ReturnType ret = E_OK;
    if(str == NULL || (str->PIN > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{
        switch(LOG){
            
            case GPIO_HIGH :
                SET_BIT(*LAT_REG[str->PORT] , str->PIN);
                break;
            case GPIO_LOW  :
                CLEAR_BIT(*LAT_REG[str->PORT] , str->PIN);
                break;
            default : ret = E_NOT_OK;  
                    
        
        }
    }
    return ret;
}


Std_ReturnType gpio_pin_read_logic(const PIN_CONFIG *str , logic *LOG){
    Std_ReturnType ret = E_OK;
    if(str == NULL || (str->PIN > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{
        *LOG = READ_BIT(*PORT_REG[str->PORT],str->PIN);
    }
    return ret;
}

Std_ReturnType gpio_pin_toggle(const PIN_CONFIG *str){
    
    Std_ReturnType ret = E_OK;
    if(str == NULL || (str->PIN > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{
        
        TOGGLE_BIT(*LAT_REG[str->PORT],str->PIN);  
    }
    
    return ret;
    
}

Std_ReturnType gpio_pin_intialize(const PIN_CONFIG *str){
    
    Std_ReturnType ret = E_OK;
    
    if(str == NULL || (str->PIN > PIN_MAX)){
        ret = E_NOT_OK;
    }
    else{
       ret = gpio_pin_direction_intialize(str);
       ret = gpio_pin_write_logic(str , str->Logic);
       
    }
    return ret;
    
}



/*PORT FUNCTIONS*/

Std_ReturnType gpio_port_direction_intialize(PORT_INDEX PORT , uint8 direction){
    
     Std_ReturnType ret = E_OK;
    
    if(PORT>PORT_MAX){
        ret = E_NOT_OK;
    }
    else{
        if(GPIO_DIRECTION_OUTPUT == direction){
          *TRIS_REG[PORT] = 0x00; 
        }
        else if(GPIO_DIRECTION_INPUT == direction){
            *TRIS_REG[PORT] = 0xFF;
        }
        else{
            ret = E_NOT_OK;
        }
    }
    return ret;
    
}

Std_ReturnType gpio_port_get_direction(PORT_INDEX PORT , uint8 *direction){
    
     Std_ReturnType ret = E_OK;
    
    if(PORT>PORT_MAX | (direction == NULL)){
        ret = E_NOT_OK;
    }
    else{
        *direction =  *TRIS_REG[PORT];
    }
    return ret;
    
}

Std_ReturnType gpio_port_write_logic(PORT_INDEX PORT , uint8 LOG ){
    
     Std_ReturnType ret = E_OK;
    
    if(PORT>PORT_MAX){
        ret = E_NOT_OK;
    }
    else{
        *LAT_REG[PORT] = LOG;
                    
    }
    return ret;
    
}

Std_ReturnType gpio_port_read_logic(PORT_INDEX PORT , uint8 *LOG){
    
     Std_ReturnType ret = E_OK;
     
    if(PORT>PORT_MAX | (LOG == NULL)){
        ret = E_NOT_OK;
    }
    else{
        *LOG = *PORT_REG[PORT];
    }
       
    
    return ret;
    
}

Std_ReturnType gpio_port_toggle_logic(PORT_INDEX PORT){
    
     Std_ReturnType ret = E_OK;
    
    if(PORT>PORT_MAX){
        ret = E_NOT_OK;
    }
    else{
        *LAT_REG[PORT] ^= PORTC_MASK;
    }
    return ret;
    
}
