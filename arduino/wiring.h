/*
  Copyright (c) 2011 Arduino.  All right reserved.
  Copyright (c) 2013 by Paul Stoffregen <paul@pjrc.com> (delayMicroseconds)

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
#ifndef _WIRING_
#define _WIRING_

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

#include <onix-time.h>

#ifdef __cplusplus
}
#endif

#define delay(ms)             onix_time_delay_ms(ms)
#define delayMicroseconds(us) onix_time_delay_us(us)
#define millis()              onix_time_ms()
#define micros()              onix_time_us()

#endif /* _WIRING_ */
