/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/02 21:42:37 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char		*ft_concat(char *str1, char c)
{
	char	*r;
	int		i;

	i = 0;
	r = malloc(ft_strlen(str1) + 2);
	while (str1[i])
	{
		r[i] = str1[i];
		i++;
	}
	r[i++] = c;
	r[i] = '\0';
	return (r);
}
