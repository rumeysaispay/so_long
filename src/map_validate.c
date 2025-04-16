
#include "so_long.h"
#include <stdlib.h>

void	check_map_wall(t_game *data)
{
	int	i;
	int	h;
	int	w;

	i = 0;
	h = data->height - 1;
	w = data->width - 1;
	while (i <= w)
	{
		if (data->map[0][i] != '1' || data->map[h][i] != '1')
			error_message("Error! Invalid map format!", 0, data);
		i++;
	}
	i = 0;
	while (i <= h)
	{
		if (data->map[i][0] != '1' || data->map[i][w] != '1')
			error_message("Error! Invalid map format!", 0, data);
		i++;
	}
}

static char	**map_duplicate(t_game *data)
{
	char	**copy;
	int		i;
    
	i = 0;
	copy = malloc(sizeof(char *) * data->height);
	if (!copy)
		error_message("Memory allocation failed!", 0, data);
	while (i < data->height)
	{
		copy[i] = ft_strdup(data->map[i]);
		if (!copy[i])
			break;
		i++;
	}
	return (copy);
}

static	void	map_flood_fill(char **map, int *count, int y, int x)
{
	if (map[y][x] == '1') 
		return;
	if (map[y][x] == 'C' || map[y][x] == 'E') 
		(*count)++;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return;
	}
	map[y][x] = '1';
	map_flood_fill(map, count, y + 1, x);
	map_flood_fill(map, count, y - 1, x);
	map_flood_fill(map, count, y, x + 1);
	map_flood_fill(map, count, y, x - 1);
}

void	map_validate(t_game *data, int y, int x)
{
	char	**copy;
	int		count;
	int		i;

	count = 0;
	i = data->height;
	copy = map_duplicate(data);
	map_flood_fill(copy, &count, y, x);
	if (count != data->collectables + 1)
	{
		while (i--) 
			free(copy[i]);
		free(copy);
		error_message("Not all collectables are accessible!", 0, data);
	}
	while (i--) 
		free(copy[i]);
	free(copy);
}
