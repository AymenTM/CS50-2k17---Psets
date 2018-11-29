// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                hashtable.h                              //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/* * * * * * * * * * * *
========================
    HASH TABLE HEADER
========================
 * * * * * * * * * * * */

#ifndef FT_HASHTABLE_H
# define FT_HASHTABLE_H

# define HASH(key, keylen) (hash((const)key, keylen))

# define MIN_LOAD_FACTOR 0.1
# define MAX_LOAD_FACTOR 0.7

typedef struct		s_entry
{
	char			*key;
	void			*value;
	unsigned int 	keylen;
	struct s_entry	*successor;
}					t_entry;

typedef struct		s_hashtable
{
	unsigned int	entries;
	unsigned int	num_buckets;
	t_entry			**buckets;
}					t_hashtable;

#endif


/**
DEPENDENCIES:	malloc, <stdlib.h>

DESCRIPTION:	Creates an empty hash table.

RETURN VALUES:	If successful, returns a pointer to the
				hash table. If an error occurs the function
				will return a NULL pointer.

SEARCH TAGS:	ft hashtable_alloc_table  	ft hashtable_create_table 
				ft ht_alloc_table  			ft ht_create_table
*/
t_hashtable		*hashtable_alloc_table(unsigned int size)
{
	t_hashtable 	*table;
	unsigned int 	i;

	if (size < 1)
		return (NULL);
	if (!(table = malloc(sizeof(t_hashtable))))
		return (NULL);
 	if (!(table->hashtab = malloc(sizeof(t_entry*) * size)))
 		return (NULL);
	table->num_buckets = size;
	table->entries = 0;
	i = 0;
	while (i < size)
		(table->hashtab)[i] = NULL;
	return (table);
}

/**
DEPENDENCIES:	ft_create_entry()
				HASH()

DESCRIPTION:	Inserts a key-value pair (an entry) into the hash
				table.

RETURN VALUES:	If successful, returns 0; otherwise -1.

SEARCH TAGS:	ft hashtable_insert_data  	ft hashtable_add_entry 
				ft ht_insert_data  			ft ht_add_entry
*/
int				hashtable_insert_data(t_hashtable **table,
										char *key,
										void *data)
{
	t_entry			*entry;
	unsigned int	index;

	if (table && *table && key && data)
	{
		if (!(entry = ft_create_entry(key, data)))
			return (-1);
		index = HASH(entry->key, entry->keylen) % table->num_buckets;
		entry->successor = ((*table)->buckets)[index];
		((*table)->buckets)[index] = entry;
		return (0);
	}
	return (-1);
}

/**
DEPENDENCIES:	none.

DESCRIPTION:	Retrieves an entry.

RETURN VALUES:	If the entry is found, a pointer to the entry is
				returned; otherwise a NULL pointer is returned.

SEARCH TAGS:	ft hashtable_fetch_entry   	ft hashtable_fetch_data
				ft hashtable_find_entry   	ft hashtable_find_data
				ft hashtable_lookup_entry   ft hashtable_lookup_data
				ft hashtable_get_entry   	ft hashtable_get_data
				ft ht_fetch_entry   		ft ht_fetch_data
				ft ht_find_entry    		ft ht_find_data
				ft ht_lookup_entry   		ft ht_lookup_data
				ft ht_get_entry   			ft ht_get_data
*/
t_entry			*hashtable_fetch_entry(t_hashtable *table, char *key)
{
	t_entry			*cur_entry;
	unsigned int	index;

	if (table && key)
	{
		index = HASH(entry->key, entry->keylen) % table->num_buckets;
		cur_entry = table->buckets[index];
		while (cur_entry)
		{
			if (ft_strcmp(cur_entry->key, key) == 0)
				return (cur_entry);
			cur_entry = cur_entry->successor;
		}
	}
	return (NULL);
}

