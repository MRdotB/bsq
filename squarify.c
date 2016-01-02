char			*g_motif;

static int	count_x(int x, char *map)
{
	int		countX;

	countX = -1;
	while (map[x++] == g_motif[2])
		countX++;
	return (countX);
}

static int	count_y(int y, int x, char **map)
{
	int		countY;

	countX = -1;
	while (map[y++][x] == g_motif[2])
		countY++;
	return (countY);
}

char	**squarify(int y, int x, char **map)
{
	int		countX;
	int		countY;
	int 	ox;
	int		oy;

	countX = count_x;
	countY = count_y;
	ox = x;
	oy = y;
	while (countX > countY)
	{
		oy = y;
		while (map[oy][x + countX] == g_motif[2])
			map[oy++][x + countX] = g_motif[0];
		countX--;
	}	
	while (countX < countY)
	{
		ox = x;
		while (map[y + countY][ox] == g_motif[2])
			map[y + countY][ox++] = g_motif[0];
		countY--;
	}	
	return (map);
}
