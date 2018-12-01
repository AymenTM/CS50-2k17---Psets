
/* ===============================================================
                            UTILIY FUNCTIONS
   =============================================================== */

#include <stdlib.h>

/* reproduction of the standard library strlen() function */
int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

/* reproduction of the standard library strcmp() function */
int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/* reproduction of the standard library strdup() function */
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

/* checks whether the number 'nb' is a prime number */
int		ft_is_prime(int nb)
{
	long i;
	long result;

	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3 || nb == 5 || nb == 7)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0)
		return (0);
	i = 11;
	while ((result = i * i) < nb)
	{
		if (nb % i == 0 || result > 2147483647)
			return (0);
		i += 2;
	}
	return (1);
}

/* returns the next prime number or itself if it is a prime number */
int		ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (nb == 2)
		return (nb);
	if (nb % 2 == 0)
		nb++;
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}

/* stores the string 'src' all lowercased in the string 'dst' */
char	*ft_strlowercase(char *dst, char *src)
{
    int    i;

    i = 0;
    while (src[i])
    {
    	if (src[i] >= 'A' && src[i] <= 'Z')
    		dst[i] = src[i] + 32;
        else
        	dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
