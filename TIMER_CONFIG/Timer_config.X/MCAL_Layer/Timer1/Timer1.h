/* 
 * File:   Timer1.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 29, 2023, 12:46 AM
 */

#ifndef TIMER1_H
#define	TIMER1_H

/* --------------------------------Section : Includes-------------------------------- */
#include "pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "../Interupt/mcal_internal_interrupt.h"
#include "../mcal_std_types.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */
/* Timer1 Clock Source (Timer or Counter) */
#define TMR1_COUNTER_MODE            1
#define TMR1_TIMER_MODE              0
/* Timer1 External Clock Input Synchronization */
#define TMR1_ASYNC_COUNTER_MODE      1
#define TMR1_SYNC_COUNTER_MODE       0
/* Timer1 Oscillator */
#define TMR1_OSCILLATOR_ENABLE       1
#define TMR1_OSCILLATOR_DISABLE      0
/* Timer1 Input Clock Pre-scaler */
#define TMR1_PRESCALER_DIV_BY_1      0
#define TMR1_PRESCALER_DIV_BY_2      1
#define TMR1_PRESCALER_DIV_BY_4      2
#define TMR1_PRESCALER_DIV_BY_8      3
/* 16-Bit Read/Write Mode */
#define TMR1_RW_REG_8Bit_MODE        0
#define TMR1_RW_REG_16Bit_MODE       1
/* --------------------------------Section: Macro Functions Declarations-------------------------------- */
/*Enable and Disable TMR1*/
#define TIMER1_ON()                      (T1CONbits.TMR1ON = 1)
#define TIMER1_OFF()                     (T1CONbits.TMR1ON = 0)
/*TMR1 Mode Select*/
#define TIMER1_COUNTER_MODE_ON()         (T1CONbits.TMR1CS = 1)
#define TIMER1_TIMER_MODE_ON()           (T1CONbits.TMR1CS = 0)
/*Prescaler Select*/
#define TIMER0_PRESCALER_SELECTING(Prescaler)    (T1CONbits.T1CKPS = Prescaler)
/*Counter Synchronization Mode Select*/
#define COUNTER_SYNCHRONIZATION_MODE_OFF()   (T1CONbits.T1SYNC = 1) 
#define COUNTER_SYNCHRONIZATION_MODE_ON()    (T1CONbits.T1SYNC = 0) 
/*Timer1 Oscillator Enable bit*/
#define TIMER1_OSCILLATOR_ENABLE()      (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSCILLATOR_DISABLE()     (T1CONbits.T1OSCEN = 0) 
/*16-bit Read/Write Mode Enable bit*/
#define TIMER1_16BIT_RW_ENABLE()        (T1CONbits.RD16 = 1)
#define TIMER1_16BIT_RW_DISABLE()       (T1CONbits.RD16 = 0)
/*Timer1 System Clock Status bit*/  
#define TIMER1_System_Clock_Status()    (T1CONbits.T1RUN)
/* --------------------------------Section: Data Type Declarations-------------------------------- */
typedef struct{
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
    void (* TMR1_Interrupt_Handler)(void);
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE    
    Interrupt_Priority TMR1_Priority;    
#endif
#endif   
    uint16 TMR1_Preload_Value; 
    uint8 TMR1_Prescaler_Selected :2 ;
    uint8 TMR1_Mode_Selected :1;
    uint8 TMR1_COUNTER_SYNCHRONIZATION_MODE :1 ;
    uint8 TMR1_OSCILLATOR_MODE :1 ;
    uint8 TMR1_16BIT_RW_MODE :1 ; 
    uint8 Reserved :2;
}TIMER1_t;
/* --------------------------------Section: Function Declarations-------------------------------- */
Std_ReturnType Timer1_Initialize(TIMER1_t *TMR1);
Std_ReturnType Timer1_Dinit(TIMER1_t *TMR1);
Std_ReturnType Timer1_Write_Value(TIMER1_t *TMR1 , uint16 value);
Std_ReturnType Timer1_Read_Value(TIMER1_t *TMR1 , uint16 *value);
#endif	/* TIMER1_H */

