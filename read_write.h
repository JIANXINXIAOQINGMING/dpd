#ifndef read_write
#define read_write

#include <stdint.h>

extern void register_write(uint32_t addr, uint32_t write_data);

extern int register_read(uint32_t addr);

#endif