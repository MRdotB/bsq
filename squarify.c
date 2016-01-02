/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squarify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 12:10:31 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/02 22:05:41 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char			*g_motif;

static int	count_x(int x, char *map)
{
	int		cx;

	cx = -1;
	while (map[x++] == g_motif[2])
		cx++;
	return (cx);
}

static int	count_y(int y, int x, char **map)
{
	int		cy;

	cy = -1;
	while (map[y++][x] == g_motif[2])
		cy++;
	return (cy);
}

char		**squarify(int y, int x, char **map)
{
	int		cx;
	int		cy;
	int		ox;
	int		oy;

	rectanglify(y, x, map);
	cx = count_x(x, map[y]);
	cy = count_y(y, x, map);
	ox = x;
	oy = y;
	while (cx > cy)
	{
		oy = y;
		while (map[oy][x + cx] == g_motif[2])
			map[oy++][x + cx] = g_motif[0];
		cx--;
	}
	while (cx < cy)
	{
		ox = x;
		while (map[y + cy][ox] == g_motif[2])
			map[y + cy][ox++] = g_motif[0];
		cy--;
	}
	return (map);
}
