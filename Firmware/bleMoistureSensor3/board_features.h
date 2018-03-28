/***********************************************************************************************//**
 * \file   board_features.h
 * \brief  Definitions of various BRDs
 ***************************************************************************************************
 * <b> (C) Copyright 2015 Silicon Labs, http://www.silabs.com</b>
 ***************************************************************************************************
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 **************************************************************************************************/

/*******************************************************************************************
 * This is a generated file. Do not modify directly! Edit board_features.h.jinja2 instead. *
 *******************************************************************************************/

#ifndef BOARD_FEATURES_H
#define BOARD_FEATURES_H

#include "ble-configuration.h"

/***********************************************************************************************//**
 * \defgroup Features Features
 * \brief Feature definitions
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup platform_hw
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup Features
 * @{
 **************************************************************************************************/


/* Indicate if LCD is supported */
#if (EMBER_AF_BOARD_TYPE == BRD4100A)\
  || (EMBER_AF_BOARD_TYPE == BRD4101B)\
  || (EMBER_AF_BOARD_TYPE == BRD4103A)\
  || (EMBER_AF_BOARD_TYPE == BRD4104A)\
  || (EMBER_AF_BOARD_TYPE == BRD4105A)\
  || (EMBER_AF_BOARD_TYPE == BRD4150A)\
  || (EMBER_AF_BOARD_TYPE == BRD4150B)\
  || (EMBER_AF_BOARD_TYPE == BRD4150C)\
  || (EMBER_AF_BOARD_TYPE == BRD4151A)\
  || (EMBER_AF_BOARD_TYPE == BRD4153A)\
  || (EMBER_AF_BOARD_TYPE == BRD4158A)\
  || (EMBER_AF_BOARD_TYPE == BRD4159A)\
  || (EMBER_AF_BOARD_TYPE == BRD4161A)\
  || (EMBER_AF_BOARD_TYPE == BRD4162A)\
  || (EMBER_AF_BOARD_TYPE == BRD4163A)\
  || (EMBER_AF_BOARD_TYPE == BRD4164A)\
  || (EMBER_AF_BOARD_TYPE == BRD4165B)\
  || (EMBER_AF_BOARD_TYPE == BRD4167A)\
  || (EMBER_AF_BOARD_TYPE == BRD4168A)\
  || (EMBER_AF_BOARD_TYPE == BRD4169A)\
  || (EMBER_AF_BOARD_TYPE == BRD4169B)\
  || (EMBER_AF_BOARD_TYPE == BRD4300AREVA02)\
  || (EMBER_AF_BOARD_TYPE == BRD4300AREVA03)\
  || (EMBER_AF_BOARD_TYPE == BRD4300C)\
  || (EMBER_AF_BOARD_TYPE == BRD4302A)\
  || (EMBER_AF_BOARD_TYPE == BRD4303A)\
  || (EMBER_AF_BOARD_TYPE == BRD4304A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305C)\
  || (EMBER_AF_BOARD_TYPE == BRD4305D)\
  || (EMBER_AF_BOARD_TYPE == BRD4305E)\
  || (EMBER_AF_BOARD_TYPE == BRD4306A)\
  || (EMBER_AF_BOARD_TYPE == BRD4306B)\
  || (EMBER_AF_BOARD_TYPE == BRD4306C)\
  || (EMBER_AF_BOARD_TYPE == BRD4306D)
#define FEATURE_LCD_SUPPORT
#endif

/* Indicate if the same pins are used for LEDs and Buttons on the WSTK */
#if (EMBER_AF_BOARD_TYPE == BRD4101B)\
  || (EMBER_AF_BOARD_TYPE == BRD4300AREVA02)\
  || (EMBER_AF_BOARD_TYPE == BRD4300AREVA03)\
  || (EMBER_AF_BOARD_TYPE == BRD4300C)\
  || (EMBER_AF_BOARD_TYPE == BRD4301A)\
  || (EMBER_AF_BOARD_TYPE == BRD4304A)\
  || (EMBER_AF_BOARD_TYPE == BRD4306A)\
  || (EMBER_AF_BOARD_TYPE == BRD4306B)\
  || (EMBER_AF_BOARD_TYPE == BRD4306C)\
  || (EMBER_AF_BOARD_TYPE == BRD4306D)
