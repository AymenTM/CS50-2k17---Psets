// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                         HASH TABLE FUNCTION LIBRARY                     //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <stdlib.h>

#include "hashtable.h"
#include "utils.h"
#include "murmurhash3/murmurhash3.h" /* hash function used */

/* creates an empty hash table */
t_hashtable     *hashtable_alloc_table(unsigned int num_entries)
{
    t_hashtable     *table;
    unsigned int    i;

    if (num_entries < 1)
        return (NULL);
    if (!(table = malloc(sizeof(t_hashtable))))
        return (NULL);
    num_entries = (unsigned int)ft_find_next_prime(num_entries);
    if (!(table->bucket_list =
        malloc(sizeof(t_entry*) * num_entries)))
    {
        free(table);
        return (NULL);
    }
    table->num_buckets = num_entries;
    table->entries = 0;
    i = 0;
    while (i < num_entries)
        (table->bucket_list)[i++] = NULL;
    return (table);
}

/* inserts a key-value pair (an entry) into the hash table */
int             hashtable_insert_entry(t_hashtable **table,
                                       char *key,
                                       void *value)
{
    t_entry         *entry;
    unsigned int    index;

    if (table && *table && key && value)
    {
        if (hashtable_set_appropriate_load_factor(table) == -1)
            return (-1);
        if (!(entry = entry_create(key, value)))
            return (-1);
        index = HASHCODE(key, (*table)->num_buckets);
        entry->successor = ((*table)->bucket_list)[index];
        ((*table)->bucket_list)[index] = entry;
        (*table)->entries += 1;
        return (0);
    }
    return (-1);
}

/* retrieves an entry */
t_entry         *hashtable_fetch_entry(t_hashtable *table, char *key)
{
    t_entry         *cur_entry;
    unsigned int    index;

    if (table && key)
    {
        index = HASHCODE(key, table->num_buckets);
        cur_entry = (table->bucket_list)[index];
        while (cur_entry)
        {
            if (ft_strcmp(cur_entry->key, key) == 0)
                return (cur_entry);
            cur_entry = cur_entry->successor;
        }
    }
    return (NULL);
}

/* finds and deletes/frees an entry in the hash table */
int             hashtable_delete_entry(t_hashtable **table, char *key)
{
    t_entry         *prev_entry;
    t_entry         *cur_entry;
    unsigned int    index;

    if (table && key)
    {
        index = HASHCODE(key, (*table)->num_buckets);
        cur_entry = ((*table)->bucket_list)[index];
        while (cur_entry)
        {
            if (ft_strcmp(cur_entry->key, key) == 0)
            {
                if (cur_entry == ((*table)->bucket_list)[index])
                    ((*table)->bucket_list)[index] = cur_entry->successor;
                else
                    prev_entry->successor = cur_entry->successor;
                entry_free(&cur_entry);
                (*table)->entries -= 1;
                return (0);
            }
            prev_entry = cur_entry;
            cur_entry = cur_entry->successor;
        }
    }
    return (-1);
}

/* deletes/frees the entire hash table and all the entries left in it */
int             hashtable_destroy_table(t_hashtable **table)
{
    unsigned int    i;

    if (table)
    {
        if (*table)
        {
            if ((*table)->bucket_list)
            {
                i = 0;
                while (i < (*table)->num_buckets)
                {
                    if (((*table)->bucket_list)[i])
                        bucket_free(&((*table)->bucket_list)[i]);
                    i++;
                }
                free((*table)->bucket_list);
                (*table)->bucket_list = NULL;
            }
            free(*table);
            (*table) = NULL;
        }
        return (0);
    }
    return (-1);
}

