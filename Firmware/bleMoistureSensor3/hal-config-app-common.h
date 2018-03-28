#ifndef HAL_CONFIG_APP_COMMON_H
#define HAL_CONFIG_APP_COMMON_H

#include "em_device.h"
#include "hal-config-types.h"

#if defined(FEATURE_IOEXPANDER)
#include "hal-config-ioexp.h"
#endif

#if defined(FEATURE_FEM)
#include "hal-config-fem.h"
#endif

#define HAL_EXTFLASH_FREQUENCY                        (1000000)

#define HAL_PA_ENABLE                                 (1)

#define HAL_PTI_ENABLE                                (1)
#define HAL_PTI_MODE                                  (HAL_PTI_MODE_UART)
#define HAL_PTI_BAUD_RATE                             (1600000)

#ifdef BSP_CLK_LFXO_CTUNE
#undef BSP_CLK_LFXO_CTUNE
#endif
#define BSP_CLK_LFXO_CTUNE                            (32)

#if (HAL_PA_ENABLE)
#define HAL_PA_RAMP                                   (10)
#define HAL_PA_2P4_LOWPOWER                           (0)
#define HAL_PA_POWER                                  (252)
#define HAL_PA_CURVE_HEADER                            "pa_curves_efr32.h"
#endif

#ifdef FEATURE_PA_HIGH_POWER
#define HAL_PA_VOLTAGE                                (3300)
#else // FEATURE_PA_HIGH_POWER
#define HAL_PA_VOLTAGE                                (1800)
#endif // FEATURE_PA_HIGH_POWER

#endif /* HAL_CONFIG_APP_COMMON_H */