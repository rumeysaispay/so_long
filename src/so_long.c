
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>

void	error_message(char *str, int flag, void *data)
{
	if (flag == 1)
	{
		ft_printf("%s\n", str);
		exit(1);
	}
	else if (flag == 3)
	{
		ft_printf("%s\n", str);
		game_exit((t_game *)data);
	}
	else
	{
		ft_printf("%s\n", str);
		game_exit((t_game *)data);
	}
}

static	void	count_map_object(t_game *data)
{
	int		i;
	int		x;
	int		y;
	char	cell;

	i = 0;
	while (i < data->width * data->height)
	{
		y = i / data->width;
		x = i % data->width;
		cell = data->map[y][x];
		if (cell == 'E')
			data->exit++;
		else if (cell == 'C')
			data->collectables++;
		else if (cell == 'P')
			data->player++;
		else if (cell != '1' && cell != '0' && cell != '\n')
			error_message("wrong map character", 0, data);
		i++;
	}
	if (data->player != 1 || data->collectables == 0 || data->exit != 1)
		error_message("Wrong equipment in map!", 0, data);
}

static	void	game_starting_values(t_game *data)
{
	data->width = 0;
	data->height = 0;
	data->exit = 0;
	data->player = 0;
	data->collectables = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->counter = 0;
	data->map = NULL;
	data->mlxinit = NULL;
	data->mlxwindow = NULL;
	data->image_player = NULL;
	data->image_wall = NULL;
	data->image_coin = NULL;
	data->image_exit = NULL;
}

static	void	all_game_functions(t_game *data, char *path)
{
	game_starting_values(data);
	check_file(path);
	check_map_size(data, path);
	create_start_map(data, path);
	check_map_wall(data);
	data->mlxinit = mlx_init();
	if (!data->mlxinit)
		error_message("MLX initialization failed", 0, data);
	data->mlxwindow = mlx_new_window(data->mlxinit, 
		data->width * RES, data->height * RES, "so_long");
	if (!data->mlxwindow)
		error_message("MLX initialization failed", 0, data);
	game_visuals_init(data);
	count_map_object(data);
	load_graphics(data);
	map_validate(data, data->player_y, data->player_x);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac == 2)
	{
		all_game_functions(&data, av[1]);
		mlx_key_hook(data.mlxwindow, &map_tracking, &data);
		mlx_hook(data.mlxwindow, 17, 0, (void *) &game_exit, &data);
		mlx_loop(data.mlxinit);
	}
	else
		error_message("Error: Wrong number of arguments", 1, NULL);
	return (0);
}
