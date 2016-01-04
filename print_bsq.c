/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/04 13:15:49 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**g_tab;
char	*g_motif;
int		g_x;
int		g_y;
void	print_bsq(void)
{
	int x = 0;
	int y = 0;
	while (g_tab[y][x])
		ft_putstr(g_tab[y++]);
	int	i;
	i = -1;
	free_sqrt(g_tab);
	g_x = 0;
	g_y = 0;
}
