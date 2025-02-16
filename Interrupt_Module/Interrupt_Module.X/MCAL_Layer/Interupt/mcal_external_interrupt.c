/* 
 * File:   mcal_external_interrupt.c
 * Author: Ahmed El-Kholy
 *
 * Created on September 17, 2023, 12:50 PM
 */

#include "mcal_external_interrupt.h"

/*----Handlers-----*/

/*INTX Pointers Callback Functions*/
static void (*INT0_InterruptHandler)(void)= NULL;
static void (*INT1_InterruptHandler)(void)= NULL;
static void (*INT2_InterruptHandler)(void)= NULL;

/*RBX Pointers Callback Functions*/
static InterruptHandler RB4_InterruptHandler_HIGH = NULL;
static InterruptHandler RB4_InterruptHandler_LOW = NULL;
static InterruptHandler RB5_InterruptHandler_HIGH = NULL;
static InterruptHandler RB5_InterruptHandler_LOW = NULL;
static InterruptHandler RB6_InterruptHandler_HIGH = NULL;
static InterruptHandler RB6_InterruptHandler_LOW = NULL;
static InterruptHandler RB7_InterruptHandler_HIGH = NULL;
static InterruptHandler RB7_InterruptHandler_LOW = NULL;


/*------------------------------*/

/*RBX*/

/*------------------------------*/

/*Helpers Functions Declaration*/

/*INTX*/
static Std_ReturnType EXT_INTX_Enable(Ext_Interrupt_INTX_t *INT_X);
static Std_ReturnType EXT_INTX_Disable_Helper(Ext_Interrupt_INTX_t *INT_X);
static Std_ReturnType EXT_INTX_Clear_Flag(Ext_Interrupt_INTX_t *INT_X);
static Std_ReturnType EXT_INTX_Edge_Set(Ext_Interrupt_INTX_t *INT_X);
static Std_ReturnType EXT_INTX_Prioity_Set(Ext_Interrupt_INTX_t *INT_X);
static Std_ReturnType EXT_INTX_Pin_Initialize(Ext_Interrupt_INTX_t *INT_X);
static Std_ReturnType EXT_INTX_Function_Initialize(Ext_Interrupt_INTX_t *INT_X);

static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void));
static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void));



/*RBX*/
static Std_ReturnType EXT_RBX_Enable(Ext_Interrupt_RBX_t *RB_X);
static Std_ReturnType EXT_RBX_Disble_Helper(Ext_Interrupt_RBX_t *RB_X);
static Std_ReturnType EXT_RBX_Pin_Initialize(Ext_Interrupt_RBX_t *RB_X);
static Std_ReturnType EXT_RBX_Prioity_Set(Ext_Interrupt_RBX_t *RB_X);
static Std_ReturnType EXT_RBX_Clear_Flag(Ext_Interrupt_RBX_t *RB_X);
static Std_ReturnType EXT_RBX_Function_Initialize(Ext_Interrupt_RBX_t *RB_X);

static Std_ReturnType RB4_SetInterruptHandler(void (*InterruptHandler_High)(void), void (*InterruptHandler_Low)(void));
static Std_ReturnType RB5_SetInterruptHandler(void (*InterruptHandler_High)(void), void (*InterruptHandler_Low)(void));
static Std_ReturnType RB6_SetInterruptHandler(void (*InterruptHandler_High)(void), void (*InterruptHandler_Low)(void));
static Std_ReturnType RB7_SetInterruptHandler(void (*InterruptHandler_High)(void), void (*InterruptHandler_Low)(void));

/*------------------------------------------------------------------------*/


/*-------------------------------------INTX--------------------------------------------*/

/*INTX Main FUNCTIONS*/
Std_ReturnType EXT_INTX_Intialize(Ext_Interrupt_INTX_t *INT_X){
    
    Std_ReturnType ret = E_OK;
    
    if(INT_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        /*Disable*/
        ret = EXT_INTX_Disable_Helper(INT_X);
        /*Clear Flag*/
        ret = EXT_INTX_Clear_Flag(INT_X);
        /*Edge Initialize*/
        ret = EXT_INTX_Edge_Set(INT_X);
        /*Pin Initialize*/
        ret = EXT_INTX_Pin_Initialize(INT_X);
        /*PRIORITY INITIALIZE*/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        ret = EXT_INTX_Prioity_Set(INT_X);
#endif        
        /*Interrupt Function Initialize*/
        ret = EXT_INTX_Function_Initialize(INT_X);
        /*Enable Interrupt*/
        ret = EXT_INTX_Enable(INT_X);
        
    }
    return ret;
}

