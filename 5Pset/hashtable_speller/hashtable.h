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

t_hashtable     *hashtable_alloc_table(unsigned int num_entries);
int             hashtable_grow_table(t_hashtable **table);
int             hashtable_shrink_table(t_hashtable **table);

t_entry         *hashtable_fetch_entry(t_hashtable *table, char *key);
int             hashtable_insert_entry(t_hashtable **table,
                                       char *key,
                                       void *value);
int             hashtable_delete_entry(t_hashtable **table, char *key);
int             hashtable_rehash_entry(t_hashtable **table_to,
                                       t_entry **entry);
int             hashtable_rehash_table(t_hashtable **table_from,
                                       t_hashtable **table_to);
int             hashtable_destroy_table(t_hashtable **table);
int             hashtable_set_appropriate_load_factor(t_hashtable **table);

t_entry         *entry_create(char *key, void *value);
void            entry_free(t_entry **entry);
void            bucket_free(t_entry **head);

#endif
