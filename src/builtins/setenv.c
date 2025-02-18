/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** setenv.c
*/

#include "../../includes/minishell.h"

static char *create_env_var(const char *name, const char *value)
{
    size_t len = my_strlen(name) + (value ? my_strlen(value) : 0) + 2;
    char *new_env = malloc(len);

    if (!new_env)
        return NULL;
    my_strcpy(new_env, name);
    my_strcat(new_env, "=");
    if (value)
        my_strcat(new_env, value);
    return new_env;
}

static void update_env_var(struct minishell_s *shell, char *new_env)
{
    size_t name_len = my_strlen(shell->argv[1]);

    for (size_t i = 0; i < shell->arr->len; i++) {
        if (my_strncmp(shell->arr->array[i], shell->argv[1], name_len) == 0
            && shell->arr->array[i][name_len] == '=') {
            remove_elt_from_array(shell->arr, i);
            break;
        }
    }
    add_elt_to_array(shell->arr, new_env);
    free(new_env);
}

void setenv_builtin(struct minishell_s *shell)
{
    int argc = 0;
    char *new_env = NULL;

    while (shell->argv[argc])
        argc++;
    if (argc == 1) {
        env_builtin(shell);
        return;
    }
    if (handle_setenv_errors(shell, argc) == FAILURE)
        return;
    new_env = create_env_var(shell->argv[1],
        argc == 3 ? shell->argv[2] : NULL);
    if (!new_env) {
        my_putstr("setenv: Memory allocation failed.\n", 2);
        shell->status = FAILURE;
        return;
    }
    update_env_var(shell, new_env);
    shell->status = SUCCESS;
}
