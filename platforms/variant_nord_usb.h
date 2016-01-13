#ifndef CUSTOM_BOARD_NORD_USB_H
#define CUSTOM_BOARD_NORD_USB_H

#define LEDS_NUMBER    3

#define LED_1          21
#define LED_2          22
#define LED_3          23

#define LED_RGB_RED    21
#define LED_RGB_GREEN  22
#define LED_RGB_BLUE   23

#define LEDS_LIST { LED_RGB_RED, LED_RGB_GREEN, LED_RGB_BLUE }

#define BUTTONS_NUMBER 0
#define BUTTONS_LIST {}

#define RX_PIN_NUMBER  11
#define TX_PIN_NUMBER  9
#define CTS_PIN_NUMBER 10
#define RTS_PIN_NUMBER 8
#define HWFC           true

#define PIN_SPI_SS     15
#define PIN_SPI_MOSI   16
#define PIN_SPI_MISO   17
#define PIN_SPI_SCK    18

#endif
