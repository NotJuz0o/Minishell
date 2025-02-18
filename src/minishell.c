/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** minishell.c
*/

#include "../includes/minishell.h"

int minishell(array_t *arr)
{
    minishell_t *shell = malloc(sizeof(minishell_t));
    size_t len = 0;
    int ret = 0;
    int read = 0;

    if (!shell)
        return FAILURE;
    init_struct(arr, shell);
    while (1) {
        if (isatty(STDIN_FILENO))
            write(1, "$> ", 3);
        read = getline(&shell->line, &len, stdin);
        if (read == -1)
            break;
        analyze_lines(shell, read);
    }
    ret = shell->status;
    free_context(shell);
    return ret;
}
