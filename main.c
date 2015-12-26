#include "header.h"

int		is_valid_map(char* str)
{
	if (*str)
		return (1);
	return (0);
}

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	get_file_info(char* file_name, t_file_info *r)
{
	int		ret;
	int		fd;
	char	*buf;

	buf = malloc(2);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_putstr_err("map error");
	while ((ret = read(fd, buf, 1)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	r->sign = ".xo";
	r->nb_line = 10;
	r->total = 14;
}

int		main(void)
{
	t_file_info r;
	get_file_info("file1", &r);
	printf("%s\n", r.sign);
	return (0);
}
