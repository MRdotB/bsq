/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:12:54 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/04 18:35:27 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*g_motif;
char	**g_tab;

static int		biggest_square(int size, int pos_y, int pos_x)
{
	int	x;
	int	y;

	y = -1;
	while (++y < size)
	{
		x = 0;
		while (x < size)
			if (g_tab[pos_y + y][pos_x + x++] != g_motif[0])
				return (0);
	}
	return (1);
}

static void		render_square(int size, int pos_y, int pos_x)
{
	int	x;
	int	y;

	y = -1;
	while (++y < size)
	{
		x = 0;
		while (x < size)
			g_tab[pos_y + y][pos_x + x++] = g_motif[2];
	}
}

void			resolve(void)
{
	t_square	r;
	int			x;
	int			y;

	y = -1;
	r.size = 0;
	while (g_tab[++y][0])
	{
		x = -1;
		while (g_tab[y][++x])
		{
			while (biggest_square(r.size + 1, y, x))
			{
				r.x = x;
				r.y = y;
				r.size++;
			}
		}
	}
	render_square(r.size, r.y, r.x);
}
