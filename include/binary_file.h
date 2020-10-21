#ifndef IF_BINARY_FILE_H
#define IF_BINARY_FILE_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

struct _Buffer
{
    uint8_t *str;
    size_t size;
    size_t idx;
};

int32_t binary_file_read(const char *path, struct _Buffer *buffer);
int32_t binary__file_write(const char *path, struct _Buffer buffer);

#endif