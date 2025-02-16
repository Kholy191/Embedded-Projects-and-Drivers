/* 
 * File:   ecu_initialize.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 7, 2023, 12:32 PM
 */
#include "ecu_initialize.h"

KeyPad_t keypad_1 = {
  .rows[0].PORT = PORTC_INDEX,
  .rows[0].PIN = GPIO_PIN0,
  .rows[0].Direction = GPIO_DIRECTION_OUTPUT,
  .rows[0].Logic = GPIO_LOW,
  
  .rows[1].PORT = PORTC_INDEX,
  .rows[1].PIN = GPIO_PIN1,
  .rows[1].Direction = GPIO_DIRECTION_OUTPUT,
  .rows[1].Logic = GPIO_LOW,
  
  .rows[2].PORT = PORTC_INDEX,
  .rows[2].PIN = GPIO_PIN2,
  .rows[2].Direction = GPIO_DIRECTION_OUTPUT,
  .rows[2].Logic = GPIO_LOW,
  
  .rows[3].PORT = PORTC_INDEX,
  .rows[3].PIN = GPIO_PIN3,
  .rows[3].Direction = GPIO_DIRECTION_OUTPUT,
  .rows[3].Logic = GPIO_LOW,
  
  .columns[0].PORT = PORTC_INDEX,
  .columns[0].PIN = GPIO_PIN4,
  .columns[0].Direction = GPIO_DIRECTION_INPUT,
  .columns[0].Logic = GPIO_LOW,
  
  .columns[1].PORT = PORTC_INDEX,
  .columns[1].PIN = GPIO_PIN5,
  .columns[1].Direction = GPIO_DIRECTION_INPUT,
  .columns[1].Logic = GPIO_LOW,
  
  .columns[2].PORT = PORTC_INDEX,
  .columns[2].PIN = GPIO_PIN6,
  .columns[2].Direction = GPIO_DIRECTION_INPUT,
  .columns[2].Logic = GPIO_LOW,
  
  .columns[3].PORT = PORTC_INDEX,
  .columns[3].PIN = GPIO_PIN7,
  .columns[3].Direction = GPIO_DIRECTION_INPUT,
  .columns[3].Logic = GPIO_LOW,
};

LCD_4bits_t lcd_1 ={
    .EN_BIT.PORT = PORTD_INDEX,
    .EN_BIT.PIN = GPIO_PIN1,
    .EN_BIT.Direction = GPIO_DIRECTION_OUTPUT,
    .EN_BIT.Logic = GPIO_LOW,
    
    .RS_REG.PORT = PORTD_INDEX,
    .RS_REG.PIN = GPIO_PIN0,
    .RS_REG.Direction = GPIO_DIRECTION_OUTPUT,
    .RS_REG.Logic = GPIO_LOW,
    
    .DATA_BITS[0].PORT = PORTD_INDEX,
    .DATA_BITS[0].PIN = GPIO_PIN4,
    .DATA_BITS[0].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[0].Logic = GPIO_LOW,
    
    .DATA_BITS[1].PORT = PORTD_INDEX,
    .DATA_BITS[1].PIN = GPIO_PIN5,
    .DATA_BITS[1].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[1].Logic = GPIO_LOW,
    
    .DATA_BITS[2].PORT = PORTD_INDEX,
    .DATA_BITS[2].PIN = GPIO_PIN6,
    .DATA_BITS[2].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[2].Logic = GPIO_LOW,
    
    .DATA_BITS[3].PORT = PORTD_INDEX,
    .DATA_BITS[3].PIN = GPIO_PIN7,
    .DATA_BITS[3].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[3].Logic = GPIO_LOW,
    
};
/*
LCD_8bits_t lcd_2 ={
    .EN_BIT.PORT = PORTC_INDEX,
    .EN_BIT.PIN = GPIO_PIN7,
    .EN_BIT.Direction = GPIO_DIRECTION_OUTPUT,
    .EN_BIT.Logic = GPIO_LOW,
    
    .RS_REG.PORT = PORTC_INDEX,
    .RS_REG.PIN = GPIO_PIN6,
    .RS_REG.Direction = GPIO_DIRECTION_OUTPUT,
    .RS_REG.Logic = GPIO_LOW,
    
    .DATA_BITS[0].PORT = PORTD_INDEX,
    .DATA_BITS[0].PIN = GPIO_PIN0,
    .DATA_BITS[0].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[0].Logic = GPIO_LOW,
    
    .DATA_BITS[1].PORT = PORTD_INDEX,
    .DATA_BITS[1].PIN = GPIO_PIN1,
    .DATA_BITS[1].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[1].Logic = GPIO_LOW,
    
    .DATA_BITS[2].PORT = PORTD_INDEX,
    .DATA_BITS[2].PIN = GPIO_PIN2,
    .DATA_BITS[2].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[2].Logic = GPIO_LOW,
    
    .DATA_BITS[3].PORT = PORTD_INDEX,
    .DATA_BITS[3].PIN = GPIO_PIN3,
    .DATA_BITS[3].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[3].Logic = GPIO_LOW,
    
    .DATA_BITS[4].PORT = PORTD_INDEX,
    .DATA_BITS[4].PIN = GPIO_PIN4,
    .DATA_BITS[4].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[4].Logic = GPIO_LOW,
    
    .DATA_BITS[5].PORT = PORTD_INDEX,
    .DATA_BITS[5].PIN = GPIO_PIN5,
    .DATA_BITS[5].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[5].Logic = GPIO_LOW,
    
    .DATA_BITS[6].PORT = PORTD_INDEX,
    .DATA_BITS[6].PIN = GPIO_PIN6,
    .DATA_BITS[6].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[6].Logic = GPIO_LOW,
    
    .DATA_BITS[7].PORT = PORTD_INDEX,
    .DATA_BITS[7].PIN = GPIO_PIN7,
    .DATA_BITS[7].Direction = GPIO_DIRECTION_OUTPUT,
    .DATA_BITS[7].Logic = GPIO_LOW,
    
};

*/