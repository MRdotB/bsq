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

static void	low_gain_ex(char **tab, int len, int i, int j)
{
	return ;
}

char		**low_gain(char **tab, int len)	// no finished segmentationfalt
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j] && tab[i])
		{
			ft_putchar(tab[i][j]);
			if (tab[i][j] == 'x' && tab[i])
				low_gain_ex(tab, len, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}
