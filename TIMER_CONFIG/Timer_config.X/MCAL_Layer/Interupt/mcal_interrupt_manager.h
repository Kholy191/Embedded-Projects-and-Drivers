/* 
 * File:   mcal_interrupt_manager.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 17, 2023, 12:50 PM
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/* --------------------------------Section : Includes-------------------------------- */
#include "mcal_interrupt_config.h"

/* --------------------------------Section: Macro Declarations-------------------------------- */

/* --------------------------------Section: Macro Functions Declarations-------------------------------- */

/* --------------------------------Section: Data Type Declarations-------------------------------- */

/* --------------------------------Section: Function Declarations-------------------------------- */
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void RB4_ISR(uint8 FUNC_DETECTION);
void RB5_ISR(uint8 FUNC_DETECTION);
void RB6_ISR(uint8 FUNC_DETECTION);
void RB7_ISR(uint8 FUNC_DETECTION);

void ADC_ISR(void);

void TMR0_ISR(void);
void TMR1_ISR(void);
#endif	/* MCAL_INTERRUPT_MANAGER_H */

