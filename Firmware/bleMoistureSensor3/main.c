//#ifndef GENERATION_DONE
//#error You must run generate first!
//#endif

/* Board Headers */
//#include "boards.h"
#include "ble-configuration.h"
#include "board_features.h"

/* Bluetooth stack headers */
#include "bg_types.h"
#include "native_gecko.h"
//#include "bg_dfu.h"
//#include "aat.h"
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

//#include "bsp_trace.h"

#include "em_usart.h"
#include <stdio.h>

//#ifdef FEATURE_BOARD_DETECTED
//#include "bspconfig.h"
//#include "pti.h"
//#else
//#error This sample app only works with a Silicon Labs Board
//#endif

/* Device initialization header */
#include "InitDevice.h"

#include "thermistor.h"

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



#define BATTERY_SENSE_ENABLE BATTERY_SENSE_ENABLE_PORT, BATTERY_SENSE_ENABLE_PIN
#define PERIPHERAL_POWER_ENABLE PERIPHERAL_POWER_ENABLE_PORT, PERIPHERAL_POWER_ENABLE_PIN
#define EXCITATION EXCITATION_PORT, EXCITATION_PIN
#define LED_CATHODE LED_CATHODE_PORT, LED_CATHODE_PIN
#define LED_ANODE LED_ANODE_PORT, LED_ANODE_PIN

#define ADC_CHANNEL_BATTERY adcPosSelAPORT4XCH13      /*PA5*/
#define ADC_CHANNEL_MOISTURE_HIGH adcPosSelAPORT2XCH7 /*PC7*/
#define ADC_CHANNEL_MOISTURE_LOW adcPosSelAPORT1XCH8  /*PC8*/
#define ADC_CHANNEL_TEMPERATURE adcPosSelAPORT2XCH9   /*PC9*/

#define ADVERTISING_MOISTURE_ID 0x01
#define ADVERTISING_TEMPERATURE_ID 0x02
#define ADVERTISING_BATT_VOLTAGE_ID 0x03

uint64_t uuid = 0;
volatile uint16 moisture = 0;
volatile uint16 temperature = 0;
volatile uint16 batteryVoltage = 0;

inline static void batterySenseOn() {
	GPIO_PinOutSet(BATTERY_SENSE_ENABLE);
}

inline static void batterySenseOff() {
	GPIO_PinOutClear(BATTERY_SENSE_ENABLE);
}

void lightSleepForTicks(uint32 ticks) {
	RTCC_IntClear(RTCC_IEN_CC0);
	RTCC_ChannelCCVSet(0, RTCC_CounterGet() + ticks);
	RTCC_IntEnable(RTCC_IEN_CC0);
	EMU_EnterEM1();
	RTCC_IntDisable(RTCC_IEN_CC0);
}

void adcSetChannel(ADC_PosSel_TypeDef channel, ADC_Res_TypeDef reference) {
	ADC_InitSingle_TypeDef ADC0_init_single = ADC_INITSINGLE_DEFAULT;

	/* PRS settings */
	ADC0_init_single.prsEnable = 0;
	ADC0_init_single.prsSel = adcPRSSELCh0;
	/* Input(s) */
	ADC0_init_single.diff = 0;
	ADC0_init_single.posSel = channel;//adcPosSelAPORT1YCH7
	ADC0_init_single.negSel = adcNegSelVSS;
	ADC0_init_single.reference = reference;//adcRef2V5;//adcRefVDD;//
	/* Generic conversion settings */
	ADC0_init_single.acqTime = adcAcqTime16;
	ADC0_init_single.resolution = adcRes12Bit;
	ADC0_init_single.leftAdjust = 0;
	ADC0_init_single.rep = 0;
	ADC0_init_single.singleDmaEm2Wu = 0;
	ADC0_init_single.fifoOverwrite = 0;

	ADC_InitSingle(ADC0, &ADC0_init_single);
}

uint32 adcMeasureChannel(ADC_PosSel_TypeDef channel, ADC_Res_TypeDef reference) {
	adcSetChannel(channel, reference);
	ADC_Start(ADC0, adcStartSingle);
	while (ADC0->STATUS & ADC_STATUS_SINGLEACT){
		//WAIT
		//TODO sleep here
	}

	return ADC_DataSingleGet(ADC0);
}


/*
 * Performs ADC measurement and returns battery level in V * 100,
 * i.e. 3.7V will be returned as 370
 */