/* updates table size if necessary */
int             hashtable_set_appropriate_load_factor(t_hashtable **table)
{
    if (table && *table)
    {
        if ((float)(*table)->entries / (float)(*table)->num_buckets
            > MAX_LOAD_FACTOR)
        {
            if (hashtable_grow_table(table) == -1)
                return (-1);
            return (0);
        }
        if ((float)(*table)->entries / (float)(*table)->num_buckets
            < MIN_LOAD_FACTOR)
        {
            if (hashtable_shrink_table(table) == -1)
                return (-1);
            return (0);
        }
        else
        {
            return (0);
        }
    }
    return (-1);
}

/* grows the hash table by a factor of 2 and then some
(to get to the next prime) */
int             hashtable_grow_table(t_hashtable **table)
{
    t_hashtable     *new_table;

    if (table && *table)
    {
        new_table = hashtable_alloc_table((*table)->num_buckets * 2);
        if (new_table == NULL)
            return (-1);
        if (hashtable_rehash_table(table, &new_table) == -1)
            return (-1);
        hashtable_destroy_table(table);
        (*table) = new_table;
        return (0);
    }
    return (-1);
}

/* shrinks the hash table by half and then some (to get to the next prime) */
int             hashtable_shrink_table(t_hashtable **table)
{
    t_hashtable     *new_table;

    if (table && *table)
    {
        if ((*table)->num_buckets > 1)
        {
            new_table = hashtable_alloc_table((*table)->num_buckets / 2);
            if (new_table == NULL)
                return (-1);
            if (hashtable_rehash_table(table, &new_table) == -1)
                return (-1);
            hashtable_destroy_table(table);
            (*table) = new_table;
            return (0);
        }
        return (0);
    }
    return (-1);
}

/* rehashs one entry into the 'table_to' */
int             hashtable_rehash_entry(t_hashtable **table_to, t_entry **entry)
{
    unsigned int    index;

    if (table_to && *table_to && entry && *entry)
    {
        index = HASHCODE((*entry)->key, (*table_to)->num_buckets);
        (*entry)->successor = ((*table_to)->bucket_list)[index];
        ((*table_to)->bucket_list)[index] = (*entry);
        (*table_to)->entries += 1;
        return (0);
    }
    return (-1);
}

/* rehashs all the entries in the 'table_from' into the 'table_to' */
int             hashtable_rehash_table(t_hashtable **table_from,
                                       t_hashtable **table_to)
{
    t_entry         *cur_entry;
    t_entry         *temp;
    unsigned int    i;

    if (table_from && *table_from && table_to && *table_to)
    {
        i = 0;
        while (i < (*table_from)->num_buckets)
        {
            if (((*table_from)->bucket_list)[i])
            {
                cur_entry = ((*table_from)->bucket_list)[i];
                while (cur_entry)
                {
                    temp = cur_entry->successor;
                    if (hashtable_rehash_entry(table_to, &cur_entry) == -1)
                        return (-1);
                    cur_entry = temp;
                }
                ((*table_from)->bucket_list)[i] = NULL;
            }
            i++;
        }
    }
    return (((*table_to)->entries == (*table_from)->entries) ? 0 : -1);
}

/* takes a key and a value and creates an entry out of them */
t_entry         *entry_create(char *key, void *value)
{
    t_entry *new_entry;

    if (key && value)
    {
        if (!(new_entry = malloc(sizeof(t_entry))))
            return (NULL);
        new_entry->key = ft_strdup(key);
        new_entry->value = value;
        new_entry->successor = NULL;
        return (new_entry);
    }
    return (NULL);
}

/* deletes/frees an entry */
void            entry_free(t_entry **entry)
{
    if (entry && *entry)
    {
        if ((*entry)->key)
            free((*entry)->key);
        if ((*entry)->value)
            free((*entry)->value);
        free(*entry);
        (*entry) = NULL;
    }
}

/* deletes/frees an entire bucket (linked list) */
void            bucket_free(t_entry **head)
{
    t_entry *temp;

    if (head)
    {
        while (*head)
        {
            temp = (*head);
            (*head) = (*head)->successor;
            entry_free(&temp);
        }
    }
}
