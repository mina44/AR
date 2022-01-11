 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.h
 *
 * Description:  This file contains the post-build Configurations for Port
 * 				 Module.
 *
 * Author: Mina Atef
 *
 *******************************************************************************/

#ifndef PORT_PBCFG_H_
#define PORT_PBCFG_H_

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
#define PORT_PB_CFG_SW_MAJOR_VERSION						(1U)
#define PORT_PB_CFG_SW_MINOR_VERSION						(0U)
#define PORT_PB_CFG_SW_PATCH_VERSION						(0U)

/*
 * AUTOSAR RELEASE	4.0.3
 */
#define PORT_PB_CFG_AR_RELEASE_MAJOR_VERSION				(4U)
#define PORT_PB_CFG_AR_RELEASE_MINOR_VERSION				(0U)
#define PORT_PB_CFG_AR_RELEASE_PATCH_VERSION				(3U)

/*******************************************************************************
 *                             External Variables                              *
 *******************************************************************************/
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_PBCFG_H_ */
