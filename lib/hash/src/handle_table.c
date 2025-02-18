/*
** EPITECH PROJECT, 2025
** src
** File description:
** handle_table.c
*/

#include "../includes/secured.h"

static int check_existing_key(
    hashtable_t *ht, char *key, void (*value)(struct minishell_s *shell),
    int index)
{
    hashtable_t *tmp;

    if (ht[index].fn && my_strcmp(ht[index].key, key) == 0) {
        ht[index].fn = value;
        return SUCCESS;
    }
    tmp = ht[index].next;
    while (tmp) {
        if (my_strcmp(tmp->key, key) == 0) {
            tmp->fn = value;
            return SUCCESS;
        }
        tmp = tmp->next;
    }
    return FAILURE;
}

static int insert_first_element(
    hashtable_t *ht, char *key, void (*value)(struct minishell_s *),
    int index)
{
    hashtable_t *first_elem = malloc(sizeof(hashtable_t));

    if (!first_elem)
        return FAILURE;
    first_elem->key = ht[index].key;
    first_elem->fn = ht[index].fn;
    first_elem->next = ht[index].next;
    ht[index].key = my_strdup(key);
    ht[index].fn = value;
    ht[index].next = first_elem;
    return SUCCESS;
}

int ht_insert(hashtable_t *ht, char *key,
    void (*value)(struct minishell_s *))
{
    int index = 0;

    if (!ht || !key || !value)
        return FAILURE;
    index = ht->hash(key, my_strlen(key)) % ht->size;
    if (check_existing_key(ht, key, value, index) == SUCCESS)
        return SUCCESS;
    if (ht[index].fn)
        return insert_first_element(ht, key, value, index);
    ht[index].key = my_strdup(key);
    ht[index].fn = value;
    return SUCCESS;
}
