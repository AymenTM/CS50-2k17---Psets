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

#include "hashtab.h"
#include "utils.h"
#include "murmurhash3/murmurhash3.h"

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
	printf("#1:	[%d]\n", hashtable_insert_entry(&hashtab, ft_strdup(av[1]), ft_strdup("yo")));
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

	printf("Buckets: %d\n\n", hashtab->num_buckets);

	printf("——————————————————————————\nDeallocation:\n\n");
	printf("Deallocated Hash Table Address: [%p]\n", hashtab = hashtable_dealloc_table(&hashtab));
	printf("Buckets: %d\n\n", hashtab->num_buckets);

	printf("——————————————————————————\nDeallocation:\n\n");
	printf("Deallocated Hash Table Address: [%p]\n", hashtab = hashtable_dealloc_table(&hashtab));
	printf("Buckets: %d\n\n", hashtab->num_buckets);

	printf("——————————————————————————\nDeallocation:\n\n");
	printf("Deallocated Hash Table Address: [%p]\n", hashtab = hashtable_dealloc_table(&hashtab));
	printf("Buckets: %d\n\n", hashtab->num_buckets);

	printf("——————————————————————————\nRetrieval:\n\n");
	printf("#1: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[1])->value));
	printf("#2: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[2])->value));
	printf("#3: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[3])->value));
	printf("#4: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[4])->value));
	printf("#5: %s\n", (void*)(hashtable_fetch_entry(hashtab, av[5])->value));
	printf("#6: %s\n\n", (void*)(hashtable_fetch_entry(hashtab, av[6])->value));

	printf("Number of current entries: %d\n\n", hashtab->entries);

	printf("——————————————————————————\nReallocation:\n\n");
	printf("Reallocated Hash Table Address: [%p]\n", hashtab = hashtable_realloc_table(&hashtab));
	printf("Buckets: %d\n\n", hashtab->num_buckets);

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
	printf("Destroy Status: [%d]\n", hashtable_destroy_table(&hashtab));
	printf("Hashtable: %p\n\n", hashtab);

	printf("——————————————————————————\n\n");

	return (0);
}
