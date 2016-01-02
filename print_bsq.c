/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/02 22:23:19 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char			*g_motif;

static int	search_obstacle(char *tab)
{
	int		i;

	i = 0;
	while (tab[i] != '\n' && tab[i])
	{
		if (tab[i] == g_motif[2])
			return (1);
		i++;
	}
	return (0);
}

void		print_bsq(char **tab, int len)
{
	int i;
	int	k;

	i = 0;
	k = 0;
	while (tab[i][0])
	{
		if (search_obstacle(tab[i]) && k == 0)
		{
			ft_putstr(tab[i]);
			while (search_obstacle(tab[i++]))
				ft_putstr(tab[i]);
			k = 1;
		}
		else
			ft_putstr(low_gain(tab[i], len + 1));
		i++;
	}
}
