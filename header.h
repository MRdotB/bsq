#ifndef HEADER_H
# define HEADER_h

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> // TEMP

typedef struct	s_file_info
{
	char	*sign;
	int		nb_line;
	int		total;
}				t_file_info;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
int		ft_strlen(char *str);

#endif
