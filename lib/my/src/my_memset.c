/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** my_memset.c
*/

#include "../includes/my.h"

void *my_memset(void *dest, int value, size_t count)
{
    unsigned char *ptr = (unsigned char *)dest;
    unsigned char byte = (unsigned char)value;

    if (!dest)
        return NULL;
    while (count > 0) {
        *ptr = byte;
        ptr++;
        count--;
    }
    return dest;
}
