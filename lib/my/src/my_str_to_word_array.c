/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** my_str_to_word_array.c
*/

#include "../includes/my.h"


static int is_a_delimiter(char c, char const *delimiters)
{
    for (int i = 0; delimiters[i] != '\0'; i++)
        if (c == delimiters[i])
            return 1;
    return 0;
}

static int get_array_size(char const *str, char const *delimiters)
{
    int result = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_a_delimiter(str[i], delimiters))
            in_word = 0;
        if (!is_a_delimiter(str[i], delimiters) && in_word == 0) {
            in_word = 1;
            result++;
        }
    }
    return result;
}

static void allocate_words_in_array(
    char **arr, char const *str, char const *del)
{
    int word_len = 0;
    int i = 0;
    int arr_i = 0;

    while (str[i] != '\0') {
        word_len = 0;
        while (str[i] != '\0' && is_a_delimiter(str[i], del))
            i++;
        while (str[i] != '\0' && !is_a_delimiter(str[i], del)) {
            word_len++;
            i++;
        }
        if (word_len > 0) {
            arr[arr_i] = malloc(sizeof(char) * (word_len + 1));
            arr_i++;
        }
    }
}

static void reset_word_index(int *in_word, int *char_index)
{
    if (*in_word == 0) {
        *in_word = 1;
        *char_index = 0;
    }
}

static void init_word_array_datas(
    char **arr, char const *str, char const *delimiters)
{
    int word_index = 0;
    int char_index = 0;
    int in_word = 0;

    arr[get_array_size(str, delimiters)] = NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_a_delimiter(str[i], delimiters)) {
            reset_word_index(&in_word, &char_index);
            arr[word_index][char_index] = str[i];
            char_index++;
        }
        if (is_a_delimiter(str[i], delimiters) && in_word == 1) {
            arr[word_index][char_index] = '\0';
            word_index++;
            in_word = 0;
        }
    }
    if (in_word == 1) {
        arr[word_index][char_index] = '\0';
    }
}

void free_word_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

char **my_str_to_word_array(char const *str, char const *delimiters)
{
    char **result = NULL;
    int size = 0;

    if (!str || !delimiters || !my_strlen(str) || !my_strlen(delimiters))
        return NULL;
    size = get_array_size(str, delimiters);
    result = malloc(sizeof(char *) * (size + 1));
    if (!result)
        return NULL;
    allocate_words_in_array(result, str, delimiters);
    init_word_array_datas(result, str, delimiters);
    return result;
}
