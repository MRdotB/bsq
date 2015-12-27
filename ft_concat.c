#include "lib.h"

char	*ft_concat(char *str1, char c)
{
	char *r;
	int	i;

	i = 0;
	r = malloc(ft_strlen(str1) + 2);
	while (str1[i])
	{
		r[i] = str1[i];
		i++;
	}
	r[i++] = c;
	r[i] = '\0';
	return (r);
}
