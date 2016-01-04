/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/04 12:47:19 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h> // TEMP

int		ft_atoi(char *str);
int		open_map(char *file);
char	*ft_concat(char *str, char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
int		ft_strlen(char *str);
void	load_map(void);
void	**matrix_sqrt(unsigned int x, unsigned int y);
void	print_bsq(void);
int		valid_map(char *file);

#endif
