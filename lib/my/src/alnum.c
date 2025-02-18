/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** alnum.c
*/

#include "../includes/my.h"

int my_isalpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int my_isalnum(char c)
{
    return (my_isalpha(c) || (c >= '0' && c <= '9'));
}
