
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#if defined (  __GNUC__  ) /* GCC CS3 */
  #include <sys/types.h>
  #include <sys/stat.h>
#endif
#include <nrf.h>


extern int  __end__ ;

extern caddr_t _sbrk ( int incr )
{
    static unsigned char *heap = NULL ;
    unsigned char *prev_heap ;

    if ( heap == NULL )
    {
        heap = (unsigned char *)&__end__ ;
    }
    prev_heap = heap;

    heap += incr ;

    return (caddr_t) prev_heap ;
}

int _write(int file, const char* buf, int len)
{
    for(int i=0; i< len; ++i){
        NRF_UART0->EVENTS_TXDRDY = 0;
        NRF_UART0->TXD = buf[i];
        while(!NRF_UART0->EVENTS_TXDRDY) __NOP();
    }
    return len;
}

/**
 * SysTick hook
 *
 * This function is called from SysTick handler, before the default
 * handler provided by Arduino.
 */
static int __false() {
	// Return false
	return 0;
}
int sysTickHook(void) __attribute__ ((weak, alias("__false")));

/**
 * SVC hook
 * PendSV hook
 *
 * These functions are called from SVC handler, and PensSV handler.
 * Default action is halting.
 */
static void __halt() {
	// Halts
	while (1)
		;
}
void svcHook(void)    __attribute__ ((weak, alias("__halt")));
void pendSVHook(void) __attribute__ ((weak, alias("__halt")));

