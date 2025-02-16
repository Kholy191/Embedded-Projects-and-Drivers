/* 
 * File:   mcal_std_types.h
 * Author: Ahmed El-Kholy
 *
 * Created on August 11, 2023, 8:58 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H


/* Section : Includes */

#include "compiler.h"
#include "std_libraries.h"

/* Section: Macro Declarations */

#define std_HIGH       0x01
#define std_LOW        0x00

#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDLE       0x00

#define E_OK     (Std_ReturnType)0x01
#define E_NOT_OK     (Std_ReturnType)0x01

#define _XTAL_FREQ 8000000U

/* Section: Macro Functions Declarations */

/* Section: Data Type Declarations */
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;
typedef signed char    sint8;
typedef signed short   sint16;
typedef signed long    sint32;

typedef  uint8 Std_ReturnType;

/* Section: Function Declarations */

#endif	/* MCAL_STD_TYPES_H */

