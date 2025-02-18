/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** my_strdup.c
*/

#include "../includes/my.h"

char *my_strdup(const char *s)
{
    char *result = NULL;
    size_t size = my_strlen(s);

    if (!s)
        return NULL;
    result = malloc(sizeof(char) * (size + 1));
    if (!result)
        return NULL;
    my_strcpy(result, s);
    return result;
}
