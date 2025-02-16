/* 
 * File:   mcal_interrupt_config.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 17, 2023, 12:59 PM
 */

#ifndef MCAL_INTERRUPT_CONFIG_H
#define	MCAL_INTERRUPT_CONFIG_H

/* --------------------------------Section : Includes-------------------------------- */
#include "pic18f4620.h"
#include "mcal_interrupt_code_gen_config.h"
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_types.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */
#define INTERRUPT_ENABLE            1
#define INTERRUPT_DISABLE           0
#define INTERRUPT_PRIORITY_ENABLE   1
#define INTERRUPT_PRIORITY_DISABLE  0
#define INTERRUPT_OCCURED           1
#define INTERRUPT_NOT_OCCURED       0
/* --------------------------------Section: Macro Functions Declarations-------------------------------- */

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/*Enable IPEN*/
#define INTERRUPT_IPEN_ENABLE()  (RCONbits.IPEN = 1)
/*Disable IPEN*/
#define INTERRUPT_IPEN_DISABLE() (RCONbits.IPEN = 0)
/*Enable GIEH*/
#define INTERRUPT_GIEH_ENABLE()  (INTCONbits.GIEH = 1)
/*Disable GIEH*/
#define INTERRUPT_GIEH_Disable()  (INTCONbits.GIEH = 0)
/*Enable GIEL*/
#define INTERRUPT_GIEL_ENABLE()  (INTCONbits.GIEL = 1)
/*Disable GIEL*/
#define INTERRUPT_GIEL_Disable()  (INTCONbits.GIEL = 0)
#else
/*Enable GIE*/
#define INTERRUPT_GIE_ENABLE()   (INTCONbits.GIE = 1)
/*Disable GIE*/
#define INTERRUPT_GIE_DISABLE()  (INTCONbits.GIE = 0)
/*Enable PEIE*/
#define INTERRUPT_PEIE_ENABLE()  (INTCONbits.PEIE = 1)
/*Disable PEIE*/
#define INTERRUPT_PEIE_DISABLE() (INTCONbits.PEIE = 0)

#endif
/* --------------------------------Section: Data Type Declarations-------------------------------- */
typedef enum{
    Low_Priority = 0,
    High_Priority
}Interrupt_Priority;
/* --------------------------------Section: Function Declarations-------------------------------- */


#endif	/* MCAL_INTERRUPT_CONFIG_H */

