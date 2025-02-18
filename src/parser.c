/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** parser.c
*/

#include "../includes/minishell.h"

void analyze_lines(minishell_t *shell, int read)
{
    if (!shell)
        return;
    if (shell->line[read - 1] == '\n')
        shell->line[read - 1] = '\0';
    if (my_strlen(shell->line) > 0)
        exec(shell->line, shell);
}

char **get_paths_from_env(char **envp)
{
    char *path_var = NULL;

    for (int i = 0; envp[i]; i++) {
        if (my_strncmp(envp[i], "PATH=", 5) == 0) {
            path_var = envp[i] + 5;
            break;
        }
    }
    if (!path_var)
        return NULL;
    return my_str_to_word_array(path_var, ":");
}

char *find_command_path(char *cmd, char **paths)
{
    char *full_path;

    if (!cmd || !paths)
        return NULL;
    if (cmd[0] == '/')
        return my_strdup(cmd);
    for (int i = 0; paths[i]; i++) {
        full_path = malloc(my_strlen(paths[i]) + my_strlen(cmd) + 2);
        if (!full_path)
            continue;
        my_strcpy(full_path, paths[i]);
        my_strcat(full_path, "/");
        my_strcat(full_path, cmd);
        if (access(full_path, X_OK) == 0)
            return full_path;
        free(full_path);
    }
    return NULL;
}
