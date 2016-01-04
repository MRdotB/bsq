/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/04 18:34:58 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char			*g_motif;
char			**g_tab;
unsigned int	g_x;
unsigned int	g_y;

static void			assign_motif(char *tmp, int i)
{
	g_motif = (char *)malloc(sizeof(*g_motif) * 3);
	g_motif[0] = tmp[i++];
	g_motif[1] = tmp[i++];
	g_motif[2] = tmp[i];
	free(tmp);
}

int					open_map(char *file)
{
	char			buf;
	int				fd;
	unsigned int	i;
	char			*tmp;

	i = 0;
	g_x = 0;
	g_y = 0;
	tmp = "\0";
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (read(fd, &buf, 1) && buf != '\n')
		tmp = ft_concat(tmp, buf);
	while (read(fd, &buf, 1) && buf != '\n')
		g_x++;
	close(fd);
	g_y = ft_atoi(tmp);
	while (tmp[i] >= '0' && tmp[i] <= '9')
		i++;
	if ((ft_strlen(tmp) - i) != 4)
		return (0);
	assign_motif(tmp, i);
	return (1);
}

static int			valid_map_ex(unsigned int i)
{
	unsigned int	j;

	while (++i < g_y)
	{
		j = -1;
		while (++j < g_x - 1)
			if ((g_tab[i][j] != g_motif[0]) && (g_tab[i][j] != g_motif[1]))
				return (0);
	}
	return (1);
}

int					valid_map(char *file)
{
	char			buf;
	int				fd;
	unsigned int	i;

	i = -1;
	fd = open(file, O_RDONLY);
	if ((g_tab = (char**)matrix_sqrt(g_x + 1, g_y + 1)) == NULL)
		return (0);
	while (read(fd, &buf, 1) && buf != '\n')
		;
	while (read(fd, g_tab[++i], g_x + 1))
		if (i > g_y)
			return (0);
	close(fd);
	if (i < g_y)
		return (0);
	while (--i)
		if (g_tab[i][g_x] != '\n')
			return (0);
	return (valid_map_ex(i));
}
