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
