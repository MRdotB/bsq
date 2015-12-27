/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nucleus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int 	filtered_x_ex(char *tab, int len, int i)
{
	int		tmp;

	tmp = i;
	while (len--)
	{
		i++;
		if (tab[i] == 'o' || tab[i] == '\n')
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
		if (tab[i] != 'o' && tab[i] != '\n')
		{
			tab[i] = 'x';
			k++;
		}
		else
			k = 0;
		i++;
	}
	return (tab);
}

static int	filtered_y_ex(char **tab, int len, int i, int y)
{
	int		tmp;

	tmp = i;
	while (len--)
	{
		i++;
		if (tab[i][y] == 'o' || tab[i][y] == '.')
			return (i);
	}
	return (tmp);
}

void		filtered_y(char **tab, int len, int y)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (tab[i][y])
	{
		if (k == 0)
			i = filtered_y_ex(tab, len, i, y);
		if (tab[i][y] != 'o' && tab[i][y] != '.')
		{
			tab[i][y] = '.';
			k++;
		}
		else
			k = 0;
		i++;
	}
}
/*
char	**nucleus(char **tab)
{
	
}
*/
