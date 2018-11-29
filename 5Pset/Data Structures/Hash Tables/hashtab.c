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

# define HASHCODE(key, buckets) (hash(key, ft_strlen(key)) % buckets)

# define MIN_LOAD_FACTOR 0.1
# define MAX_LOAD_FACTOR 0.7

typedef struct		s_entry
{
	char			*key;
	void			*value;
	struct s_entry	*successor;
}					t_entry;

typedef struct		s_hashtable
{
	unsigned int	entries;
	unsigned int	num_buckets;
	t_entry			**buckets;
}					t_hashtable;

t_hashtable		*hashtable_alloc_table(unsigned int size);
t_hashtable		*hashtable_realloc_table(t_hashtable *table);
t_hashtable		*hashtable_dealloc_table(t_hashtable *table);

t_entry			*ft_entry_create(char *key, void *value);

t_entry			*hashtable_fetch_entry(t_hashtable *table, char *key);
int				hashtable_insert_entry(t_hashtable **table, char *key,
				void *value);
int				hashtable_delete_entry(t_hashtable **table, char *key);

int				hashtable_destroy_table(t_hashtable **table);
int				hashtable_check_load_factor(t_hashtable **table);

void			ft_entry_free(t_entry **entry);
void			ft_bucket_free(t_entry **head);

#endif


/* creates an empty hash table */
t_hashtable		*hashtable_alloc_table(unsigned int size)
{
	t_hashtable		*table;
	unsigned int	i;

	if (size < 1)
		return (NULL);
	if (!(table = malloc(sizeof(t_hashtable))))
		return (NULL);
	if (!(table->buckets = malloc(sizeof(t_entry*) * size)))
		return (NULL);
	table->num_buckets = size;
	table->entries = 0;
	i = 0;
	while (i < size)
		(table->buckets)[i++] = NULL;
	return (table);
}

/* inserts a key-value pair (an entry) into the hash table */
int				hashtable_insert_entry(t_hashtable **table, char *key,
				void *value)
{
	t_entry			*entry;
	unsigned int	index;

	if (table && *table && key && value)
	{
		if (!(entry = ft_entry_create(key, value)))
			return (-1);
		index = HASHCODE(key, (*table)->num_buckets);
		entry->successor = ((*table)->buckets)[index];
		((*table)->buckets)[index] = entry;
		(*table)->entries += 1;
		return (0);
	}
	return (-1);
}

/* retrieves an entry */
t_entry			*hashtable_fetch_entry(t_hashtable *table, char *key)
{
	t_entry			*cur_entry;
	unsigned int	index;

	if (table && key)
	{
		index = HASHCODE(key, table->num_buckets);
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

/* finds and deletes/frees an entry in the hash table */
int				hashtable_delete_entry(t_hashtable **table, char *key)
{
	t_entry			*prev_entry;
	t_entry			*cur_entry;
	unsigned int	index;

	if (table && key)
	{
		index = HASHCODE(key, (*table)->num_buckets);
		cur_entry = ((*table)->buckets)[index];
		while (cur_entry)
		{
			if (ft_strcmp(cur_entry->key, key) == 0)
			{
				if (cur_entry == ((*table)->buckets)[index])
					((*table)->buckets)[index] = cur_entry->successor;
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

/* deletes/frees the entire hash table and all the entries left in it */
int				hashtable_destroy_table(t_hashtable **table)
{
	unsigned int	i;

	if (table)
	{
		if (*table)
		{
			if ((*table)->buckets)
			{
				i = 0;
				while (i < (*table)->num_buckets)
				{
					ft_bucket_free(&((*table)->buckets)[i]);
					i++;
				}
				free((*table)->buckets);
				(*table)->buckets = NULL;
			}
			free(*table);
			(*table) = NULL;
		}
		return (0);
	}
	return (-1);
}

/* grows table size */
t_hashtable		*hashtable_realloc_table(t_hashtable *table)
{
	return (table);
}

/* shrinks table size */
t_hashtable		*hashtable_dealloc_table(t_hashtable *table)
{
	return (table);
}

/* updates table size if necessary */
int				hashtable_check_load_factor(t_hashtable **table)
{
	if (table && *table)
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
	return (-2);
}

/* takes a key and a value and creates an entry out of them */
t_entry			*ft_entry_create(char *key, void *value)
{
	t_entry *new_entry;

	if (key && value)
	{
		if (!(new_entry = malloc(sizeof(t_entry))))
			return (NULL);
		new_entry->key = key;
		new_entry->value = value;
		return (new_entry);
	}
	return (NULL);
}

/* deletes/frees an entry */
void			ft_entry_free(t_entry **entry)
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
void			ft_bucket_free(t_entry **head)
{
	t_entry	*temp;

	if (head)
	{
		while (*head)
		{
			temp = *head;
			*head = (*head)->successor;
			ft_entry_free(&temp);
		}
	}
}
