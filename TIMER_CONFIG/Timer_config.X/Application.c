/* 
 * File:   Applicaton_1.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 8:58 AM
 */
#include "application.h"
void TMR1_Interrupt_Func(void);
Std_ReturnType ret = 0;
volatile uint16 TMR1_COUNTER = 0;
/*
TIMER0_t TM0_timer ={
    .TMR0_Prescaler_Mode_Selected = TIMER0_Prescaler_Enable,
    .TMR0_Prescaler_Selected = TIMER0_PRESCALER_DIV_BY_8,
    .TMR0_Mode_Selected = TIMER0_TIMER_MODE,
    .TMR0_Size_Selected = TIMER0_16BIT__MODE,
    .TMR0_Preload_Value = 3036,
    .TMR0_Interrupt_Handler = TMR0_Interrupt_Func,
    .TMR0_Priority = Low_Priority
};
*/
/*
TIMER0_t TM0_counter ={
    .TMR0_Mode_Selected = TIMER0_COUNTER_MODE,
    .TMR0_Size_Selected = TIMER0_16BIT__MODE,
    .TMR0_Preload_Value = 65530,
    .TMR0_Interrupt_Handler = TMR0_Interrupt_Func,
    .TMR0_EdgeMode_Selected = TIMER0_RISING_EDGE_MODE,
    .TMR0_Prescaler_Mode_Selected = TIMER0_Prescaler_Disable
};
*/
/*
TIMER1_t TM1_Timer ={
    .TMR1_Mode_Selected = TMR1_TIMER_MODE,
    .TMR1_Interrupt_Handler = TMR1_Interrupt_Func,
    .TMR1_OSCILLATOR_MODE = TMR1_OSCILLATOR_DISABLE,
    .TMR1_16BIT_RW_MODE = TMR1_RW_REG_8Bit_MODE,
    .TMR1_Prescaler_Selected = TMR1_PRESCALER_DIV_BY_8,
    .TMR1_Preload_Value = 3036
};
*/
TIMER1_t TM1_Counter ={
    .TMR1_Mode_Selected = TMR1_COUNTER_MODE,
    .TMR1_Interrupt_Handler = TMR1_Interrupt_Func,
    .TMR1_OSCILLATOR_MODE = TMR1_OSCILLATOR_ENABLE,
    .TMR1_16BIT_RW_MODE = TMR1_RW_REG_8Bit_MODE,
    .TMR1_Prescaler_Selected = TMR1_PRESCALER_DIV_BY_1,
    .TMR1_Preload_Value = 0,
    .TMR1_COUNTER_SYNCHRONIZATION_MODE = TMR1_SYNC_COUNTER_MODE
};
LED led_1 = {
    .PORT_NAME_L = PORTC_INDEX,
    .PIN_L = GPIO_PIN0,
    .LOGIC_L = GPIO_LOW
};

int main(){
    ret = Timer1_Initialize(&TM1_Counter);
    while(1){
        ret = Timer1_Read_Value(&TM1_Counter , &TMR1_COUNTER);
    }
    return (EXIT_SUCCESS);
}

void TMR1_Interrupt_Func(void){
    led_toggle(&led_1);
}