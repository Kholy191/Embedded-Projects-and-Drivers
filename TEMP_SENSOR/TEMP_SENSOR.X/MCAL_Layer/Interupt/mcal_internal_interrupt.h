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
#define ADC_SET_LowPriority()  (IPR1bits.ADIP = 0)      
#endif
/*--------------------------------------------*/
/* --------------------------------Section: Data Type Declarations-------------------------------- */

/* --------------------------------Section: Function Declarations-------------------------------- */


#endif	/* MCAL_INTERNAL_INTERRUPT_H */

