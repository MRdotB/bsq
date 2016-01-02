/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nucleus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/02 20:46:56 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int  filtered_x_ex(char *tab, int len, int i)
{
	int     tmp;

	tmp = i;
	while (len--)
	{
		i++;
		if (tab[i] != '.') 
			return (i);
	}
	return (tmp);
}

char		*filtered_x(char *tab, int len)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (tab[i])
	{
		if (k == 0)
			i = filtered_x_ex(tab, len, i);
		k = 1;
		if (tab[i] != '.') 
			k = 0;
		else
			tab[i] = 'x';
		i++;
	}
	return (tab);
}

char		**filtered_y(char **tab, int len, int x)
{
	int i;
	int j;
	int f;

	i = 0;
	f = 0;
	while (tab[i][0])
	{
		j = 0;
		while (tab[i][x] == 'x' && j++ < len && (tab[i - f][x] != 'x' || i == 0))
			if (tab[i + j][x] != 'x' || tab[i + j][x] == '\0')
				while (j--)
					tab[i + j][x] = '.';
		i++;
		f = 1;
	}
	return (tab);
}
