#ifndef ONIX_SERIAL_H
#define ONIX_SERIAL_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef void (*uart_rx_handler_t) (uint8_t byte);

void onix_serial_init(uart_rx_handler_t p_rx_handler, uint32_t baudrate);
void onix_serial_cb(uart_rx_handler_t p_rx_handler);
void onix_serial_putchar(uint32_t ch);
int  onix_serial_printf(const char* fmt, ...);
int  onix_serial_printF(const char* fmt, ...);

#endif
