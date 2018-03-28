/***********************************************************************************************//**
 * \file   pti.c
 * \brief  Functions and data related to PTI
 ***************************************************************************************************
 * <b> (C) Copyright 2017 Silicon Labs, http://www.silabs.com</b>
 ***************************************************************************************************
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 **************************************************************************************************/

#include "pti.h"
#include "rail.h"
#if defined(HAL_CONFIG)
#include "bsphalconfig.h"
#else
#include "bspconfig.h"
#endif

uint8_t configEnablePti(void)
{
  RAIL_PtiConfig_t ptiConfig = RAIL_PTI_CONFIG;
  RAIL_Status_t status;

  status = RAIL_ConfigPti(RAIL_EFR32_HANDLE, &ptiConfig);

  if (RAIL_STATUS_NO_ERROR == status) {
    status = RAIL_EnablePti(RAIL_EFR32_HANDLE, true);
  }

  return (uint8_t)status;
}
