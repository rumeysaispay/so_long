#include "so_long.h"

static	void	update_player_position(t_game *data, int y, int x)
{
	data->map[data->player_y][data->player_x] = '0';
	data->map[y][x] = 'P';
	data->player_y = y;
	data->player_x = x;
	data->counter++;
	ft_printf("Step Count: %d\nLeft Coins: %d\n", data->counter, data->collectables);
	load_graphics(data);
}

static	int	player_move_control(t_game *data, int y, int x)
{
	if (data->map[y][x] == 'E')
	{
		if (data->collectables != 0)
			return (0);
		error_message("YOU WIN!\n", 3, data);
	}
	if (data->map[y][x] == 'C')
		data->collectables--;
	update_player_position(data, y, x);
	return (1);
}

static	int	player_movement(t_game *data, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + x;
	new_y = data->player_y + y;
	if (new_x < 0 || new_y < 0 || new_x >= data->width || new_y >= data->height)
		return (0);
	if (data->map[new_y][new_x] == '1')
		return (0);
	return (player_move_control(data, new_y, new_x));
}

static	int	game_key_movement(t_game *data, int key)
{
	if (key == W) 
		return (player_movement(data, 0, -1));
	if (key == S) 
		return (player_movement(data, 0, 1));
	if (key == A) 
		return(player_movement(data, -1, 0));
	if (key == D) 
		return (player_movement(data, 1, 0));
	return (0);
}

int	map_tracking(int key, t_game *data)
{
	if (key == ESC)
		game_exit(data);
	return (game_key_movement(data, key));
}
