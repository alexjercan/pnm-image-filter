#ifndef IF_PIXEL_H
#define IF_PIXEL_H

#include <stdint.h>
#include <stdlib.h>

#define MIN(a, b) (((a) < (b)) ? a : b)
#define MAX(a, b) (((a) < (b)) ? b : a)

struct _Pixel
{
    uint8_t r, g, b;
};

int32_t pixel_init(struct _Pixel *pixel, uint8_t r, uint8_t g, uint8_t b);
int32_t pixel_clamp(struct _Pixel *pixel, uint8_t min, uint8_t max);

#endif