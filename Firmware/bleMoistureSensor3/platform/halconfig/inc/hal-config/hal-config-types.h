#ifndef HAL_CONFIG_TYPES_H
#define HAL_CONFIG_TYPES_H

#include "em_gpio.h"

#define HAL_CLK_HFCLK_SOURCE_HFRCO      1
#define HAL_CLK_HFCLK_SOURCE_HFXO       2

#define HAL_CLK_LFCLK_SOURCE_DISABLED   0
#define HAL_CLK_LFCLK_SOURCE_LFRCO      1
#define HAL_CLK_LFCLK_SOURCE_LFXO       2
#define HAL_CLK_LFCLK_SOURCE_ULFRCO     3
#define HAL_CLK_LFCLK_SOURCE_HFLE       4

#define HAL_CLK_HFXO_AUTOSTART_NONE     0
#define HAL_CLK_HFXO_AUTOSTART_START    1
#define HAL_CLK_HFXO_AUTOSTART_SELECT   2

#define HAL_DISPLAY_SHARP_LS013B7DH03   1
#define HAL_DISPLAY_SHARP_LS013B7DH06   2

#define HAL_EMU_EM23_VSCALE_FASTWAKEUP  1
#define HAL_EMU_EM23_VSCALE_LOWPOWER    2

#define HAL_GPIO_DOUT_LOW               0
#define HAL_GPIO_DOUT_HIGH              1

#define HAL_GPIO_MODE_INPUT               gpioModeInput
#define HAL_GPIO_MODE_INPUT_PULL          gpioModeInputPull
#define HAL_GPIO_MODE_INPUT_PULL_FILTER   gpioModeInputPullFilter

#define HAL_I2C_PORT_I2C0          	  0x40
#define HAL_I2C_PORT_I2C1          	  0x41
#define HAL_I2C_PORT_I2C2          	  0x42
#define HAL_I2C_PORT_I2C3          	  0x43

#define HAL_LEUART_FLOW_CONTROL_NONE    0
#define HAL_LEUART_FLOW_CONTROL_SW      1
#define HAL_LEUART_FLOW_CONTROL_HW      2
#define HAL_LEUART_FLOW_CONTROL_HWUART  3

#define HAL_PTI_MODE_SPI                1
#define HAL_PTI_MODE_UART               2
#define HAL_PTI_MODE_UART_ONEWIRE       3

#define HAL_SERIAL_PORT_VUART         0x10
#define HAL_SERIAL_PORT_USART0        0x20
#define HAL_SERIAL_PORT_USART1        0x21
#define HAL_SERIAL_PORT_USART2        0x22
#define HAL_SERIAL_PORT_USART3        0x23
#define HAL_SERIAL_PORT_USART4        0x24
#define HAL_SERIAL_PORT_USART5        0x25
#define HAL_SERIAL_PORT_UART0         0x30
#define HAL_SERIAL_PORT_UART1         0x31
#define HAL_SERIAL_PORT_LEUART0       0x40
#define HAL_SERIAL_PORT_LEUART1       0x41

#define HAL_SPI_PORT_USART0           0x20
#define HAL_SPI_PORT_USART1           0x21
#define HAL_SPI_PORT_USART2           0x22
#define HAL_SPI_PORT_USART3           0x23
#define HAL_SPI_PORT_USART4           0x24
#define HAL_SPI_PORT_USART5           0x25

#define HAL_UART_FLOW_CONTROL_NONE      0
#define HAL_UART_FLOW_CONTROL_SW        1
#define HAL_UART_FLOW_CONTROL_HW        2
#define HAL_UART_FLOW_CONTROL_HWUART    3

#define HAL_USART_FLOW_CONTROL_NONE     0
#define HAL_USART_FLOW_CONTROL_SW       1
#define HAL_USART_FLOW_CONTROL_HW       2
#define HAL_USART_FLOW_CONTROL_HWUART   3

#endif // HAL_CONFIG_TYPES_H
