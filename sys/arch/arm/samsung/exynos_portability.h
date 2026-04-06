#ifndef _EXYNOS_PORTABILITY_H_
#define _EXYNOS_PORTABILITY_H_

#include <sys/param.h>
#include <sys/types.h>

#if defined(__aarch64__)
#include <sys/bus.h>

extern struct bus_space arm_generic_bs_tag;
#define armv7_generic_bs_tag arm_generic_bs_tag

/* These are the real functions we defined in exynos_aarch64_glue.c */
extern uint32_t aarch64_bus_space_read_4(bus_space_tag_t, bus_space_handle_t, bus_size_t);
extern void aarch64_bus_space_write_4(bus_space_tag_t, bus_space_handle_t, bus_size_t, uint32_t);

#undef bus_space_read_4
#define bus_space_read_4(t, h, o)      \
    ((void)(t), aarch64_bus_space_read_4(&arm_generic_bs_tag, (h), (o)))

#undef bus_space_write_4
#define bus_space_write_4(t, h, o, v)  \
    ((void)(t), aarch64_bus_space_write_4(&arm_generic_bs_tag, (h), (o), (v)))

#endif
#endif
