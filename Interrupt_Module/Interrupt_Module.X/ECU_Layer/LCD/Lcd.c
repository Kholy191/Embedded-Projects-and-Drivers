/* 
 * File:   Lcd.c
 * Author: Ahmed El-Kholy
 *
 * Created on September 7, 2023, 4:34 PM
 */

#include "Lcd.h"

static Std_ReturnType enable_pin_8bits(const LCD_8bits_t *lcd);
static Std_ReturnType enable_pin_4bits(const LCD_4bits_t *lcd);
static Std_ReturnType send_4bits(const LCD_4bits_t *lcd , uint8 command);
static Std_ReturnType lcd_4bits_set_cursor(const LCD_4bits_t *lcd , uint8 ROW , uint8 COLUMN);
static Std_ReturnType lcd_8bits_set_cursor(const LCD_8bits_t *lcd , uint8 ROW , uint8 COLUMN);

               /*4 Bits LCD Functions*/

Std_ReturnType lcd_4bits_initialze(const LCD_4bits_t *lcd){
    
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_intialize(&(lcd->RS_REG));
        ret = gpio_pin_intialize(&(lcd->EN_BIT));
        for(counter = 0; counter<LCD_4_BITS; counter++){
            ret = gpio_pin_intialize(&(lcd->DATA_BITS[counter]));
        }
        __delay_ms(20);
        ret = lcd_4bits_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_4bits_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_4bits_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
 
        ret = lcd_4bits_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bits_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bits_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_4bits_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_4bits_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bits_send_command(lcd, 0x80);

    }
    return ret;
}    

Std_ReturnType lcd_4bits_send_command(const LCD_4bits_t *lcd , uint8 command){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->RS_REG), GPIO_LOW);
        ret = send_4bits(lcd , command>>4);
        ret = enable_pin_4bits(lcd);
        ret = send_4bits(lcd , command);
        ret = enable_pin_4bits(lcd);
    }
    return ret;
}  

Std_ReturnType lcd_4bits_send_char(const LCD_4bits_t *lcd , uint8 data){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->RS_REG), GPIO_HIGH);
        ret = send_4bits(lcd , data >> 4 );
        ret = enable_pin_4bits(lcd);
        ret = send_4bits(lcd , data);
        ret = enable_pin_4bits(lcd);
    }
    return ret;
}    

Std_ReturnType lcd_4bits_send_char_pos(const LCD_4bits_t *lcd , uint8 data , uint8 ROW , uint8 COLUMN){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bits_set_cursor(lcd , ROW , COLUMN);
        ret = lcd_4bits_send_char(lcd , data);
    }
    return ret;
}    

Std_ReturnType lcd_4bits_send_string(const LCD_4bits_t *lcd , uint8 *data){
    
    Std_ReturnType ret = E_OK;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        while(*data){
            ret = lcd_4bits_send_char(lcd , *data++);
        }
    }
    return ret;
}    

Std_ReturnType lcd_4bits_send_string_pos(const LCD_4bits_t *lcd , uint8 *data , uint8 ROW , uint8 COLUMN){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bits_set_cursor(lcd , ROW , COLUMN);
        ret = lcd_4bits_send_string(lcd , data);
    }
    return ret;
}  

Std_ReturnType lcd_4bits_send_custom_char(const LCD_4bits_t *lcd, uint8 ROW, uint8 COLUMN, 
                                         const uint8 _chr[], uint8 mem_pos){
    
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_4bits_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*8)));
        for(counter = 0; counter<7; counter++){
            ret = lcd_4bits_send_char(lcd , _chr[counter]);       
        }
        ret = lcd_4bits_send_char_pos(lcd, mem_pos, ROW, COLUMN);
    }
    return ret;
}    

static Std_ReturnType lcd_4bits_set_cursor(const LCD_4bits_t *lcd , uint8 ROW , uint8 COLUMN){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(ROW){
                case ROW1: lcd_4bits_send_command(lcd , (0x80 + COLUMN)); break;
                case ROW2: lcd_4bits_send_command(lcd , (0xc0 + COLUMN)); break;    
                case ROW3: lcd_4bits_send_command(lcd , (0x94 + COLUMN)); break;
                case ROW4: lcd_4bits_send_command(lcd , (0xd4 + COLUMN)); break;    
                default:;  
        };
    }
    return ret; 
}

static Std_ReturnType enable_pin_4bits(const LCD_4bits_t *lcd){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->EN_BIT) ,GPIO_HIGH);
        __delay_ms(5);
        ret = gpio_pin_write_logic(&(lcd->EN_BIT) ,GPIO_LOW);   
    }
    return ret;
}

static Std_ReturnType send_4bits(const LCD_4bits_t *lcd , uint8 command){
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->DATA_BITS[0]) , (command >> 0) & (uint8)0x01);
        ret = gpio_pin_write_logic(&(lcd->DATA_BITS[1]) , (command >> 1) & (uint8)0x01);
        ret = gpio_pin_write_logic(&(lcd->DATA_BITS[2]) , (command >> 2) & (uint8)0x01);
        ret = gpio_pin_write_logic(&(lcd->DATA_BITS[3]) , (command >> 3) & (uint8)0x01);
        
    }
    return ret;
}


               /*8 Bits LCD Functions*/

