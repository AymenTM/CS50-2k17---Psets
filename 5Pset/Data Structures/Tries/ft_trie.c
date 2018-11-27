// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
// ======================================================================= //
//                                  trie.h                                 //
// ======================================================================= //
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

/* * * * * * * * * * * *
========================
       TRIE HEADER
========================
 * * * * * * * * * * * */

#ifndef FT_TRIE_H
# define FT_TRIE_H

# define ALPHABET_SIZE 27
# define HEXDIGIT_SIZE 16
# define SIZE_OF_ARRAY ALPHABET_SIZE

typedef struct			s_trie
{
	void				*data;
	struct s_trie		*children[SIZE_OF_ARRAY];
}						t_trie;

unsigned int	char_2_indx(char c);

unsigned int	alpha_2_indx(char c);

t_trie			*trie_create_node(void);

void			trie_insert_data(t_trie **root, char *hash, void *data,
				unsigned int (*char_to_index)(char c));

void			trie_insert_data_recursive(t_trie **root, char *hash,
				void *data, unsigned int (*char_to_index)(char c));

void			trie_delete_data(t_trie **root, char *hash,
				unsigned int (*char_to_index)(char c));
void			trie_destroy(t_trie **root);

void			*trie_fetch_data(t_trie *root, char *hash,
				unsigned int (*char_to_index)(char c));

unsigned int	trie_size(t_trie *root);

#endif

/**
DEPENDENCIES: none.
ft char_2_indx ; turns a given character into the
index it corresponds to.

HALF TESTED !
NOT NORMED !
*/
unsigned int				char_2_indx(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	else if (c >= 'a' && c <= 'z')
	{
		return (c - 'a' + 10);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (c - 'A' + 10);
	}
	else if (c == '\'')
	{
		return (36);
	}
	return (0);
}

/**
DEPENDENCIES: none.
ft alpha_2_indx ; turns a given alphabetical letter
character into the index it corresponds to.

HALF TESTED !
NOT NORMED !
*/
unsigned int				alpha_2_indx(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 97);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (c - 65);
	}
	else if (c == '\'')
	{
		return (26);
	}
	return (0);
}

/**
DEPENDENCIES: malloc, <stdlib.h>
ft trie_create_node ; creates a trie node & returns a pointer
to the node.

HALF TESTED !
NOT NORMED !
*/
t_trie			*trie_create_node(void)
{
	t_trie *new_node;
	unsigned int i;

	if (!(new_node = malloc(sizeof(t_trie))))
		return (NULL);
	new_node->data = NULL;
	i = 0;
	while (i < SIZE_OF_ARRAY)
		(new_node->children)[i++] = NULL;
	return (new_node);
}

/**
DEPENDENCIES: trie_create_node
ft trie_insert_data ; creates & inserts given data into a trie data-structure.

HALF TESTED !
NOT NORMED !
*/
void			trie_insert_data(t_trie **root, char *hash, void *data,
				unsigned int (*char_to_index)(char c))
{
	t_trie			*cur_node;
	unsigned int	index;

	if (root && *root && hash)
	{
		cur_node = (*root);
		while (*hash != '\0')
		{
			index = char_to_index(*hash);
			if ((cur_node->children)[index] == NULL)
				(cur_node->children)[index] = trie_create_node();
			cur_node = (cur_node->children)[index];
			hash++;
		}
		cur_node->data = data;
	}
}

void			trie_insert_data_recursive(t_trie **root, char *hash,
				void *data, unsigned int (*char_to_index)(char c))
{
	unsigned int index;

	if (root && *root && hash)
	{
		if (*hash != '\0')
		{
			index = char_to_index(*hash);
			if (((*root)->children)[index] == NULL)
				((*root)->children)[index] = trie_create_node();
			trie_insert_data(
				(&((*root)->children)[index]), hash + 1, data, char_to_index);
		}
		else
			(*root)->data = data;
	}
}

/**
DEPENDENCIES: free, <stdlib.h>
ft trie_delete_data ; deletes the data that is mapped to the hash
and only the leaf nodes that do not contain any data that lead to
the deleted node.

HALF TESTED !
NOT NORMED !
*/
void			trie_delete_data(t_trie **root, char *hash,
				unsigned int (*char_to_index)(char c))
{
	unsigned int index;

	if (root && *root && hash)
	{
		if (*hash == '\0')
		{
			free((*root)->data);
			(*root)->data = NULL;
		}
		else
		{
			index = char_to_index(*hash);
			if (((*root)->children)[index])
				trie_delete_data(
					&(((*root)->children)[index]), hash + 1, char_to_index);	
		}
		if ((*root)->data)
			return ;
		index = 0;
		while (index < SIZE_OF_ARRAY)
			if (((*root)->children)[index++])
				return ;
		free(*root);
		(*root) = NULL;
	}
}

/**
DEPENDENCIES: free, <stdlib.h>
ft trie_destroy ; frees up the entire trie data-structure
(deleteing every node of the trie and all the data
contained within it).

HALF TESTED !
NOT NORMED !
*/
void			trie_destroy(t_trie **root)
{
	unsigned int i;

	if (root && *root)
	{
		i = 0;
		while (i < SIZE_OF_ARRAY)
		{
			if (((*root)->children)[i])
				trie_destroy(&(((*root)->children)[i]));
			i++;
		}
		if ((*root)->data)
		{
			free((*root)->data);
			(*root)->data = NULL;
		}
		free(*root);
		(*root) = NULL;
	}
}

/**
DEPENDENCIES: none.
ft trie_fetch_data ; retrieves the data that is mapped to the hash.
Returns an address to the data.

HALF TESTED !
NOT NORMED !
*/
void			*trie_fetch_data(t_trie *root, char *hash,
				unsigned int (*char_to_index)(char c))
{
	unsigned int index;

	if (root && hash)
	{
		if (*hash == '\0')
			return (root->data);
		index = char_to_index(*hash);
		return (trie_fetch_data(
			(root->children)[index], hash + 1, char_to_index));
	}
	return (NULL);
}

/**
DEPENDENCIES: none.
ft trie_size ; counts & returns the number of data elements currently
stored within the trie data-structure.

HALF TESTED !
NOT NORMED !
*/
unsigned int	trie_size(t_trie *root)
{
	unsigned int data_count;
	unsigned int i;

	if (root)
	{
		data_count = 0;
		if (root->data)
			data_count++;
		i = 0;
		while (i < SIZE_OF_ARRAY)
		{
			if (root->children[i])
				data_count += trie_size(root->children[i]);
			i++;
		}
		return (data_count);
	}
	return (0);
}
