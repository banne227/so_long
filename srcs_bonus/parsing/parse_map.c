/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:05:00 by banne             #+#    #+#             */
/*   Updated: 2025/11/14 13:54:09 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	remove_newline(char *line)
{
	int	len;

	len = ft_strlenn(line);
	if (!line)
		return ;
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

char	**read_map_lines(int fd, int height)
{
	char	**grid;
	char	*line;
	int		i;

	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line && i < height)
	{
		remove_newline(line);
		grid[i] = line;
		i++;
		line = get_next_line(fd);
	}
	grid[i] = NULL;
	return (grid);
}

t_map	*init_map_struct(char **grid, int height)
{
	t_map	*map;

	if (!grid)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->grid = grid;
	map->width = ft_strlenn(grid[0]);
	map->height = height;
	map->collectibles = 0;
	map->collected = 0;
	map->exits = 0;
	map->player_pos.x = -1;
	map->player_pos.y = -1;
	map->players = 0;
	map->exit_pos.x = -1;
	map->exit_pos.y = -1;
	map->cherry = 0;
	return (map);
}

t_map	*parse_map(char *filename)
{
	int		fd;
	int		height;
	char	**grid;
	t_map	*map;

	height = count_lines(filename);
	if (height <= 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	grid = read_map_lines(fd, height);
	if (!grid)
		return (NULL);
	close(fd);
	map = init_map_struct(grid, height);
	if (!map)
	{
		free_grid(grid);
		return (NULL);
	}
	return (map);
}
