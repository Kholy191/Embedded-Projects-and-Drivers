/* 
 * File:   Timer1.c
 * Author: Ahmed El-Kholy
 *
 * Created on September 29, 2023, 12:46 AM
 */

#include "Timer1.h"
/*HELPERS FUNCTION DECLRATION*/
static void TMR1_Mode_Select(TIMER1_t *TMR1);
static void TMR1_Interrupt_Init(TIMER1_t *TMR1);

static void (*Interrupt_Handler)(void) = NULL;
static uint16 TMR1_preload = 0;
/*---------------------------*/


Std_ReturnType Timer1_Initialize(TIMER1_t *TMR1){
     
    Std_ReturnType ret = E_OK;
    
    if(TMR1 == NULL){
        ret = E_NOT_OK;
    }
    else{
        /*Disable TMR0*/
        TIMER1_OFF();
        /*TMR1 Mode Select*/
        TMR1_Mode_Select(TMR1);
        /*Timer1 Oscillator Enable bit*/
        if(TMR1_OSCILLATOR_ENABLE == TMR1->TMR1_OSCILLATOR_MODE){
            TIMER1_OSCILLATOR_ENABLE();
        }
        else if(TMR1_OSCILLATOR_DISABLE == TMR1->TMR1_OSCILLATOR_MODE){
            TIMER1_OSCILLATOR_DISABLE();
        }
        else{/*Nothing*/}
        /*Prescaler Select*/
        TIMER0_PRESCALER_SELECTING(TMR1->TMR1_Prescaler_Selected);
        /*Interrupt configuration*/
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TMR1_Interrupt_Init(TMR1);
#endif
        /*preload Value Writing*/
        TMR1H = (TMR1->TMR1_Preload_Value >> 8);
        TMR1L = (uint8)(TMR1->TMR1_Preload_Value);
        TMR1_preload = TMR1->TMR1_Preload_Value;
        /*Enable TMR1*/  
        TIMER1_ON();
    }
    return ret;
}

Std_ReturnType Timer1_Dinit(TIMER1_t *TMR1){
     
    Std_ReturnType ret = E_OK;
    
    if(TMR1 == NULL){
        ret = E_NOT_OK;
    }
    else{
         TIMER1_OFF();
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE
        TMR1_INTERRUPT_DISABLE();    
#endif
    }
    return ret; 
}

Std_ReturnType Timer1_Write_Value(TIMER1_t *TMR1 , uint16 value){
     
    Std_ReturnType ret = E_OK;
    
    if(TMR1 == NULL){
        ret = E_NOT_OK;
    }
    else{
        TMR1H = (value >> 8);
        TMR1L = (uint8)(value);
    }
    return ret;
}

Std_ReturnType Timer1_Read_Value(TIMER1_t *TMR1 , uint16 *value){
    uint8 TMHIGH = 0 , TMLOW = 0;
    Std_ReturnType ret = E_OK;
    
    if((TMR1 == NULL) || (value == NULL)){
        ret = E_NOT_OK;
    }
    else{
            TMLOW = TMR1L;
            TMHIGH = TMR1H;
            *value = (uint16)(TMLOW + (TMHIGH << 8));
    }
    return ret;
}


/*HELPERS FUNCTIONS*/
static void TMR1_Mode_Select(TIMER1_t *TMR1){
    if(TMR1_TIMER_MODE == TMR1->TMR1_Mode_Selected){
        TIMER1_TIMER_MODE_ON();
    }
    else if(TMR1_COUNTER_MODE == TMR1->TMR1_Mode_Selected){
        TIMER1_COUNTER_MODE_ON();
        if(TMR1_ASYNC_COUNTER_MODE == TMR1->TMR1_COUNTER_SYNCHRONIZATION_MODE){
            COUNTER_SYNCHRONIZATION_MODE_OFF();
        }
        else if(TMR1_SYNC_COUNTER_MODE == TMR1->TMR1_COUNTER_SYNCHRONIZATION_MODE){
            COUNTER_SYNCHRONIZATION_MODE_ON();
        }
        else{/*Nothing*/}
       
        SET_BIT(TRISC, _TRISC_RC0_POSN);
    }
    else{/*Nothing*/}
}

#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE   
static void TMR1_Interrupt_Init(TIMER1_t *TMR1){
    TMR1_CLEAR_FLAG();
    TMR1_INTERRUPT_DISABLE();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
    INTERRUPT_IPEN_ENABLE();
    if(High_Priority == TMR1->TMR1_Priority){
        INTERRUPT_GIEH_ENABLE();
        TMR0_SET_HighPriority();
    }  
    else if(Low_Priority == TMR1->TMR1_Priority){
        INTERRUPT_GIEH_ENABLE();
        INTERRUPT_GIEL_ENABLE();
        TMR0_SET_LowPriority();
    }    
#else
    INTERRUPT_GIE_ENABLE();
    INTERRUPT_PEIE_ENABLE();
#endif
    Interrupt_Handler = TMR1->TMR1_Interrupt_Handler;    
    TMR1_INTERRUPT_ENABLE();
}
#endif

/*TMR0 INTERRUPT FUNCTION*/
#if TIMER1_INTERRUPT_FEATURE_ENABLE == INTERRUPT_FEATURE_ENABLE   
void TMR1_ISR(void){
    TMR1_CLEAR_FLAG();
    TMR1H = (TMR1_preload >> 8);
    TMR1L = (uint8)(TMR1_preload);
    if(Interrupt_Handler){
        Interrupt_Handler();
    }
    else{
        //Nothing
    }
}
#endif