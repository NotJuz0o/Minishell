/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** cd.c
*/

#include "../../includes/minishell.h"

static char *expand_tilde(char *arg, char *home)
{
    char *result = NULL;

    if (!arg || !home)
        return NULL;
    if (arg[0] != '~')
        return my_strdup(arg);
    result = malloc(my_strlen(home) + my_strlen(arg));
    if (!result)
        return NULL;
    my_strcpy(result, home);
    my_strcat(result, arg + 1);
    return result;
}

static void print_errors(char const *dir)
{
    my_putstr("cd: no such file or directory: ", 2);
    my_putstr(dir, 2);
    my_putstr("\n", 2);
}

static void handle_home_cd(char *path)
{
    char *clean_path = NULL;

    if (!path)
        return;
    clean_path = my_strdup(path);
    if (clean_path[my_strlen(clean_path) - 1] == '\n')
        clean_path[my_strlen(clean_path) - 1] = '\0';
    if (chdir(clean_path) == -1)
        print_errors(clean_path);
    free(clean_path);
}

void cd_builtin(struct minishell_s *shell)
{
    char *path = NULL;
    char *expanded_path = NULL;

    if (!shell)
        return;
    for (int i = 0; shell->envp[i]; i++) {
        if (my_strncmp(shell->envp[i], "HOME=", 5) == 0) {
            path = shell->envp[i] + 5;
            break;
        }
    }
    if (!shell->argv[1])
        handle_home_cd(path);
    else {
        expanded_path = expand_tilde(shell->argv[1], path);
        if (chdir(expanded_path) == -1)
            print_errors(shell->argv[1]);
        free(expanded_path);
    }
}
