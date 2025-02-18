/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main function
*/

#include "../includes/secured.h"

int hash(char *key, int len)
{
    int code = 0;

    if (!key || len <= 0)
        return -1;
    for (int i = 0; key[i] != '\0'; i++)
        code = (code + (key[i] << (i % 8))) % 2147483647;
    code = ((code >> 16) ^ code) * 0x45d9f3b;
    code = ((code >> 16) ^ code) * 0x45d9f3b;
    code = (code >> 16) ^ code;
    return (code < 0) ? code * -1 : code;
}
