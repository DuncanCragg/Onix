#ifndef _ONIX_TIME_
#define _ONIX_TIME_

#include <stdint.h>
#include <stdbool.h>

void     onix_time_init();
uint32_t onix_time_ms();
uint32_t onix_time_us();

#ifdef TARGET_LINUX

 #include <unistd.h>
 #include <time.h>

 #define onix_time_delay_s(m)  usleep(1000000 * (m))
 #define onix_time_delay_ms(m) usleep(   1000 * (m))
 #define onix_time_delay_us(m) usleep(          (m))

#else

void onix_time_delay_s( uint32_t s);
void onix_time_delay_ms(uint32_t ms);
void onix_time_delay_us(uint32_t us);

#endif

#endif
