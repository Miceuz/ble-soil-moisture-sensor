/***************************************************************************//**
 * @file init_mcu.c
 *******************************************************************************
 * # License
 * <b>Copyright 2017 Silicon Labs, Inc. http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#if defined(HAL_CONFIG)
#include "bsphalconfig.h"
#include "hal-config.h"
#else
#include "bspconfig.h"
#endif

#include "board_features.h"

#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_rtcc.h"

#include "bsp.h"

#include "tempdrv.h"

static void initMcu_clocks(void);

void initMcu(void)
{
  // Device errata
  CHIP_Init();

  // Set up DC-DC converter
  EMU_DCDCInit_TypeDef dcdcInit = BSP_DCDC_INIT;
  #if HAL_DCDC_BYPASS
  dcdcInit.dcdcMode = emuDcdcMode_Bypass;
  #endif
  EMU_DCDCInit(&dcdcInit);

  // Set up clocks
  initMcu_clocks();

  RTCC_Init_TypeDef rtccInit = RTCC_INIT_DEFAULT;
  rtccInit.enable                = true;
  rtccInit.debugRun              = false;
  rtccInit.precntWrapOnCCV0      = false;
  rtccInit.cntWrapOnCCV1         = false;
  rtccInit.prescMode             = rtccCntTickPresc;
  rtccInit.presc                 = rtccCntPresc_1;
  rtccInit.enaOSCFailDetect      = false;
  rtccInit.cntMode               = rtccCntModeNormal;
  RTCC_Init(&rtccInit);

#if defined(_EMU_CMD_EM01VSCALE0_MASK)
  // Set up EM0, EM1 energy mode configuration
  EMU_EM01Init_TypeDef em01Init = EMU_EM01INIT_DEFAULT;
  EMU_EM01Init(&em01Init);
#endif // _EMU_CMD_EM01VSCALE0_MASK

#if defined(_EMU_CTRL_EM23VSCALE_MASK)
  // Set up EM2, EM3 energy mode configuration
  EMU_EM23Init_TypeDef em23init = EMU_EM23INIT_DEFAULT;
  em23init.vScaleEM23Voltage = emuVScaleEM23_LowPower;
  EMU_EM23Init(&em23init);
#endif //_EMU_CTRL_EM23VSCALE_MASK

  TEMPDRV_Init();
}

static void initMcu_clocks(void)
{
  // Initialize HFXO
  CMU_HFXOInit_TypeDef hfxoInit = BSP_CLK_HFXO_INIT;
#if defined(BSP_CLK_HFXO_CTUNE) && BSP_CLK_HFXO_CTUNE > -1
  hfxoInit.ctuneStartup = BSP_CLK_HFXO_CTUNE;
  hfxoInit.ctuneSteadyState = BSP_CLK_HFXO_CTUNE;
#endif
  CMU_HFXOInit(&hfxoInit);

  // Set system HFXO frequency
  SystemHFXOClockSet(BSP_CLK_HFXO_FREQ);

  // Enable HFXO oscillator, and wait for it to be stable
  CMU_OscillatorEnable(cmuOsc_HFXO, true, true);

  // Automatically start and select HFXO
  CMU_HFXOAutostartEnable(0, true, true);

  // HFRCO not needed when using HFXO
  CMU_OscillatorEnable(cmuOsc_HFRCO, false, false);

  // Enabling HFBUSCLKLE clock for LE peripherals
  CMU_ClockEnable(cmuClock_HFLE, true);

  // Initialize LFXO
  CMU_LFXOInit_TypeDef lfxoInit = BSP_CLK_LFXO_INIT;
  lfxoInit.ctune = BSP_CLK_LFXO_CTUNE;
  CMU_LFXOInit(&lfxoInit);

  // Set system LFXO frequency
  SystemLFXOClockSet(BSP_CLK_LFXO_FREQ);

  // Set LFXO if selected as LFCLK
  CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
  CMU_ClockSelectSet(cmuClock_LFB, cmuSelect_LFXO);
  CMU_ClockSelectSet(cmuClock_LFE, cmuSelect_LFXO);
}