#include "../include/image.h"

static int32_t set_image_type(struct _Image *image);
static int32_t set_image_description(struct _Image *image);
static int32_t set_image_dimensions(struct _Image *image);
static int32_t set_image_max_color(struct _Image *image);
static int32_t set_image_pixels(struct _Image *image);

char *read_line_from_buffer(struct _Buffer *buffer);

uint32_t image_read(const char *path, struct _Image *image)
{
    binary_file_read(path, &image->raw);

    set_image_type(image);
    set_image_description(image);
    set_image_dimensions(image);
    set_image_max_color(image);
    set_image_pixels(image);

    return 0;
}

uint32_t image_write(const char *path, struct _Image *image)
{
    return binary__file_write(path, image->raw);
}

struct _Pixel image_get_pixel(struct _Image *image, int32_t x, int32_t y)
{
    if (x < 0 || x >= image->width || y < 0 || y >= image->height)
    {
        struct _Pixel zero;
        zero.r = zero.g = zero.b = 0;
        return zero;
    }
    return image->pixels[x + y * image->width];
}

void image_free(struct _Image *image)
{
    if (image->description != NULL)
        free(image->description);
    if (image->raw.str != NULL)
        free(image->raw.str);
}

int32_t set_image_type(struct _Image *image)
{
    char *line = read_line_from_buffer(&image->raw);

    if (strcmp((const char *)line, "P5\n") == 0)
        image->type = PGM;
    else
        image->type = PNM;

    free(line);
    return 0;
}

int32_t set_image_description(struct _Image *image)
{
    image->description = read_line_from_buffer(&image->raw);

    return 0;
}

int32_t set_image_dimensions(struct _Image *image)
{
    char *line = read_line_from_buffer(&image->raw);

    char *width = strtok((char *)line, " ");
    char *height = strtok(NULL, "\n");

    image->width = atoi(width);
    image->height = atoi(height);

    free(line);
    return 0;
}

int32_t set_image_max_color(struct _Image *image)
{
    char *line = read_line_from_buffer(&image->raw);

    image->max = atoi(line);

    free(line);
    return 0;
}

int32_t set_image_pixels(struct _Image *image)
{
    image->pixels = (void *)image->raw.str + image->raw.idx;
    return 0;
}

char *read_line_from_buffer(struct _Buffer *buffer)
{
    char *line = NULL;
    uint8_t *str = buffer->str;
    size_t idx = buffer->idx;
    size_t size = 0;

    while (str[idx] != '\n' && idx < buffer->size)
        idx++;

    size = idx - buffer->idx + 1;

    line = calloc(size + 1, sizeof(char));
    memcpy(line, str + buffer->idx, size * sizeof(char));
    line[size] = '\0';

    buffer->idx += size;

    return line;
}
