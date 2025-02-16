/* 
 * File:   Applicaton_1.c
 * Author: Ahmed El-Kholy
 *
 * Created on August 10, 2023, 8:58 AM
 */
#include "application.h"

Std_ReturnType ret = 0;
uint8 str__1[4];
uint8 str__2[4];
uint8 result_1[4];
uint8 operation_l = '\0';
uint8 value_1 = 0;
uint8 value_2 = 0;
uint8 result = 0;
uint8 num =250;
int main() {
    memset((char *)str__1, '\0', 4);
    memset((char *)str__2, '\0', 4);
    ret = lcd_4bits_initialze(&lcd_1);
    ret = keypad_initialize(&keypad_1);
    ret = num_1_read(&lcd_1 , &keypad_1 , str__1 , &operation_l , str__2);
    ret = convert_string_to_numbers(str__1 , &value_1);
    ret = convert_string_to_numbers(str__2 , &value_2);
    ret = detect_operation(&operation_l , value_1 , value_2 , &result);
    num = result;
    ret = print_result(&lcd_1 , result_1 , num);
    while(1){
        
    }
    
    return (EXIT_SUCCESS);
}

Std_ReturnType num_1_read(LCD_4bits_t *lcd, KeyPad_t *keypad, uint8 *str , uint8 *operation , uint8 *str_2){
    Std_ReturnType ret = E_OK;
    uint8 counter_1 = 0;
    uint8 counter_2 = 0;
    uint8 counter_3 = 0;
    uint8 temp_value = 0;
    while(1){
        if(counter_1 > 3){
            ret = lcd_4bits_send_string_pos(lcd , "error" , 3 , 1 );
            return ret;
        }
   
        else{
            ret = keypad_read_value(keypad , &temp_value);
                if(temp_value != 0){
                    
                    if((temp_value == '+') || (temp_value == '*') || (temp_value == '-')){
                        switch(temp_value){
                            case '+': *operation = '+'; break;
                            case '-': *operation = '-'; break;
                            case '*': *operation = '*'; break;
                            default: break;
                        }
                        counter_3++;
                        if(counter_3 == 10){
                            ret = lcd_4bits_send_char(lcd ,temp_value);
                            temp_value = 0;
                            counter_3 = 0;
                            ret = num_2_read(lcd , keypad , str_2);
                            ret = convert_string_to_numbers(str , &value_1);
                            ret = convert_string_to_numbers(str_2 , &value_2);
                            
                            return ret;
                        }
                    }
                    else if((temp_value == '=')){
                        ret = lcd_4bits_send_string_pos(lcd , str , 3 , 1 );
                        return ret;
                    }
                    else{
                        counter_3++;
                        if(counter_3 == 5){
                            ret = lcd_4bits_send_char(lcd ,temp_value);
                            str[counter_1] = temp_value;
                            counter_1++;
                            temp_value = 0;
                            counter_3 = 0;
                            
                        } 
                    }
                                       
                }
            
            }    
        
    }
    
}



Std_ReturnType num_2_read(LCD_4bits_t *lcd, KeyPad_t *keypad, uint8 *str ){
   Std_ReturnType ret = E_OK;
    uint8 counter_1 = 0;
    uint8 counter_2 = 0;
    uint8 counter_3 = 0;
    uint8 temp_value = 0;
    while(1){
        if(counter_1 > 3){
            ret = lcd_4bits_send_string_pos(lcd , "error" , 3 , 1 );
            return ret;
        }
   
        else{
            ret = keypad_read_value(keypad , &temp_value);
                if(temp_value != 0){
                    if((temp_value == '+') || (temp_value == '*') || (temp_value == '-')){
                        counter_3++;
                        if(counter_3 == 10){
                            ret = lcd_4bits_send_string_pos(lcd , "error" , 3 , 1 );
                            temp_value = 0;
                            counter_3 = 0;
                            return ret;
                        } 
                    }
                    else if((temp_value == '=')){
                        return ret;
                    }
                    else{
                        counter_3++;
                        if(counter_3 == 10){
                            ret = lcd_4bits_send_char(lcd ,temp_value);
                            str[counter_1] = temp_value;
                            counter_1++;
                            temp_value = 0;
                            counter_3 = 0;
                            
                        } 
                    }
                                       
                }
            
            }    
        
    }
}

Std_ReturnType convert_string_to_numbers(uint8 *str , uint8 *value){
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    uint8 temp_1 = 0;
    uint8 temp_2 = 0;
    uint8 temp_3 = 0;
    for(counter=0; counter<3; counter++){
        if(0 == str[2]){
            if(0 == str[1]){
                temp_3 = ((str[0] - '0') * 1);
                *value = temp_3;
            }
            else{
                temp_2 = ((str[0] - '0') * 10);
                temp_3 = ((str[1] - '0') * 1);
                *value = (temp_2 + temp_3);
            }
            
        }
        else{
        if(0 == counter){
            temp_1 = ((str[counter] - '0') * 100);
        }
        if(1 == counter){
            temp_2 = ((str[counter] - '0') * 10);
        }
        if(2 == counter){
            temp_3 = ((str[counter] - '0') * 1);
        }
        }
    }
    *value = (temp_1 + temp_2 + temp_3);

    return ret;
}

Std_ReturnType detect_operation(uint8 *operation_2 , uint8 value__1 , uint8 value__2 , uint8 *result__){
    Std_ReturnType ret = E_OK;
    switch(*operation_2){
    case 43: 
        *result__ = (value__1 + value__2);
        break;
    case 42:
        *result__ = (value__1 * value__2);
        break;
    case 45:
        *result__ = (value__1 - value__2);
        break;
    default:
        break;
}
    return ret;

}

Std_ReturnType print_result(LCD_4bits_t *lcd , uint8 *result_1_ , uint8 num){
    Std_ReturnType ret = 0;
    ret = number_8bit_to_string(num , result_1_);
    ret = lcd_4bits_send_string_pos(lcd , result_1_ , 3 ,3);
}
        