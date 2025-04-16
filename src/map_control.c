
#include "so_long.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static	void	map_line_control(char *line, t_game *data)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' 
			&& line[i] != 'C' && line[i] != 'E')
		{
			free(line);
			error_message("Error! Invalid map format!", 0, data);
		}
		i++;
	}
	if (i != data->width)
	{
		free(line);
		error_message("Error! Invalid map format!", 0, data);
	}
	line = NULL;
}

static	void	dup_map(char *line, t_game *data, int i)
{
	data->map[i] = ft_strdup(line);
	if (!(data->map[i]))
	{
		free(line);
		error_message("Memory allocation failed!", 0, data);
	}
}

void	create_start_map(t_game *data, char *str)
{
	int		fd;
	int		i;
	char	*line;

	data->map = malloc(sizeof(char *) * data->height);
	if (!(data->map))
		error_message("Memory allocation failed!", 0, data);
	i = -1;
	while (++i < data->height)
		data->map[i] = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		error_message("Failed to open mapfile!", 0, data);
	i = -1;
	while (++i < data->height)
	{
		line = get_next_line(fd);
		if (!line)
			error_message("Memory allocation failed!", 0, data);
		map_line_control(line, data);
		dup_map(line, data, i);
		free(line);
	}
	close(fd);
}

void	check_map_size(t_game *data, char *map_file)
{
	int		fd;
	int		flag;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_message("Error! File could not be opened or empty!", 0, data);
	flag = 1;
	line = get_next_line(fd);
	while(line != NULL)
	{
		if (flag == 1)
			data->width = ft_strlen(line) - 1;
    	data->height++;
    	free(line);
    	line = get_next_line(fd);
		if (flag == 1)
			flag = 0;
	}
	if (data->height == 0)
	{
		close(fd);
		error_message("Map file is empty!", 0, data);
	}
	close(fd);
}

void	check_file(char *str)
{
	int	fd;
	int	file_len;

	file_len = ft_strlen(str);
	if (!(str[file_len - 1] == 'r' && str[file_len - 2] == 'e' 
		&& str[file_len - 3] == 'b' && str[file_len - 4] == '.') 
		|| (!(str[file_len - 5] >= 32 && str[file_len - 5] < 127)))
			error_message("Error! Incorrect file name!", 1, NULL);
	fd = open(str, O_RDONLY);
	if(fd < 0)
	{
		close (fd);
		error_message("Error! File could not be opened or empty!", 1, NULL);
	}
	close (fd);
}
