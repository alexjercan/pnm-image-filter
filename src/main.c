#include "../include/image.h"
#include "../include/filters.h"

uint32_t apply_filter(struct _Image *image, float filter[3][3])
{
    uint32_t size = image->width * image->height;
    struct _Pixel *tmp = calloc(size, sizeof(struct _Pixel));
    int32_t i, j;

    memmove(tmp, image->pixels, size * sizeof(struct _Pixel));

    for (j = 0; j < image->height; j++)
        for (i = 0; i < image->width; i++)
            image_filter_pixel_at(image, i, j, filter,
                                  &tmp[i + j * image->width]);

    memmove(image->pixels, tmp, size * sizeof(struct _Pixel));
    return 0;
}

void apply_filters(struct _Image *image, int filters_cnt, char **filters)
{
    int i = 0;

    for (i = 0; i < filters_cnt; i++)
    {
        if (strcmp(filters[i], "smooth") == 0)
            apply_filter(image, smooth_filter);
        else if (strcmp(filters[i], "blur") == 0)
            apply_filter(image, blur_filter);
        else if (strcmp(filters[i], "sharpen") == 0)
            apply_filter(image, sharpen_filter);
        else if (strcmp(filters[i], "mean") == 0)
            apply_filter(image, mean_filter);
        else if (strcmp(filters[i], "emboss") == 0)
            apply_filter(image, emboss_filter);
    }
}

int main(int argc, char **argv)
{
    struct _Image image;

    image_read(argv[1], &image);

    apply_filters(&image, argc - 3, argv + 3);

    image_write(argv[2], &image);

    image_free(&image);

    return 0;
}