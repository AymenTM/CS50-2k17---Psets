/*
 *
 * Testing grounds.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "ft_trie.c"

#define NUM_BUCKETS 10000000000

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	ft_itoa_base(unsigned int nbr, int base, char (*buf)[13])
{
	int		i;
	int		quotient;
	long	col;

	i = 0;
	col = base;
	while (col <= nbr)
		col *= base;
	while (col > 1)
	{
		col /= base;
		quotient = (nbr / col);
		(*buf)[i++] = quotient + ((quotient < 10) ? '0' : 'W');
		nbr -= (quotient * col);
	}
	(*buf)[i] = '\0';
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	if (!(dest = malloc(i + 1)))
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*http://www.partow.net/programming/hashfunctions/#SDBMHashFunction*/
unsigned int SDBMHash(const char* str, unsigned int length)
{
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = (*str) + (hash << 6) + (hash << 16) - hash;
   }

   return (hash);
}

int		main(int ac, char *av[])
{
	(void)ac;
	(void)av;

	t_trie *root;
	char *s1 = ft_strdup(av[1]);
	char *s2 = ft_strdup(av[2]);
	char *s3 = ft_strdup(av[3]);
 
	// Create root of the trie
	root = trie_create_node();

	// Insert some data
	trie_insert_data_recursive(&root, s1, s1, &alpha_2_indx);
	trie_insert_data_recursive(&root, s2, s2, &alpha_2_indx);
	trie_insert_data_recursive(&root, s3, s3, &alpha_2_indx);

	printf("\n  Hash: %s\nString: '%s'\n\n", s1,(char*)trie_fetch_data(root, s1, &alpha_2_indx));

	trie_delete_data(&root, s1, &alpha_2_indx);

	printf("  Hash: %s\nString: '%s'\n\n", s2,(char*)trie_fetch_data(root, s2, &alpha_2_indx));
	
	trie_delete_data(&root, s2, &alpha_2_indx);	

	printf("  Hash: %s\nString: '%s'\n\n", s3,(char*)trie_fetch_data(root, s3, &alpha_2_indx));

	printf("Current Trie Size: %d\n\n", trie_size(root));

	trie_destroy(&root);

	return (0);
}