Std_ReturnType EXT_INTX_Disable(Ext_Interrupt_INTX_t *INT_X){
    
    Std_ReturnType ret = E_OK;
    
    if(INT_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = EXT_INTX_Disable_Helper(INT_X);
    }
    return ret;
}

/*------------------------------------------------------------------------*/

/*INTX Interrupts Functions*/

void INT0_ISR(void){
    EXT_INT0_Clear_Flag();
    if(INT0_InterruptHandler){
        INT0_InterruptHandler();
    }
    else{
        //Nothing
    }
}

void INT1_ISR(void){
    EXT_INT1_Clear_Flag();
    if(INT1_InterruptHandler){
        INT1_InterruptHandler();
    }
    else{
        //Nothing
    }
}

void INT2_ISR(void){
    EXT_INT2_Clear_Flag();
    if(INT2_InterruptHandler){
        INT2_InterruptHandler();
    }
    else{
        //Nothing
    }
}



/*------------------------------------------------------------------------*/

/*INTX Helpers Functions Implementation*/

/*INTX*/
static Std_ReturnType EXT_INTX_Enable(Ext_Interrupt_INTX_t *INT_X){
    
    Std_ReturnType ret = E_OK;
    
    if(INT_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(INT_X->INTX_SRC){
            case INTERRUPT_EXTERNAL_INT0: 
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE    
                INTERRUPT_IPEN_ENABLE();
                INTERRUPT_GIEH_ENABLE();    
                
#else
                INTERRUPT_GIE_ENABLE();
                INTERRUPT_PEIE_ENABLE();
#endif                
                
                EXT_INT0_Enable();
                break;
            case INTERRUPT_EXTERNAL_INT1: 
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE 
                
                INTERRUPT_IPEN_ENABLE();
                
                if (Low_Priority == INT_X->INTX_PRIORITY) {
                    INTERRUPT_GIEH_ENABLE();
                    INTERRUPT_GIEL_ENABLE();
                } else if (High_Priority == INT_X->INTX_PRIORITY) {
                    INTERRUPT_GIEH_ENABLE();
                } else { /*Nothing*/ }
                
                
#else
                INTERRUPT_GIE_ENABLE();
                INTERRUPT_PEIE_ENABLE();
#endif                   
                EXT_INT1_Enable();
                break;
            case INTERRUPT_EXTERNAL_INT2: 
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE    
                
                INTERRUPT_IPEN_ENABLE();
                      
                if (Low_Priority == INT_X->INTX_PRIORITY) {
                    INTERRUPT_GIEH_ENABLE();
                    INTERRUPT_GIEL_ENABLE();
                } else if (High_Priority == INT_X->INTX_PRIORITY) {
                    INTERRUPT_GIEH_ENABLE();
                } else {
                    /*Nothing*/
                }       
                
#else
                INTERRUPT_GIE_ENABLE();
                INTERRUPT_PEIE_ENABLE();
#endif                
                EXT_INT2_Enable();
                break;    
            default :;
        }
        
    }
    return ret;
}

static Std_ReturnType EXT_INTX_Disable_Helper(Ext_Interrupt_INTX_t *INT_X){
    
    Std_ReturnType ret = E_OK;
    
    if(INT_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(INT_X->INTX_SRC){
            case INTERRUPT_EXTERNAL_INT0 : 
                EXT_INT0_Disable();
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                EXT_INT1_Disable();
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                EXT_INT2_Disable();
                break;    
            default :;
        }
    }
    return ret;
}

static Std_ReturnType EXT_INTX_Clear_Flag(Ext_Interrupt_INTX_t *INT_X){
    
    Std_ReturnType ret = E_OK;
    
    if(INT_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(INT_X->INTX_SRC){
            case INTERRUPT_EXTERNAL_INT0 : 
                EXT_INT0_Clear_Flag();
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                EXT_INT1_Clear_Flag();
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                EXT_INT2_Clear_Flag();
                break;    
            default :;
        }
    }
    return ret;
}