uint32_t measureBatteryVoltage() {
	batterySenseOn();

	lightSleepForTicks(1); //wait for voltage to stabilize
	lightSleepForTicks(70); //wait for voltage to stabilize

//	gecko_sleep_for_ms(gecko_can_sleep_ms());
//	gecko_sleep_for_ms(gecko_can_sleep_ms());

	uint32 adcVal = adcMeasureChannel(ADC_CHANNEL_BATTERY, adcRefVDD);

	batterySenseOff();

	return adcVal * 250 * 2 / 4095;
}

uint8 getBatteryLevel() {
	/*
	 * Allowed battery level range is 320 - 420, convienently 420 - 320 = 100
	 * @return battery level in percent
	 */
	return measureBatteryVoltage() - 320;
}

int isBatteryLow() {
	return measureBatteryVoltage() <= 320;
}

int batteryLowFlag = 0;

int _write(int file, const char *ptr, int len) {
	int x;
	for (x = 0; x < len; x++) {
		USART_Tx(USART0, *ptr++);
	}

	return (len);
}

void lightSleepSetup() {
	RTCC_CCChConf_TypeDef rtccChConf = RTCC_CH_INIT_COMPARE_DEFAULT;
	rtccChConf.chMode = rtccCapComChModeCompare;
	rtccChConf.compBase = rtccCompBaseCnt;
	rtccChConf.compMask = 0;
	rtccChConf.compMatchOutAction = rtccCompMatchOutActionPulse;
	rtccChConf.dayCompMode = rtccDayCompareModeMonth;
	rtccChConf.inputEdgeSel = rtccInEdgeNone;
	rtccChConf.prsSel = rtccPRSCh0;

	RTCC_ChannelInit(0, &rtccChConf);
}

inline static void sensingPowerOn() {
	GPIO_PinOutClear(PERIPHERAL_POWER_ENABLE);
}

inline static void sensingPowerOff() {
	GPIO_PinOutSet(PERIPHERAL_POWER_ENABLE);
}

inline static void capSensExcitationStart() {
	GPIO_PinModeSet(EXCITATION, gpioModePushPull, 0);
	TIMER_TopSet(TIMER0, 0);
	TIMER_CompareSet(TIMER0, 0, 0);
	TIMER_Enable(TIMER0, true);
}

inline static void capSensExcitationStop() {
	TIMER_Enable(TIMER0, false);
	GPIO_PinOutClear(EXCITATION);
	GPIO_PinModeSet(EXCITATION, gpioModeDisabled, 0);
}

uint32 measureMoisture() {
	uint32 high = adcMeasureChannel(ADC_CHANNEL_MOISTURE_HIGH, adcRefVDD);
	high = adcMeasureChannel(ADC_CHANNEL_MOISTURE_HIGH, adcRefVDD);
	//lightSleepForTicks(1); //wait for voltage to stabilize
	uint32 low = adcMeasureChannel(ADC_CHANNEL_MOISTURE_LOW, adcRefVDD);
	low = adcMeasureChannel(ADC_CHANNEL_MOISTURE_LOW, adcRefVDD);
	return 4095 - (low - high);
}

uint32 measureTemperature() {
	uint32 tempLsb = adcMeasureChannel(ADC_CHANNEL_TEMPERATURE, adcRefVDD);
	return thermistorLsbToTemperature(tempLsb >> 2);
}

void performMeasurements() {
	sensingPowerOn();
	capSensExcitationStart();
	lightSleepSetup();
	lightSleepForTicks(1); //wait for voltage to stabilize
	lightSleepForTicks(60); //wait for voltage to stabilize

	moisture = measureMoisture();

	capSensExcitationStop();

	temperature = measureTemperature();

	sensingPowerOff();

	batteryVoltage = measureBatteryVoltage();
}

int main3() {
	enter_DefaultMode_from_RESET();
	gecko_init(&config);

	capSensExcitationStart();
	lightSleepSetup();

	while(1) {
		//measureBatteryVoltage();
		int i;
		for(i = 0; i < 2000000; i++) {

		}

		lightSleepForTicks(32768);
		//gecko_sleep_for_ms(100);
	}
}

