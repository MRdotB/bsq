char			*g_motif;

/*
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
*/

char	**square(int y, int x, char **map)
{
	int		countX;
	int		countY;
	int 	ox;
	int		oy;

	countX = -1;
	countY = -1;
	ox = x;
	oy = y;
	while (map[y][ox++] == g_motif[2])
		countX++;
	while (map[oy++][x] == g_motif[2])
		countY++;
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