static Std_ReturnType EXT_INTX_Edge_Set(Ext_Interrupt_INTX_t *INT_X){
    
    Std_ReturnType ret = E_OK;
    
    if(INT_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(INT_X->INTX_SRC){
            case INTERRUPT_EXTERNAL_INT0 : 
                if(Interrupt_Rising_Edge == INT_X->INTX_EDGE){
                    EXT_INT0_Set_RisingEdge();
                }    
                else if(Interrupt_Falling_Edge == INT_X->INTX_EDGE){
                    EXT_INT0_Set_FallingEdge();
                }
                else {
                    //Nothing
                }
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                if(Interrupt_Rising_Edge == INT_X->INTX_EDGE){
                    EXT_INT1_Set_RisingEdge();
                }    
                else if(Interrupt_Falling_Edge == INT_X->INTX_EDGE){
                    EXT_INT1_Set_FallingEdge();
                }
                else {
                    //Nothing
                }
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                if(Interrupt_Rising_Edge == INT_X->INTX_EDGE){
                    EXT_INT2_Set_RisingEdge();
                }    
                else if(Interrupt_Falling_Edge == INT_X->INTX_EDGE){
                    EXT_INT2_Set_FallingEdge();
                }
                else {
                    //Nothing
                }
                break;    
            default :;
        }    
    return ret;
    }
}

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE    

static Std_ReturnType EXT_INTX_Prioity_Set(Ext_Interrupt_INTX_t *INT_X){
    
    Std_ReturnType ret = E_OK;
    
    if(INT_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(INT_X->INTX_SRC){
            case INTERRUPT_EXTERNAL_INT1 : 
                if(Low_Priority == INT_X->INTX_PRIORITY){
                    EXT_INT1_Priority_LOW();
                }    
                else if(High_Priority == INT_X->INTX_PRIORITY){
                    EXT_INT1_Priority_HIGH();
                }
                else {
                    //Nothing
                }
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                if(Low_Priority == INT_X->INTX_PRIORITY){
                    EXT_INT2_Priority_LOW();   
                }    
                else if(High_Priority == INT_X->INTX_PRIORITY){
                    EXT_INT2_Priority_HIGH();
                }
                else {
                    //Nothing
                }
                break;    
            default :;
        }
    }
    return ret;
}

#endif

static Std_ReturnType EXT_INTX_Pin_Initialize(Ext_Interrupt_INTX_t *INT_X){
    
    Std_ReturnType ret = E_OK;
    
    if(INT_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_intialize(&(INT_X->INTX_PIN));
    }
    return ret;
}

static Std_ReturnType EXT_INTX_Function_Initialize(Ext_Interrupt_INTX_t *INT_X){
     
    Std_ReturnType ret = E_OK;
    
    if(INT_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(INT_X->INTX_SRC){
            case INTERRUPT_EXTERNAL_INT0 : 
                ret = INT0_SetInterruptHandler(INT_X->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT1 : 
                ret = INT1_SetInterruptHandler(INT_X->EXT_InterruptHandler);
                break;
            case INTERRUPT_EXTERNAL_INT2 : 
                ret = INT2_SetInterruptHandler(INT_X->EXT_InterruptHandler);
                break;    
            default :;
        }    
    }
    return ret;
}


static Std_ReturnType INT0_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for INT0 External Interrupt : Application ISR */
        INT0_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;
}

static Std_ReturnType INT1_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for INT1 External Interrupt : Application ISR */
        INT1_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;
}

static Std_ReturnType INT2_SetInterruptHandler(void (*InterruptHandler)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if(NULL == InterruptHandler){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for INT2 External Interrupt : Application ISR */
        INT2_InterruptHandler = InterruptHandler;
        ret = E_OK;
    }
    return ret;
}

    /*------------------------------------------------------------------------*/


/*-------------------------------------RBX--------------------------------------------*/