Std_ReturnType lcd_8bits_initialze(const LCD_8bits_t *lcd){
    
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;   
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_intialize(&(lcd->RS_REG));
        ret = gpio_pin_intialize(&(lcd->EN_BIT));
        for(counter = 0; counter<LCD_8_BITS; counter++){
            ret = gpio_pin_intialize(&(lcd->DATA_BITS[counter]));
        }
        __delay_ms(20);
        ret = lcd_8bits_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_8bits_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_8bits_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
 
        ret = lcd_8bits_send_command(lcd, _LCD_CLEAR);
        ret = lcd_8bits_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_8bits_send_command(lcd, _LCD_ENTRY_MODE_INC_SHIFT_OFF);
        ret = lcd_8bits_send_command(lcd, _LCD_DISPLAY_ON_UNDERLINE_OFF_CURSOR_OFF);
        ret = lcd_8bits_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bits_send_command(lcd, 0x80);
    }
    return ret;
}    

Std_ReturnType lcd_8bits_send_command(const LCD_8bits_t *lcd , uint8 command){
    
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->RS_REG), GPIO_LOW);
        for(counter=0; counter<8; counter++){
            ret = gpio_pin_write_logic(&(lcd->DATA_BITS[counter]) , (command >> counter) & (uint8)0x01);   
        }
        ret = enable_pin_8bits(lcd);
    }
    return ret;
}    

Std_ReturnType lcd_8bits_send_char(const LCD_8bits_t *lcd , uint8 data){
    
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->RS_REG), GPIO_HIGH);
        for(counter=0; counter<8; counter++){
            ret = gpio_pin_write_logic(&(lcd->DATA_BITS[counter]) , (data >> counter) & (uint8)0x01);   
        }
        ret = enable_pin_8bits(lcd);
    }
    return ret;
}    

Std_ReturnType lcd_8bits_send_char_pos(const LCD_8bits_t *lcd , uint8 data , uint8 ROW , uint8 COLUMN){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bits_set_cursor(lcd , ROW , COLUMN);
        ret = lcd_8bits_send_char(lcd , data);
    }
    return ret;
}    

Std_ReturnType lcd_8bits_send_string(const LCD_8bits_t *lcd , uint8 *data){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        while(*data){
            ret = lcd_8bits_send_char(lcd , *data++);
        }
    }
    return ret;
}    

Std_ReturnType lcd_8bits_send_string_pos(const LCD_8bits_t *lcd , uint8 *data , uint8 ROW , uint8 COLUMN){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bits_set_cursor(lcd , ROW , COLUMN);
        ret = lcd_8bits_send_string(lcd , data);
    }
    return ret;
}    

Std_ReturnType lcd_8bits_send_custom_char(const LCD_8bits_t *lcd, uint8 ROW, uint8 COLUMN, 
                                         const uint8 _chr[], uint8 mem_pos){
    
    Std_ReturnType ret = E_OK;
    uint8 counter = 0;    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = lcd_8bits_send_command(lcd, (_LCD_CGRAM_START+(mem_pos*8)));
        for(counter = 0; counter<7; counter++){
            ret = lcd_8bits_send_char(lcd , _chr[counter]);       
        }
        ret = lcd_8bits_send_char_pos(lcd, mem_pos, ROW, COLUMN);
    }
    return ret;
}    

static Std_ReturnType lcd_8bits_set_cursor(const LCD_8bits_t *lcd , uint8 ROW , uint8 COLUMN){
      
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        switch(ROW){
                case ROW1: lcd_8bits_send_command(lcd , (0x80 + COLUMN)); break;
                case ROW2: lcd_8bits_send_command(lcd , (0xc0 + COLUMN)); break;    
                case ROW3: lcd_8bits_send_command(lcd , (0x94 + COLUMN)); break;
                case ROW4: lcd_8bits_send_command(lcd , (0xd4 + COLUMN)); break;    
                default:;  
        };
    }
    return ret; 
}

static Std_ReturnType enable_pin_8bits(const LCD_8bits_t *lcd){
    
    Std_ReturnType ret = E_OK;
    
    if(lcd == NULL){
        ret = E_NOT_OK;
    }
    else{
        ret = gpio_pin_write_logic(&(lcd->EN_BIT) ,GPIO_HIGH);
        __delay_ms(5);
        ret = gpio_pin_write_logic(&(lcd->EN_BIT) ,GPIO_LOW);   
    }
    return ret;
}

                    /*integer to string functions*/

Std_ReturnType number_8bit_to_string(uint8 value , uint8 *str){
    
    Std_ReturnType ret = E_OK;
    memset(( unsigned char *)str, '\0', 4);
    sprintf(str, "%d", value);
    return ret;
}    

Std_ReturnType number_16bit_to_string(uint16 value , uint8 *str){
    
    Std_ReturnType ret = E_OK;
    memset((char *)str, '\0', 5);
    sprintf(str, "%i", value);
    return ret;
}    

Std_ReturnType number_32bit_to_string(uint32 value , uint8 *str){
    
    Std_ReturnType ret = E_OK;
    memset((char *)str, '\0', 11);
    sprintf(str, "%i", value);
    return ret;
}    











