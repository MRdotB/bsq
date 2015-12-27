/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodenos <glodenos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by glodenos          #+#    #+#             */
/*   Updated: 2100/01/01 00:00:00 by glodenos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
#include <stdio.h> //TODO remove

typedef struct	s_file_info
{
	char	*sign;
	int		info_len;
	int		x_max;
	int		y_max;
}				t_file_info;

char	*ffg(char *str);
char	*filtered_x(char *tab, int len);
void	filtered_y(char **tab, int len, int y);
int		ft_char_in_str(char c, char *match);
char	*ft_concat(char *str1, char c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_print_tables(char **tab);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
void	**malloc_t_sqrt(size_t x, size_t y);
char	**load_map(char *file, t_file_info *r);
char	**nucleus(char **tab);
int		get_file_info(char* file_name, t_file_info *r);
int		is_map_valid(char *file_name, t_file_info *r);

#endif
