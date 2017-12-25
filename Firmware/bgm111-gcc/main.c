#ifndef GENERATION_DONE
#error You must run generate first!
#endif

/* Board Headers */
#include "boards.h"
#include "ble-configuration.h"
#include "board_features.h"

/* Bluetooth stack headers */
#include "bg_types.h"
#include "native_gecko.h"
#include "bg_dfu.h"
#include "aat.h"
#include "infrastructure.h"

/* GATT database */
#include "gatt_db.h"

/* EM library (EMlib) */
#include "em_system.h"
#include "em_rtcc.h"

/* Libraries containing default Gecko configuration values */
#include "em_adc.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_timer.h"
#include "em_int.h"

#include "bsp_trace.h"

#include "em_usart.h"
#include <stdio.h>

#ifdef FEATURE_BOARD_DETECTED
#include "bspconfig.h"
#include "pti.h"
#else
#error This sample app only works with a Silicon Labs Board
#endif

/* Device initialization header */
#include "InitDevice.h"

/* Gecko configuration parameters (see gecko_configuration.h) */
#ifndef MAX_CONNECTIONS
#define MAX_CONNECTIONS 4
#endif
uint8_t bluetooth_stack_heap[DEFAULT_BLUETOOTH_HEAP(MAX_CONNECTIONS)];

//#ifdef FEATURE_PTI_SUPPORT
//static const RADIO_PTIInit_t ptiInit = RADIO_PTI_INIT;
//#endif

static const gecko_configuration_t config = { .config_flags = 0, .sleep.flags =
		SLEEP_FLAGS_DEEP_SLEEP_ENABLE, .bluetooth.max_connections =
		MAX_CONNECTIONS, .bluetooth.heap = bluetooth_stack_heap,
		.bluetooth.heap_size = sizeof(bluetooth_stack_heap), .gattdb =
				&bg_gattdb_data,
//  .ota.flags=0,
//  .ota.device_name_len=3,
//  .ota.device_name_ptr="OTA",
#ifdef FEATURE_PTI_SUPPORT
//  .pti = &ptiInit,
#endif
		};


/*
 * Performs ADC measurement and returns battery level in V * 100,
 * i.e. 3.7V will be returned as 370
 */
uint32_t measureBatteryVoltage() {
	return 420;
}

uint8 getBatteryLevel() {
	/*
	 * Allowed battery level range is 320 - 420, convienently 420 - 320 = 100
	 * @return battery level in percent
	 */
	return measureBatteryVoltage() - 320;
}

uint8 hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void toHexBuf(uint64_t uuid, uint8 *ret) {
	uint8 i,j = 0;
	for(i = 0; i < 4; i++) {
		uint8 b = (uuid >> (3 - i)) & 0xFF;
		ret[j++] = hex[b / 16];
		ret[j++] = hex[b % 16];
	}
}

uint64_t uuid;

void updateAdvertisingPacket() {
	uint8 advertisingPacket[27]={
			15, //struct length
			0x09, //type - Complete Local Name
			'H',
			'e',
			'l',
			'l',
			'o',
			'-',
			' ',
			' ',
			' ',
			' ',
			' ',
			' ',
			' ',
			' '
};

	toHexBuf(uuid, &(advertisingPacket[8]));

	gecko_cmd_le_gap_set_adv_data(0, 27, advertisingPacket);
	gecko_cmd_le_gap_set_adv_data(1, 27, advertisingPacket);
}

static inline void bleStartAdvertising() {

	/* Set advertising parameters. 100ms advertisement interval. All channels used.
	 * The first two parameters are minimum and maximum advertising interval, both in
	 * units of (milliseconds * 1.6). The third parameter '7' sets advertising on all channels. */
	gecko_cmd_le_gap_set_adv_parameters(1600*4, 1600*4, 7);
	/* Start general advertising and enable connections. */
	gecko_cmd_le_gap_set_mode(le_gap_general_discoverable,	le_gap_undirected_connectable);
	updateAdvertisingPacket();
}

