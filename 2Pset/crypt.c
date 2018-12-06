
/* To test crack.c */

#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
    	printf("Usage: ./crypt password salt\n");
    	return (1);
    }
    printf("%s\n", crypt(argv[1], argv[2]));
    return (0);
}
