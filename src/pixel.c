#include "../include/pixel.h"

int32_t pixel_init(struct _Pixel *pixel, uint8_t r, uint8_t g, uint8_t b)
{
    pixel->r = r;
    pixel->g = g;
    pixel->b = b;

    return 0;
}

struct _Pixel pixel_zero()
{
    struct _Pixel zero;
    pixel_init(&zero, 0, 0, 0);
    return zero;
}