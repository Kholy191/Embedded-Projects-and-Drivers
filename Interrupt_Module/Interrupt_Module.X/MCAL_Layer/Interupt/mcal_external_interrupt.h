/* 
 * File:   mcal_external_interrupt.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 17, 2023, 12:50 PM
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/* --------------------------------Section : Includes-------------------------------- */
#include "mcal_interrupt_config.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */

/* --------------------------------Section: Macro Functions Declarations-------------------------------- */
/*INTX MACRO_FUNCTIONS*/
#if EXTERNAL_INTERRUPT_INTx_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE

/*INT0*/
#define EXT_INT0_Enable()          (INTCONbits.INT0IE = 1)
#define EXT_INT0_Disable()         (INTCONbits.INT0IE = 0)
#define EXT_INT0_Clear_Flag()      (INTCONbits.INT0IF = 0)
#define EXT_INT0_Set_RisingEdge()  (INTCON2bits.INTEDG0 = 1)
#define EXT_INT0_Set_FallingEdge() (INTCON2bits.INTEDG0 = 0)

/*INT1*/
#define EXT_INT1_Enable()          (INTCON3bits.INT1IE = 1)
#define EXT_INT1_Disable()         (INTCON3bits.INT1IE = 0)
#define EXT_INT1_Clear_Flag()      (INTCON3bits.INT1IF = 0)
#define EXT_INT1_Set_RisingEdge()  (INTCON2bits.INTEDG1 = 1)
#define EXT_INT1_Set_FallingEdge() (INTCON2bits.INTEDG1 = 0)

/*INT2*/
#define EXT_INT2_Enable()          (INTCON3bits.INT2IE = 1)
#define EXT_INT2_Disable()         (INTCON3bits.INT2IE = 0)
#define EXT_INT2_Clear_Flag()      (INTCON3bits.INT2IF = 0)
#define EXT_INT2_Set_RisingEdge()  (INTCON2bits.INTEDG2 = 1)
#define EXT_INT2_Set_FallingEdge() (INTCON2bits.INTEDG2 = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/*INT1 PRIORITY INITALIZE*/
#define EXT_INT1_Priority_HIGH()   (INTCON3bits.INT1IP = 1)
#define EXT_INT1_Priority_LOW()    (INTCON3bits.INT1IP = 0)
/*INT2 PRIORITY INITALIZE*/
#define EXT_INT2_Priority_HIGH()   (INTCON3bits.INT2IP = 1)
#define EXT_INT2_Priority_LOW()    (INTCON3bits.INT2IP = 0)

#endif

#endif

#if EXTERNAL_INTERRUPT_OnChange_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
/*RBX INITIALIZE*/
#define EXT_RB_Enable()            (INTCONbits.RBIE = INTERRUPT_ENABLE)
#define EXT_RB_Disable()           (INTCONbits.RBIE = INTERRUPT_DISABLE)
#define EXT_RB_Clear_Flag()        (INTCONbits.RBIF = 0)

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
/*RBX PRIORITY INITALIZE*/
#define EXT_RB_Priority_HIGH()   (INTCON2bits.RBIP = INTERRUPT_PRIORITY_ENABLE)
#define EXT_RB_Priority_LOW()    (INTCON2bits.RBIP = INTERRUPT_PRIORITY_DISABLE)

#endif

#endif
/* --------------------------------Section: Data Type Declarations-------------------------------- */
typedef void (*InterruptHandler)(void);

typedef enum{
    Interrupt_Falling_Edge,
    Interrupt_Rising_Edge    
}EXT_Interrupt_Edge;

typedef enum{
    INTERRUPT_EXTERNAL_INT0,
    INTERRUPT_EXTERNAL_INT1,
    INTERRUPT_EXTERNAL_INT2        
}EXT_Interrupt_Src;

/*INTX Type*/
typedef struct{
    void (* EXT_InterruptHandler) (void);
    PIN_CONFIG INTX_PIN;
    EXT_Interrupt_Src INTX_SRC;
    EXT_Interrupt_Edge INTX_EDGE;
    Interrupt_Priority INTX_PRIORITY;
}Ext_Interrupt_INTX_t;

/*On change Type*/
typedef struct{
    void (* EXT_InterruptHandler_HIGH) (void);
    void (* EXT_InterruptHandler_LOW) (void);
    PIN_CONFIG INTX_PIN;
    Interrupt_Priority INTX_PRIORITY;
}Ext_Interrupt_RBX_t;
/* --------------------------------Section: Function Declarations-------------------------------- */
/*INTX FUNCTIONS*/
Std_ReturnType EXT_INTX_Intialize(Ext_Interrupt_INTX_t *INT_X);
Std_ReturnType EXT_INTX_Disable(Ext_Interrupt_INTX_t *INT_X);
/*RBX FUNCTIONS*/
Std_ReturnType EXT_RBX_Intialize(Ext_Interrupt_RBX_t *RB_X);
Std_ReturnType EXT_RBX_Disable(Ext_Interrupt_RBX_t *RB_X);

#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

