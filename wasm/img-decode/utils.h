#include <stdint.h>

#ifndef utils_h__
#define utils_h__

uint32_t mem_to_uint32(unsigned char *buf);
uint32_t get_bytes_uint32(uint8_t *bytes, unsigned offset, unsigned length);

#endif
