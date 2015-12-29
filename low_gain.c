/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_gain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

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

char		*low_gain(char *tab, int len)	// no finished segmentationfalt
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
