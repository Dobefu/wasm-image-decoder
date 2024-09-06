#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint32_t mem_to_uint32(unsigned char *buf)
{
  unsigned ret;
  memcpy(&ret, buf, sizeof(ret));
  return ret;
}

uint32_t get_bytes_uint32(uint8_t *bytes, unsigned offset, unsigned length)
{
  unsigned char buffer[length];
  memcpy(buffer, bytes + offset, length);
  uint32_t value = mem_to_uint32(buffer);

  return value;
}
