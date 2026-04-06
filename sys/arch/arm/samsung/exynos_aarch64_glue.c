#define EXYNOS_GLUE
#include <sys/param.h>
#include <sys/types.h>
#include <sys/bus.h>

/* These are the raw AArch64 accessors that don't use the 'read/write' tokens */
#include <aarch64/armreg.h>

uint32_t aarch64_bus_space_read_4(bus_space_tag_t, bus_space_handle_t, bus_size_t);
void aarch64_bus_space_write_4(bus_space_tag_t, bus_space_handle_t, bus_size_t, uint32_t);

uint32_t
aarch64_bus_space_read_4(bus_space_tag_t t, bus_space_handle_t h, bus_size_t o)
{
    /* h + o is the virtual address. We use the generic memory accessor. */
    return *(volatile uint32_t *)(h + o);
}

void
aarch64_bus_space_write_4(bus_space_tag_t t, bus_space_handle_t h, bus_size_t o, uint32_t v)
{
    *(volatile uint32_t *)(h + o) = v;
}
