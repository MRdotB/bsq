/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int			main(int ac, char **av)
{
	t_file_info r;
	int			i;

	
	i = 1;
	if (ac == 1)
		return (0); // read 0
	while (i < ac)
	{
		if (get_file_info(av[i], &r))
			if (is_map_valid(av[i], &r))
				ft_print_tables(load_map(av[i], &r));
			else
				ft_putstr_err("map error");
		else
			ft_putstr_err("map error");
		i++;
	}	
	/*printf("r.info_len = %d | r.sign = %s | ", r.info_len, r.sign);
	printf("r.x_max = %d | r.y_max = %d\n", r.x_max, r.y_max);
	*/
	return (0);
}
