#ifndef RBL_NANO_BOARD_H
#define RBL_NANO_BOARD_H

#define LEDS_NUMBER    1
#define LED_1          19
#define LEDS_LIST      { LED_1 }

#define BUTTONS_NUMBER 1
#define BUTTON_1       29
#define BUTTONS_LIST   { BUTTON_1 }

#define RX_PIN_NUMBER  11
#define TX_PIN_NUMBER  9
#define CTS_PIN_NUMBER 10
#define RTS_PIN_NUMBER 8
#define HWFC           true

#define PIN_SPI_SS     10
#define PIN_SPI_MOSI   9
#define PIN_SPI_MISO   11
#define PIN_SPI_SCK    8

#define PIN_WIRE_SDA   10
#define PIN_WIRE_SCL   8

#endif
