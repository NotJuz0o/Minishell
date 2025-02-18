/*
** EPITECH PROJECT, 2025
** src
** File description:
** create.c
*/
#include "../includes/secured.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *ret = NULL;

    if (!hash || len <= 0)
        return NULL;
    ret = malloc(sizeof(hashtable_t) * len);
    if (!ret)
        return NULL;
    ret->hash = hash;
    ret->size = len;
        ret->size = len;
    for (int i = 0; i < len; i++) {
        ret[i].key = NULL;
        ret[i].next = NULL;
        ret[i].fn = NULL;
    }
    return ret;
}

void delete_hashtable(hashtable_t *ht)
{
    hashtable_t *current;
    hashtable_t *next;

    if (!ht)
        return;
    for (int i = 0; i < ht->size; i++) {
        current = ht[i].next;
        while (current) {
            next = current->next;
            free(current->key);
            free(current);
            current = next;
        }
        if (ht[i].fn)
            free(ht[i].key);
    }
    free(ht);
}
