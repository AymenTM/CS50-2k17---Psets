/*
*
*  TEST MAIN FRAMEWORK.
*
*/

// HEADERS ====================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// FUNCTIONS ==================================================================

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
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

uint32_t hash(const char* data, size_t len);

#include "hashtab.c"

// MAIN =======================================================================

int main(int ac, char *av[])
{
	if (ac < 7)
	{
		printf("Usage: ./a str1 str2 str3 str4 str5 str6\n");
		return (0);
	}

	t_hashtable *hashtab;

	printf("——————————————————————————\nCreation:\n\n");
	printf("Hash Table Address: %p\n\n", hashtab = hashtable_alloc_table(100));

	printf("——————————————————————————\nInsertion:\n\n");
	printf("#1:	[%d]\n", hashtable_insert_entry(&hashtab, ft_strdup(av[1]), ft_strdup("aymen")));
	printf("#2:	[%d]\n", hashtable_insert_entry(&hashtab, ft_strdup(av[2]), ft_strdup("check")));
	printf("#3:	[%d]\n", hashtable_insert_entry(&hashtab, ft_strdup(av[3]), ft_strdup("this")));
	printf("#4:	[%d]\n", hashtable_insert_entry(&hashtab, ft_strdup(av[4]), ft_strdup("hash")));
	printf("#5:	[%d]\n", hashtable_insert_entry(&hashtab, ft_strdup(av[5]), ft_strdup("table")));
	printf("#6:	[%d]\n\n", hashtable_insert_entry(&hashtab, ft_strdup(av[6]), ft_strdup("out!")));

	printf("——————————————————————————\nRetrieval:\n\n");
	printf("#1: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[1])->value));
	printf("#2: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[2])->value));
	printf("#3: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[3])->value));
	printf("#4: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[4])->value));
	printf("#5: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[5])->value));
	printf("#6: %s\n\n", (void*)(hashtable_fetch_entry(hashtab, av[6])->value));

	printf("Number of current entries: %d\n\n", hashtab->entries);

	printf("——————————————————————————\nDeletion:\n\n");
	printf("#1:	[%d]\n", hashtable_delete_entry(&hashtab, av[1]));
	printf("#2:	[%d]\n", hashtable_delete_entry(&hashtab, av[2]));
	printf("#3:	[%d]\n", hashtable_delete_entry(&hashtab, av[3]));
	printf("#4:	[%d]\n", hashtable_delete_entry(&hashtab, av[4]));
	printf("#5:	[%d]\n", hashtable_delete_entry(&hashtab, av[5]));
	printf("#6:	[%d]\n\n", hashtable_delete_entry(&hashtab, av[6]));

	printf("Number of current entries: %d\n\n", hashtab->entries);

	printf("——————————————————————————\nDestruction:\n\n");
	printf("Destroy Status: %d\n", hashtable_destroy_table(&hashtab));
	printf("Hashtab: %p\n\n", hashtab);

	printf("——————————————————————————\n\n");

	return (0);
}
