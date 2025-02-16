/* 
 * File:   KeyPad.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 7, 2023, 12:21 PM
 */

#include "KeyPad.h"

static Std_ReturnType turnoff_all_rows(KeyPad_t *key_pad);

static const uint8 btn_values[KEYPAD_ROWS_NUM][KEYPAD_COLUMNS_NUM] = {
                                                                        {'7', '8', '9', '/'},
                                                                        {'4', '5', '6', '*'},
                                                                        {'1', '2', '3', '-'},
                                                                        {'#', '0', '=', '+'}
                                                                     };

Std_ReturnType keypad_initialize(KeyPad_t *key_pad){
    
Std_ReturnType ret = E_OK;

    uint8 rows_counter = 0;
    uint8 columns_counter = 0;
    
    if(key_pad == NULL){
        ret = E_NOT_OK;
    }
    else{
        
        for(rows_counter=0; rows_counter<KEYPAD_ROWS_NUM; rows_counter++){
            ret = gpio_pin_intialize(&(key_pad->rows[rows_counter]));
        }
        
        for(columns_counter=0; columns_counter<KEYPAD_COLUMNS_NUM; columns_counter++){
            ret = gpio_pin_direction_intialize(&(key_pad->columns[columns_counter]));
        }
          
    }
    return ret;
}    

Std_ReturnType keypad_read_value(KeyPad_t *key_pad , uint8 *value){
Std_ReturnType ret = E_OK;
    
    uint8 rows_counter = 0;
    uint8 columns_counter = 0;
    uint8 temp_value = 0;
    
    if(key_pad == NULL){
        ret = E_NOT_OK;
    }
    else{
        
        for(rows_counter=0; rows_counter<KEYPAD_ROWS_NUM; rows_counter++){
            
            ret = turnoff_all_rows(key_pad);
            
            ret = gpio_pin_write_logic(&(key_pad->rows[rows_counter]) , GPIO_HIGH);
            __delay_ms(10);
            
            for(columns_counter=0; columns_counter<KEYPAD_COLUMNS_NUM; columns_counter++){
                ret = gpio_pin_read_logic(&(key_pad->columns[columns_counter]) , &temp_value);
            
                if (GPIO_HIGH == temp_value){
                    *value = btn_values[rows_counter][columns_counter];
                    
                }
                else{
                    //nothing
                }
            }
            
        }
        
        
    }
    return ret;
}    

static Std_ReturnType turnoff_all_rows(KeyPad_t *key_pad){
    
    Std_ReturnType ret = E_OK;

    uint8 rows_counter = 0;
    
    if(key_pad == NULL){
        ret = E_NOT_OK;
    }
    else{
        
        for(rows_counter=0; rows_counter<KEYPAD_ROWS_NUM; rows_counter++){
            ret = gpio_pin_write_logic(&(key_pad->rows[rows_counter]) , GPIO_LOW);
        }
          
    }
    return ret;
    
}