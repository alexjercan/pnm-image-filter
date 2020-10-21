#include "../include/image.h"

float blur_filter[3][3] = {{0.0625, 0.125, 0.0625},
                           {0.125, 0.25, 0.125},
                           {0.0625, 0.125, 0.0625}};

uint32_t apply3x3Filter(struct _Image *image, float filter[3][3])
{
    uint32_t size = image->width * image->height;
    struct _Pixel *tmp = calloc(size, sizeof(struct _Pixel));
    int32_t i, j, x, y;

    memmove(tmp, image->pixels, size * sizeof(struct _Pixel));

    for (j = 0; j < image->height; j++)
    {
        for (i = 0; i < image->width; i++)
        {
            float r = 0, g = 0, b = 0;
            for (x = i - 1; x <= i + 1; ++x)
            {
                for (y = j - 1; y <= j + 1; ++y)
                {
                    struct _Pixel pixel = image_get_pixel(image, x, y);
                    r += pixel.r * filter[x - (i - 1)][y - (j - 1)];
                    g += pixel.g * filter[x - (i - 1)][y - (j - 1)];
                    b += pixel.b * filter[x - (i - 1)][y - (j - 1)];
                }
            }

            pixel_init(&tmp[i + j * image->width], r, g, b);
            pixel_clamp(&tmp[i + j * image->width], 0, image->max);
        }
    }

    memmove(image->pixels, tmp, size * sizeof(struct _Pixel));
    return 0;
}

int main(int argc, char **argv)
{
    struct _Image image;

    image_read(argv[1], &image);

    apply3x3Filter(&image, blur_filter);

    image_write(argv[2], &image);

    image_free(&image);

    return 0;
}