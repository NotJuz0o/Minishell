/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** demo.c
*/

#include "../../includes/minishell.h"

void env_builtin(struct minishell_s *shell)
{
    for (int i = 0; shell->envp[i]; i++) {
        my_putstr(shell->envp[i], 1);
        my_putstr("\n", 1);
    }
}
