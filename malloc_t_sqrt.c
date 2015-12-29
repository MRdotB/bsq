/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_t_sqrt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char		**malloc_t_sqrt(int x, int y)
{
	char	**tmp;
	int		i;

	tmp = (char**)malloc(sizeof(char**) * y + 1);
	while (i < y)
	{
		tmp[i] = (char*)malloc(sizeof(char*) * x + 1);
		i++;
	}
	return (tmp);
}
