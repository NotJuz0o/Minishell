/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** executor.c
*/

#include "../includes/minishell.h"

static char *search_command_in_path(char *cmd, char **envp)
{
    char **paths = get_paths_from_env(envp);
    char *cmd_path = NULL;

    if (!paths)
        return NULL;
    cmd_path = find_command_path(cmd, paths);
    for (int i = 0; paths[i]; i++)
        free(paths[i]);
    free(paths);
    return cmd_path;
}

static void handle_absolute_path(minishell_t *shell)
{
    char *cmd_path;

    if (!shell || !shell->argv)
        return;
    if (shell->cmd_name) {
        free(shell->cmd_name);
        shell->cmd_name = NULL;
    }
    shell->cmd_name = my_strdup(shell->argv[0]);
    if (!is_direct_path(shell->argv[0]) &&
        ht_search(shell->ht, shell->argv[0]) == NULL) {
        cmd_path = search_command_in_path(shell->argv[0], shell->envp);
        if (cmd_path) {
            free(shell->argv[0]);
            shell->argv[0] = cmd_path;
        }
    }
}

static void print_signal_error(int status)
{
    char *msg;

    if (WIFSIGNALED(status)) {
        msg = strsignal(WTERMSIG(status));
        if (msg) {
            write(2, msg, my_strlen(msg));
            write(2, "\n", 1);
        }
    }
}

static void handle_exit_status(minishell_t *shell, int status)
{
    if (WIFEXITED(status))
        shell->status = WEXITSTATUS(status);
}

static void handle_child_process(minishell_t *shell, int *status)
{
    pid_t pid = fork();

    if (pid == 0) {
        handle_errors(shell);
        execve(shell->argv[0], shell->argv, shell->envp);
        exit(1);
    }
    if (pid > 0) {
        waitpid(pid, status, 0);
        handle_exit_status(shell, *status);
        print_signal_error(*status);
    }
}

void manage_forks(minishell_t *shell)
{
    void (*builtin)(struct minishell_s *);
    int status = 0;

    handle_absolute_path(shell);
    builtin = ht_search(shell->ht, shell->argv[0]);
    if (builtin) {
        builtin((struct minishell_s *) shell);
    } else {
        handle_child_process(shell, &status);
    }
}

int exec(char *arg, minishell_t *shell)
{
    if (!arg || !shell || !shell->envp)
        return FAILURE;
    shell->argv = my_str_to_word_array(arg, " ");
    manage_forks(shell);
    free_word_array(shell->argv);
    shell->argv = NULL;
    return SUCCESS;
}