#define FEATURE_LED_BUTTON_ON_SAME_PIN
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4100A)\
  || (EMBER_AF_BOARD_TYPE == BRD4101B)\
  || (EMBER_AF_BOARD_TYPE == BRD4103A)\
  || (EMBER_AF_BOARD_TYPE == BRD4104A)\
  || (EMBER_AF_BOARD_TYPE == BRD4105A)\
  || (EMBER_AF_BOARD_TYPE == BRD4150A)\
  || (EMBER_AF_BOARD_TYPE == BRD4150B)\
  || (EMBER_AF_BOARD_TYPE == BRD4150C)\
  || (EMBER_AF_BOARD_TYPE == BRD4151A)\
  || (EMBER_AF_BOARD_TYPE == BRD4153A)\
  || (EMBER_AF_BOARD_TYPE == BRD4158A)\
  || (EMBER_AF_BOARD_TYPE == BRD4159A)\
  || (EMBER_AF_BOARD_TYPE == BRD4160A)\
  || (EMBER_AF_BOARD_TYPE == BRD4161A)\
  || (EMBER_AF_BOARD_TYPE == BRD4162A)\
  || (EMBER_AF_BOARD_TYPE == BRD4163A)\
  || (EMBER_AF_BOARD_TYPE == BRD4164A)\
  || (EMBER_AF_BOARD_TYPE == BRD4166A)\
  || (EMBER_AF_BOARD_TYPE == BRD4167A)\
  || (EMBER_AF_BOARD_TYPE == BRD4168A)\
  || (EMBER_AF_BOARD_TYPE == BRD4169A)\
  || (EMBER_AF_BOARD_TYPE == BRD4169B)\
  || (EMBER_AF_BOARD_TYPE == BRD4300C)\
  || (EMBER_AF_BOARD_TYPE == BRD4301A)\
  || (EMBER_AF_BOARD_TYPE == BRD4302A)\
  || (EMBER_AF_BOARD_TYPE == BRD4303A)\
  || (EMBER_AF_BOARD_TYPE == BRD4304A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305C)\
  || (EMBER_AF_BOARD_TYPE == BRD4305D)\
  || (EMBER_AF_BOARD_TYPE == BRD4305E)\
  || (EMBER_AF_BOARD_TYPE == BRD4306A)\
  || (EMBER_AF_BOARD_TYPE == BRD4306B)\
  || (EMBER_AF_BOARD_TYPE == BRD4306C)\
  || (EMBER_AF_BOARD_TYPE == BRD4306D)
#define FEATURE_SPI_FLASH
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4101B)
#define FEATURE_IOEXPANDER
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4304A)
#define FEATURE_FEM
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4150B)\
  || (EMBER_AF_BOARD_TYPE == BRD4151A)\
  || (EMBER_AF_BOARD_TYPE == BRD4158A)\
  || (EMBER_AF_BOARD_TYPE == BRD4161A)\
  || (EMBER_AF_BOARD_TYPE == BRD4164A)\
  || (EMBER_AF_BOARD_TYPE == BRD4168A)\
  || (EMBER_AF_BOARD_TYPE == BRD4169B)\
  || (EMBER_AF_BOARD_TYPE == BRD4304A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305E)\
  || (EMBER_AF_BOARD_TYPE == BRD4306B)\
  || (EMBER_AF_BOARD_TYPE == BRD4306D)
#define FEATURE_PA_HIGH_POWER
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4103A)\
  || (EMBER_AF_BOARD_TYPE == BRD4161A)\
  || (EMBER_AF_BOARD_TYPE == BRD4162A)\
  || (EMBER_AF_BOARD_TYPE == BRD4163A)\
  || (EMBER_AF_BOARD_TYPE == BRD4164A)
#define FEATURE_EXP_HEADER_USART3
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4100A)\
  || (EMBER_AF_BOARD_TYPE == BRD4101B)\
  || (EMBER_AF_BOARD_TYPE == BRD4103A)\
  || (EMBER_AF_BOARD_TYPE == BRD4104A)\
  || (EMBER_AF_BOARD_TYPE == BRD4105A)\
  || (EMBER_AF_BOARD_TYPE == BRD4150A)\
  || (EMBER_AF_BOARD_TYPE == BRD4150B)\
  || (EMBER_AF_BOARD_TYPE == BRD4150C)\
  || (EMBER_AF_BOARD_TYPE == BRD4151A)\
  || (EMBER_AF_BOARD_TYPE == BRD4153A)\
  || (EMBER_AF_BOARD_TYPE == BRD4158A)\
  || (EMBER_AF_BOARD_TYPE == BRD4159A)\
  || (EMBER_AF_BOARD_TYPE == BRD4160A)\
  || (EMBER_AF_BOARD_TYPE == BRD4161A)\
  || (EMBER_AF_BOARD_TYPE == BRD4162A)\
  || (EMBER_AF_BOARD_TYPE == BRD4163A)\
  || (EMBER_AF_BOARD_TYPE == BRD4164A)\
  || (EMBER_AF_BOARD_TYPE == BRD4165B)\
  || (EMBER_AF_BOARD_TYPE == BRD4166A)\
  || (EMBER_AF_BOARD_TYPE == BRD4167A)\
  || (EMBER_AF_BOARD_TYPE == BRD4168A)\
  || (EMBER_AF_BOARD_TYPE == BRD4169A)\
  || (EMBER_AF_BOARD_TYPE == BRD4169B)\
  || (EMBER_AF_BOARD_TYPE == BRD4300AREVA02)\
  || (EMBER_AF_BOARD_TYPE == BRD4300AREVA03)\
  || (EMBER_AF_BOARD_TYPE == BRD4300C)\
  || (EMBER_AF_BOARD_TYPE == BRD4301A)\
  || (EMBER_AF_BOARD_TYPE == BRD4302A)\
  || (EMBER_AF_BOARD_TYPE == BRD4303A)\
  || (EMBER_AF_BOARD_TYPE == BRD4304A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305C)\
  || (EMBER_AF_BOARD_TYPE == BRD4305D)\
  || (EMBER_AF_BOARD_TYPE == BRD4305E)\
  || (EMBER_AF_BOARD_TYPE == BRD4306A)\
  || (EMBER_AF_BOARD_TYPE == BRD4306B)\
  || (EMBER_AF_BOARD_TYPE == BRD4306C)\
  || (EMBER_AF_BOARD_TYPE == BRD4306D)
