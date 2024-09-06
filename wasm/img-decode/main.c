#include <emscripten/emscripten.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

#define EXTERN

void decode_bmp(uint8_t *bytes, uint32_t num_bytes)
{
  printf("BMP detected!\n");

  uint32_t filesize = get_bytes_uint32(bytes, 2, 4);
  uint32_t offset = get_bytes_uint32(bytes, 10, 4);
  uint32_t width = get_bytes_uint32(bytes, 18, 4);
  uint32_t height = get_bytes_uint32(bytes, 22, 4);
  uint32_t depth = get_bytes_uint32(bytes, 28, 4);
  uint32_t compression = get_bytes_uint32(bytes, 30, 4);
  uint32_t bmp_size = get_bytes_uint32(bytes, 34, 4);
  uint32_t num_colours = get_bytes_uint32(bytes, 46, 4);

  unsigned char buffer[bmp_size];
  memcpy(buffer, bytes + offset, bmp_size);

  for (uint32_t i = 0; i < bmp_size; i++)
  {
  }
}

void decode_png(uint8_t *bytes, uint32_t num_bytes)
{
  printf("PNG detected!\n");
}

void hide(void)
{
  EM_ASM_({
    document.querySelector('#img-result').classList.add('hidden');
  });
}

void render(void)
{
  EM_ASM_({
    document.querySelector('#img-result').classList.remove('hidden');
  });
}

EXTERN EMSCRIPTEN_KEEPALIVE void decode_img(uint8_t *bytes, uint32_t num_bytes)
{
  hide();
  // printf("%u %u %u %u\n", bytes[0], bytes[1], bytes[2], bytes[3]);

  char magic_bmp[] = {66, 77};
  if (memcmp(bytes, magic_bmp, sizeof(magic_bmp)) == 0)
  {
    decode_bmp(bytes, num_bytes);
    render();
    return;
  }

  char magic_png[] = {137, 80, 78, 71};
  if (memcmp(bytes, magic_png, sizeof(magic_png)) == 0)
  {
    decode_png(bytes, num_bytes);
    render();
    return;
  }

  printf("Unknown format!\n");
}
