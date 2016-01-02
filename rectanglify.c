/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectanglify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <hello@baptistechaleil.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 12:10:46 by bchaleil          #+#    #+#             */
/*   Updated: 2016/01/02 17:17:08 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char			*g_motif;

static int	count_x(int x, char *map)
{
	int		countX;

	countX = -1;
	while (map[x++] == g_motif[2])
		countX++;
	return (countX);
}

static int	count_y(int y, int x, char **map)
{
	int		countY;

	countY = -1;
	while (map[y++][x] == g_motif[2])
		countY++;
	return (countY);
}

static char	**check_x(int y, int x, char **map)
{
	int firstCountX;
	int countX;
	int ox;
	int oy;

	oy = y;
	firstCountX = count_x(x, map[y]);
	while (map[oy][x] == 'x')
	{
		ox = x;
		countX = count_x(x, map[oy]);
		while (firstCountX < countX)
			map[oy][x + countX--] = '.';
		if (firstCountX > countX)
		{
			firstCountX = countX;
			oy = y;
			continue ;
		}
		oy++;	
	}
	return (map);
}

char	**rectanglify(int y, int x, char **map)
{
	int firstCountY;
	int countY;
	int ox;
	int oy;

	map = check_x(y, x, map);
	ox = x;
	oy = y;
	firstCountY = count_y(y, x, map);
	while (map[oy][ox] == 'x')
	{
		oy = y;
		countY = count_y(y, ox, map);
		while (firstCountY < countY)
			map[y + countY--][ox] = '.';
		if (firstCountY > countY)
		{
			firstCountY = countY;
			ox = x;
			continue ;
		}
		ox++;
	}
	return (map);
}
