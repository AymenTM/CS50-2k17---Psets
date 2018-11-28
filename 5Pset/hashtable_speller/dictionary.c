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
#include "utils.h"

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    return (
        (hash_check_word(g_root, (char*)word, &alpha_2_indx) == 1)
            ? true : false);
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

    g_root = trie_create_node();

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
        trie_load_word(&g_root, word, &alpha_2_indx);
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
    trie_destroy(&g_root);
    return ((g_root == NULL) ? true : false);
}
