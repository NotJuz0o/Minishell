/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** my_realloc.c
*/

#include "../includes/my.h"

void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *new_ptr = NULL;
    size_t copy_size = 0;

    if (ptr == NULL)
        return malloc(new_size);
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;
    copy_size = old_size < new_size ? old_size : new_size;
    my_memset(new_ptr, 0, new_size);
    my_memcpy(new_ptr, ptr, copy_size);
    free(ptr);
    return new_ptr;
}
