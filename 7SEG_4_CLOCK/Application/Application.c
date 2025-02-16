/* 
 * File:   Applicaton_1.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 8:58 AM
 */
#include "application.h"
#include "ECU_Layer/SEG_7/Seg_7.h"
Std_ReturnType ret = 0;

Seg_7_t seg_1 ={
    
    .SEG_PINS[0].PORT = PORTC_INDEX,
    .SEG_PINS[0].Direction = GPIO_DIRECTION_OUTPUT,
    .SEG_PINS[0].PIN = GPIO_PIN0,
    .SEG_PINS[0].Logic = GPIO_LOW,
    
    .SEG_PINS[1].PORT = PORTC_INDEX,
    .SEG_PINS[1].Direction = GPIO_DIRECTION_OUTPUT,
    .SEG_PINS[1].PIN = GPIO_PIN1,
    .SEG_PINS[1].Logic = GPIO_LOW,
    
    .SEG_PINS[2].PORT = PORTC_INDEX,
    .SEG_PINS[2].Direction = GPIO_DIRECTION_OUTPUT,
    .SEG_PINS[2].PIN = GPIO_PIN2,
    .SEG_PINS[2].Logic = GPIO_LOW,
    
    .SEG_PINS[3].PORT = PORTC_INDEX,
    .SEG_PINS[3].Direction = GPIO_DIRECTION_OUTPUT,
    .SEG_PINS[3].PIN = GPIO_PIN3,
    .SEG_PINS[3].Logic = GPIO_LOW,
    
    .seg_type = Common_Anode
    
};

PIN_CONFIG control_pin_1 ={
    
  .PORT = PORTD_INDEX,
  .PIN = GPIO_PIN0,
  .Direction = GPIO_DIRECTION_OUTPUT,
  .Logic = GPIO_LOW
          
};

PIN_CONFIG control_pin_2 ={
    
  .PORT = PORTD_INDEX,
  .PIN = GPIO_PIN1,
  .Direction = GPIO_DIRECTION_OUTPUT,
  .Logic = GPIO_LOW
          
};

PIN_CONFIG control_pin_3 ={
    
  .PORT = PORTD_INDEX,
  .PIN = GPIO_PIN2,
  .Direction = GPIO_DIRECTION_OUTPUT,
  .Logic = GPIO_LOW
          
};

PIN_CONFIG control_pin_4 ={
    
  .PORT = PORTD_INDEX,
  .PIN = GPIO_PIN3,
  .Direction = GPIO_DIRECTION_OUTPUT,
  .Logic = GPIO_LOW
          
};

uint8 mins = 0; 
uint8 secs = 0;
uint8 counter = 0;  

int main() {
    
    ret = seg_7_pins_intialize(&seg_1);
    
    ret = gpio_pin_intialize(&control_pin_1);
    ret = gpio_pin_intialize(&control_pin_2);
    ret = gpio_pin_intialize(&control_pin_3);
    ret = gpio_pin_intialize(&control_pin_4);
    
    while(1){
        
        
        for(counter=0;counter<50;counter++){

            ret = seg_7_pins_write(&seg_1 , (uint8)(mins/10));
            ret = gpio_pin_write_logic(&control_pin_1 , GPIO_HIGH);
            __delay_ms(5);
            ret = gpio_pin_write_logic(&control_pin_1 , GPIO_LOW);
            
            ret = seg_7_pins_write(&seg_1 , (uint8)(mins%10));
            ret = gpio_pin_write_logic(&control_pin_2 , GPIO_HIGH);
            __delay_ms(5);
            ret = gpio_pin_write_logic(&control_pin_2 , GPIO_LOW);
            

            ret = seg_7_pins_write(&seg_1 , (uint8)(secs/10));
            ret = gpio_pin_write_logic(&control_pin_3 , GPIO_HIGH);
            __delay_ms(5);
            ret = gpio_pin_write_logic(&control_pin_3 , GPIO_LOW);

            ret = seg_7_pins_write(&seg_1 , (uint8)(secs%10));
            ret = gpio_pin_write_logic(&control_pin_4 , GPIO_HIGH);
            __delay_ms(5);
            ret = gpio_pin_write_logic(&control_pin_4 , GPIO_LOW);
        }

        secs++;
        
        if(60 == secs){
            secs = 0;
            mins++;
        }
        
        if(60 == mins){
            mins = 0;
        }
        
    }   
    return (EXIT_SUCCESS);

}
