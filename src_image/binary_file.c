#include "../include/binary_file.h"

int32_t binary_file_read(const char *path, struct _Buffer *buffer)
{
    FILE *file = fopen(path, "rb");

    fseek(file, 0, SEEK_END);
    buffer->size = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer->idx = 0;
    buffer->str = calloc(buffer->size, sizeof(uint8_t));
    fread(buffer->str, sizeof(uint8_t), buffer->size, file);

    return fclose(file);
}

int32_t binary__file_write(const char *path, struct _Buffer buffer)
{
    FILE *file = NULL;

    file = fopen(path, "wb");

    fwrite(buffer.str, sizeof(uint8_t), buffer.size, file);
    fclose(file);

    return 0;
}