/**
DEPENDENCIES:	none.

DESCRIPTION:	.

RETURN VALUES:	If successful returns 0; otherwise -1.

SEARCH TAGS:	ft hashtable_delete_data  ft ht_delete_data
*/
int				hashtable_delete_data(t_hashtable **table, char *key)
{

}

/**
DEPENDENCIES:	none.

DESCRIPTION:	.

RETURN VALUES:	If successful returns 0; otherwise -1.

SEARCH TAGS:	ft hashtable_destroy  ft ht_destroy
*/
int				hashtable_destroy(t_hashtable **table)
{
	
}

/**
DEPENDENCIES:	none.

DESCRIPTION:	.

RETURN VALUES:	If successful returns 0; otherwise -1.

SEARCH TAGS:	ft hashtable_realloc_table  ft ht_realloc_table
*/
t_hashtable		*hashtable_realloc_table()
{

}

/**
DEPENDENCIES:	none.

DESCRIPTION:	.

RETURN VALUES:	If successful returns 0; otherwise -1.

SEARCH TAGS:	ft hashtable_dealloc  ft ht_dealloc
*/
t_hashtable		*hashtable_dealloc()
{

}

/**
DEPENDENCIES:	none.

DESCRIPTION:	.

RETURN VALUES:	If successful returns 0; otherwise -1.

SEARCH TAGS:	ft hashtable_size  ft ht_size
*/
unsigned int	hashtable_size(const t_hashtable *table)
{

}

/**
DEPENDENCIES:	none.

DESCRIPTION:	.

RETURN VALUES:	If successful returns 0; otherwise -1.

SEARCH TAGS:	ft hashtable_sizeof  ft ht_sizeof
*/
size_t			hashtable_sizeof(const t_hashtable *table)
{

}

/**
DEPENDENCIES:	none.

DESCRIPTION:	clears node value if it exists.

RETURN VALUES:	If successful returns 0; otherwise -1.

SEARCH TAGS:	ft hashtable_clear_val  ft ht_clear_val
*/
int				hashtable_clear_val(t_hashtable **table, char *key)
{

}

/**
DEPENDENCIES:	hashtable_realloc_table()
				hashtable_dealloc_table()

DESCRIPTION:	Checks that the current load factor is
				neither greater than the desired max
				load factor nor is smaller than the
				desired minimum load factor.

				If either is the case, a procedure to
				realloc (grow) or dealloc (shrink) the
				table will take place.

				If neither is the case, nothing happens.

RETURN VALUES:	If nothing happens the function returns 0.

				If a successful reallocation of the table happens, it returns 2.
				If a successful deallocation happens, it returns 1.

				If an unsuccessful reallocation or deallocation happens,
				it returns -1.

SEARCH TAGS:	ft hashtable_check_load_factor  ft ht_check_load_factor
*/
int				hashtable_check_load_factor(t_hashtable **table)
{
	if ((float)(*table)->entries / (float)(*table)->num_buckets
		> MAX_LOAD_FACTOR)
	{
		*table = hashtable_realloc_table(*table);
		return ((*table == NULL) ? -1 : 2);
	}
	if ((float)(*table)->entries / (float)(*table)->num_buckets
		< MIN_LOAD_FACTOR)
	{
		*table = hashtable_dealloc_table(*table);
		return ((*table == NULL) ? -1 : 1);
	}
	return (0);
}

/**
DEPENDENCIES:	malloc, <stdlib.h>, ft_strdup, ft_strlen

DESCRIPTION:	Takes a key and a value and creates an entry out
				of them.

RETURN VALUES:	If successful, it returns a pointer to the new entry;
				if an error occurs, it returns a NULL pointer.

SEARCH TAGS:	ft create_entry
*/
t_entry			*ft_create_entry(char *key, void *value)
{
	t_entry *new_entry;

	if (key && value)
	{
		if (!(new_entry = malloc(sizeof(t_entry*))))
			return (NULL);
		new_entry->key = ft_strdup(key);
		new_entry->value = data;
		new_entry->keylen = ft_strlen(key);
		return (new_entry);
	}
	return (NULL);
}
