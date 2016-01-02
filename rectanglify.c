/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectanglify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 12:10:46 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/02 22:00:23 by bchaleil         ###   ########.fr       */
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

static char	**check_x(int y, int x, char **map)
{
	int fcx;
	int cx;
	int oy;

	oy = y;
	fcx = count_x(x, map[y]);
	while (map[oy][x] == 'x')
	{
		cx = count_x(x, map[oy]);
		while (fcx < cx)
			map[oy][x + cx--] = '.';
		if (fcx > cx)
		{
			fcx = cx;
			oy = y;
			continue ;
		}
		oy++;
	}
	return (map);
}

char	**rectanglify(int y, int x, char **map)
{
	int fcy;
	int cy;
	int ox;
	int oy;

	map = check_x(y, x, map);
	ox = x;
	oy = y;
	fcy = count_y(y, x, map);
	while (map[oy][ox] == 'x')
	{
		oy = y;
		cy = count_y(y, ox, map);
		while (fcy < cy)
			map[y + cy--][ox] = '.';
		if (fcy > cy)
		{
			fcy = cy;
			ox = x;
			continue ;
		}
		ox++;
	}
	return (map);
}
