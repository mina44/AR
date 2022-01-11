 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Mina Atef
 ******************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/*
 * VENDOR ID		2020
 */
#define PORT_VENDOR_ID								(2020U)

/*
 * MODULE ID		124
 */
#define PORT_MODULE_ID								(124U)

/*
 * Instance ID		0
 */
#define PORT_INSTANCE_ID							(0U)

/*
 * MODULE Version	1.0.0
 */
#define PORT_SW_MAJOR_VERSION						(1U)
#define PORT_SW_MINOR_VERSION						(0U)
#define PORT_SW_PATCH_VERSION						(0U)

/*
 * AUTOSAR RELEASE	4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION				(4U)
#define PORT_AR_RELEASE_MINOR_VERSION				(0U)
#define PORT_AR_RELEASE_PATCH_VERSION				(3U)

#include"Std_Types.h"
/* AUTOSAR Release checking between Std Types and Port Modules */
#if((PORT_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 || (PORT_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 || (PORT_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error"The AR Version of STD_Types Is not Compatible With AR Version of Port "
#endif

#include"Port_Cfg.h"
/* Software Version checking between Port Cfg and Port Modules */
#if((PORT_SW_MAJOR_VERSION != PORT_CFG_SW_MAJOR_VERSION)\
 || (PORT_SW_MINOR_VERSION != PORT_CFG_SW_MINOR_VERSION)\
 || (PORT_SW_PATCH_VERSION != PORT_CFG_SW_PATCH_VERSION))
#error"The SW Version of Port_Cfg Is not Compatible With SW Version of Port "
#endif

/* AUTOSAR Release checking between Port Cfg and Port Modules */
#if((PORT_AR_RELEASE_MAJOR_VERSION != PORT_CFG_AR_RELEASE_MAJOR_VERSION)\
 || (PORT_AR_RELEASE_MINOR_VERSION != PORT_CFG_AR_RELEASE_MINOR_VERSION)\
 || (PORT_AR_RELEASE_PATCH_VERSION != PORT_CFG_AR_RELEASE_PATCH_VERSION))
#error"The AR Version of Port_Cfg Is not Compatible With AR Version of Port "
#endif


/*Non-AUTOSAR files*/
#include"common_macros.h"

/*****************************************************************************
 * 					       	API	Service Id Macros    						 *
 *****************************************************************************/

/*Service ID for Port_Init*/
#define PORT_INIT_SID								(uint8)0x00

/*Service ID for Port_SetPinDirection*/
#define PORT_SET_PIN_DIRECTION_SID						(uint8)0x01

/*Service ID for Port_RefreshPortDirection*/
#define PORT_REFRESH_PORT_DIRECTION_SID					(uint8)0x02

/*Service ID for Port_GetVersionInfo*/
#define PORT_GET_VERSION_INFO_SID						(uint8)0x03

/*Service ID for Port_SetPinMode*/
#define PORT_SET_PIN_MODE_SID							(uint8)0x04

/*******************************************************************************
 *                               DET Error Codes                               *
 *******************************************************************************/

/* DET code to report Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN							(uint8)0x0A

/* DET code to report Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE				(uint8)0x0B

/* DET code to report Port_Init service called with wrong parameter */
#define  PORT_E_PARAM_CONFIG						(uint8)0x0C

/* DET code to report API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_INVALID_MODE					(uint8)0x0D

/* DET code to report API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE					(uint8)0x0E

/* DET code to report API service called without module initialization */
#define PORT_E_UNINIT								(uint8)0x0F

/* DET code to report APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER						(uint8)0x10

/*******************************************************************************
 *                           Non AUTOSAR Definitions                           *
 *******************************************************************************/

#define INTERNAL_PULLUP_ENABLE						(PORT_PIN_LEVEL_HIGH)
#define INTERNAL_PULLUP_DISABLE						(PORT_PIN_LEVEL_LOW)
#define Port_INITIALIZED							(TRUE)
#define Port_UNINITIALIZED							(FALSE)
#define Pins_PER_PORT_COUNT							(8U)
/* Ports Pins */
#define PORTA_FIRST_PIN								(0U)
#define PORTA_LAST_PIN								(7U)

#define PORTB_FIRST_PIN								(8U)
#define PORTB_LAST_PIN								(15U)

