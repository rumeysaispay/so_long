#include "so_long.h"
#include <stdlib.h>

static void	destroy_image(t_game *data, void **img)
{
	if (data && *img)
	{
		mlx_destroy_image(data->mlxinit, *img);
		*img = NULL;
	}
}

static void	free_images(t_game *data)
{
	destroy_image(data, &data->image_player);
	destroy_image(data, &data->image_coin);
	destroy_image(data, &data->image_exit);
	destroy_image(data, &data->image_wall);
}

static void	free_map(t_game *data)
{
	int	line;

	line = 0;
	if (data && data->map)
	{
		while (line < data->height)
		{
			if (data->map[line] != NULL)
			{
				free(data->map[line]);
				data->map[line] = NULL;
			}
			line++;
		}
		free(data->map);
		data->map = NULL;
	}
}

static	void	free_mlx(t_game *data)
{
	if (data)
		free_images(data);
	if ( data && data->mlxinit)
	{
		if (data->mlxwindow)
		{
			mlx_clear_window(data->mlxinit, data->mlxwindow);
			mlx_destroy_window(data->mlxinit, data->mlxwindow);
			data->mlxwindow = NULL;
		}
		mlx_destroy_display(data->mlxinit);
		free(data->mlxinit);
		data->mlxinit = NULL;
	}
}

int	game_exit(t_game *data)
{
	free_map(data);
	free_mlx(data);
	exit(0);
}
