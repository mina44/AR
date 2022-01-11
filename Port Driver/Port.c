 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Mina Atef
 ******************************************************************************/

#include"Port.h"
#include"Port_REG.h"

#if(PORT_DEV_ERROR_DETECT == STD_ON)
#include"Det.h"

/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (DET_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (DET_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR Version of Det Is not Compatible With AR Version of Port "
#endif

#endif/* (PORT_DEV_ERROR_DETECT == STD_ON) */

#include"Port_PBcfg.h"

/* Software Version checking between Port PBcfg and Port Modules */
#if((PORT_SW_MAJOR_VERSION != PORT_PB_CFG_SW_MAJOR_VERSION)\
 || (PORT_SW_MINOR_VERSION != PORT_PB_CFG_SW_MINOR_VERSION)\
 || (PORT_SW_PATCH_VERSION != PORT_PB_CFG_SW_PATCH_VERSION))
#error"The SW Version of Port_PBcfg Is not Compatible With SW Version of Port "
#endif

/* AUTOSAR Release checking between Port PBcfg and Port Modules */
#if((PORT_AR_RELEASE_MAJOR_VERSION != PORT_PB_CFG_AR_RELEASE_MAJOR_VERSION)\
 || (PORT_AR_RELEASE_MINOR_VERSION != PORT_PB_CFG_AR_RELEASE_MINOR_VERSION)\
 || (PORT_AR_RELEASE_PATCH_VERSION != PORT_PB_CFG_AR_RELEASE_PATCH_VERSION))
#error"The AR Version of Port_PBcfg Is not Compatible With AR Version of Port "
#endif

/* Local Global flag for Port init API */
STATIC Std_ReturnType    Port_Status=Port_UNINITIALIZED;

/* Local Global pointer */
STATIC Port_ConfigPinType * Port_ConfigPtr=NULL_PTR;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port Driver module.
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{
	uint8  index=0;
	uint8  pinId=0;
	uint8* ddrPtr=NULL_PTR;
	uint8* portPtr=NULL_PTR;
	Port_ConfigPtr=(Port_ConfigPinType *)ConfigPtr->PortPin;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif
	{


		for(index=0;index<PORT_NUMBER_OF_PORT_PINS;index++)
		{

			if( (index >= PORTA_FIRST_PIN) && (index <= PORTA_LAST_PIN) )
			{
				pinId=index;
				ddrPtr =&DDRA_REG;
				portPtr=&PORTA_REG;
			}
			else if( (index >= PORTB_FIRST_PIN) && (index <= PORTB_LAST_PIN) )
			{
				pinId= index%Pins_PER_PORT_COUNT;
				ddrPtr =&DDRB_REG;
				portPtr=&PORTB_REG;
			}
			else if( (index >= PORTC_FIRST_PIN) && (index <= PORTC_LAST_PIN) )
			{
				pinId= index%Pins_PER_PORT_COUNT;
				ddrPtr =&DDRC_REG;
				portPtr=&PORTC_REG;
			}
			else if( (index >= PORTD_FIRST_PIN) && (index <= PORTD_LAST_PIN) )
			{
				pinId= index%Pins_PER_PORT_COUNT;
				ddrPtr =&DDRD_REG;
				portPtr=&PORTD_REG;
			}

			/* Set Pin Direction and Level Value */
			if(Port_ConfigPtr[index].PORT_PIN_DIRECTION == PORT_PIN_OUT)
			{
				/* Set Pin Direction Output */
				SET_BIT(*ddrPtr , pinId);


				if(Port_ConfigPtr[index].PORT_PIN_LEVEL_VALUE == PORT_PIN_LEVEL_HIGH)
				{
					/* Set Pin Level to High */
					SET_BIT(*portPtr , pinId);
				}
				else
				{
					/* Set Pin Level to Low */
					CLEAR_BIT(*portPtr , pinId);
				}
			}
			else
			{
				/* Set Pin Direction Input */
				CLEAR_BIT(*ddrPtr , pinId);
#if(INTERNAL_PULLUP_RES_SUPPORT == STD_ON)
				if(Port_ConfigPtr[index].PORT_PIN_LEVEL_VALUE == PORT_PIN_LEVEL_HIGH)
				{
					/* Enable Internal pullup resistor */
					SET_BIT(*portPtr , pinId);
				}
				else
				{
					/* Disable Internal pullup resistor */
					CLEAR_BIT(*portPtr , pinId);
				}
#endif /*INTERNAL_PULLUP_RES_SUPPORT == STD_ON*/
			}

		}
		Port_Status=Port_INITIALIZED;
	}
}


