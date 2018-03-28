/***************************************************************************//**
 * @file ecode.h
 * @brief Energy Aware drivers error code definitions.
 * @version 5.4.0
 *******************************************************************************
 * # License
 * <b>(C) Copyright 2015 Silicon Labs, www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/
#ifndef __SILICON_LABS_ECODE_H__
#define __SILICON_LABS_ECODE_H__

#include <stdint.h>

/***************************************************************************//**
 * @defgroup emdrv EMDRV
 * @brief energyAware drivers
 * @details
 *
 *  EMDRV is a set of function specific high performance drivers for EFM32, EZR32
 *  and EFR32 on-chip peripherals. Drivers are typically DMA based and are using
 *  all available low-energy features. For most drivers, the API offers both
 *  synchronous and asynchronous functions. The APIs are fully reentrant and
 *  callback based.
 *
 *  Most drivers are compile-time configurable to allow the highest possible
 *  code size optimization for the application. Compile-time configuration is
 *  defined in *_config.h files. Templates for the configuration files can be
 *  found in emdrv\\<driver>\\config.
 *
 * @note
 *	EMDRV APIs use @ref Ecode_t to return status.
 * @n @n
 *  With the exception of ezradiodrv, EMDRV does not implement RF support.
 *  Please refer to stack documentation for more information.
 *
 * @{
 ******************************************************************************/

/***************************************************************************//**
 * @brief Typedef for API function error code return values.
 *
 * @details
 *        Bit 24-31:  Component, for example @ref EMDRV @n
 *        Bit 16-23:  Module, for example @ref UARTDRV or @ref RTCDRV @n
 *        Bit 0-15:   Error code
 ******************************************************************************/
typedef uint32_t Ecode_t;

#define ECODE_EMDRV_BASE  (0xF0000000U)   ///< Base value for all EMDRV errorcodes.

#define ECODE_OK          (0U)            ///< Generic success return value.

#define ECODE_EMDRV_RTCDRV_BASE     (ECODE_EMDRV_BASE | 0x00001000U)   ///< Base value for RTCDRV error codes.
#define ECODE_EMDRV_SPIDRV_BASE     (ECODE_EMDRV_BASE | 0x00002000U)   ///< Base value for SPIDRV error codes.
#define ECODE_EMDRV_NVM_BASE        (ECODE_EMDRV_BASE | 0x00003000U)   ///< Base value for NVM error codes.
#define ECODE_EMDRV_USTIMER_BASE    (ECODE_EMDRV_BASE | 0x00004000U)   ///< Base value for USTIMER error codes.
#define ECODE_EMDRV_UARTDRV_BASE    (ECODE_EMDRV_BASE | 0x00007000U)   ///< Base value for UARTDRV error codes.
#define ECODE_EMDRV_DMADRV_BASE     (ECODE_EMDRV_BASE | 0x00008000U)   ///< Base value for DMADRV error codes.
#define ECODE_EMDRV_EZRADIODRV_BASE (ECODE_EMDRV_BASE | 0x00009000U)   ///< Base value for EZRADIODRV error codes.
#define ECODE_EMDRV_TEMPDRV_BASE    (ECODE_EMDRV_BASE | 0x0000D000U)   ///< Base value for TEMPDRV error codes.
#define ECODE_EMDRV_NVM3_BASE       (ECODE_EMDRV_BASE | 0x0000E000U)   ///< Base value for NVM3 error codes.

/** @} (end addtogroup emdrv) */

#endif // __SILICON_LABS_ECODE_H__
