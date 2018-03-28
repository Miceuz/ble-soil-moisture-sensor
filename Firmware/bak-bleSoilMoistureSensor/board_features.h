/***********************************************************************************************//**
 * \file   feature.h
 * \brief  Definitions of various BRDs
 ***************************************************************************************************
 * <b> (C) Copyright 2015 Silicon Labs, http://www.silabs.com</b>
 ***************************************************************************************************
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 **************************************************************************************************/

#ifndef FEATURES_H_
#define FEATURES_H_

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
#if (EMBER_AF_BOARD_TYPE == BRD4100A) \
    || (EMBER_AF_BOARD_TYPE == BRD4150B) \
    || (EMBER_AF_BOARD_TYPE == BRD4151A) \
    || (EMBER_AF_BOARD_TYPE == BRD4153A) \
    || (EMBER_AF_BOARD_TYPE == BRD4300C) \
    || (EMBER_AF_BOARD_TYPE == BRD4300AREVA01) \
    || (EMBER_AF_BOARD_TYPE == BRD4300AREVA02) \
    || (EMBER_AF_BOARD_TYPE == BRD4300AREVA03) \
    || (EMBER_AF_BOARD_TYPE == BRD4302A)
#define FEATURE_LCD_SUPPORT
#endif

/* Indicate if the same pins are used for LEDs and Buttons on the WSTK */
#if (EMBER_AF_BOARD_TYPE == BRD4300AREVA01) \
    || (EMBER_AF_BOARD_TYPE == BRD4300AREVA02) \
    || (EMBER_AF_BOARD_TYPE == BRD4300AREVA03) \
    || (EMBER_AF_BOARD_TYPE == BRD4300C) \
    || (EMBER_AF_BOARD_TYPE == BRD4301A)
#define FEATURE_LED_BUTTON_ON_SAME_PIN
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4100A) \
    || (EMBER_AF_BOARD_TYPE == BRD4151A) \
    || (EMBER_AF_BOARD_TYPE == BRD4153A) \
    || (EMBER_AF_BOARD_TYPE == BRD4302A) \
    || (EMBER_AF_BOARD_TYPE == RD_0057_0101)
#define FEATURE_SPI_FLASH
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4151A) \
    || (EMBER_AF_BOARD_TYPE == BRD4150B)
#define FEATURE_PA_20DBM
#endif

#if (EMBER_AF_BOARD_TYPE == BRD4100A) \
    || (EMBER_AF_BOARD_TYPE == BRD4150B) \
    || (EMBER_AF_BOARD_TYPE == BRD4151A) \
    || (EMBER_AF_BOARD_TYPE == BRD4153A) \
    || (EMBER_AF_BOARD_TYPE == BRD4300C) \
    || (EMBER_AF_BOARD_TYPE == BRD4300AREVA01) \
    || (EMBER_AF_BOARD_TYPE == BRD4300AREVA02) \
    || (EMBER_AF_BOARD_TYPE == BRD4300AREVA03) \
    || (EMBER_AF_BOARD_TYPE == BRD4301A) \
    || (EMBER_AF_BOARD_TYPE == BRD4302A) 
#define FEATURE_BOARD_DETECTED
/* Currently all radio boards support PTI*/
#define FEATURE_PTI_SUPPORT
#endif

/** @} (end addtogroup Features) */
/** @} (end addtogroup platform_hw) */

#endif /* FEATURES_H_ */

