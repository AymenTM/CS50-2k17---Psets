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

uint32_t hash(const char* data, size_t len);






// MAIN =======================================================================

int main(int ac, char *av[])
{

	(void)ac;
	printf("%u\n", hash(av[1], strlen(av[1])) % 1000);
	return (0);
}
