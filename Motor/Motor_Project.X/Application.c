/* 
 * File:   Applicaton_1.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 8:58 AM
 */
#include "application.h"
Std_ReturnType ret = 0;

Motor_t moto_1 = {
    .motor_pins[0].PORT = PORTC_INDEX,
    .motor_pins[0].PIN = GPIO_PIN0,
    .motor_pins[0].Direction = GPIO_DIRECTION_OUTPUT,
    .motor_pins[0].Logic = GPIO_LOW,
    
    .motor_pins[1].PORT = PORTC_INDEX,
    .motor_pins[1].PIN = GPIO_PIN1,
    .motor_pins[1].Direction = GPIO_DIRECTION_OUTPUT,
    .motor_pins[1].Logic = GPIO_LOW
};

Motor_t moto_2 = {
    .motor_pins[0].PORT = PORTC_INDEX,
    .motor_pins[0].PIN = GPIO_PIN6,
    .motor_pins[0].Direction = GPIO_DIRECTION_OUTPUT,
    .motor_pins[0].Logic = GPIO_LOW,
    
    .motor_pins[1].PORT = PORTC_INDEX,              
    .motor_pins[1].PIN = GPIO_PIN7,
    .motor_pins[1].Direction = GPIO_DIRECTION_OUTPUT,
    .motor_pins[1].Logic = GPIO_LOW
};


int main() {

    ret = dc_motor_initialize(&moto_1);
    ret = dc_motor_initialize(&moto_2);
    
    while(1){
        ret = dc_motor_move_forward(&moto_1);
        ret = dc_motor_stop(&moto_2);
        __delay_ms(2000);
        ret = dc_motor_move_forward(&moto_2);
        ret = dc_motor_stop(&moto_1);
        __delay_ms(2000);
    }
    
    
    return (EXIT_SUCCESS);

}

