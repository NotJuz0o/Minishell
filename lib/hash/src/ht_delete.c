/*
** EPITECH PROJECT, 2024
** juzoo
** File description:
** ht_delete.c
*/

#include "../includes/secured.h"

static void remove_first_element(hashtable_t *current)
{
    hashtable_t *temp;

    free(current->key);
    current->key = NULL;
    current->fn = NULL;
    if (current->next) {
        temp = current->next;
        current->key = temp->key;
        current->fn = temp->fn;
        current->next = temp->next;
        free(temp);
    }
}

static void remove_next_element(hashtable_t *current)
{
    hashtable_t *temp;

    temp = current->next;
    current->next = temp->next;
    free(temp->key);
    free(temp);
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index;
    hashtable_t *current;

    if (!ht || !key)
        return FAILURE;
    index = ht->hash(key, my_strlen(key)) % ht->size;
    current = &ht[index];
    if (current->key && my_strcmp(current->key, key) == 0) {
        remove_first_element(current);
        return SUCCESS;
    }
    while (current->next) {
        if (my_strcmp(current->next->key, key) == 0) {
            remove_next_element(current);
            return SUCCESS;
        }
        current = current->next;
    }
    return FAILURE;
}

void (*ht_search(hashtable_t *ht, char *key))(struct minishell_s *)
{
    int index = 0;
    hashtable_t *current;

    if (!ht || !key)
        return NULL;
    index = ht->hash(key, my_strlen(key)) % ht->size;
    if (ht[index].key && !my_strcmp(ht[index].key, key))
        return ht[index].fn;
    current = ht[index].next;
    while (current) {
        if (!my_strcmp(current->key, key))
            return current->fn;
        current = current->next;
    }
    return NULL;
}
