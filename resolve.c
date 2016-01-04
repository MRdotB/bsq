/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:12:54 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/04 16:28:08 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char			*g_motif;
char			**g_tab;



int		biggest_square(int size, int pos_y, int pos_x)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (g_tab[pos_y + y][pos_x + x] != '.')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	render_square(int size, int pos_y, int pos_x)
{
	int x;
	int y;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			g_tab[pos_y + y][pos_x + x] = 'x';
			x++;
		}
		y++;
	}
}

void	resolve(void)
{
	t_square r;
	int x;
	int y;

	y = 0;
	r.size = 0;
	while (g_tab[y][0])
	{
		x = 0;
		while (g_tab[y][x])
		{
			while (biggest_square(r.size + 1, y, x))
			{
				r.x = x;
				r.y = y;
				r.size++;
			}
			x++;
		}
		y++;
	}
	render_square(r.size, r.y, r.x);
}
