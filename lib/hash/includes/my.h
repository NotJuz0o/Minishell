/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** CPOOL LIB
*/

#ifndef MY_H
    #define MY_H

    #include <stddef.h>
    #include <unistd.h>
    #include <stdlib.h>

    #define SUCCESS 0
    #define FAILURE 84

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
char *my_strdup(const char *s);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_strlen(char const *str);
int my_putchar(int c);
int my_putstr(char const *str);
int my_compute_power_rec(int nb, int p);
int my_put_nbr(int nb);

#endif /* MY_h */