/*RBX Main FUNCTIONS*/
Std_ReturnType EXT_RBX_Intialize(Ext_Interrupt_RBX_t *RB_X){
    
    Std_ReturnType ret = E_OK;
    
    if(RB_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        /*Disable*/
        ret = EXT_RBX_Disble_Helper(RB_X);
        /*Clear Flag*/
        ret = EXT_RBX_Clear_Flag(RB_X);
        /*Pin Initialize*/
        ret = EXT_RBX_Pin_Initialize(RB_X);
        /*PRIORITY INITIALIZE*/
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
        ret = EXT_RBX_Prioity_Set(RB_X);
#endif        
        /*Interrupt Function Initialize*/
        ret = EXT_RBX_Function_Initialize(RB_X);
        /*Enable Interrupt*/
        ret = EXT_RBX_Enable(RB_X);
    }
    return ret;
}

Std_ReturnType EXT_RBX_Disable(Ext_Interrupt_RBX_t *RB_X){
    
    Std_ReturnType ret = E_OK;
    
    if(RB_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = EXT_RBX_Enable(RB_X);
    }
    return ret;
}

/*------------------------------------------------------------------------*/

/*INTX Interrupts Functions*/

void RB4_ISR(uint8 FUNC_DETECTION){
    EXT_RB_Clear_Flag();
    switch(FUNC_DETECTION){
        case 0:
            if(RB4_InterruptHandler_HIGH){
                RB4_InterruptHandler_HIGH();
            }
            else{
                //Nothing
            }
            break;
        case 1:
            if(RB4_InterruptHandler_LOW){
                RB4_InterruptHandler_LOW();
            }
            else{
                //Nothing
            }
            break;         
        default:;
    }
}

void RB5_ISR(uint8 FUNC_DETECTION){
    EXT_RB_Clear_Flag();
    switch(FUNC_DETECTION){
        case 0:
            if(RB5_InterruptHandler_HIGH){
                RB5_InterruptHandler_HIGH();
            }
            else{
                //Nothing
            }
            break;
        case 1:
            if(RB5_InterruptHandler_LOW){
                RB5_InterruptHandler_LOW();
            }
            else{
                //Nothing
            }
            break;         
        default:;
    }
}

void RB6_ISR(uint8 FUNC_DETECTION){
    EXT_RB_Clear_Flag();
    switch(FUNC_DETECTION){
        case 0:
            if(RB6_InterruptHandler_HIGH){
                RB6_InterruptHandler_HIGH();
            }
            else{
                //Nothing
            }
            break;
        case 1:
            if(RB6_InterruptHandler_LOW){
                RB6_InterruptHandler_LOW();
            }
            else{
                //Nothing
            }
            break;         
        default:;
    }
}

void RB7_ISR(uint8 FUNC_DETECTION){
    EXT_RB_Clear_Flag();
    switch(FUNC_DETECTION){
        case 0:
            if(RB7_InterruptHandler_HIGH){
                RB7_InterruptHandler_HIGH();
            }
            else{
                //Nothing
            }
            break;
        case 1:
            if(RB7_InterruptHandler_LOW){
                RB7_InterruptHandler_LOW();
            }
            else{
                //Nothing
            }
            break;         
        default:;
    }
}

/*------------------------------------------------------------------------*/

/*RBX Helpers Functions Implementation*/
static Std_ReturnType EXT_RBX_Enable(Ext_Interrupt_RBX_t *RB_X){
    
    Std_ReturnType ret = E_OK;
    
    if(RB_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        
#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE 
                
        INTERRUPT_IPEN_ENABLE();
                
        if(High_Priority == RB_X->INTX_PRIORITY) {
            INTERRUPT_GIEH_ENABLE();
        } 
        else if (Low_Priority == RB_X->INTX_PRIORITY){
            INTERRUPT_GIEH_ENABLE();
            INTERRUPT_GIEL_ENABLE();
        } 
            
        else { /*Nothing*/ }
                
                
#else
                INTERRUPT_GIE_ENABLE();
                INTERRUPT_PEIE_ENABLE();
#endif           
                EXT_RB_Enable();
    }
    return ret;
}

static Std_ReturnType EXT_RBX_Disble_Helper(Ext_Interrupt_RBX_t *RB_X){
    
    Std_ReturnType ret = E_OK;
    
    if(RB_X == NULL){
        ret = E_NOT_OK;
    }
    
    else{
        EXT_RB_Disable();
    }
    return ret;
}

