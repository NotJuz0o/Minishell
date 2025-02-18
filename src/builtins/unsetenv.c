/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** unsetenv.c
*/

#include "../../includes/minishell.h"

static void print_usage_error(struct minishell_s *shell)
{
    write(2, "unsetenv: Too few arguments.\n", 29);
    shell->status = 84;
}

static void remove_env_var(struct minishell_s *shell, const char *var_name)
{
    size_t name_len = my_strlen(var_name);

    for (size_t i = 0; i < shell->arr->len; i++) {
        if (my_strncmp(shell->arr->array[i], var_name, name_len) == 0
            && shell->arr->array[i][name_len] == '=') {
            remove_elt_from_array(shell->arr, i);
            i--;
        }
    }
}

static void unset_variables(struct minishell_s *shell)
{
    int i = 1;

    while (shell->argv[i]) {
        remove_env_var(shell, shell->argv[i]);
        i++;
    }
    shell->status = 0;
}

void unsetenv_builtin(struct minishell_s *shell)
{
    int argc = 0;

    while (shell->argv[argc])
        argc++;
    if (argc == 1) {
        print_usage_error(shell);
        return;
    }
    unset_variables(shell);
}
