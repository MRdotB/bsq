/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2016/01/02 15:05:35 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>	// Remove if finished
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

char	*filtered_x(char *tab, int len);
char	**filtered_y(char **tab, int len, int x);
int		ft_atoi(char *str);
char	*ft_concat(char *str, char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
int		ft_strlen(char *str);
void	load_map(void);
char	*low_gain(char *tab, int len);
void	**matrix_sqrt(unsigned int x, unsigned int y);
int		*pos(char **tab);
void	print_bsq(char **tab, int len);
int		valid_map(char *file);
char	**squarify(int x, int y, char **map);
char	**rectanglify(int y, int x, char **map);

#endif