int isCharacteristic(int characteristicId, struct gecko_cmd_packet* evt) {
	return (evt->data.evt_gatt_server_characteristic_status.characteristic
			== characteristicId);
}

/* This event is generated when a connected client has either
 * 1) changed a Characteristic Client Configuration, meaning that they have enabled
 * or disabled Notifications or Indications, or
 * 2) sent a confirmation upon a successful reception of the indication. */
/* Check that the characteristic in question is temperature - its ID is defined
 * in gatt.xml as "temp_measurement". Also check that status_flags = 1, meaning that
 * the characteristic client configuration was changed (notifications or indications
 * enabled or disabled). */
int isCharacteristicClientConfigChanged(int characteristicId, struct gecko_cmd_packet* evt) {
	return isCharacteristic(characteristicId, evt) &&
		   (evt->data.evt_gatt_server_characteristic_status.status_flags == 0x01);
}

int isNotificationOn(struct gecko_cmd_packet* evt) {
	return 0 != (evt->data.evt_gatt_server_characteristic_status.client_config_flags
				 & 0x01);
}

int main() {
	enter_DefaultMode_from_RESET();
	/* Initialize stack */
	gecko_init(&config);

	BSP_TraceProfilerSetup();

	struct gecko_cmd_packet* evt;
	uuid = SYSTEM_GetUnique();

	while (1) {

		evt = gecko_wait_event();

		switch (BGLIB_MSG_ID(evt->header)) {
		case gecko_evt_system_boot_id:

			gecko_cmd_system_set_tx_power(0);
			bleStartAdvertising();

			break;

		case gecko_evt_gatt_server_characteristic_status_id:

//			if (isCharacteristicClientConfigChanged(gattdb_battery_voltage, evt)) {
//				if (isNotificationOn(evt)) {
//					gecko_cmd_hardware_set_soft_timer(32768, 0, 0);
//				} else {
//					/* Indications have been turned OFF - stop the timer. */
//					gecko_cmd_hardware_set_soft_timer(0, 0, 0);
//				}
//			}
			break;

		case gecko_evt_gatt_server_user_read_request_id:

			if (isCharacteristic(gattdb_battery_level, evt)) {
				uint8 batteryLevel = getBatteryLevel();
				gecko_cmd_gatt_server_send_user_read_response(
						evt->data.evt_gatt_server_user_read_request.connection,
						evt->data.evt_gatt_server_user_read_request.characteristic,
						0, 1, &batteryLevel);
			} else if (isCharacteristic(gattdb_battery_voltage, evt)) {
				uint32 batteryVoltage = measureBatteryVoltage();
				gecko_cmd_gatt_server_send_user_read_response(
						evt->data.evt_gatt_server_user_read_request.connection,
						evt->data.evt_gatt_server_user_read_request.characteristic,
						0, 2, (uint8*)&batteryVoltage);
			}
			break;

		case gecko_evt_gatt_server_user_write_request_id:

			if (isCharacteristic(gattdb_reset, evt)) {
				gecko_cmd_system_reset(0);
			} else 	if (isCharacteristic(gattdb_disconnect, evt)) {
				gecko_cmd_endpoint_close(evt->data.evt_gatt_server_user_write_request.connection);
			}
			break;

		case gecko_evt_le_connection_opened_id:

			gecko_cmd_le_connection_set_parameters(evt->data.evt_le_connection_opened.connection, 50, 100, 0, 300);
			break;

		case gecko_evt_le_connection_closed_id:

			/* Restart advertising after client has disconnected */
			bleStartAdvertising();
			break;

		case gecko_evt_hardware_soft_timer_id:

			updateAdvertisingPacket();

			break;

		default:
			break;
		}
	}
	gecko_sleep_for_ms(gecko_can_sleep_ms());
	return 0;
}