static Std_ReturnType EXT_RBX_Pin_Initialize(Ext_Interrupt_RBX_t *RB_X){
    
    Std_ReturnType ret = E_OK;
    
    if(RB_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_direction_intialize(&(RB_X->INTX_PIN));
    }
    return ret;
}

#if INTERRUPT_PRIORITY_LEVELS_ENABLE == INTERRUPT_FEATURE_ENABLE
static Std_ReturnType EXT_RBX_Prioity_Set(Ext_Interrupt_RBX_t *RB_X){
    
    Std_ReturnType ret = E_OK;
    
    if(RB_X == NULL){
        ret = E_NOT_OK;
    }
    else{
         if(High_Priority == RB_X->INTX_PRIORITY){
            EXT_RB_Priority_HIGH();
        }
        else if(Low_Priority == RB_X->INTX_PRIORITY){
            EXT_RB_Priority_LOW();
        }
        else{ /* Nothing */ }
    }
    return ret;
}
#endif

static Std_ReturnType EXT_RBX_Clear_Flag(Ext_Interrupt_RBX_t *RB_X){
    
    Std_ReturnType ret = E_OK;
    
    if(RB_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        EXT_RB_Clear_Flag();
    }
    return ret;
}

static Std_ReturnType EXT_RBX_Function_Initialize(Ext_Interrupt_RBX_t *RB_X){
 
    Std_ReturnType ret = E_OK;
    
    if(RB_X == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(RB_X->INTX_PIN.PIN){
            case GPIO_PIN4: 
                RB4_SetInterruptHandler(RB_X->EXT_InterruptHandler_HIGH , RB_X->EXT_InterruptHandler_LOW);
                break;
            case GPIO_PIN5: 
                RB5_SetInterruptHandler(RB_X->EXT_InterruptHandler_HIGH , RB_X->EXT_InterruptHandler_LOW);
                break;
            case GPIO_PIN6: 
                RB6_SetInterruptHandler(RB_X->EXT_InterruptHandler_HIGH , RB_X->EXT_InterruptHandler_LOW);
                break;
            case GPIO_PIN7: 
                RB7_SetInterruptHandler(RB_X->EXT_InterruptHandler_HIGH , RB_X->EXT_InterruptHandler_LOW);
                break;
        }
    }
    return ret;
}


static Std_ReturnType RB4_SetInterruptHandler(void (*InterruptHandler_High)(void), void (*InterruptHandler_Low)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == InterruptHandler_High) || (NULL == InterruptHandler_Low)){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for RB4 External Interrupt : Application ISR */
        RB4_InterruptHandler_HIGH = InterruptHandler_High;
        RB4_InterruptHandler_LOW = InterruptHandler_Low;
        ret = E_OK;
    }
    return ret;
}

static Std_ReturnType RB5_SetInterruptHandler(void (*InterruptHandler_High)(void), void (*InterruptHandler_Low)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == InterruptHandler_High) || (NULL == InterruptHandler_Low)){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for RB5 External Interrupt : Application ISR */
        RB5_InterruptHandler_HIGH = InterruptHandler_High;
        RB5_InterruptHandler_LOW = InterruptHandler_Low;
        ret = E_OK;
    }
    return ret;
    
}

static Std_ReturnType RB6_SetInterruptHandler(void (*InterruptHandler_High)(void), void (*InterruptHandler_Low)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == InterruptHandler_High) || (NULL == InterruptHandler_Low)){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for RB6 External Interrupt : Application ISR */
        RB6_InterruptHandler_HIGH = InterruptHandler_High;
        RB6_InterruptHandler_LOW = InterruptHandler_Low;
        ret = E_OK;
    }
    return ret;
    
}

static Std_ReturnType RB7_SetInterruptHandler(void (*InterruptHandler_High)(void), void (*InterruptHandler_Low)(void)){
    Std_ReturnType ret = E_NOT_OK;
    if((NULL == InterruptHandler_High) || (NULL == InterruptHandler_Low)){
        ret = E_NOT_OK;
    }
    else{
        /* Set Default Interrupt Handler for RB7 External Interrupt : Application ISR */
        RB7_InterruptHandler_HIGH = InterruptHandler_High;
        RB7_InterruptHandler_LOW = InterruptHandler_Low;
        ret = E_OK;
    }
    return ret;
    
}
/*------------------------------------------------------------------------*/