int main2() {
	enter_DefaultMode_from_RESET();
	gecko_init(&config);

	GPIO_PinModeSet(gpioPortC, 10, gpioModePushPull, 0);

	/* Pin PC11 is configured to Push-pull */
	GPIO_PinModeSet(gpioPortC, 11, gpioModePushPull, 0);

	GPIO_PinOutClear(LED_CATHODE);
	GPIO_PinOutClear(LED_ANODE);

	while (1) {
		GPIO_PinOutSet(LED_ANODE);

		gecko_sleep_for_ms(1000);

		GPIO_PinOutClear(LED_ANODE);

		gecko_sleep_for_ms(1000);
	}
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

void updateAdvertisingPacket() {
	uint8 advertisingPacket[27]={
			15, //struct length
			0x09, //type - Complete Local Name
			'C',
			'h',
			'i',
			'r',
			'p',
			'-',
			' ',
			' ',
			' ',
			' ',
			' ',
			' ',
			' ',
			' ',
			10,
			0xFF,
			ADVERTISING_MOISTURE_ID,
			(moisture >> 8) & 0xFF,
			moisture & 0xFF,
			ADVERTISING_TEMPERATURE_ID,
			(temperature >> 8) & 0xFF,
			temperature & 0xFF,
			ADVERTISING_BATT_VOLTAGE_ID,
			(batteryVoltage >> 8) & 0xFF,
			batteryVoltage & 0xFF
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

#define TIMER_DATA_UPDATE 0

int main() {
	/* Initialize peripherals */
	enter_DefaultMode_from_RESET();

	batterySenseOff();
	sensingPowerOff();

	/* Initialize stack */
	gecko_init(&config);

//	BSP_TraceProfilerSetup();

	GPIO_PinOutClear(LED_CATHODE);
	GPIO_PinOutSet(LED_ANODE);

	gecko_sleep_for_ms(100);

	GPIO_PinOutClear(LED_ANODE);

	//		printf("Hello Hello! \n");

	struct gecko_cmd_packet* evt;

	uuid = SYSTEM_GetUnique();

	performMeasurements();

	int bootToDFU = false;

	while (1) {

//		if(isBatteryLow()) {
//			batteryLowFlag = 1;
//			ledPowerOff();
//			dcdcPowerOff();
//			clearLeds();
//		}

		evt = gecko_wait_event();

		switch (BGLIB_MSG_ID(evt->header)) {

		case gecko_evt_system_boot_id:

			gecko_cmd_system_set_tx_power(0);
			bleStartAdvertising();
	        gecko_cmd_hardware_set_soft_timer(32768*10, TIMER_DATA_UPDATE, 0);

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
			} else if (isCharacteristic(gattdb_soil_moisture, evt)) {
				uint32 moisture = measureMoisture();
				gecko_cmd_gatt_server_send_user_read_response(
						evt->data.evt_gatt_server_user_read_request.connection,
						evt->data.evt_gatt_server_user_read_request.characteristic,
						0, 2, (uint8*)&moisture);
			} else if (isCharacteristic(gattdb_temperature, evt)) {
				uint32 temp = measureTemperature();
				gecko_cmd_gatt_server_send_user_read_response(
						evt->data.evt_gatt_server_user_read_request.connection,
						evt->data.evt_gatt_server_user_read_request.characteristic,
						0, 2, (uint8*)&temp);
			} else if (isCharacteristic(gattdb_battery_low, evt)) {
				uint8 batteryLow = batteryLowFlag;
				gecko_cmd_gatt_server_send_user_read_response(
						evt->data.evt_gatt_server_user_read_request.connection,
						evt->data.evt_gatt_server_user_read_request.characteristic,
						0, 1, &batteryLow);
			}
			break;

		case gecko_evt_gatt_server_user_write_request_id:

			if (isCharacteristic(gattdb_reset, evt)) {
				gecko_cmd_system_reset(0);
			} else 	if (isCharacteristic(gattdb_disconnect, evt)) {
				gecko_cmd_endpoint_close(evt->data.evt_gatt_server_user_write_request.connection);
			} else if (isCharacteristic(gattdb_ota_control, evt)) {
				bootToDFU = 1;
				gecko_cmd_gatt_server_send_user_write_response(
									evt->data.evt_gatt_server_user_write_request.connection,
									gattdb_ota_control,
									bg_err_success);
			}
			break;

		case gecko_evt_le_connection_opened_id:

			gecko_cmd_le_connection_set_parameters(evt->data.evt_le_connection_opened.connection, 50, 100, 0, 300);
			break;

		case gecko_evt_le_connection_closed_id:
			if (bootToDFU) {
	          /* Enter to DFU OTA mode */
	          gecko_cmd_system_reset(2);
	        }
			/* Restart advertising after client has disconnected */
			bleStartAdvertising();
			break;

		case gecko_evt_hardware_soft_timer_id:

			performMeasurements();
			updateAdvertisingPacket();

			break;

		default:
			break;
		}
	}
	gecko_sleep_for_ms(gecko_can_sleep_ms());
	return 0;
}