/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin 		 - Port Pin ID number
* 				   Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin direction.
************************************************************************************/
#if(PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
	uint8* ddrPtr=NULL_PTR;

	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (Port_UNINITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}

	/* Check if the Incorrect Port Pin ID passed */
	if (PORT_NUMBER_OF_PORT_PINS <= Pin)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}

	/* Check if the Port Pin not configured as changeable */
	if (TRUE != Port_ConfigPtr[Pin].PORT_PIN_DIRECTION_CHANGEABLE)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
		if( (Pin >= PORTA_FIRST_PIN) && (Pin <= PORTA_LAST_PIN) )
		{
			ddrPtr =&DDRA_REG;
		}
		else if( (Pin >= PORTB_FIRST_PIN) && (Pin <= PORTB_LAST_PIN) )
		{
			Pin= Pin % Pins_PER_PORT_COUNT;
			ddrPtr =&DDRB_REG;
		}
		else if( (Pin >= PORTC_FIRST_PIN) && (Pin <= PORTC_LAST_PIN) )
		{
			Pin= Pin % Pins_PER_PORT_COUNT;
			ddrPtr =&DDRC_REG;
		}
		else if( (Pin >= PORTD_FIRST_PIN) && (Pin <= PORTD_LAST_PIN) )
		{
			Pin= Pin % Pins_PER_PORT_COUNT;
			ddrPtr =&DDRD_REG;
		}

		if(PORT_PIN_OUT == Direction)
		{
			/* Set Pin Direction Output */
			SET_BIT(*ddrPtr , Pin);
		}
		else
		{
			/* Set Pin Direction INPUT */
			CLEAR_BIT(*ddrPtr , Pin);
		}
	}
}
#endif /* PORT_SET_PIN_DIRECTION_API == STD_ON */

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refresh port direction.
************************************************************************************/
void Port_RefreshPortDirection( void )
{
	boolean error = FALSE;
	Port_PinType Pin;
	uint8 * ddrPtr=NULL_PTR;
	uint8 index=0;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (Port_UNINITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
		for(index=0;index<PORT_NUMBER_OF_PORT_PINS;index++)
		{
			/* Reset pin direction only if its direction is unchangeable*/
			if (TRUE != Port_ConfigPtr[index].PORT_PIN_DIRECTION_CHANGEABLE)
			{
				if( (index >= PORTA_FIRST_PIN) && (index <= PORTA_LAST_PIN) )
				{
					ddrPtr =&DDRA_REG;
				}
				else if( (index >= PORTB_FIRST_PIN) && (index <= PORTB_LAST_PIN) )
				{
					Pin= index % Pins_PER_PORT_COUNT;
					ddrPtr =&DDRB_REG;
				}
				else if( (index >= PORTC_FIRST_PIN) && (index <= PORTC_LAST_PIN) )
				{
					Pin= index % Pins_PER_PORT_COUNT;
					ddrPtr =&DDRC_REG;
				}
				else if( (index >= PORTD_FIRST_PIN) && (index <= PORTD_LAST_PIN) )
				{
					Pin= index % Pins_PER_PORT_COUNT;
					ddrPtr =&DDRD_REG;
				}

				else
				{
					/* No Action Required */
				}

				if(NULL_PTR != ddrPtr)
				{
					if(PORT_PIN_OUT == Port_ConfigPtr[index].PORT_PIN_DIRECTION)
					{
						/* Set Pin Direction Output */
						SET_BIT(*ddrPtr , Pin);
					}
					else
					{
						/* Set Pin Direction INPUT */
						CLEAR_BIT(*ddrPtr , Pin);
					}
				}
				else
				{
					/* No Action Required */
				}
			}

			else
			{
				/* No Action Required */
			}
		}
	}
}

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version
* 								  information of this module.
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
#if(PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif /* PORT_VERSION_INFO_API == STD_ON */
/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin 	 - Port Pin ID number
* 				   Mode	 - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
#if(PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (Port_UNINITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}

	/* Check if the Incorrect Port Pin ID passed */
	if (PORT_NUMBER_OF_PORT_PINS <= Pin)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}

	/* Check if the Port Pin not configured as changeable */
	if (TRUE != Port_ConfigPtr[Pin].PORT_PIN_MODE_CHANGEABLE)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}

	/* Check if the Invalid Mode passed */
	if (Mode < PORT_PIN_MODE_ADC || Mode > PORT_PIN_MODE_SPI)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}

#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{

	}
}
#endif /*PORT_SET_PIN_MODE_API == STD_ON*/
