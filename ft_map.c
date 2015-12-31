/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char			*g_motif;
char			**tab;
unsigned int	g_x;
unsigned int	g_y;

int					open_map(char *file)	//	25	lines
{
	char			buf;
	int				fd;
	unsigned int	i;
	char			*tmp;

	i = 0;
	g_x = 0;
	tmp = "\0";
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (read(fd, &buf, 1) && buf != '\n')
		tmp = ft_concat(tmp, buf);
	while (read(fd, &buf, 1) && buf != '\n')
		g_x++;
	close(fd);
	g_y = atoi(tmp);
	while (tmp[i] >= '0' && tmp[i] <= '9')
		i++;
	if ((ft_strlen(tmp) - i) != 4)
		return (0);
	g_motif = (char *)malloc(sizeof(*g_motif) * 3);
	g_motif[0] = tmp[i++];
	g_motif[1] = tmp[i++];
	g_motif[2] = tmp[i];
	return (1);
}

static int			valid_map_ex(unsigned int i)	//	10	lines
{
	unsigned		j;

	while (++i < g_y)
	{
		j = -1;
		while (++j < g_x - 1)
			if ((tab[i][j] != g_motif[0]) && (tab[i][j] != g_motif[1]))
				return (0);
	}
	return (1);
}

int					valid_map(char *file)	//	20	lines
{
	char			buf;
	int				fd;
	unsigned int	i;

	i = -1;
	fd = open(file, O_RDONLY);
	if ((tab = (char**)matrix_sqrt(g_x + 1, g_y + 2)) == NULL)
		return (0);
	while (read(fd, &buf, 1) && buf != '\n')
		;
	while (read(fd, tab[++i], g_x + 1))
		if (i > g_y)
			return (0);
	close(fd);
	if (i < g_y)
		return (0);
	while (--i)
		if (tab[i][g_x] != '\n')
			return (0);
	return (valid_map_ex(i - 1));
}

void				load_map(void)	// No Finished	// Shit	// But is works
{
	int	i;
	int	len;

	len = 7;
	i = -1;
	while (++i < g_y)						// x
		tab[i] = filtered_x(tab[i], len);

	i = 0;
	while (i < g_y)
		tab = filtered_y(tab, len, i++);       // y
	i = -1;
	while (++i < g_y)
		tab[i] = low_gain(tab[i], len);   // low_gain
	i = 0;
	while (i < g_y)
		tab = filtered_y(tab, len, i++);       // y
	i = 0;
	while (++i < g_y)
		tab[i] = low_gain(tab[i], len);   // low_gain

	ft_print_tables(tab);
}
