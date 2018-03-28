/***************************************************************************//**
 * @file application_properties.h
 * @brief Representation of Application Properties
 * @author Silicon Labs
 * @version 1.5.0
 *******************************************************************************
 * # License
 * <b>Copyright 2016 Silicon Laboratories, Inc. http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/
#ifndef APPLICATION_PROPERTIES_H
#define APPLICATION_PROPERTIES_H

#include <stdint.h>

/***************************************************************************//**
 * @addtogroup Interface
 * @{
 * @addtogroup ApplicationProperties Application Properties
 * @brief Properties of the application that can be accessed by the bootloader
 * @details
 *   Applications must contain an @ref ApplicationProperties_t struct declaring
 *   the application version and capabilities, etc. The metadata contained in
 *   this struct will be extracted from the application by the Simplicity
 *   Commander tool and placed in the EBL upgrade file. If such a struct is not
 *   present in the application image, it will be added to the EBL file by the
 *   Simplicity Commander.
 *
 *   The struct is also used to declare whether the application image is signed,
 *   and what type of signature is used. If no @ref ApplicationProperties_t
 *   struct is present, the bootloader will assume that the application image
 *   is signed using @ref APPLICATION_SIGNATURE_ECDSA_P256.
 *
 *   In order for the bootloader to easily locate the ApplicationProperties_t
 *   struct, if not already done by the linker, Simplicity Commander will modify
 *   word 13 of the application to insert a pointer to the
 *   ApplicationProperties_t struct.
 * @{
 ******************************************************************************/

/// Magic value declaring the existence of an ApplicationProperties_t struct
#define APPLICATION_PROPERTIES_MAGIC     { \
    0x13, 0xb7, 0x79, 0xfa,                \
    0xc9, 0x25, 0xdd, 0xb7,                \
    0xad, 0xf3, 0xcf, 0xe0,                \
    0xf1, 0xb6, 0x14, 0xb8                 \
}

/// Version number of the AppliationProperties_t struct
#define APPLICATION_PROPERTIES_VERSION   0x00000100

/// The application is not signed
#define APPLICATION_SIGNATURE_NONE       (0UL)
/// @brief The SHA-256 digest of the application is signed using ECDSA with the
///        NIST P-256 curve
#define APPLICATION_SIGNATURE_ECDSA_P256 (1UL << 0UL)
/// @brief The application is not signed, but has a CRC-32 checksum
#define APPLICATION_SIGNATURE_CRC32      (1UL << 1UL)

/// The application contains a Zigbee wireless stack
#define APPLICATION_TYPE_ZIGBEE          (1UL << 0UL)
/// The application contains a Thread wireless stack
#define APPLICATION_TYPE_THREAD          (1UL << 1UL)
/// The application contains a Flex wireless stack
#define APPLICATION_TYPE_FLEX            (1UL << 2UL)
/// The application contains a Bluetooth wireless stack
#define APPLICATION_TYPE_BLUETOOTH       (1UL << 3UL)
/// The application is an MCU application
#define APPLICATION_TYPE_MCU             (1UL << 4UL)
/// The application contains a Bluetooth application
#define APPLICATION_TYPE_BLUETOOTH_APP   (1UL << 5UL)

/// Application Data
typedef struct ApplicationData {
  /// @brief Bitfield representing type of application, e.g.
  /// @ref APPLICATION_TYPE_ZIGBEE
  uint32_t type;
  /// Version number for this application
  uint32_t version;
  /// Capabilities of this application
  uint32_t capabilities;
  /// Unique ID (UUID or GUID) for the product this application is built for
  uint8_t productId[16];
} ApplicationData_t;

/// Application Properties struct
typedef struct {
  /// @brief Magic value indicating this is an ApplicationProperties_t struct.
  /// Must equal @ref APPLICATION_PROPERTIES_MAGIC
  uint8_t magic[16];
  /// Version number of this struct
  uint32_t structVersion;
  /// Type of signature this application is signed with
  uint32_t signatureType;
  /// Location of the signature. Typically points to the end of the application
  uint32_t signatureLocation;
  /// Information about the application
  ApplicationData_t app;
} ApplicationProperties_t;

/** @} // addtogroup ApplicationProperties */
/** @} // addtogroup Interface */

#endif // APPLICATION_PROPERTIES_H
