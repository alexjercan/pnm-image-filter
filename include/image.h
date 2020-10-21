#ifndef IF_IMAGE_H
#define IF_IMAGE_H

#include <string.h>

#include "binary_file.h"
#include "pixel.h"

#define PGM 5
#define PNM 6

struct _Image
{
    uint16_t type;
    char *description;
    uint32_t width, height;
    uint32_t max;
    struct _Pixel *pixels;
    struct _Buffer raw;
};

uint32_t image_read(const char *path, struct _Image *image);
uint32_t image_write(const char *path, struct _Image *image);

struct _Pixel image_get_pixel(struct _Image *image, int32_t x, int32_t y);

void image_free(struct _Image *image);

#endif
