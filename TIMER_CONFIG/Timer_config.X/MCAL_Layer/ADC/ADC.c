/* 
 * File:   ADC.c
 * Author: Ahmed El-Kholy
 *
 * Created on September 24, 2023, 2:54 PM
 */
#include "ADC.h"
static void Interrupt_Init(ADC_t *Adc_);
static inline void Pins_Configration_Func(CHANNEL_SELECTED_t channel);

#if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
static void (*ADC_InterruptHandler)(void) = NULL;
#endif

Std_ReturnType ADC_Initialize(ADC_t *Adc_){
     
    Std_ReturnType ret = E_OK;
    
    if(Adc_ == NULL){
        ret = E_NOT_OK;
    }
    else{
        /*Disable ADC*/
        ADC_Disable();
        /*Set Voltage Reference*/
        if(Voltage_Reference_Externally == Adc_->VOLTAGE_REFERENCE){
            ADC_ENABLE_VOLTAGE_REFERENCE();
        }
        else if(Voltage_Reference_Internally == Adc_->VOLTAGE_REFERENCE){
            ADC_DISABLE_VOLTAGE_REFERENCE();
        }
        else{
            ADC_DISABLE_VOLTAGE_REFERENCE();
        }
        /*Select Format*/
        if(ADC_RESULT_RIGHT == Adc_->RESULT_FORMAT){
            Right_Result_Format();
        }
        else if(ADC_RESULT_LEFT == Adc_->RESULT_FORMAT){
            Left_Result_Format();
        }
        else{
            Right_Result_Format();
        }
        /*A/D Acquisition time select*/
        Acquisition_Time_Select(Adc_->ACQU_TIME);
        /*A/D clock Select*/
        Freq_Select(Adc_->CLOCK_FREQ);
        /*Channel Selecting*/
        Channel_Selecting(Adc_->DEFAULT_CHANNEL);
        /*MAKE PINS INPUT*/
        Pins_Configration_Func(Adc_->DEFAULT_CHANNEL);
        /*initialize interrupt*/
#if INTERRUPT_FEATURE_ENABLE==ADC_INTERRUPT_FEATURE_ENABLE   
        Interrupt_Init(Adc_);
#endif
        /*Enable ADC*/
        ADC_Enable();
        
        
    }
    return ret;
}

Std_ReturnType ADC_DInitialize(ADC_t *Adc_){
     
    Std_ReturnType ret = E_OK;
    
    if(Adc_ == NULL){
        ret = E_NOT_OK;
    }
    else{
        /*Enable ADC*/
        ADC_Disable();
        /*Disable Interrupt*/
#if ADC_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
        
#endif
    }
    return ret;
}

Std_ReturnType ADC_Start_Conversion_Func(ADC_t *Adc_){
     
    Std_ReturnType ret = E_OK;
    
    if(Adc_ == NULL){
        ret = E_NOT_OK;
    }
    else{
        ADC_Start_Conversion();
    }
    return ret;
}

Std_ReturnType ADC_Select_Channel(ADC_t *Adc_ , CHANNEL_SELECTED_t channel){
     
    Std_ReturnType ret = E_OK;
    
    if(Adc_ == NULL){
        ret = E_NOT_OK;
    }
    else{
        Channel_Selecting(channel);
        Pins_Configration_Func(channel);
        
    }
    return ret;
}

Std_ReturnType ADC_IsConversionDone(ADC_t *Adc_ , uint8 *Isdone_Detect){
     
    Std_ReturnType ret = E_OK;
    
    if(Adc_ == NULL || (NULL ==Isdone_Detect)){
        ret = E_NOT_OK;
    }
    else{
        *Isdone_Detect = ADC_Conversion_Status();
    }
    return ret;
}

Std_ReturnType ADC_GetConversionResult(ADC_t *Adc_ , Result_t *Result){
     
    Std_ReturnType ret = E_OK;
    
    if(Adc_ == NULL  || (NULL ==Result)){
        ret = E_NOT_OK;
    }
    else{
        if(ADC_RESULT_RIGHT == Adc_->RESULT_FORMAT){
            *Result = (Result_t)((ADRESH << 8) + ADRESL); 
        }
        else if(ADC_RESULT_LEFT == Adc_->RESULT_FORMAT){
            *Result = (Result_t)(((ADRESH << 8) + ADRESL) >> 6);
        }
        else{
            *Result = (Result_t)((ADRESH << 8) + ADRESL);
        }
         
    }
    return ret;
}

