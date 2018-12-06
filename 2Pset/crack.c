/* * * * * * * * * * * * * * * #
# ============================ #
#        CS50 - crack.c        #
# ============================ #
# * * * * * * * * * * * * * * */

#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ISALPHA(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
#define MATCH_FOUND(hash, passwd, salt) (strcmp(hash, crypt(passwd, salt)) == 0)

int total_chars = 0;

/* ==================================================================== #
#                                                                       #
#   SYNOPSIS:       crack(hsh)                                          #
#                                                                       #
#   DESCRIPTION:    Cycles through all the possible characters          #
#                   for index 0; does so once when we have a            #
#                   1 character password, and once again when           #
#                   we have a 2 character password, and again           #
#                   for a 3, 4 & 5 character password.                  #
#                                                                       #
#                   If the password is cracked it or its recursive      #
#                   helper function will print the cracked password     #
#                   to screen and return back to the initial call,      #
#                   returning 1 as a final return value.                #
#                                                                       #
#   RETURN VALUES:  Returns 1 if the password is found; otherwise       #
#                   0.                                                  #
#                                                                       #
# ===================================================================== */

int        crack_furthur(char *hash, char *salt, char passwd[6], int index)
{
    int found;

    found = 0;
    passwd[index] = 'A';
    while (ISALPHA(passwd[index]))
    {
        if (total_chars > index)
            found = crack_furthur(hash, salt, passwd, index + 1);
        else if (MATCH_FOUND(hash, passwd, salt))
        {
            printf("%s\n", passwd);
            return (1);
        }
        if (found)
            return (1);
        if (passwd[index] == 'Z')
            passwd[index] = 'a' - 1;
        passwd[index]++;
    }
    return (0);
}

/* ==================================================================== #
#                                                                       #
#   SYNOPSIS:       crack_furthur(hsh, passwd, salt, index)             #
#                                                                       #
#   DESCRIPTION:    Cycles through all the possible characters          #
#                   for the current index.                              #
#                                                                       #
#                   If the password is cracked it will print the        #
#                   cracked password to screen and return back to       #
#                   the initial call, returning 1 as a final return     #
#                   value.                                              #
#                                                                       #
#   RETURN VALUES:  Returns 1 if the password is found; otherwise       #
#                   0.                                                  #
#                                                                       #
# ===================================================================== */

int        crack(char *hash, char *salt)
{
    char  passwd[6] = "A\0\0\0\0\0";
    int   found;

    found = 0;
    while (total_chars < 5)
    {
        while (ISALPHA(passwd[0]))
        {
            if (total_chars > 0)
                found = crack_furthur(hash, salt, passwd, 1);
            else if (MATCH_FOUND(hash, passwd, salt))
            {
                printf("%s\n", passwd);
                return (1);
            }
            if (found)
                return (1);
            if (passwd[0] == 'Z')
                passwd[0] = 'a' - 1;
            passwd[0]++;
        }
        total_chars++;
        passwd[0] = 'A';
    }
    return (0);
}

int        main(int argc, char *argv[])
{
    char  *salt;
    int   found;

    if (argc == 2)
    {
        salt = strdup(argv[1]);
        salt[2] = '\0';
        found = crack(argv[1], salt);
        free(salt);
        return ((found) ? 0 : 1);
    }
    printf("Usage: ./crack hash\n");
    return (1);
}
