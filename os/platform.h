#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#define MAXNUM_CPU 8

/* This machine puts UART registers here in physical memory. */
#define UART0 0x10000000L
#define UART0_IRQ 1

/*
 * This machine puts platform-level interrupt controller (PLIC) here.
 * Here only list PLIC registers in Machine mode.
 * see https://github.com/qemu/qemu/blob/master/include/hw/riscv/virt.h
 * #define VIRT_PLIC_HART_CONFIG "MS"
 * #define VIRT_PLIC_NUM_SOURCES 127
 * #define VIRT_PLIC_NUM_PRIORITIES 7
 * #define VIRT_PLIC_PRIORITY_BASE 0x04
 * #define VIRT_PLIC_PENDING_BASE 0x1000
 * #define VIRT_PLIC_ENABLE_BASE 0x2000
 * #define VIRT_PLIC_ENABLE_STRIDE 0x80
 * #define VIRT_PLIC_CONTEXT_BASE 0x200000
 * #define VIRT_PLIC_CONTEXT_STRIDE 0x1000
 * #define VIRT_PLIC_SIZE(__num_context) \
 *     (VIRT_PLIC_CONTEXT_BASE + (__num_context) * VIRT_PLIC_CONTEXT_STRIDE)
 */
#define PLIC_BASE 0x30000000L
#define PLIC_PRIORITY(id) (PLIC_BASE + (id) * 4)
#define PLIC_PENDING(id) (PLIC_BASE + 0x1000 + ((id) / 32) * 4)
#define PLIC_MENABLE(hart) (PLIC_BASE + 0x2000)
#define PLIC_MTHRESHOLD(hart) (PLIC_BASE + 0x200000)
#define PLIC_MCLAIM(hart) (PLIC_BASE + 0x200004)
#define PLIC_MCOMPLETE(hart) (PLIC_BASE + 0x200004)

#define CLINT_BASE 0x4000000L
#define CLINT_MSIP(hartid) (CLINT_BASE)
#define CLINT_MTIMECMP(hartid) (CLINT_BASE + 0x4000)
#define CLINT_MTIME (CLINT_BASE + 0xBFF8) // cycles since boot.

/* 10000000 ticks per-second */
#define CLINT_TIMEBASE_FREQ 10000000

#endif /* __PLATFORM_H__ */
