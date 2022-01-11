 /******************************************************************************
 *
 * Module: Det
 *
 * File Name: Det.h
 *
 * Description:  Det stores the development errors reported by other modules.
 *
 * Author: Mina Atef
 ******************************************************************************/

#ifndef DET_H_
#define DET_H_

/*
 * VENDOR ID		2020
 */
#define DET_VENDOR_ID								(2020U)

/*
 * MODULE ID		15
 */
#define DET_MODULE_ID								(15U)

/*
 * MODULE Version	1.0.0
 */
#define DET_SW_MAJOR_VERSION						(1U)
#define DET_SW_MINOR_VERSION						(0U)
#define DET_SW_PATCH_VERSION						(0U)

/*
 * AUTOSAR RELEASE	4.0.3
 */
#define DET_AR_RELEASE_MAJOR_VERSION				(4U)
#define DET_AR_RELEASE_MINOR_VERSION				(0U)
#define DET_AR_RELEASE_PATCH_VERSION				(3U)

#include"Std_Types.h"
/* AUTOSAR Release checking between Std Types and Det Modules */
#if((DET_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error"The AR Version of STD_Types Is not Compatible With AR Version of Port "
#endif



/*****************************************************************************
 * 					       	API	Service Id Macros    						 *
 *****************************************************************************/

/* Service ID for Det_Init */
#define DET_INIT_SID								(0x00U)

/* Service ID for Det_ReportError */
#define DET_REPORT_ERROR_SID						(0x01U)

/* Service ID for Det_Start */
#define DET_START_SID								(0x02U)

/* Service ID for Det_GetVersionInfo*/
#define DET_GET_VERSION_INFO_SID					(0x03U)

/*****************************************************************************
 *                               DET Error Codes                             *
 *****************************************************************************/

/* Det_GetVersionInfo called with null parameter pointer */
#define DET_E_PARAM_POINTER							(0x01U)

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* No module specific types */

/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/

void Det_Init(void);

Std_ReturnType Det_ReportError(
								uint16	ModuleId,
								uint8	InstanceId,
								uint8	ApiId,
								uint8	ErrorId);

void Det_Start(void);

void Det_GetVersionInfo(Std_VersionInfoType* versioninfo);

#endif /* DET_H_ */
