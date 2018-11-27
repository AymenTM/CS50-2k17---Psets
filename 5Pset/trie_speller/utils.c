/**
 *
 * Some trie functions.
 *
 */

#include <stdlib.h>
#include <unistd.h>

#include "dictionary.h"
#include "utils.h"

/**
DEPENDENCIES: none.
ft alpha_2_indx ; turns a given alphabetical letter
character into the index it corresponds to.
*/
int			alpha_2_indx(char c)
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
*/
t_trie			*trie_create_node(void)
{
	t_trie *new_node;
	unsigned int i;

	if (!(new_node = malloc(sizeof(t_trie))))
		return (NULL);
	new_node->end = 0;
	i = 0;
	while (i < ALPHABET_SIZE)
		(new_node->children)[i++] = NULL;
	return (new_node);
}

/**
DEPENDENCIES: trie_create_node
ft trie_load_word ; adds a word to the trie data-structure.
*/
void			trie_load_word(t_trie **root, char *word,
				int (*char_to_index)(char c))
{
	t_trie			*cur_node;
	unsigned int	index;

	if (root && *root && word)
	{
		cur_node = (*root);
		while (*word != '\0')
		{
			index = char_to_index(*word);
			if ((cur_node->children)[index] == NULL)
				(cur_node->children)[index] = trie_create_node();
			cur_node = (cur_node->children)[index];
			word++;
		}
		cur_node->end = 1;
	}
}

void		trie_load_word_recursive(t_trie **root, char *word,
			int (*char_to_index)(char c))
{
	int index;

	if (root && *root && word)
	{
		if (*(word) != '\0')
		{
			index = char_to_index(*word);
			if (((*root)->children)[index] == NULL)
				((*root)->children)[index] = trie_create_node();
			trie_load_word(
				(&((*root)->children)[index]), word + 1, char_to_index);
		}
		else
			(*root)->end = 1;
	}
}

/**
DEPENDENCIES: free, <stdlib.h>
ft trie_unload_word ; deletes a word from the trie data-structure.
*/
void		trie_unload_word(t_trie **root, char *word,
			int (*char_to_index)(char c))
{
	int index;

	if (root && *root && word)
	{
		if (*word == '\0')
			(*root)->end = 0;
		else
		{
			index = char_to_index(*word);
			if (((*root)->children)[index])
				trie_unload_word(
					&(((*root)->children)[index]), word + 1, char_to_index);
		}
		if ((*root)->end)
			return ;
		index = 0;
		while (index < ALPHABET_SIZE)
			if (((*root)->children)[index++])
				return ;
		free(*root);
		(*root) = NULL;
	}
}

/**
DEPENDENCIES: free, <stdlib.h>
ft trie_destroy ; deletes/unloads the entire trie data-structure.
*/
void		trie_destroy(t_trie **root)
{
	int i;

	if (root && *root)
	{
		i = 0;
		while (i < ALPHABET_SIZE)
		{
			if (((*root)->children)[i])
				trie_destroy(&(((*root)->children)[i]));
			i++;
		}
		free(*root);
		(*root) = NULL;
	}
}

/**
DEPENDENCIES: none.
ft trie_check_word ; checks whether or not a given word exists
in the trie data-structure (i.e checks if the spelling of the
given word is correct).
*/
int			trie_check_word(t_trie *root, char *word,
			int (*char_to_index)(char c))
{
	unsigned int index;

	if (root && word)
	{
		if (*word == '\0')
			return (root->end);
		index = char_to_index(*word);
		return (trie_check_word(
			(root->children)[index], word + 1, char_to_index));
	}
	return (0);
}

/**
DEPENDENCIES: write, <unistd.h>
ft trie_print_words ; prints all the existing words in the
trie data-structure.
*/
void		trie_print_words(t_trie *root, char word[LENGTH + 1])
{
	static int index = 0;
	int i;

	if (root)
	{
		if (root->end == 1)
		{
			word[index] = '\0';
			write(1, word, index);
			write(1, "\n", 1);
		}
		i = 0;
		while (i < ALPHABET_SIZE)
		{
			if (root->children[i])
			{
				word[index] = i + 97;
				index++;
				trie_print_words(root->children[i], word);
				index--;
			}
			i++;
		}
	}
}

/**
DEPENDENCIES: free, <stdlib.h>
ft trie_size ; counts & returns the number of words
currently held in the trie data-structure.
*/
unsigned int	trie_size(t_trie *root)
{
	unsigned int word_count;
	unsigned int i;

	if (root)
	{
		word_count = 0;
		if (root->end)
			word_count++;
		i = 0;
		while (i < ALPHABET_SIZE)
		{
			if (root->children[i])
				word_count += trie_size(root->children[i]);
			i++;
		}
		return (word_count);
	}
	return (0);
}
