#ifndef ONIX_GPIO_H
#define ONIX_GPIO_H

#include <stdint.h>

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define INPUT_PULLDOWN 0x4
#define HIGH 0x1
#define LOW  0x0

void onix_gpio_mode(  uint32_t pin, uint32_t mode);
int  onix_gpio_get(   uint32_t pin);
void onix_gpio_set(   uint32_t pin, uint32_t value);
void onix_gpio_toggle(uint32_t pin);

#endif
