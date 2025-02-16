/* 
 * File:   mcal_internal_interrupt.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 17, 2023, 12:50 PM
 */

#ifndef MCAL_INTERNAL_INTERRUPT_H
#define	MCAL_INTERNAL_INTERRUPT_H

/* --------------------------------Section : Includes-------------------------------- */
#include "mcal_interrupt_config.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */

/* --------------------------------Section: Macro Functions Declarations-------------------------------- */
/*ADC MACRO_FUNCTIONS*/
#define ADC_ENABLE()            (PIE1bits.ADIE = 1)
#define ADC_DISABLE()           (PIE1bits.ADIE = 0)

#define ADC_CLEAR_FLAG()        (PIR1bits.ADIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define ADC_SET_HighPriority()  (IPR1bits.ADIP = 1)  
#define ADC_SET_LowPriority()   (IPR1bits.ADIP = 0)      
#endif
/*--------------------------------------------*/

/*TMR0 MACRO_FUNCTIONS*/
#define TMR0_INTERRUPT_ENABLE()     (INTCONbits.TMR0IE = 1)
#define TMR0_INTERRUPT_DISABLE()    (INTCONbits.TMR0IE = 0)

#define TMR0_CLEAR_FLAG()           (INTCONbits.TMR0IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TMR0_SET_HighPriority()     (INTCON2bits.TMR0IP = 1)  
#define TMR0_SET_LowPriority()      (INTCON2bits.TMR0IP = 0)      
#endif
/*--------------------------------------------*/

/*TMR1 MACRO_FUNCTIONS*/
#define TMR1_INTERRUPT_ENABLE()     (PIE1bits.TMR1IE = 1)
#define TMR1_INTERRUPT_DISABLE()    (PIE1bits.TMR1IE = 0)

#define TMR1_CLEAR_FLAG()           (PIR1bits.TMR1IF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
#define TMR1_SET_HighPriority()     (IPR1bits.TMR1IP = 1)  
#define TMR1_SET_LowPriority()      (IPR1bits.TMR1IP = 0)      
#endif
/*--------------------------------------------*/

/* --------------------------------Section: Data Type Declarations-------------------------------- */

/* --------------------------------Section: Function Declarations-------------------------------- */


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

