/* 
 * File:   Applicaton_1.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 8:58 AM
 */
#include "application.h"

void Adc_interr(void);
Std_ReturnType ret = 0;

volatile Result_t ADC_1_Result = 0;
volatile Result_t ADC_2_Result = 0;

volatile Result_t TEMP_1 = 0;
volatile Result_t TEMP_2 = 0;

uint8 TEMP_1_txt[6] = {0};
uint8 TEMP_2_txt[6] = {0};

volatile uint8 Prog_counter = 0;

ADC_t ADC_1 = {
  .ACQU_TIME = _12_TAD_Acquisition_time,
  .CLOCK_FREQ = ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
  .DEFAULT_CHANNEL = AN0_CHANNEL,
  .RESULT_FORMAT = ADC_RESULT_RIGHT,
  .VOLTAGE_REFERENCE = Voltage_Reference_Internally,
  .ADC_INTERRUPT = Adc_interr,
  .ADC_Interrupt_Priority = High_Priority
};

LCD_4bits_t lcd_1 ={
    .EN_BIT.PORT = PORTC_INDEX,
    .EN_BIT.PIN = GPIO_PIN6,
    .EN_BIT.Direction = GPIO_DIRECTION_OUTPUT,
    .EN_BIT.Logic = GPIO_LOW,
    
    .RS_REG.PORT = PORTC_INDEX,
    .RS_REG.PIN = GPIO_PIN7,
    .RS_REG.Direction = GPIO_DIRECTION_OUTPUT,
    .RS_REG.Logic = GPIO_LOW,
    
    .DATA_BITS[0].PORT = PORTC_INDEX,
    .DATA_BITS[0].PIN = GPIO_PIN0,
    .DATA_BITS[0].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[0].Logic = GPIO_LOW,
    
    .DATA_BITS[1].PORT = PORTC_INDEX,
    .DATA_BITS[1].PIN = GPIO_PIN1,
    .DATA_BITS[1].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[1].Logic = GPIO_LOW,
    
    .DATA_BITS[2].PORT = PORTC_INDEX,
    .DATA_BITS[2].PIN = GPIO_PIN2,
    .DATA_BITS[2].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[2].Logic = GPIO_LOW,
    
    .DATA_BITS[3].PORT = PORTC_INDEX,
    .DATA_BITS[3].PIN = GPIO_PIN3,
    .DATA_BITS[3].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[3].Logic = GPIO_LOW,
    
};

Motor_t moto_1 = {
    .motor_pins[0].PORT = PORTD_INDEX,
    .motor_pins[0].PIN = GPIO_PIN0,
    .motor_pins[0].Direction = GPIO_DIRECTION_OUTPUT,
    .motor_pins[0].Logic = GPIO_LOW,
    
    .motor_pins[1].PORT = PORTD_INDEX,
    .motor_pins[1].PIN = GPIO_PIN1,
    .motor_pins[1].Direction = GPIO_DIRECTION_OUTPUT,
    .motor_pins[1].Logic = GPIO_LOW
};

Motor_t moto_2 = {
    .motor_pins[0].PORT = PORTD_INDEX,
    .motor_pins[0].PIN = GPIO_PIN2,
    .motor_pins[0].Direction = GPIO_DIRECTION_OUTPUT,
    .motor_pins[0].Logic = GPIO_LOW,
    
    .motor_pins[1].PORT = PORTD_INDEX,              
    .motor_pins[1].PIN = GPIO_PIN3,
    .motor_pins[1].Direction = GPIO_DIRECTION_OUTPUT,
    .motor_pins[1].Logic = GPIO_LOW
};


int main(){
    
    ret = ADC_Initialize(&ADC_1);
    ret = lcd_4bits_initialze(&lcd_1);
    ret = dc_motor_initialize(&moto_1);
    ret = dc_motor_initialize(&moto_2);
    
    while(1){
        
        
        if(0 == Prog_counter){
            ret = ADC_StartConversion_Interrupt(&ADC_1 , AN0_CHANNEL);
        }
        else if(1 == Prog_counter){
            ret = ADC_StartConversion_Interrupt(&ADC_1 , AN1_CHANNEL);
        }
        TEMP_1 = ADC_1_Result * 4.88f;
        TEMP_1 /= 10;
        
        TEMP_2 = ADC_2_Result * 4.88f;
        TEMP_2 /= 10;
        
        ret = number_16bit_to_string(TEMP_1 , TEMP_1_txt);
        ret = number_16bit_to_string(TEMP_2 , TEMP_2_txt);
        
        ret = lcd_4bits_send_string_pos(&lcd_1 , "ADC_TEST" , 1 ,7);
        ret = lcd_4bits_send_string_pos(&lcd_1 , "TEMP_1" , 2 ,1);
        ret = lcd_4bits_send_string_pos(&lcd_1 , "TEMP_2" , 3 ,1);
        
        ret = lcd_4bits_send_string_pos(&lcd_1 , TEMP_1_txt , 2 ,8);
        ret = lcd_4bits_send_string_pos(&lcd_1 , TEMP_2_txt , 3 ,8);
        
        if(TEMP_1 > 20){
            ret = dc_motor_move_forward(&moto_1);
        }
        else{
            ret = dc_motor_stop(&moto_1);
        }
        if(TEMP_2 < 19){
            ret = dc_motor_move_forward(&moto_2);
        }
        else{
            ret = dc_motor_stop(&moto_2);
        }
        
    }
    return (EXIT_SUCCESS);
}

void Adc_interr(void){
    if(0 == Prog_counter){
            ret = ADC_GetConversionResult(&ADC_1 , &ADC_1_Result);
            Prog_counter = 1;
        }
        else if(1 == Prog_counter){
            ret = ADC_GetConversionResult(&ADC_1 , &ADC_2_Result);
            Prog_counter = 0;
        }
}