Std_ReturnType ADC_GetConversion_Blocking(ADC_t *Adc_ , CHANNEL_SELECTED_t channel , Result_t *Result){
     
    Std_ReturnType ret = E_OK;
    
    if(Adc_ == NULL || (NULL ==Result)){
        ret = E_NOT_OK;
    }
    else{
        /*select channel*/
        ret = ADC_Select_Channel(Adc_ , channel);
        /*Start Conversion*/
        ret = ADC_Start_Conversion_Func(Adc_);
        /*wait until Conversion finished*/
        while(ADC_Conversion_Status());
        /*return results*/
        ret = ADC_GetConversionResult(Adc_ , Result);
    }
    return ret;
}



Std_ReturnType ADC_StartConversion_Interrupt(ADC_t *Adc_ , CHANNEL_SELECTED_t channel){
     
    Std_ReturnType ret = E_OK;
    
    if(Adc_ == NULL){
        ret = E_NOT_OK;
    }
    else{
        /*select channel*/
        ret = ADC_Select_Channel(Adc_ , channel);
        /*Start Conversion*/
        ret = ADC_Start_Conversion_Func(Adc_);
    }
    return ret;
}

static inline void Pins_Configration_Func(CHANNEL_SELECTED_t channel){
    switch(channel){
        case AN0_CHANNEL :  SET_BIT(TRISA, _TRISA_RA0_POSN); break; /* Disable the digital output driver */
        case AN1_CHANNEL :  SET_BIT(TRISA, _TRISA_RA1_POSN); break; /* Disable the digital output driver */
        case AN2_CHANNEL :  SET_BIT(TRISA, _TRISA_RA2_POSN); break; /* Disable the digital output driver */
        case AN3_CHANNEL :  SET_BIT(TRISA, _TRISA_RA3_POSN); break; /* Disable the digital output driver */
        case AN4_CHANNEL :  SET_BIT(TRISA, _TRISA_RA5_POSN); break; /* Disable the digital output driver */
        case AN5_CHANNEL :  SET_BIT(TRISE, _TRISE_RE0_POSN); break; /* Disable the digital output driver */
        case AN6_CHANNEL :  SET_BIT(TRISE, _TRISE_RE1_POSN); break; /* Disable the digital output driver */
        case AN7_CHANNEL :  SET_BIT(TRISE, _TRISE_RE2_POSN); break; /* Disable the digital output driver */
        case AN8_CHANNEL :  SET_BIT(TRISB, _TRISB_RB2_POSN); break; /* Disable the digital output driver */
        case AN9_CHANNEL :  SET_BIT(TRISB, _TRISB_RB3_POSN); break; /* Disable the digital output driver */
        case AN10_CHANNEL : SET_BIT(TRISB, _TRISB_RB1_POSN); break; /* Disable the digital output driver */
        case AN11_CHANNEL : SET_BIT(TRISB, _TRISB_RB4_POSN); break; /* Disable the digital output driver */
        case AN12_CHANNEL : SET_BIT(TRISB, _TRISB_RB0_POSN); break; /* Disable the digital output driver */
        default : /* Nothing */;
    }
}
#if INTERRUPT_FEATURE_ENABLE == ADC_INTERRUPT_FEATURE_ENABLE   
static void Interrupt_Init(ADC_t *Adc_){
    ADC_CLEAR_FLAG();
    ADC_DISABLE();
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
    INTERRUPT_IPEN_ENABLE();
    if(High_Priority == Adc_->ADC_Interrupt_Priority){
        INTERRUPT_GIEH_ENABLE();
        ADC_SET_HighPriority();
    }  
    else if(Low_Priority == Adc_->ADC_Interrupt_Priority){
        INTERRUPT_GIEH_ENABLE();
        INTERRUPT_GIEL_ENABLE();
        ADC_SET_LowPriority();
    }    
#else
    INTERRUPT_GIE_ENABLE();
    INTERRUPT_PEIE_ENABLE();
#endif
    ADC_InterruptHandler = Adc_->ADC_INTERRUPT;    
    ADC_ENABLE();
}
#endif

#if INTERRUPT_FEATURE_ENABLE==ADC_INTERRUPT_FEATURE_ENABLE   
void ADC_ISR(void){
    ADC_CLEAR_FLAG();
    if(ADC_InterruptHandler){
        ADC_InterruptHandler();
    }
    else{
        //Nothing
    }
}
#endif