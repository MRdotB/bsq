#include "header.h"

char	*str_cut_3_last(char *str)
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

void	get_file_info(char* file_name, t_file_info *r)
{
	int		ret;
	int		fd;
	char	*buf;
	char	*str;

	str = "";
	buf = malloc(2);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (ft_putstr_err("map error"));
	while ((ret = read(fd, buf, 1)) && buf[0] != '\n')
	{
		buf[ret] = '\0';
		str = ft_concat(str, buf);
	}
	ret = 0;
	while (read(fd, buf, 1) && buf[0] != '\n')
		ret++;
	r->info_len = ft_strlen(str) + 1;
	r->sign = str_cut_3_last(str); 
	r->y_max = ft_atoi(str);
	r->x_max = ret;
	close(fd);
}

int		is_char_in_str(char c, char *match)
{
	while (*match)
		if (c == *match++)
			return (1);
	return (0);
}

int		is_map_valid(char *file_name, t_file_info *r)
{
	int ret;
	int fd;
	int count;
	char buf[2];

	fd = open(file_name, O_RDONLY);
	// jump info
	read(fd, buf, r->info_len);
	count = 0;
	while ((ret = read(fd, buf, 1)))
	{
		buf[ret] = '\0';
		if (!(is_char_in_str(buf[0], r->sign) || buf[0] == '\n'))
			return (0);
		count++;
		printf("%d", count);
		printf("|%s|\n", buf);
	}
	if (count != ((r->x_max + 1) * r->y_max))
		return (0);
	printf("count = %d | x * y = %d\n", count, ((r->x_max + 1) * r->y_max));
	close(fd);
	return (1);
}

int		main(void)
{
	t_file_info r;

	get_file_info("file1", &r);
	printf("is_map_valid = %d \n", is_map_valid("file1", &r));
	printf("r.info_len = %d | r.sign = %s | ", r.info_len, r.sign);
	printf("r.x_max = %d | r.y_max = %d\n", r.x_max, r.y_max);
	return (0);
}
