#ifndef GECKO_CONFIGURATION
#define GECKO_CONFIGURATION

#include "bg_gattdb_def.h"

#define DEFAULT_BLUETOOTH_HEAP(CONNECTIONS) (4824 +(CONNECTIONS)*(436))

#define SLEEP_FLAGS_DEEP_SLEEP_ENABLE  4
typedef struct {
  uint8_t     flags;
}gecko_sleep_config_t;

typedef struct {
  uint8_t max_connections;  //!< Maximum number of connections to support, if 0 defaults to 4
  uint8_t max_advertisers;  //!< Maximum number of advertisers to support, if 0 defaults to 1
  //heap configuration, if NULL uses default
  void    *heap;
  uint16_t heap_size;
  uint16_t sleep_clock_accuracy;   // ppm, 0 = default (250 ppm)
  uint32_t linklayer_config;
  uint8_t * linklayer_priorities; //Priority configuration, if NULL uses default values
}gecko_bluetooth_config_t;

#define GECKO_RADIO_PA_INPUT_VBAT   0
#define GECKO_RADIO_PA_INPUT_DCDC   1

typedef struct {
  uint8_t config_enable;   // Non-zero value indicates this PA config is valid.
  uint8_t input;    // VBAT or DCDC
}gecko_radio_pa_config_t;

#define GECKO_OTA_FLAGS_RANDOM_ADDRESS      0x10000

typedef struct {
  uint32_t flags;
  uint8_t  device_name_len;
  char     *device_name_ptr;
}gecko_ota_config_t;

#define GECKO_MBEDTLS_FLAGS_NO_MBEDTLS_DEVICE_INIT      1
typedef struct {
  uint8_t flags;
  uint8_t dev_number;
}gecko_mbedtls_config_t;

#define GECKO_CONFIG_FLAG_USE_LAST_CTUNE               64 //Use ctune value from last_ctune ps-key
#define GECKO_CONFIG_FLAG_RTOS                         256
#define GECKO_CONFIG_FLAG_NO_SLEEPDRV_INIT             512

typedef void (*gecko_priority_schedule_callback)(void);
typedef void (*gecko_stack_schedule_callback)(void);

typedef struct {
  uint32_t config_flags;
  gecko_sleep_config_t  sleep;
  gecko_bluetooth_config_t bluetooth;
  //

  const struct bg_gattdb_def *gattdb;
  //Callback for priority scheduling, used for RTOS support. If NULL uses pendsv irq.
  //This is called from Interrupt context
  gecko_priority_schedule_callback scheduler_callback;

  //Callback for requesting Bluetooth stack scheduling, used for RTOS support
  //This is called from Interrupt context
  gecko_stack_schedule_callback stack_schedule_callback;

  gecko_radio_pa_config_t pa;

  gecko_ota_config_t ota;

  gecko_mbedtls_config_t mbedtls;
  uint8_t max_timers;  // Max number of soft timers, up to 16, the application will use through BGAPI. Default: 4
}gecko_configuration_t;

#endif