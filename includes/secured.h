/*
** EPITECH PROJECT, 2024
** secured.h
** File description:
** Epitech secured.h
*/

#ifndef SECURED_H
    #define SECURED_H

    #include "my.h"
    #include <stdio.h>
    #include <stddef.h>

struct minishell_s;

typedef struct hashtable_s {
    char *key;
    void (*fn)(struct minishell_s *shell);
    int (*hash)(char *, int);
    int size;
    struct hashtable_s *next;
} hashtable_t;

int hash(char *key, int len);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);
int ht_insert(hashtable_t *ht, char *key,
    void (*fn)(struct minishell_s *shell));
int ht_delete(hashtable_t *ht, char *key);
void (*ht_search(hashtable_t *ht, char *key))(struct minishell_s *shell);

#endif /* SECURED_H */
