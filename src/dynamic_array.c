/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** dynamic_array.c
*/

#include "../includes/minishell.h"

array_t *init_array(void)
{
    array_t *ret = malloc(sizeof(array_t));

    if (!ret)
        return NULL;
    ret->len = 0;
    ret->size = DEFAULT_SIZE;
    ret->array = malloc(sizeof(char *) * DEFAULT_SIZE);
    if (!ret->array) {
        free(ret);
        return NULL;
    }
    return ret;
}

int add_elt_to_array(array_t *array, char *element)
{
    char **new_array = NULL;

    if (!array || !element)
        return 84;
    if (array->len == array->size) {
        array->size *= 2;
        new_array = my_realloc(array->array,
            sizeof(char *) * (array->size / 2),
            sizeof(char *) * array->size);
        if (!new_array)
            return 84;
        array->array = new_array;
    }
    array->array[array->len] = my_strdup(element);
    if (!array->array[array->len])
        return 84;
    array->len++;
    return 0;
}

int remove_elt_from_array(array_t *array, size_t index)
{
    char *tmp = NULL;

    if (!array || index >= array->len)
        return 84;
    tmp = array->array[index];
    for (size_t i = index; i < array->len - 1; i++)
        array->array[i] = array->array[i + 1];
    array->array[array->len - 1] = NULL;
    array->len--;
    free(tmp);
    return 0;
}

void free_array(array_t *array)
{
    if (!array || !array->array)
        return;
    for (size_t i = 0; i < array->len; i++) {
        free(array->array[i]);
    }
    free(array->array);
    free(array);
}

void print_array(array_t *array)
{
    if (!array)
        return;
    for (size_t i = 0; i < array->len; i++) {
        my_putstr(array->array[i], 1);
        my_putstr("\n", 1);
    }
}
