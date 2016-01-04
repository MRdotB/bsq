/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/04 22:51:39 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static	void	lunch_bsq(int fd)
{
	if (open_map(fd))
		if (valid_map(fd))
			print_bsq();
		else
			ft_putstr_err("map error\n");
	else
		ft_putstr_err("map error\n");
}

int				main(int argc, char **argv)
{
	int			i;
	int			fd;

	i = 0;
	fd = 0;
	if (argc == 1)
		lunch_bsq(fd);
	while (++i < argc)
		if ((fd = open(argv[i], O_RDONLY)) > -1)
			lunch_bsq(fd);
		else
			ft_putstr_err("map error\n");
	return (0);
}
