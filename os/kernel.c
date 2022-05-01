#include "os.h"

/*
 * Following functions SHOULD be called ONLY ONE time here,
 * so just declared here ONCE and NOT included in file os.h.
 */
extern void uart_init(void);
extern void page_init(void);
extern void sched_init(void);
extern void schedule(void);
extern void os_main(void);
extern void trap_init(void);
extern void plic_init(void);
extern void timer_init(void);

void start_kernel(void)
{
	uart_init();
	uart_puts("               vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
	uart_puts("                   vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrr       vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrrrr       vvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrrrrrr     vvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrrrrrr     vvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrrrrrr     vvvvvvvvvvvvvvvvvvvvvvvvvvv  \n");
	uart_puts("rrrrrrrrrrrrrrrrr      vvvvvvvvvvvvvvvvvvvvvvvvvv    \n");
	uart_puts("rrrrrrrrrrrrrrr      vvvvvvvvvvvvvvvvvvvvvvvvvv      \n");
	uart_puts("rr                 vvvvvvvvvvvvvvvvvvvvvvvvvv      vv\n");
	uart_puts("rr             vvvvvvvvvvvvvvvvvvvvvvvvvvvv      vvvv\n");
	uart_puts("rrrrr      vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv      vvvvvv\n");
	uart_puts("rrrrrrr      vvvvvvvvvvvvvvvvvvvvvvvvvv      vvvvvvvv\n");
	uart_puts("rrrrrrrrr      vvvvvvvvvvvvvvvvvvvvvv      vvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrr      vvvvvvvvvvvvvvvvvv      vvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrr      vvvvvvvvvvvvvv      vvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrr      vvvvvvvvvv      vvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrrrr      vvvvvv      vvvvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrrrrrr      vv      vvvvvvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrrrrrrrr          vvvvvvvvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrrrrrrrrrr      vvvvvvvvvvvvvvvvvvvvvvvv\n");
	uart_puts("rrrrrrrrrrrrrrrrrrrrrrrrr  vvvvvvvvvvvvvvvvvvvvvvvvvv\n\n");
	uart_puts("*********************\n");
	uart_puts("* Welcome to Falco! *\n");
	uart_puts("*********************\n");

	page_init();

	trap_init();

	plic_init();

	timer_init();

	sched_init();

	os_main();

	schedule();

	uart_puts("Would not go here!\n");
	while (1) {}; // stop here!
}

