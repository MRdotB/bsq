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

char*	ft_concat(char *str1, char *str2)
{
	char *r;
	int	i;
	int j;

	i = 0;
	j = 0;
	r = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	while (str1[i])
	{
		r[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		r[i + j] = str2[j];
		j++;
	}
	r[i + j] = '\0';
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
	{
		ft_putstr_err("map error");
		return ;
	}
	while ((ret = read(fd, buf, 1)) && buf[0] != '\n')
	{
		buf[ret] = '\0';
		str = ft_concat(str, buf);
	}
	r->total = ft_strlen(str) + 1;
	r->sign = str_cut_3_last(str); 
	r->nb_line = ft_atoi(str);
}

int		main(void)
{
	t_file_info r;

	get_file_info("file1", &r);
	printf("r.total = %d | r.sign = %s | r.nb_line = %d\n", r.total, r.sign, r.nb_line);
	return (0);
}
