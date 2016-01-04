/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/04 16:31:41 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**g_tab;
char	*g_motif;

void	print_bsq(void)
{
	int x;
	int y;
	
	x = 0;
	y = 0;
	resolve();
	while (g_tab[y][x])
		ft_putstr(g_tab[y++]);
	free_sqrt(g_tab);
}
