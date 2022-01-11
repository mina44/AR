 /******************************************************************************
 *
 * Module: Common - Compiler Abstraction
 *
 * File Name: Compiler.h
 *
 * Description:  This file contains the definitions and macros specified by
 *               AUTOSAR for the abstraction of compiler specific keywords.
 *
 * Author: Mina Atef
 *
 *******************************************************************************/

#ifndef COMPILER_H_
#define COMPILER_H_

/*
 * Id for the company in the AUTOSAR
 */
#define COMPILER_VENDOR_ID								(2020U)

/*
 * Module ID		198
 */
#define COMPILER_MODULE_ID								(198U)


/*
 * Module Version	1.0.0
 */
#define COMPILER_SW_MAJOR_VERSION						(1U)
#define COMPILER_SW_MINOR_VERSION						(0U)
#define COMPILER_SW_PATCH_VERSION						(0U)


/*
 * AUTOSAR VERSION	4.0.3
 */
#define COMPILER_AR_RELEASE_MAJOR_VERSION				(4U)
#define COMPILER_AR_RELEASE_MINOR_VERSION				(0U)
#define COMPILER_AR_RELEASE_PATCH_VERSION				(3U)

#include"Compiler_Cfg.h"

/* Software Version checking between Compiler Cfg and Compiler Modules */
#if((COMPILER_SW_MAJOR_VERSION != COMPILER_CFG_SW_MAJOR_VERSION)\
 || (COMPILER_SW_MINOR_VERSION != COMPILER_CFG_SW_MINOR_VERSION)\
 || (COMPILER_SW_PATCH_VERSION != COMPILER_CFG_SW_PATCH_VERSION))
#error"The SW Version of Port_Cfg Is not Compatible With SW Version of Port "
#endif

/* AUTOSAR Release checking between Compiler Cfg and Compiler Modules */
#if((COMPILER_AR_RELEASE_MAJOR_VERSION != COMPILER_CFG_AR_RELEASE_MAJOR_VERSION)\
 || (COMPILER_AR_RELEASE_MINOR_VERSION != COMPILER_CFG_AR_RELEASE_MINOR_VERSION)\
 || (COMPILER_AR_RELEASE_PATCH_VERSION != COMPILER_CFG_AR_RELEASE_PATCH_VERSION))
#error"The AR Version of Port_Cfg Is not Compatible With AR Version of Port "
#endif

/*******************************************************************************
 *                                 Definitions                                 *
 *******************************************************************************/

/*
 * necessary for defining pointer types, with e.g. P2VAR,
 * where the macros require two parameters
 */
#define TYPEDEF

/* Used for the declaration of local pointers */
#define AUTOMATIC

#define NULL_PTR					((void*)0)

/* Keyword inline */
#define INLINE						inline

/* Local inline*/
#define LOCAL_INLINE				static inline

/* Keyword static*/
#define STATIC						static

/*******************************************************************************
 *                                    Macros                                   *
 *******************************************************************************/



#endif /* COMPILER_H_ */
