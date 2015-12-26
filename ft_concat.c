#include "header.h"

char	*ft_concat(char *str1, char *str2)
{
	char *r;
	int	i;
	int j;

	i = 0;
	j = 0;
	r = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	while (str1[i])
	{
		r[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		r[i + j] = str2[j];
		j++;
	}
	r[i + j] = '\0';
	return (r);
}
