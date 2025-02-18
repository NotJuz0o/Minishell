/*
** EPITECH PROJECT, 2024
** minishell.h
** File description:
** Epitech project.h
*/

#ifndef PROJECT_H
    #define PROJECT_H
    #define DEFAULT_SIZE 1

    #include "my.h"
    #include "secured.h"
    #include "string.h"
    #include <stdio.h>
    #include <sys/wait.h>

typedef struct {
    size_t len;
    size_t size;
    char **array;
} array_t;

typedef struct minishell_s {
    char **argv;
    char **envp;
    char *line;
    char *cmd_name;
    array_t *arr;
    hashtable_t *ht;
    int status;
} minishell_t;

void cd_builtin(struct minishell_s *shell);
void exit_builtin(struct minishell_s *shell);
void env_builtin(struct minishell_s *shell);
void setenv_builtin(struct minishell_s *shell);
void unsetenv_builtin(struct minishell_s *shell);
int handle_setenv_errors(struct minishell_s *shell, int argc);
void handle_errors(minishell_t *shell);
void manage_forks(minishell_t *shell);
array_t *init_array(void);
int add_elt_to_array(array_t *array, char *element);
int remove_elt_from_array(array_t *array, size_t index);
void free_array(array_t *array);
void print_array(array_t *array);
char **get_paths_from_env(char **envp);
char *find_command_path(char *cmd, char **paths);
int exec(char *arg, minishell_t *shell);
void init_struct(array_t *arr, minishell_t *shell);
void analyze_lines(minishell_t *shell, int read);
void free_context(minishell_t *shell);
int is_direct_path(const char *cmd);
char *concat_path(char *cmd);
int minishell(array_t *arr);

#endif /* PROJECT_H */
