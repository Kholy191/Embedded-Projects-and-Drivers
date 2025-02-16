/* 
 * File:   Applicaton_1.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 8:58 AM
 */
#include "application.h"

Std_ReturnType ret = 0;

volatile uint8 program_number;

LED led_1 = {
    .PORT_NAME_L = PORTC_INDEX,
    .PIN_L = GPIO_PIN0,
    .LOGIC_L = GPIO_LOW
};

LED led_2 = {
    .PORT_NAME_L = PORTC_INDEX,
    .PIN_L = GPIO_PIN1,
    .LOGIC_L = GPIO_LOW
};

void INTERRUPT_FUNC_0(void){
    program_number++;
    if(3 == program_number){
        program_number = 0;
    }
    EEPROM_WRITE_DATA(0x3FF , program_number);
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
 



int main(){
    ret = EXT_INTX_Intialize(&INT_0);
    ret = led_intialize(&led_1);
    ret = led_intialize(&led_2);
    ret = EEPROM_READ_DATA(0x3FF , &program_number);
    
    while(1){
        if(1 == program_number){
            ret = led_turn_on(&led_1);
            __delay_ms(250);
            ret = led_turn_off(&led_1);
            __delay_ms(250);
        }
        
        if(2 == program_number){
            ret = led_turn_on(&led_2);
            __delay_ms(250);
            ret = led_turn_off(&led_2);
            __delay_ms(250);
        }
        
        
    }
    return (EXIT_SUCCESS);
}

