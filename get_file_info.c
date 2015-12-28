#include "lib.h"

static char	*str_cut_3_last(char *str)
{
	char *r;
	int length;

	r = malloc(4);
	length = ft_strlen(str);
	r[3] = '\0';	
	r[2] = str[length - 1];
	r[1] = str[length - 2];
	r[0] = str[length - 3];
	str[length - 3] = '\0';
	return (r);
}

static void	clean_r(t_file_info *r)
{
	r->info_len = 0;
	r->sign = "";
	r->x_max = 0;
	r->y_max = 0;
}

int		get_file_info(char* file_name, t_file_info *r)
{
	int		count;
	int		fd;
	char	buf;
	char	*str;

	str = "";
	clean_r(r);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	while ((read(fd, &buf, 1)) && buf != '\n')
		str = ft_concat(str, buf);
	count = 0;
	while (read(fd, &buf, 1) && buf != '\n')
		count++;
	if (ft_strlen(str) < 4)
		return (0);
	r->info_len = ft_strlen(str) + 1;
	r->sign = str_cut_3_last(str); 
	r->y_max = ft_atoi(str);
	r->x_max = count;
	close(fd);
	return (1);
}

int		is_map_valid(char *file_name, t_file_info *r)
{
	int fd;
	int count;
	char buf;
	char j[r->info_len];

	fd = open(file_name, O_RDONLY);
	read(fd, j, r->info_len); // jump info
	count = 0;
	while ((read(fd, &buf, 1)))
	{
		if (!(ft_char_in_str(buf, r->sign) || buf == '\n'))
			return (0);
		count++;
	}
	if (count != ((r->x_max + 1) * r->y_max))
		return (0);
	close(fd);
	return (1);
}

char	**load_map(char *file, t_file_info *r)
{
	int		fd;
	int		i;
	char	**tab;
	char 	j[r->info_len];

	i = 0;
	tab = malloc_t_sqrt(r->x_max + 1, r->y_max);
	fd = open(file, O_RDONLY);
	read(fd, j, r->info_len); // jump info
	while (read(fd, tab[i], r->x_max + 1))
	{
		tab[i][r->x_max + 1] = '\0';
		tab[i] = filtered_x(tab[i], 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
