/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** CPOOL LIB
*/

#ifndef MY_H
    #define MY_H

    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>

    #define SUCCESS 0
    #define FAILURE 84

char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strdup(const char *s);
void *my_realloc(void *ptr, size_t old_size, size_t new_size);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memset(void *dest, int value, size_t count);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strlen(char const *str);
int my_putchar(int c);
int my_putstr(char const *str, int fd);
int my_isalnum(char c);
int my_isalpha(char c);
char *my_strcat(char *dest, const char *src);
void free_word_array(char **array);
char **my_str_to_word_array(char const *str, char const *delimiters);

#endif /* MY_h */
