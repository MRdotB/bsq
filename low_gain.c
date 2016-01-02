/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_gain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/02 20:46:34 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int			len_gain(char **tab)
{
	int		i;
	int		j;
	int		len;
	int		tmp;

	i = -1;
	j = -1;
	len = 0;
	tmp = 0;
	while (tab[++i][0])
	{
		while (tab[i][j] != '\n' && tab[i][j])
		{
			if (tab[i][++j] == 'x')
				len++;
			else
			{
				if (len > tmp)
					tmp = len;
				len = 0;
			}
		}
		j = 0;
	}
	return (tmp);
}

static void	low_gain_ex(char *tab, int len, int i)
{
	int		tmp;
	int		n;

	tmp = i;
	n = 0;
	while (len-- && tab[i + 1])
	{
		i++;
		n++;
		if (tab[i] != 'x')
		{
			while (n--)
				tab[tmp++] = '.';
			return ;
		}
	}
	return ;
}

char		*low_gain(char *tab, int len)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (tab[i])
	{
		if (k == 0 && tab[i] == 'x')
			low_gain_ex(tab, len, i);
		k = 1;
		if (tab[i] != 'x')
			k = 0;
		i++;
	}
	return (tab);
}

int			*pos(char **tab)
{
	int		i;
	int		j;
	int		*tmp;

	i = 0;
	j = 0;
	tmp = (int *)malloc(sizeof(*tmp) * 2);
	while (tab[i][j])
	{
		while (tab[i][j] != '\n')
		{
			if (tab[i][j] == 'x')
			{
				tmp[0] = j;
				tmp[1] = i;
				return (tmp);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (tmp);
}
