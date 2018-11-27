/**
 *
 * Header.
 *
 */

#ifndef UTILS_H
# define UTILS_H

# define ALPHABET_SIZE 27

typedef unsigned char t_bool;

typedef struct	s_trie
{
	t_bool			end;
	struct s_trie	*children[ALPHABET_SIZE];
}
t_trie;

extern t_trie 			*g_root;
extern unsigned int 	g_size;

int				alpha_2_indx(char c);

t_trie			*trie_create_node(void);

void			trie_load_word(t_trie **root, char *word,
				int (*char_to_index)(char c));

void			trie_unload_word(t_trie **root, char *word,
				int (*char_to_index)(char c));

void			trie_destroy(t_trie **root);

int				trie_check_word(t_trie *root, char *word,
				int (*char_to_index)(char c));

void			trie_print_words(t_trie *root, char word[LENGTH + 1]);

unsigned int	trie_size(t_trie *root);

#endif
