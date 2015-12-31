/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_sqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void				**matrix_sqrt(unsigned int x, unsigned int y)
{
	void			**tmp;
	unsigned int	i;

	tmp = (void**)malloc(sizeof(void**) * y);
	while (i < y)
		tmp[i++] = (void*)malloc(sizeof(void*) * x);
	return (tmp);
}
