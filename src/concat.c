/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** concat.c
*/

#include "../includes/minishell.h"

int is_direct_path(const char *cmd)
{
    return (cmd[0] == '/' || cmd[0] == '.');
}

char *concat_path(char *cmd)
{
    char *cmd_path = NULL;

    if (!cmd)
        return NULL;
    cmd_path = malloc(my_strlen("/bin/") + my_strlen(cmd) + 1);
    if (!cmd_path)
        return NULL;
    my_strcpy(cmd_path, "/bin/");
    my_strcat(cmd_path, cmd);
    free(cmd);
    return cmd_path;
}
