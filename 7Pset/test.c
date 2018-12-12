
#include <stdio.h>

#define ISALNUM(c) (ISALPHA(c) || ISNUM(c))
#define ISALPHA(c) ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
#define ISUPPER(c) (c >= 'A' && c <= 'Z')
#define ISLOWER(c) (c >= 'a' && c <= 'z')
#define ISNUM(c) ((c >= '0' && c <= '9'))

char	*ft_strcapitalize(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		while (str[i] && !ISALNUM(str[i]))
			i++;
		if (str[i] && ISLOWER(str[i]))
			str[i] = str[i] - 32;
		while (str[i] && ISALNUM(str[i++]))
			if (ISUPPER(str[i]))
				str[i] = str[i] + 32;
	}
	return (str);
}

/*
 *
 * TEST MAIN FRAMEWORK
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int ac, char *av[])
{
	(void)ac;
	printf("%s\n", ft_strcapitalize(av[1]));
	return (0);
}






// find . \( -name '*.dSYM' -or -name '*.o' -or -name 'a' -or -name 'a.out' -or -name '.DS*' -or -name '._DS*' -or -name 'test_run.*' \) -exec rm -rf {} \;



// find .
//         (
//             -name '*.dSYM'
//             -or -name '*.o'
//             -or -name 'a'
//             -or -name 'a.out'
//             -or -name '.DS*'
//             -or -name '._DS*'
//             -or -name 'test_run.*'
//         ) -exec rm -rf {} ;







    echo ——————————————————————————————————————————————; \
    echo Deleted Files: ; \
    echo ; \
    find . \
        \( \
            -name '*.dSYM' \
            -or -name '*.o' \
            -or -name 'a' \
            -or -name 'a.out' \
            -or -name '.DS*' \
            -or -name '._DS*' \
            -or -name 'test_run.*' \
        \) \
        -exec rm -rf {} \; \
        find . -type d \
            \( \
                -name '*.dSYM' \
                -or -name '.DS*' \
                -or -name '._DS*' \
            \) \
            -exec rm -r {} \; \
    \
    echo ; \
    echo ——————————————————————————————————————————————; \
    echo ; \
    ls"







