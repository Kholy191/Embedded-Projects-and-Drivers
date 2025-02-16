/* 
 * File:   Timer0.c
 * Author: Ahmed El-Kholy
 * Created on September 27, 2023, 11:42 PM
 */

#include "Timer0.h"

#if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
void (*Interrupt_Handler)(void) = NULL;
#endif

static uint16 TMR0_preload = 0;

/*Helpers Functions Decl*/
static void TMR0_Mode_Select(TIMER0_t *TMR0);
static void TMR0_Interrupt_Init(TIMER0_t *TMR0);
/*-----------------*/

Std_ReturnType Timer0_Initialize(TIMER0_t *TMR0){
     
    Std_ReturnType ret = E_OK;
    
    if(TMR0 == NULL){
        ret = E_NOT_OK;
    }
    else{
        /*Disable TMR0*/
        TIMER0_OFF();
        /*TMR0 Size Select*/
        if(TIMER0_16BIT__MODE == TMR0->TMR0_Size_Selected){
            TIMER0_16BIT_REGISTER_MODE_ENABLE();
        }
        else if(TIMER0_8BIT__MODE == TMR0->TMR0_Size_Selected){
            TIMER0_8BIT_REGISTER_MODE_ENABLE();
        }
        else{/*Nothing*/}
        /*TMR0 Mode Select*/
        TMR0_Mode_Select(TMR0);
        /*Prescaler Mode Select*/
        if(TIMER0_Prescaler_Disable == TMR0->TMR0_Prescaler_Mode_Selected){
            TIMER0_PRESCALER_DISABLE();
        }
        else if(TIMER0_Prescaler_Enable == TMR0->TMR0_Prescaler_Mode_Selected){
            TIMER0_PRESCALER_ENABLE();
            TIMER0_PRESCALER_SELECTING(TMR0->TMR0_Prescaler_Selected);
        }
        else{/*Nothing*/}
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TMR0_Interrupt_Init(TMR0);    
#endif
        /*Preload Value Writing*/
        TMR0H = ((TMR0->TMR0_Preload_Value) >> 8);
        TMR0L = (uint8)(TMR0->TMR0_Preload_Value);
        TMR0_preload = TMR0->TMR0_Preload_Value;
        /*Enable TMR0*/  
        TIMER0_ON();
    }
    return ret;
}

Std_ReturnType Timer0_Dinit(TIMER0_t *TMR0){
     
    Std_ReturnType ret = E_OK;
    
    if(TMR0 == NULL){
        ret = E_NOT_OK;
    }
    else{
        TIMER0_OFF();
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TMR0_INTERRUPT_DISABLE();    
#endif
    }
    return ret;
}

Std_ReturnType Timer0_Write_Value(TIMER0_t *TMR0 , uint16 value){
     
    Std_ReturnType ret = E_OK;
    
    if(TMR0 == NULL){
        ret = E_NOT_OK;
    }
    else{
        TMR0H = (value >> 8);
        TMR0L = (uint8)(value);
    }
    return ret;
}

Std_ReturnType Timer0_Read_Value(TIMER0_t *TMR0 , uint16 *value){
    uint8 TMHIGH = 0 , TMLOW = 0;
    Std_ReturnType ret = E_OK;
    
    if(TMR0 == NULL){
        ret = E_NOT_OK;
    }
    else{
        TMLOW = TMR0L;
        TMHIGH = TMR0H;
        *value = (uint16)(TMLOW + (TMHIGH << 8));
        
    }
    return ret;
}

/*Helpers Functions*/

static void TMR0_Mode_Select(TIMER0_t *TMR0){
    if(TIMER0_TIMER_MODE == TMR0->TMR0_Mode_Selected){
        TIMER0_TIMER_MODE_ON();
    }
    else if(TIMER0_COUNTER_MODE == TMR0->TMR0_Mode_Selected){
        TIMER0_COUNTER_MODE_ON();
        if(TIMER0_FALLING_EDGE_MODE == TMR0->TMR0_EdgeMode_Selected){
            TIMER0_FALLING_EDGE_SELECT();
        }
        else if(TIMER0_RISING_EDGE_MODE == TMR0->TMR0_EdgeMode_Selected){
            TIMER0_RISING_EDGE_SELECT();
        }
        else{/*Nothing*/}
        SET_BIT(TRISA, _TRISA_RA4_POSN);
    }
    else{/*Nothing*/}
}

#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE   
static void TMR0_Interrupt_Init(TIMER0_t *TMR0){
    TMR0_CLEAR_FLAG();
    TMR0_INTERRUPT_DISABLE();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
    INTERRUPT_IPEN_ENABLE();
    if(High_Priority == TMR0->TMR0_Priority){
        INTERRUPT_GIEH_ENABLE();
        TMR0_SET_HighPriority();
    }  
    else if(Low_Priority == TMR0->TMR0_Priority){
        INTERRUPT_GIEH_ENABLE();
        INTERRUPT_GIEL_ENABLE();
        TMR0_SET_LowPriority();
    }    
#else
    INTERRUPT_GIE_ENABLE();
    INTERRUPT_PEIE_ENABLE();
#endif
    Interrupt_Handler = TMR0->TMR0_Interrupt_Handler;    
    TMR0_INTERRUPT_ENABLE();
}
#endif

/*TMR0 INTERRUPT FUNCTION*/
#if TIMER0_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE   
void TMR0_ISR(void){
    TMR0_CLEAR_FLAG();
    TMR0H = (TMR0_preload >> 8);
    TMR0L = (uint8)(TMR0_preload);
    if(Interrupt_Handler){
        Interrupt_Handler();
    }
    else{
        //Nothing
    }
}
#endif