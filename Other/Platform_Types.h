/******************************************************************************
 *
 * Module: Common - Platform Types
 *
 * File Name: Platform_Types.h
 *
 * Description:  This file contains the definitions and macros specified by
 *               AUTOSAR for the abstraction of platform specific types.
 *
 * Author: Mina Atef
 *
 *******************************************************************************/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/*
 * VENDOR ID		2020
 */
#define PLATFORM_TYPES_VENDOR_ID							(2020U)

/*
 * Module ID		199
 */
#define PLATFORM_TYPES_MODULE_ID							(199U)

/*
 * MODULE VERSION 1.0.0
 */
#define PLATFORM_TYPES_SW_MAJOR_VERSION						(1U)
#define PLATFORM_TYPES_SW_MINOR_VERSION						(0U)
#define PLATFORM_TYPES_SW_PATCH_VERSION						(0U)

/*
 * AUTOSAR RELEASE 4.0.3
 */
#define PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION				(4U)
#define PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION				(0U)
#define PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION				(3U)



/*
 * CPU register width types
 */

/* 8 bit processor */
#define CPU_TYPE_8			(8U)
/* 16 bit processor */
#define CPU_TYPE_16			(16U)
/* 32 bit processor */
#define CPU_TYPE_32			(32U)

/*
 * CPU Bit Order
 */
#define MSB_FIRST			(0U)
#define LSB_FIRST			(1U)

/*
 * CPU Byte Order
 */
#define HIGH_BYTE_FIRST		(0U)
#define LOW_BYTE_FIRST		(1U)

#ifndef TRUE
#define TRUE				((boolean)0x01)
#endif

#ifndef FALSE
#define FALSE				((boolean)0x00)
#endif

/*
 * Platform type and endianess definitions, specific for AVR
 */
#define CPU_TYPE			CPU_TYPE_8
#define CPU_BIT_ORDER		LSB_FIRST
#define CPU_BYTE_ORDER		LOW_BYTE_FIRST


typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned long		uint32;
typedef unsigned long long	uint64;

typedef signed char			sint8;
typedef signed short 		sint16;
typedef signed long 		sint32;
typedef signed long long    sint64;

typedef uint8				uint8_least;
typedef uint16				uint16_least;
typedef uint32				uint32_least;
typedef sint8				Sint8_least;
typedef sint16				Sint16_least;
typedef sint32				Sint32_least;

typedef float				float32;
typedef double				float64;

typedef uint8 				boolean;
#endif /* PLATFORM_TYPES_H_ */
