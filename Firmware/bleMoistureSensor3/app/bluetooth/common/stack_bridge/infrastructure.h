/**************************************************************************//**
 * \file   infrastructure.h
 * \brief  Infrastructure for code development, macros for type conversion
 ******************************************************************************
 * <b> (C) Copyright 2015 Silicon Labs, http://www.silabs.com</b>
 ******************************************************************************
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *****************************************************************************/

#ifndef INFRASTRUCTURE_H
#define INFRASTRUCTURE_H

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
 * Macros for type conversion
 *************************************************************************************************/
// Note: This is an extended copy of appbuilder/sample-apps/commmon/infrastructure.h

#define FLT_TO_UINT32(m, e)         (((uint32_t)(m) & 0x00FFFFFFU) | (uint32_t)((int32_t)(e) << 24))

#define UINT16_TO_BITSTREAM(p, n)   { *(p)++ = (uint8_t)(n); *(p)++ = (uint8_t)((n) >> 8); }

#define UINT8_TO_BITSTREAM(p, n)    { *(p)++ = (uint8_t)(n); }

#define UINT16_TO_BYTES(n)          ((uint8_t) (n)), ((uint8_t)((n) >> 8))

#define UINT32_TO_BITSTREAM(p, n)   { *(p)++ = (uint8_t)(n); *(p)++ = (uint8_t)((n) >> 8); \
                                      *(p)++ = (uint8_t)((n) >> 16); *(p)++ = (uint8_t)((n) >> 24); }

#define UINT16_TO_BYTE0(n)        ((uint8_t) (n))
#define UINT16_TO_BYTE1(n)        ((uint8_t) ((n) >> 8))

#define UINT32_TO_BYTE0(n)        ((uint8_t) (n))
#define UINT32_TO_BYTE1(n)        ((uint8_t) ((n) >> 8))
#define UINT32_TO_BYTE2(n)        ((uint8_t) ((n) >> 16))
#define UINT32_TO_BYTE3(n)        ((uint8_t) ((n) >> 24))

#define BYTES_TO_UINT16(byte0, byte1) ( (((uint16_t)(byte1)) << 8) + ((uint16_t)(byte0)) )

#define BYTES_TO_UINT32(byte0, byte1, byte2, byte3) \
  ( (((uint32_t)(byte3)) << 24)                     \
    + (((uint32_t)(byte2)) << 16)                   \
    + (((uint32_t)(byte1)) << 8)                    \
    +  ((uint32_t)(byte0)) )

#define MIN(a, b)                  (((a) < (b)) ? (a) : (b))
#define MAX(a, b)                  (((a) > (b)) ? (a) : (b))

#define COUNTOF(x)                ((sizeof (x)) / (sizeof ((x)[0])))

#ifdef __cplusplus
};
#endif

#endif /* INFRASTRUCTURE_H */
