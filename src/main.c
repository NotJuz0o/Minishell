/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Main function
*/

#include "../includes/minishell.h"

void init_env_arr(char **env, array_t *arr)
{
    if (!env || !arr)
        return;
    for (int i = 0; env[i]; i++)
        add_elt_to_array(arr, env[i]);
}

int main(int __attribute__((unused)) argc,
    char __attribute__((unused)) *argv[], char *env[])
{
    array_t *arr = init_array();

    if (!arr)
        return FAILURE;
    init_env_arr(env, arr);
    return minishell(arr);
}
