/* 
 * File:   EEPROM.c
 * Author: Ahmed El-Kholy
 *
 * Created on September 20, 2023, 1:10 PM
 */

#include "EEPROM.h"
/**
 * 
 * @param address
 * @param data
 * @return 
 */
Std_ReturnType EEPROM_WRITE_DATA(uint16 address , uint8 data){
    Std_ReturnType ret = E_OK;
    uint8 Interrupt_status = 0;
    /* Read the Interrupt Status "Enabled or Disabled" */
    Interrupt_status = INTCONbits.GIE;
    /* Update the Address Registers */
    EEADR = (uint8) (address & 0xFF);
    EEADRH = (uint8) ((address >> 8) & 0x03);
    /* Update the Data Register */
    EEDATA = data;
    /* Select Access data EEPROM memory */
    EECON1bits.EEPGD = Access_EEPROM_Memory;
    EECON1bits.CFGS = Access_data_EEPROM_memory;
    /* Allows write cycles to Flash program/data EEPROM */
    EECON1bits.WREN = ALLOW_WRITE_CYCLES_FLASH_EEPROM;
    /* Disable all interrupts "General Interrupt" */
    INTERRUPT_GIE_DISABLE();
    /* Write the required sequence : 0x55 -> 0xAA */
    EECON2 = 0x55;
    EECON2 = 0xAA;
    /* Initiates a data EEPROM erase/write cycle */
    EECON1bits.WR = INITIATE_DATA_EEPROM_WRITE_ERASE;
    /* Wait for write to complete */
    while(EECON1bits.WR);
    /* Inhibits write cycles to Flash program/data EEPROM */
    EECON1bits.WREN = INHIBTS_WRITE_CYCLES_FLASH_EEPROM;
    /* Restore the Interrupt Status "Enabled or Disabled" */
    INTCONbits.GIE = Interrupt_status;
    return ret;
}


Std_ReturnType EEPROM_READ_DATA(uint16 address , uint8 *data){
    Std_ReturnType ret = E_OK;
    uint8 Interrupt_status = 0;
    if(NULL == data){
        ret = E_NOT_OK;
    }
    else{
        /* Read the Interrupt Status "Enabled or Disabled" */
        Interrupt_status = INTCONbits.GIE;
        /* Update the Address Registers */
        EEADR = (uint8) (address & 0xFF);
        EEADRH = (uint8) ((address >> 8) & 0x03);
        /* Select Access data EEPROM memory */
        EECON1bits.EEPGD = Access_EEPROM_Memory;
        EECON1bits.CFGS = Access_data_EEPROM_memory;
        /* Disable all interrupts "General Interrupt" */
        INTERRUPT_GIE_DISABLE();
        /* Initiates a data EEPROM read cycle */
        EECON1bits.RD = INITIATE_DATA_EEPROM_READ;
        /* Wait 2 instruction cycles*/
        NOP(); /* NOPs may be required for latency at high frequencies */
        NOP(); /* NOPs may be required for latency at high frequencies */
        /* Return data */
        *data = EEDATA;
        /* Restore the Interrupt Status "Enabled or Disabled" */
        INTCONbits.GIE = Interrupt_status;
    }
    return ret;
}
