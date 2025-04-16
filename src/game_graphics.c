
#include "so_long.h"

static void *image_from_texture(t_game *data, char *path)
{
	int		x;
	int		y;
	void	*image;

	image = mlx_xpm_file_to_image(data->mlxinit, path, &x, &y);
	if (!image)
		error_message("photo upload error", 0, data);
	return (image);
}

void game_visuals_init(t_game *data)
{
	data->image_coin = image_from_texture(data, "./texture/coin.xpm");
	data->image_exit = image_from_texture(data, "./texture/exit.xpm");
	data->image_player = image_from_texture(data, "./texture/player.xpm");
	data->image_wall = image_from_texture(data, "./texture/wall.xpm");
}

static void render_game_graphics(t_game *data, char cell, int x, int y)
{
	void *image;

	image = NULL;
	if (cell == '1')
		image = data->image_wall;
	else if (cell == 'E')
		image = data->image_exit;
	else if (cell == 'C')
		image = data->image_coin;
	else if (cell == 'P')
	{
		data->player_x = x;
		data->player_y = y;
		image = data->image_player;
	}
	if (image)
		mlx_put_image_to_window(data->mlxinit, data->mlxwindow, 
			image, x * RES, y * RES);
}

void	load_graphics(t_game *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	mlx_clear_window(data->mlxinit, data->mlxwindow);
	while (i < (data->height * data->width))
    {
		y = i / data->width;
		x = i % data->width;
		render_game_graphics(data, data->map[y][x], x, y);
		i++;
    }
}
