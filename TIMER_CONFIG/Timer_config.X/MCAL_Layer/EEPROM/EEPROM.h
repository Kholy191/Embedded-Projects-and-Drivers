/* 
 * File:   EEPROM.h
 * Author: Ahmed El-Kholy
 *
 * Created on September 20, 2023, 1:10 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H


/* --------------------------------Section : Includes-------------------------------- */
#include "../Interupt/mcal_interrupt_config.h"
#include "pic18f4620.h"
#include "../mcal_std_types.h"
/* --------------------------------Section: Macro Declarations-------------------------------- */
/*Flash Program or Data EEPROM Memory Select bit (EEPGD)*/
#define Access_EEPROM_Memory                0
#define Access_Flash_Program_Memory         1
/*Flash Program/Data EEPROM or Configuration Select bit (CFGS)*/
#define Access_data_EEPROM_memory           0
#define Access_Configuration_registers      1
/*Flash Program/Data EEPROM Write Enable bit(WREN)*/
#define INHIBTS_WRITE_CYCLES_FLASH_EEPROM   0
#define ALLOW_WRITE_CYCLES_FLASH_EEPROM     1
/*Write Control bit (WR)*/
#define INITIATE_DATA_EEPROM_WRITE_ERASE    1
/* Read Control (RD) */
#define INITIATE_DATA_EEPROM_READ           1
/* --------------------------------Section: Macro Functions Declarations-------------------------------- */
#define INTERRUPT_GIE_DISABLE()  (INTCONbits.GIE = 0)
/* --------------------------------Section: Data Type Declarations-------------------------------- */

/* --------------------------------Section: Function Declarations-------------------------------- */
Std_ReturnType EEPROM_WRITE_DATA(uint16 address , uint8 data_1);
Std_ReturnType EEPROM_READ_DATA(uint16 address , uint8 *data);
#endif	/* EEPROM_H */

