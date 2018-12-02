// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                         HASH TABLE FUNCTION LIBRARY                     //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/* * * * * * * * * * * *
========================
    HASH TABLE HEADER
========================
 * * * * * * * * * * * */

#ifndef FT_HASHTABLE_H
# define FT_HASHTABLE_H

# define HASHCODE(key, buckets) (hash(key, ft_strlen(key)) % buckets)

# define MIN_LOAD_FACTOR 0.0
# define MAX_LOAD_FACTOR 0.7

typedef struct      s_entry
{
    char            *key;
    void            *value;
    struct s_entry  *successor;
}                   t_entry;

typedef struct      s_hashtable
{
    unsigned int    entries;
    unsigned int    num_buckets;
    t_entry         **bucket_list;
}                   t_hashtable;

t_hashtable     *hashtable_alloc_table(unsigned int size);
t_hashtable     *hashtable_realloc_table(t_hashtable **table);
t_hashtable     *hashtable_dealloc_table(t_hashtable **table);

t_entry         *hashtable_fetch_entry(t_hashtable *table, char *key);
int             hashtable_insert_entry(t_hashtable **table, char *key,
                void *value);
int             hashtable_delete_entry(t_hashtable **table, char *key);
int             hashtable_rehash_entry(t_hashtable **table_to,
                t_entry **entry);
int             hashtable_rehash_table(t_hashtable **table_from,
                t_hashtable **table_to);
int             hashtable_destroy_table(t_hashtable **table);
int             hashtable_check_load_factor(t_hashtable **table);

t_entry         *ft_entry_create(char *key, void *value);
void            ft_entry_free(t_entry **entry);
void            ft_bucket_free(t_entry **head);

#endif


/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   malloc() , <stdlib.h>
                ft_find_next_prime()

DESCRIPTION:    Creates/allocates an empty hash table of size 'size'
                and then some (inorder to get to the nearest prime
                number).

RETURN VALUES:  If successful, returns a pointer to the
                hash table. If an error occurs the function
                will return a NULL pointer.

SEARCH TAGS:    ft hashtable_alloc_table    ft hashtable_create_table
                ft ht_alloc_table           ft ht_create_table
 — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

t_hashtable     *hashtable_alloc_table(unsigned int size)
{
    t_hashtable     *table;
    unsigned int    i;

    if (size < 1)
        return (NULL);
    if (!(table = malloc(sizeof(t_hashtable))))
        return (NULL);
    size = (unsigned int)ft_find_next_prime(size);
    if (!(table->bucket_list =
                malloc(sizeof(t_entry*) * size)))
    {
        return (NULL);
    }
    table->num_buckets = size;
    table->entries = 0;
    i = 0;
    while (i < size)
        (table->bucket_list)[i++] = NULL;
    return (table);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   ft_entry_create()
                ft_strlen()
                HASHCODE()
                hash()
                hashtable_check_load_factor()

DESCRIPTION:    Inserts a key-value pair into the hash table.

                NOTE: in this implementation ownership is taken of the
                'value', that's to say that 'value' MUST be allocated
                before hand somewhere in the code, if you fail to do
                so, upon free'ing the hash table you WILL get a
                'bad free' error.

                As for the 'key', a copy/duplicate of it is made (i.e memory
                is allocated inorder to make a duplicate of it). The memory,
                upon free'ing of an entry or the hash table, is free'd.

RETURN VALUES:  If successful, returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_insert_data    ft hashtable_add_entry
                ft ht_insert_data           ft ht_add_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int             hashtable_insert_entry(t_hashtable **table, char *key,
                void *value)
{
    t_entry         *entry;
    unsigned int    index;

    if (table && *table && key && value)
    {
        if (hashtable_check_load_factor(table) == -1)
            return (-1);
        if (!(entry = ft_entry_create(key, value)))
            return (-1);
        index = HASHCODE(key, (*table)->num_buckets);
        entry->successor = ((*table)->bucket_list)[index];
        ((*table)->bucket_list)[index] = entry;
        (*table)->entries += 1;
        return (0);
    }
    return (-1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   ft_strcmp()
                ft_strlen()
                HASHCODE()
                hash()

DESCRIPTION:    Finds and returns (retrieves) an entry.

RETURN VALUES:  If the entry is found, a pointer to the entry is
                returned; otherwise a NULL pointer is returned.

SEARCH TAGS:    ft hashtable_fetch_entry     ft hashtable_fetch_data
                ft hashtable_find_entry      ft hashtable_lookup_entry
                ft ht_fetch_entry            ft ht_fetch_data
                ft ht_find_entry             ft ht_lookup_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

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



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   ft_entry_free()
                ft_strcmp()
                ft_strlen()
                HASHCODE()
                hash()

DESCRIPTION:    Finds and deletes/frees an entry in the hash
                table.

RETURN VALUES:  If the entry is found, and is successfully
                deleted/free'd, the function returns 0;
                otherwise the function returns -1.

SEARCH TAGS:    ft hashtable_delete_data    ft ht_delete_data
                ft hashtable_delete_entry   ft ht_delete_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

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
                ft_entry_free(&cur_entry);
                (*table)->entries -= 1;
                return (0);
            }
            prev_entry = cur_entry;
            cur_entry = cur_entry->successor;
        }
    }
    return (-1);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   free() , <stdlib.h>
                ft_bucket_free()

