#ifndef HEADER_H
# define HEADER_h

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> // TEMP

typedef struct	s_file_info
{
	char	*sign;
	int		info_len;
	int		x_max;
	int		y_max;
}				t_file_info;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
char	*ft_concat(char *str1, char *str2);
int		ft_strlen(char *str);
int		ft_atoi(char *s);

#endif
