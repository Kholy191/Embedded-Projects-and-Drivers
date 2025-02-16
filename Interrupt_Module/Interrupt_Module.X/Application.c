/* 
 * File:   Applicaton_1.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 8:58 AM
 */
#include "application.h"

Std_ReturnType ret = 0;

LED led_1 = {
    .PORT_NAME_L = PORTC_INDEX,
    .PIN_L = GPIO_PIN0,
    .LOGIC_L = GPIO_LOW
};

void INTERRUPT_FUNC_0(void){
    ret = led_turn_off(&led_1);
}

void INTERRUPT_FUNC_1(void){
    ret = led_turn_on(&led_1);
    __delay_ms(2000);
    ret = led_turn_off(&led_1);
}

void INTERRUPT_FUNC_2(void){
    ret = led_turn_on(&led_1);
}

void RB_INTERRUPT_FUNC_2_High(void){
    ret = led_turn_on(&led_1);
}

void RB_INTERRUPT_FUNC_2_Low(void){
    ret = led_turn_off(&led_1);
}


Ext_Interrupt_INTX_t INT_0 = {
    .INTX_SRC = INTERRUPT_EXTERNAL_INT0,
    .INTX_EDGE = Interrupt_Rising_Edge,
    .INTX_PRIORITY = Low_Priority,
    
    .INTX_PIN.PORT = PORTB_INDEX,
    .INTX_PIN.PIN = GPIO_PIN0,
    .INTX_PIN.Direction = GPIO_DIRECTION_INPUT,
    .INTX_PIN.Logic = GPIO_LOW,
    
    .EXT_InterruptHandler = INTERRUPT_FUNC_0   
};
 
Ext_Interrupt_INTX_t INT_1 = {
    .INTX_SRC = INTERRUPT_EXTERNAL_INT1,
    .INTX_EDGE = Interrupt_Rising_Edge,
    .INTX_PRIORITY = High_Priority,
    
    .INTX_PIN.PORT = PORTB_INDEX,
    .INTX_PIN.PIN = GPIO_PIN1,
    .INTX_PIN.Direction = GPIO_DIRECTION_INPUT,
    .INTX_PIN.Logic = GPIO_LOW,
    
    .EXT_InterruptHandler = INTERRUPT_FUNC_1   
};

Ext_Interrupt_INTX_t INT_2 = {
    .INTX_SRC = INTERRUPT_EXTERNAL_INT2,
    .INTX_EDGE = Interrupt_Rising_Edge,
    .INTX_PRIORITY = Low_Priority,
    
    .INTX_PIN.PORT = PORTB_INDEX,
    .INTX_PIN.PIN = GPIO_PIN2,
    .INTX_PIN.Direction = GPIO_DIRECTION_INPUT,
    .INTX_PIN.Logic = GPIO_LOW,
    
    .EXT_InterruptHandler = INTERRUPT_FUNC_2
};
 
Ext_Interrupt_RBX_t RB_7 = {
    .INTX_PRIORITY = Low_Priority,
    .INTX_PIN.PORT = PORTB_INDEX,
    .INTX_PIN.PIN = GPIO_PIN7,
    .INTX_PIN.Direction = GPIO_DIRECTION_INPUT,
    .INTX_PIN.Logic = GPIO_LOW,
    
    .EXT_InterruptHandler_HIGH = RB_INTERRUPT_FUNC_2_High,
    .EXT_InterruptHandler_LOW = RB_INTERRUPT_FUNC_2_Low
};



int main(){
    
    ret = led_intialize(&led_1);
    ret = EXT_INTX_Intialize(&INT_2);   
    ret = EXT_INTX_Intialize(&INT_1);
    ret = EXT_INTX_Intialize(&INT_0);
    ret = EXT_RBX_Intialize(&RB_7);
    
    while(1){
        
    }
    return (EXIT_SUCCESS);
}

