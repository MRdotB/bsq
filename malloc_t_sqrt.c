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

void		**malloc_t_sqrt(size_t x, size_t y)
{
	void	**tmp;

	tmp = (void *)malloc(sizeof(**tmp) * y);
	while (y + 1)
		tmp[y--] = (void **)malloc(sizeof(**tmp) * x);
	return (tmp);
}
