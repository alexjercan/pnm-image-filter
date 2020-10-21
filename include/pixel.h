#ifndef IF_PIXEL_H
#define IF_PIXEL_H

#include <stdint.h>
#include <stdlib.h>

struct _Pixel
{
    uint8_t r, g, b;
};

int32_t pixel_init(struct _Pixel *pixel, uint8_t r, uint8_t g, uint8_t b);
struct _Pixel pixel_zero();

#endif