/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

void pinMode(     uint32_t pin, uint32_t mode) {        onix_gpio_mode(pin, mode); }
int  digitalRead( uint32_t pin)                { return onix_gpio_get( pin); }
void digitalWrite(uint32_t pin, uint32_t value){        onix_gpio_set( pin, value); }

#ifdef __cplusplus
}
#endif
