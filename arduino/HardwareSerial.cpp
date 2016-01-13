
#include "HardwareSerial.h"

extern "C"{
#include <onix-serial.h>
}

void   HardwareSerial::begin(unsigned long baud){ onix_serial_init(0,baud); }
size_t HardwareSerial::write(uint8_t ch){         onix_serial_putchar(ch); return 1; }

HardwareSerial Serial;

