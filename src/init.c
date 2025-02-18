/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** init.c
*/

#include "../includes/minishell.h"

void init_struct(array_t *arr, minishell_t *shell)
{
    if (!arr || !shell)
        return;
    shell->ht = new_hashtable(&hash, 16);
    shell->arr = arr;
    shell->envp = arr->array;
    shell->line = NULL;
    shell->status = SUCCESS;
    shell->cmd_name = NULL;
    ht_insert(shell->ht, "exit", &exit_builtin);
    ht_insert(shell->ht, "cd", &cd_builtin);
    ht_insert(shell->ht, "setenv", &setenv_builtin);
    ht_insert(shell->ht, "unsetenv", &unsetenv_builtin);
    ht_insert(shell->ht, "env", &env_builtin);
}

void free_context(minishell_t *shell)
{
    if (shell->argv)
        free_word_array(shell->argv);
    free_array(shell->arr);
    delete_hashtable(shell->ht);
    if (shell->line)
        free(shell->line);
    if (shell->cmd_name)
        free(shell->cmd_name);
    free(shell);
}
