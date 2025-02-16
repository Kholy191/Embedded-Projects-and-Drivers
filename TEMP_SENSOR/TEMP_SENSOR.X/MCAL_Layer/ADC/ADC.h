/* 
 * File:   ADC.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 24, 2023, 2:54 PM
 */

#ifndef ADC_H
#define	ADC_H

/* --------------------------------Section : Includes-------------------------------- */
#include "ADC_config.h"
#include "pic18f4620.h"
#include "../GPIO/hal_gpio.h"
#include "../Interupt/mcal_internal_interrupt.h"
#include "../mcal_std_types.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */
#define ADC_AN0_ANALOG_FUNCTIONALITY    0x0E
#define ADC_AN1_ANALOG_FUNCTIONALITY    0x0D
#define ADC_AN2_ANALOG_FUNCTIONALITY    0x0C
#define ADC_AN3_ANALOG_FUNCTIONALITY    0x0B
#define ADC_AN4_ANALOG_FUNCTIONALITY    0x0A
#define ADC_AN5_ANALOG_FUNCTIONALITY    0x09
#define ADC_AN6_ANALOG_FUNCTIONALITY    0x08
#define ADC_AN7_ANALOG_FUNCTIONALITY    0x07
#define ADC_AN8_ANALOG_FUNCTIONALITY    0x06
#define ADC_AN9_ANALOG_FUNCTIONALITY    0x05
#define ADC_AN10_ANALOG_FUNCTIONALITY   0x04
#define ADC_AN11_ANALOG_FUNCTIONALITY   0x03
#define ADC_AN12_ANALOG_FUNCTIONALITY   0x02
#define ADC_ALL_ANALOG_FUNCTIONALITY    0x00
#define ADC_ALL_DIGITAL_FUNCTIONALITY   0x0F

#define Voltage_Reference_Externally    1
#define Voltage_Reference_Internally    0

#define ADC_RESULT_RIGHT    0x01U
#define ADC_RESULT_LEFT     0x00U

#define Result_t            uint16

/* --------------------------------Section: Macro Functions Declarations-------------------------------- */
/*Enable and Disable ADC*/
#define ADC_Enable()            (ADCON0bits.ADON = 1)
#define ADC_Disable()           (ADCON0bits.ADON = 0)

/*Start Conversion And Conversion finished detection*/
#define ADC_Start_Conversion()  (ADCON0bits.GO_DONE = 1)
#define ADC_Conversion_Status()  (ADCON0bits.GO_DONE)
/*Select Voltage Reference*/
#define ADC_ENABLE_VOLTAGE_REFERENCE()  do{ADCON1bits.VCFG1 = 1;\
                                           ADCON1bits.VCFG0 = 1;\
                                        }while(0)
#define ADC_DISABLE_VOLTAGE_REFERENCE() do{ADCON1bits.VCFG1 = 0;\
                                           ADCON1bits.VCFG0 = 0;\
                                        }while(0)
/*Result Formart Select*/
#define Right_Result_Format()   (ADCON2bits.ADFM = 1)
#define Left_Result_Format()    (ADCON2bits.ADFM = 0)

/*A/D Acquisition time select bits.*/
#define Acquisition_Time_Select(time_selected)  (ADCON2bits.ACQT = time_selected)

/*A/D clock Select bits.*/
#define Freq_Select(freq_selected)  (ADCON2bits.ADCS = freq_selected)

/*Channel Selecting macro function*/
#define Channel_Selecting(Channel_)   (ADCON0bits.CHS = Channel_)

/*Analog-To-Digital Port Configuration Control*/
#define ADC_Analog_Digital_Port_CONFIG(_CONFIG) (ADCON1bits.PCFG = _CONFIG)

/* --------------------------------Section: Data Type Declarations-------------------------------- */
typedef enum{
    AN0_CHANNEL = 0,
    AN1_CHANNEL,
    AN2_CHANNEL,
    AN3_CHANNEL,        
    AN4_CHANNEL,        
    AN5_CHANNEL,
    AN6_CHANNEL,
    AN7_CHANNEL,        
    AN8_CHANNEL,    
    AN9_CHANNEL,
    AN10_CHANNEL,
    AN11_CHANNEL,        
    AN12_CHANNEL              
}CHANNEL_SELECTED_t;

typedef enum{
    _0_TAD_Acquisition_time = 0,
    _2_TAD_Acquisition_time,
    _4_TAD_Acquisition_time,        
    _6_TAD_Acquisition_time,
    _8_TAD_Acquisition_time,        
    _12_TAD_Acquisition_time,
    _16_TAD_Acquisition_time,
    _20_TAD_Acquisition_time
            
}Acquisition_time_t;

typedef enum{
    ADC_CONVERSION_CLOCK_FOSC_DIV_2 = 0,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    ADC_CONVERSION_CLOCK_FOSC_DIV_FRC,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64
}adc_conversion_clock_t;

typedef struct{
#if INTERRUPT_FEATURE_ENABLE==ADC_INTERRUPT_FEATURE_ENABLE   
    void (*ADC_INTERRUPT)(void);
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
    Interrupt_Priority ADC_Interrupt_Priority;
#endif
#endif    
    adc_conversion_clock_t CLOCK_FREQ;
    Acquisition_time_t ACQU_TIME;
    CHANNEL_SELECTED_t DEFAULT_CHANNEL;
    uint8 VOLTAGE_REFERENCE :1;
    uint8 RESULT_FORMAT :1;
    uint8 ADC_Reserved : 6;
}ADC_t;

/* --------------------------------Section: Function Declarations-------------------------------- */
Std_ReturnType ADC_Initialize(ADC_t *Adc_);
Std_ReturnType ADC_DInitialize(ADC_t *Adc_);
Std_ReturnType ADC_Start_Conversion_Func(ADC_t *Adc_);
Std_ReturnType ADC_Select_Channel(ADC_t *Adc_ , CHANNEL_SELECTED_t channel);
Std_ReturnType ADC_IsConversionDone(ADC_t *Adc_ , uint8 *Isdone_Detect);
Std_ReturnType ADC_GetConversionResult(ADC_t *Adc_ , Result_t *Result);
Std_ReturnType ADC_GetConversion_Blocking(ADC_t *Adc_ , CHANNEL_SELECTED_t channel , Result_t *Result);


Std_ReturnType ADC_StartConversion_Interrupt(ADC_t *Adc_ , CHANNEL_SELECTED_t channel);

#endif	/* ADC_H */

