/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** exit.c
*/

#include "../../includes/minishell.h"

void exit_builtin(struct minishell_s *shell)
{
    free_context(shell);
    exit(0);
}
