/* 
 * File:   Timer0.h
 * Author: Ahmed El-Kholy
 * Created on September 27, 2023, 11:42 PM
 */

#ifndef TIMER0_H
#define	TIMER0_H

/* --------------------------------Section : Includes-------------------------------- */
#include "pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "../Interupt/mcal_internal_interrupt.h"
#include "../mcal_std_types.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */
#define TIMER0_8BIT__MODE           1
#define TIMER0_16BIT__MODE          0

#define TIMER0_COUNTER_MODE         1
#define TIMER0_TIMER_MODE           0

#define TIMER0_FALLING_EDGE_MODE    1
#define TIMER0_RISING_EDGE_MODE     0

#define TIMER0_Prescaler_Enable     1
#define TIMER0_Prescaler_Disable    0

/* --------------------------------Section: Macro Functions Declarations-------------------------------- */
/*Enable and Disable TMR0*/
#define TIMER0_ON()     (T0CONbits.TMR0ON = 1)
#define TIMER0_OFF()    (T0CONbits.TMR0ON = 0)
/*TMR0 Size Control*/
#define TIMER0_8BIT_REGISTER_MODE_ENABLE()     (T0CONbits.T08BIT = 1)
#define TIMER0_16BIT_REGISTER_MODE_ENABLE()    (T0CONbits.T08BIT = 0)
/*TMR0 Mode Select*/
#define TIMER0_COUNTER_MODE_ON()        (T0CONbits.T0CS = 1)
#define TIMER0_TIMER_MODE_ON()          (T0CONbits.T0CS = 0)
/*Edge Initialize in Counter Mode*/
#define TIMER0_FALLING_EDGE_SELECT()    (T0CONbits.T0SE = 1)
#define TIMER0_RISING_EDGE_SELECT()     (T0CONbits.T0SE = 0)
/*Prescaler Enable/Disable*/
#define TIMER0_PRESCALER_DISABLE()      (T0CONbits.PSA = 1)
#define TIMER0_PRESCALER_ENABLE()       (T0CONbits.PSA = 0)
/*Prescaler Select*/
#define TIMER0_PRESCALER_SELECTING(Selected_Prescaler)    (T0CONbits.T0PS = Selected_Prescaler)

/* --------------------------------Section: Data Type Declarations-------------------------------- */
typedef enum{
    TIMER0_PRESCALER_DIV_BY_2= 0,
    TIMER0_PRESCALER_DIV_BY_4,
    TIMER0_PRESCALER_DIV_BY_8,
    TIMER0_PRESCALER_DIV_BY_16,
    TIMER0_PRESCALER_DIV_BY_32,
    TIMER0_PRESCALER_DIV_BY_64,
    TIMER0_PRESCALER_DIV_BY_128,
    TIMER0_PRESCALER_DIV_BY_256
}Timer0_Prescaler_Select;

typedef struct{
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* TMR0_Interrupt_Handler)(void);
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE    
    Interrupt_Priority TMR0_Priority;    
#endif
#endif    
    Timer0_Prescaler_Select TMR0_Prescaler_Selected;
    uint16 TMR0_Preload_Value;    
    uint8 TMR0_Mode_Selected :1;
    uint8 TMR0_Size_Selected :1;
    uint8 TMR0_EdgeMode_Selected :1;
    uint8 TMR0_Prescaler_Mode_Selected :1;
    uint8 Reserved :4;
}TIMER0_t;

/* --------------------------------Section: Function Declarations-------------------------------- */
Std_ReturnType Timer0_Initialize(TIMER0_t *TMR0);
Std_ReturnType Timer0_Dinit(TIMER0_t *TMR0);
Std_ReturnType Timer0_Write_Value(TIMER0_t *TMR0 , uint16 value);
Std_ReturnType Timer0_Read_Value(TIMER0_t *TMR0 , uint16 *value);
#endif	/* TIMER0_H */

