 /******************************************************************************
 *
 * Module: Common - Standard Types
 *
 * File Name: Std_Types.h
 *
 * Description:  This header file contains the definitions and macros
 * 				 specified by AUTOSAR for standard types.
 *
 * Author: Mina Atef
 *
 *******************************************************************************/

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*
 * VENDOR ID		2020
 */
#define STD_TYPES_VENDOR_ID								(2020U)

/*
 * Module ID		197
 */
#define STD_TYPES_MODULE_ID								(197U)

/*
 * MODULE VERSION 1.0.0
 */
#define STD_TYPES_SW_MAJOR_VERSION						(1U)
#define STD_TYPES_SW_MINOR_VERSION						(0U)
#define STD_TYPES_SW_PATCH_VERSION						(0U)

/*
 * AUTOSAR RELEASE 4.0.3
 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION				(4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION				(0U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION				(3U)



#include"Compiler.h"

#if((STD_TYPES_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)\
 || (STD_TYPES_AR_RELEASE_MINOR_VERSION != COMPILER_AR_RELEASE_MINOR_VERSION)\
 || (STD_TYPES_AR_RELEASE_PATCH_VERSION != COMPILER_AR_RELEASE_PATCH_VERSION))
#error"The AR Version of Compiler Is not Compatible With AR Version of STD_Types "
#endif

#include"Platform_Types.h"
#if((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION)\
 || (STD_TYPES_AR_RELEASE_MINOR_VERSION != PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION)\
 || (STD_TYPES_AR_RELEASE_PATCH_VERSION != PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION))
#error"The AR Version of Compiler Is not Compatible With AR Version of STD_Types "
#endif


/* This type used as standard API return type */
typedef uint8 Std_ReturnType;



/* Get Version Information API's formal Parameter */
typedef struct
{
uint16 vendorID;
uint16 moduleID;
uint8 sw_major_version;
uint8 sw_minor_version;
uint8 sw_patch_version;
} Std_VersionInfoType;

/*****************************************************************************
 * 					         Symbol definitions     						 *
 *****************************************************************************/

#define STD_HIGH 					(0x01U) /* Physical state 5V or 3.3V */
#define STD_LOW 					(0x00U) /* Physical state 0V */

#define STD_ACTIVE 					(0x01U) /* Logical state active */
#define STD_IDLE 					(0x00U) /* Logical state idle */

#define STD_ON 						(0x01U)
#define STD_OFF 					(0x00U)

#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 						(0x00U)
typedef uint8 StatusType; /* OSEK compliance */
#endif

#define E_NOT_OK 					(0x01U)
#endif /* STD_TYPES_H_ */