DESCRIPTION:    Deletes/frees the entire hash table
                and all the entries contained in it.

RETURN VALUES:  If successful returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_destroy    ft ht_destroy
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

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
                        ft_bucket_free(&((*table)->bucket_list)[i]);
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



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   hashtable_realloc_table()
                hashtable_dealloc_table()
                MAX_LOAD_FACTOR
                MIN_LOAD_FACTOR

DESCRIPTION:    Checks that the current load factor is
                neither greater than nor smaller than
                the desired max load factor and desired
                minimum load factor respectively.

                If either is the case, a procedure to
                realloc (grow) or dealloc (shrink) the
                table will ensue.

                If neither is the case, nothing happens.

RETURN VALUES:  If nothing happens, or a successful
                reallocation or deallocation happens,
                0 is returned. If an error occurs -1
                is returned.

SEARCH TAGS:    ft hashtable_check_load_factor  ft ht_check_load_factor
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

int             hashtable_check_load_factor(t_hashtable **table)
{
    if (table && *table)
    {
        if ((float)(*table)->entries / (float)(*table)->num_buckets
            > MAX_LOAD_FACTOR)
        {
            if (!(*table = hashtable_realloc_table(table)))
                return (-1);
            return (0);
        }
        if ((float)(*table)->entries / (float)(*table)->num_buckets
            < MIN_LOAD_FACTOR)
        {
            if (!(*table = hashtable_dealloc_table(table)))
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



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   free() , <stdlib.h>
                hashtable_alloc_table()
                hashtable_rehash_table()
                hashtable_destroy_table()

DESCRIPTION:    Grows the hash table by half and then some
                (inorder to get to the nearest prime number).

RETURN VALUES:  If successful returns a pointer to the grown
                hash table. Otherwise, if an error occurs the
                function returns a NULL pointer.

SEARCH TAGS:    ft hashtable_realloc_table    ft ht_realloc_table
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

t_hashtable     *hashtable_realloc_table(t_hashtable **table)
{
    t_hashtable     *new_table;

    if (table && *table)
    {
        new_table = hashtable_alloc_table((*table)->num_buckets * 2);
        if (new_table == NULL)
            return (NULL);
        if (hashtable_rehash_table(table, &new_table) == -1)
            return (NULL);
        hashtable_destroy_table(table);
        return (new_table);
    }
    return (NULL);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   free() , <stdlib.h>
                hashtable_alloc_table()
                hashtable_rehash_table()
                hashtable_destroy_table()

DESCRIPTION:    Shrinks the hash table by half and then some
                (inorder to get to the nearest prime number).

RETURN VALUES:  If successful returns a pointer to the shrunk
                hash table. Otherwise, if an error occurs the
                function returns a NULL pointer.

SEARCH TAGS:    ft hashtable_dealloc_table    ft ht_dealloc_table
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

t_hashtable     *hashtable_dealloc_table(t_hashtable **table)
{
    t_hashtable     *new_table;

    if (table && *table)
    {
        if ((*table)->num_buckets > 1)
        {
            new_table = hashtable_alloc_table((*table)->num_buckets / 2);
            if (new_table == NULL)
                return (NULL);
            if (hashtable_rehash_table(table, &new_table) == -1)
                return (NULL);
            hashtable_destroy_table(table);
            return (new_table);
        }
        return (*table);
    }
    return (NULL);
}



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   ft_strlen()
                HASHCODE()
                hash()

DESCRIPTION:    Rehashs one entry in the 'table_to' hashtable.

RETURN VALUES:  If successful returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_rehash_entry  ft ht_rehash_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

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



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   hashtable_rehash_entry()

DESCRIPTION:    Rehashs all the entries in the hashtable
                'table_from' into the hashtable 'table_to'.

RETURN VALUES:  If successful returns 0; otherwise -1.

SEARCH TAGS:    ft hashtable_rehash_table  ft ht_rehash_table
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

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



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   malloc() , <stdlib.h>
                ft_strdup()

DESCRIPTION:    Takes a key and a value and creates an entry out
                of them.

                NOTE: 'value' MUST have previously been
                allocated, otherwise in the free'ing of
                an entry, you WILL get a 'bad free' error.

RETURN VALUES:  If successful, the function returns a pointer
                to the new entry; if an error occurs, it returns
                a NULL pointer.

SEARCH TAGS:    ft entry_create    ft create_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

t_entry         *ft_entry_create(char *key, void *value)
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



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   free() , <stdlib.h>

DESCRIPTION:    Deletes/frees an entry (this is for use with entries that
                have members that were allocated only).

                NOTE: if 'entry->value' was not allocated somewhere in
                the code, you WILL get a 'bad free' error.

RETURN VALUES:  none.

SEARCH TAGS:    ft entry_free    ft free_entry
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void            ft_entry_free(t_entry **entry)
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



/* — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — —
DEPENDENCIES:   ft_entry_free()

DESCRIPTION:    Deletes/frees the entire bucket (linked
                list).

RETURN VALUES:  none.

SEARCH TAGS:    ft bucket_free    ft free_bucket
— — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — — */

void            ft_bucket_free(t_entry **head)
{
    t_entry *temp;

    if (head)
    {
        while (*head)
        {
            temp = (*head);
            (*head) = (*head)->successor;
            ft_entry_free(&temp);
        }
    }
}
