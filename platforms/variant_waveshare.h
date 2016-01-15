#ifndef CUSTOM_BOARD_WAVESHARE_H
#define CUSTOM_BOARD_WAVESHARE_H

#define LEDS_NUMBER    5
#define LED_1          18
#define LED_2          19
#define LED_3          20
#define LED_4          21
#define LED_5          22
#define LEDS_LIST      { LED_1, LED_2, LED_3, LED_4, LED_5 }

#define BUTTONS_NUMBER 2
#define BUTTON_1       16
#define BUTTON_2       17
#define BUTTONS_LIST   { BUTTON_1, BUTTON_2 }

#define RX_PIN_NUMBER  11
#define TX_PIN_NUMBER  9
#define CTS_PIN_NUMBER 10
#define RTS_PIN_NUMBER 8
#define HWFC           true

#define PIN_SPI_SS     30
#define PIN_SPI_MOSI   24
#define PIN_SPI_MISO   23
#define PIN_SPI_SCK    25

#endif
