

/* To test crack.c */

#define _XOPEN_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	main(int argc, char const *argv[])
{
	(void)argc;
	printf("%s\n", crypt(argv[1], "12"));
	return (0);
}
