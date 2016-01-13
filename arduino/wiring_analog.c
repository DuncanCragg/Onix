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

#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

static int _readResolution = 10;
static int _writeResolution = 8;

void analogReadResolution(int res) {
  _readResolution = res;
}

void analogWriteResolution(int res) {
  _writeResolution = res;
}

static inline uint32_t mapResolution(uint32_t value, uint32_t from, uint32_t to) {
  if (from == to)
    return value;
  if (from > to)
    return value >> (from-to);
  else
    return value << (to-from);
}

eAnalogReference analog_reference = AR_DEFAULT;

void analogReference(eAnalogReference ulMode)
{
  analog_reference = ulMode;
}

uint32_t analogRead(uint32_t ulPin)
{
  uint32_t ulValue = 0;
  return ulValue;
}

void analogOutputInit(void) {
}

void analogWrite(uint32_t ulPin, uint32_t ulValue) {

  // Defaults to digital write
  pinMode(ulPin, OUTPUT);
  ulValue = mapResolution(ulValue, _writeResolution, 8);
  if (ulValue < 128)
    digitalWrite(ulPin, LOW);
  else
    digitalWrite(ulPin, HIGH);
}

#ifdef __cplusplus
}
#endif