#define PORTC_FIRST_PIN								(16U)
#define PORTC_LAST_PIN								(23U)

#define PORTD_FIRST_PIN								(24U)
#define PORTD_LAST_PIN								(31U)
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for pin type used by Port APIs */
typedef uint8	Port_PinType;


/* Type definition enum for Pin Direction */
typedef	enum{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

/* Type definition enum for Pin Level Value */
typedef enum{
	PORT_PIN_LEVEL_HIGH,
	PORT_PIN_LEVEL_LOW
}Port_PinLevelValueType;

/* Type definition enum for Pin Mode */
typedef enum{
	PORT_PIN_MODE_ADC,		/*Port Pin used by ADC*/
	PORT_PIN_MODE_CAN,		/*Port Pin used for CAN*/
	PORT_PIN_MODE_DIO,		/*Port Pin configured for DIO*/
	PORT_PIN_MODE_DIO_GPT,	/*Port Pin configured for DIO and used by GPT*/
	PORT_PIN_MODE_DIO_WDG,	/*Port Pin configured for DIO and used by WDG*/
	PORT_PIN_MODE_FLEXRAY,	/*Port Pin used for FlexRay*/
	PORT_PIN_MODE_ICU,		/*Port Pin used by ICU*/
	PORT_PIN_MODE_LIN,		/*Port Pin used for LIN*/
	PORT_PIN_MODE_MEM,		/*Port Pin used for external memory under control of a memory driver*/
	PORT_PIN_MODE_PWM,		/*Port Pin used by PWM*/
	PORT_PIN_MODE_SPI		/*Port Pin used by SPI*/
}Port_PinModeType;

typedef struct
{
	Port_PinDirectionType	PORT_PIN_DIRECTION;
	boolean					PORT_PIN_DIRECTION_CHANGEABLE;
	Port_PinModeType 		PORT_INITIAL_PIN_MODE;
	Port_PinLevelValueType  PORT_PIN_LEVEL_VALUE;
	Port_PinModeType		PORT_PIN_MODE;
	boolean 				PORT_PIN_MODE_CHANGEABLE;
}Port_ConfigPinType;

/* Data Structure required for initializing the Port Driver */
typedef struct{
	Port_ConfigPinType		PortPin[PORT_NUMBER_OF_PORT_PINS];
}Port_ConfigType;


/*******************************************************************************
 *                            Functions Prototypes                             *
 *******************************************************************************/

/* Function for Port Init API */
void Port_Init( const Port_ConfigType* ConfigPtr );

/* Function for Port Set Pin Direction API */
#if(PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif /*PORT_SET_PIN_DIRECTION_API == STD_ON*/

/* Function for Port Refresh Port Direction API */
void Port_RefreshPortDirection( void );


/* Function for Port Get Version Info API */
#if(PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif /*PORT_VERSION_INFO_API == STD_ON*/

/* Function for Port Set Pin Mode API */
#if(PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );
#endif/*PORT_SET_PIN_MODE_API == STD_ON*/

/*******************************************************************************
 *                              External Variables                             *
 *******************************************************************************/
#include"Port_PBcfg.h"
/* Software Version checking between Port PBcfg and Port Modules */
#if((PORT_SW_MAJOR_VERSION != PORT_PB_CFG_SW_MAJOR_VERSION)\
 || (PORT_SW_MINOR_VERSION != PORT_PB_CFG_SW_MINOR_VERSION)\
 || (PORT_SW_PATCH_VERSION != PORT_PB_CFG_SW_PATCH_VERSION))
#error"The SW Version of Port_Cfg Is not Compatible With SW Version of Port "
#endif

/* AUTOSAR Release checking between Port PBcfg and Port Modules */
#if((PORT_AR_RELEASE_MAJOR_VERSION != PORT_PB_CFG_AR_RELEASE_MAJOR_VERSION)\
 || (PORT_AR_RELEASE_MINOR_VERSION != PORT_PB_CFG_AR_RELEASE_MINOR_VERSION)\
 || (PORT_AR_RELEASE_PATCH_VERSION != PORT_PB_CFG_AR_RELEASE_PATCH_VERSION))
#error"The AR Version of Port_Cfg Is not Compatible With AR Version of Port "
#endif

#endif /* PORT_H_ */
