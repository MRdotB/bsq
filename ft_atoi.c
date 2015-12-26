int		ft_atoi(char *s)
{
	int i;
	int neg;
	int r;

	i = 0;
	neg = 0;
	r = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if (s[i] == '-')
		neg = 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		r *= 10;
		r += (int)s[i] - 48;
		i++;
	}
	return (neg) ? (-r) : (r);
}
