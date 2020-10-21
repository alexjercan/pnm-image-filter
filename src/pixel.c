#include "../include/pixel.h"

int32_t pixel_init(struct _Pixel *pixel, uint8_t r, uint8_t g, uint8_t b)
{
    pixel->r = r;
    pixel->g = g;
    pixel->b = b;

    return 0;
}

int32_t pixel_clamp(struct _Pixel *pixel, uint8_t min, uint8_t max)
{
    pixel->r = MIN(max, MAX(min, pixel->r));
    pixel->g = MIN(max, MAX(min, pixel->g));
    pixel->b = MIN(max, MAX(min, pixel->b));

    return 0;
}
