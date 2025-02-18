/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** errors_management.c
*/

#include "../includes/minishell.h"

void handle_errors(minishell_t *shell)
{
    if (!shell->cmd_name)
        return;
    if (access(shell->argv[0], F_OK) == -1
        || access(shell->argv[0], X_OK) == -1) {
        my_putstr(shell->cmd_name, 2);
        my_putstr(": Command not found.\n", 2);
        exit(84);
    }
}

static int check_identifier(const char *str)
{
    if (!str || !*str || (!my_isalpha(*str) && *str != '_'))
        return 0;
    for (int i = 1; str[i]; i++) {
        if (!my_isalnum(str[i]) && str[i] != '_')
            return 0;
    }
    return 1;
}

int handle_setenv_errors(struct minishell_s *shell, int argc)
{
    if (argc > 3) {
        my_putstr("setenv: Too many arguments.\n", 2);
        shell->status = FAILURE;
        return FAILURE;
    }
    if (argc > 1 && !check_identifier(shell->argv[1])) {
        my_putstr("setenv: Variable name must begin with a letter.\n", 2);
        shell->status = FAILURE;
        return FAILURE;
    }
    return 0;
}
