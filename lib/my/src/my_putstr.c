/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** my_putstr.c
*/

#include "../includes/my.h"

int my_putstr(char const *str, int fd)
{
    if (!str)
        return FAILURE;
    if (write(fd, str, my_strlen(str)) == -1)
        return FAILURE;
    return SUCCESS;
}
