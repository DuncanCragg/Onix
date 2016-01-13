
#include <onix-time.h>

static bool initialised=false;

#ifdef TARGET_LINUX

uint64_t startus;

uint64_t get_time_us()
{
  struct timespec t;
  clock_gettime(CLOCK_REALTIME, &t);
  return t.tv_sec*1000000+t.tv_nsec/1000;
}

void onix_time_init()
{
  if(initialised) return;
  startus=get_time_us();
  initialised=true;
}

uint32_t onix_time_us()
{
  onix_time_init();
  return get_time_us()-startus;
}

uint32_t onix_time_ms()
{
  onix_time_init();
  return onix_time_us()/1000;
}


#else

#include <nrf51.h>
#include <nrf51_bitfields.h>

#define LFCLK_FREQUENCY    32768UL
#define TICK_HZ            1000

static void rtc_initialise() __attribute__((constructor));
static void rtc_initialise()
{
    NRF_CLOCK->LFCLKSRC            = (CLOCK_LFCLKSRC_SRC_Synth << CLOCK_LFCLKSRC_SRC_Pos);
    NRF_CLOCK->EVENTS_LFCLKSTARTED = 0;
    NRF_CLOCK->TASKS_LFCLKSTART    = 1;
    while(!NRF_CLOCK->EVENTS_LFCLKSTARTED);
    NRF_CLOCK->EVENTS_LFCLKSTARTED = 0;
    NVIC_EnableIRQ(RTC0_IRQn);
    NRF_RTC0->PRESCALER = (LFCLK_FREQUENCY / TICK_HZ) - 1;
    NRF_RTC0->EVTENSET = RTC_EVTENSET_TICK_Msk;
    NRF_RTC0->INTENSET = RTC_INTENSET_TICK_Msk;
    NRF_RTC0->TASKS_CLEAR = 1;
    NRF_RTC0->TASKS_START = 1;
}

void onix_time_init()
{
}

static volatile bool     done  = false;
static volatile uint64_t clock = 0;

void onix_time_delay_ms(uint32_t ms)
{
    NRF_RTC0->CC[0] = (ms * TICK_HZ) / 1000;
    NRF_RTC0->EVTENSET = RTC_EVTENSET_COMPARE0_Msk;
    NRF_RTC0->INTENSET = RTC_INTENSET_COMPARE0_Msk;
    done=false; while(!done) __WFE();
}

void RTC0_IRQHandler()
{
    if(NRF_RTC0->EVENTS_TICK && (NRF_RTC0->INTENSET & RTC_INTENSET_TICK_Msk))
    {
        NRF_RTC0->EVENTS_TICK = 0;
        clock++;
    }
    if(NRF_RTC0->EVENTS_COMPARE[0] && (NRF_RTC0->INTENSET & RTC_INTENSET_COMPARE0_Msk))
    {
        NRF_RTC0->EVENTS_COMPARE[0] = 0;
        NRF_RTC0->TASKS_CLEAR = 1;
        NRF_RTC0->TASKS_START = 1;
        done=true;
    }
}

uint32_t onix_time_ms(){ return clock; }

uint32_t onix_time_us(){ return clock*1000; }

void onix_time_delay_us(uint32_t us)
{
  while(us--) {
      __ASM(" NOP\n\t"
       " NOP\n\t"
       " NOP\n\t"
       " NOP\n\t"
       " NOP\n\t"
       " NOP\n\t"
       " NOP\n\t"
       " NOP\n\t"
       " NOP\n\t"
       " NOP\n\t"
       " NOP\n\t");
  };
}

void onix_time_delay_s( uint32_t s)
{
  onix_time_delay_ms(1000*s);
}

#endif
