/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "dictionary.h"
#include "hashtable.h"
#include "utils.h"

#define INIT_SIZE 100

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char s[46];

    return (hashtable_fetch_entry(g_hashtab, ft_strlowercase(s, (char*)word)) ?
     true : false);
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE*           fp;
    char            c;
    char            word[LENGTH + 1];
    unsigned int    index;

    if ((fp = fopen(dictionary, "r")) == NULL)
        return (false);

    g_hashtab = hashtable_alloc_table(INIT_SIZE);

    while ((c = fgetc(fp)) != EOF)
    {
        index = 0;
        while (c != '\n' && c != EOF)
        {
            word[index++] = c;
            c = fgetc(fp);
        }
        g_size++;
        word[index] = '\0';
        hashtable_insert_entry(&g_hashtab, word, ft_strdup(word));
    }

    // check whether there was an error
    if (ferror(fp))
    {
        fclose(fp);
        return (false);
    }

    // close dictionary
    fclose(fp);

    // success
    return (true);
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return (g_size);
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    hashtable_destroy_table(&g_hashtab);
    return ((g_hashtab == NULL) ? true : false);
}