#define FEATURE_PTI_SUPPORT
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4100A)\
  || (EMBER_AF_BOARD_TYPE == BRD4101B)\
  || (EMBER_AF_BOARD_TYPE == BRD4103A)\
  || (EMBER_AF_BOARD_TYPE == BRD4104A)\
  || (EMBER_AF_BOARD_TYPE == BRD4105A)\
  || (EMBER_AF_BOARD_TYPE == BRD4150A)\
  || (EMBER_AF_BOARD_TYPE == BRD4150B)\
  || (EMBER_AF_BOARD_TYPE == BRD4150C)\
  || (EMBER_AF_BOARD_TYPE == BRD4151A)\
  || (EMBER_AF_BOARD_TYPE == BRD4153A)\
  || (EMBER_AF_BOARD_TYPE == BRD4158A)\
  || (EMBER_AF_BOARD_TYPE == BRD4159A)\
  || (EMBER_AF_BOARD_TYPE == BRD4160A)\
  || (EMBER_AF_BOARD_TYPE == BRD4161A)\
  || (EMBER_AF_BOARD_TYPE == BRD4162A)\
  || (EMBER_AF_BOARD_TYPE == BRD4163A)\
  || (EMBER_AF_BOARD_TYPE == BRD4164A)\
  || (EMBER_AF_BOARD_TYPE == BRD4165B)\
  || (EMBER_AF_BOARD_TYPE == BRD4166A)\
  || (EMBER_AF_BOARD_TYPE == BRD4167A)\
  || (EMBER_AF_BOARD_TYPE == BRD4168A)\
  || (EMBER_AF_BOARD_TYPE == BRD4169A)\
  || (EMBER_AF_BOARD_TYPE == BRD4169B)\
  || (EMBER_AF_BOARD_TYPE == BRD4300AREVA02)\
  || (EMBER_AF_BOARD_TYPE == BRD4300AREVA03)\
  || (EMBER_AF_BOARD_TYPE == BRD4300C)\
  || (EMBER_AF_BOARD_TYPE == BRD4301A)\
  || (EMBER_AF_BOARD_TYPE == BRD4302A)\
  || (EMBER_AF_BOARD_TYPE == BRD4303A)\
  || (EMBER_AF_BOARD_TYPE == BRD4304A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305A)\
  || (EMBER_AF_BOARD_TYPE == BRD4305C)\
  || (EMBER_AF_BOARD_TYPE == BRD4305D)\
  || (EMBER_AF_BOARD_TYPE == BRD4305E)\
  || (EMBER_AF_BOARD_TYPE == BRD4306A)\
  || (EMBER_AF_BOARD_TYPE == BRD4306B)\
  || (EMBER_AF_BOARD_TYPE == BRD4306C)\
  || (EMBER_AF_BOARD_TYPE == BRD4306D)\
  || (EMBER_AF_BOARD_TYPE == RD_0057_0101)
#define FEATURE_BOARD_DETECTED
#endif

#if (EMBER_AF_BOARD_TYPE == CUSTOM_BOARD)
// Uncomment the corresponding line in case of using Silicon Labs board feature in your design.
// For using the selected feature you may need additional drivers. Check an appropriate SDK example for reference.

// #define FEATURE_LCD_SUPPORT
// #define FEATURE_LED_BUTTON_ON_SAME_PIN
// #define FEATURE_SPI_FLASH
// #define FEATURE_IOEXPANDER
// #define FEATURE_FEM
// #define FEATURE_PA_HIGH_POWER
// #define FEATURE_EXP_HEADER_USART3
// #define FEATURE_PTI_SUPPORT
// #define FEATURE_BOARD_DETECTED
#endif

/** @} (end addtogroup Features) */
/** @} (end addtogroup platform_hw) */

#endif /* BOARD_FEATURES_H */