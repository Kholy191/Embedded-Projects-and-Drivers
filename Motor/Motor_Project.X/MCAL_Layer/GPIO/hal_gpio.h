/* 
 * File:   hal_gpio.h
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 1:05 PM
 */

#ifndef HAL_GPIO_H
#define	HAL_GPIO_H

/* Section : Includes */

#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../device_config.h"

/* Section: Macro Declarations */

#define BIT_MASK 0x01

#define PORT_MAX 4
#define PIN_MAX  7

#define PORTC_MASK           0xFF

#define PORT_OUTPUT          0x00
#define PORT_INPUT           0xFF



/* Section: Macro Functions Declarations */

#define HWREG8(Address)           (*((volatile uint8 *)(Address)))

#define SET_BIT(REG,Bit_Pos)      (REG |= (BIT_MASK << Bit_Pos))
#define CLEAR_BIT(REG,Bit_Pos)    (REG &= ~(BIT_MASK << Bit_Pos))
#define TOGGLE_BIT(REG,Bit_Pos)   (REG ^= (BIT_MASK << Bit_Pos))

#define READ_BIT(REG, BIT_POSN)    ((REG >> BIT_POSN) & BIT_MASK)
 
/* Section: Data Type Declarations */

typedef enum{
    
    GPIO_PIN0=0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
            
}Pin_Index;

typedef enum{
    
    PORTA_INDEX=0,
    PORTB_INDEX,  
    PORTC_INDEX,
    PORTD_INDEX,
    PORTE_INDEX        
            
}PORT_INDEX;

typedef enum{
    
    GPIO_DIRECTION_OUTPUT=0,
    GPIO_DIRECTION_INPUT
            
}DIRECTON;

typedef enum{
    
    GPIO_LOW=0,
    GPIO_HIGH=1
            
}logic;

typedef struct{
    
    uint8 PIN  :3;
    uint8 PORT :3;
    uint8 Direction :1;
    uint8 Logic     :1;
    
}PIN_CONFIG;




/* Section: Function Declarations */

Std_ReturnType gpio_pin_direction_intialize(const PIN_CONFIG *str);
Std_ReturnType gpio_pin_get_direction(const PIN_CONFIG *str, DIRECTON *direction );
Std_ReturnType gpio_pin_write_logic(const PIN_CONFIG *str, logic LOG );
Std_ReturnType gpio_pin_read_logic(const PIN_CONFIG *str , logic *LOG);
Std_ReturnType gpio_pin_toggle(const PIN_CONFIG *str);
Std_ReturnType gpio_pin_intialize(const PIN_CONFIG *str);


Std_ReturnType gpio_port_direction_intialize(PORT_INDEX PORT , uint8 direction);
Std_ReturnType gpio_port_get_direction(PORT_INDEX PORT , uint8 *direction);
Std_ReturnType gpio_port_write_logic(PORT_INDEX PORT , uint8 LOG );
Std_ReturnType gpio_port_read_logic(PORT_INDEX PORT , uint8 *LOG);
Std_ReturnType gpio_port_toggle_logic(PORT_INDEX PORT);






#endif	/* HAL_GPIO_H */

