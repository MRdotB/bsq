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
/*
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
*/
static char	*empty_to_filled(char *tab)
{
	int i;

	i = 0;
	while (tab[i] != '\n')
	{
		if (tab[i] == '.')
			tab[i] = 'x';
		i++;
	}
	return (tab);
}

char		*filtered_x(char *tab, int len)
{
	int i;
	int j;

	i = 0;
	tab = empty_to_filled(tab);
	while (tab[i] != '\n')
	{
		j = 0;
		while (tab[i] == 'x' && j++ < len && (tab[i - 1] == 'o' || i == 0))
			if (tab[i + j] == 'o' || tab[i + j] == '\n')
				while (j--)
					tab[i + j] = '.';
		i++;
	}
	return (tab);
}

char		**filtered_y(char **tab, int len, int x, t_file_info *r)
{
	int i;
	int j;
	int f;

	i = 0;
	f = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][x] == 'x' && j++ < len && (tab[i - f][x] == 'o' || i == 0))
			if (tab[i + j][x] == 'o' || tab[i + j][x] == '\0')
				while (j--)
					tab[i + j][x] = '.';
		i++;
		f = 1;
	}
	return (tab);
}
/*
static void	filtered_y_ex(char **tab, int len, int i, int y)
{
	int		tmp;	//	fonction salle mais fonctionnel
	int		n;

	tmp = i;
	n = 0;
	while (len-- && tab[i + 1])
	{
		i++;
		n++;
		if (tab[i][y] != 'x')
		{
			while (n--)
				tab[tmp++][y] = '.';
			return ;
		}	
	}
}

char		**filtered_y(char **tab, int len, int y)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (tab[i + 1])	//	ça merde !!! si on enlève le +1
	{
		if (k == 0)
		{
			if (tab[i][y] != 'x')
				;
			else
				filtered_y_ex(tab, len, i, y);
			k = 1;
		}
		if (tab[i][y] != 'x')
			k = 0;
		i++;
	}
	return (tab);
}
*/
