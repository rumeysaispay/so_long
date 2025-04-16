
#ifndef	SO_LONG_H
# define	SO_LONG_H

#include	"../inc/get_next_line/get_next_line.h"
#include	"../inc/ft_printf/ft_printf.h"
#include	"../inc/minilibx-linux/mlx.h"

#include	<stddef.h>

# define RES 64
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef	struct	s_game
{
	char	**map;

	int	width;
	int	height;
	int	exit;
	int	player;
	int	collectables;
	int	player_x;
    int	player_y;
	int	counter;

	void	*mlxinit;
	void	*mlxwindow;
	void	*image_player;
	void	*image_wall;
	void	*image_coin;
	void	*image_exit;
}	t_game;

int		game_exit(t_game *data);
void	game_visuals_init(t_game *data);
void	load_graphics(t_game *data);
void	create_start_map(t_game *data, char *str);
void	check_map_size(t_game *data, char *map_file);
void	check_file(char *str);
void	map_validate(t_game *data, int y, int x);
void	check_map_wall(t_game *data);
int		map_tracking(int key, t_game *data);
void	error_message(char *str, int flag, void *data);

#endif