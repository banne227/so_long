/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:20:51 by banne             #+#    #+#             */
/*   Updated: 2025/11/14 13:53:56 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_rectangular(t_map *map)
{
	int	len;
	int	i;

	if (!map || !map->grid || !map->grid[0])
		return (0);
	len = ft_strlenn(map->grid[0]);
	i = 1;
	while (map->grid[i])
	{
		if (ft_strlenn(map->grid[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int	check_walls(t_map *map)
{
	int	i;
	int	j;
	int	width;
	int	height;

	if (!map || !map->grid || !map->grid[0])
		return (0);
	height = 0;
	while (map->grid[height])
		height++;
	width = ft_strlenn(map->grid[0]);
	j = 0;
	while (j < width)
	{
		if (map->grid[0][j] != '1' || map->grid[height - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i++ < height - 1)
		if (map->grid[i][0] != '1' || map->grid[i][width - 1] != '1')
			return (0);
	return (1);
}

static void	add_elt(char elt, int x, int y, t_map *map)
{
	if (elt == 'P')
	{
		map->players++;
		map->player_pos.x = x;
		map->player_pos.y = y;
	}
	else if (elt == 'C')
		map->collectibles++;
	else if (elt == 'E')
	{
		map->exits++;
		map->exit_pos.x = x;
		map->exit_pos.y = y;
	}
	else if (elt == 'S')
		map->cherry++;
}

static int	check_elements(t_map *map)
{
	int	x;
	int	y;

	if (!map || !map->grid)
		return (0);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_in(map->grid[y][x], "PCEGS"))
				add_elt(map->grid[y][x], x, y, map);
			else if (map->grid[y][x] != '0' && map->grid[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

// Fonction principale de validation
int	validate_map(t_map *map)
{
	if (!map || !map->grid)
		return (0);
	if (!is_rectangular(map))
		return (print_error("Map is not rectangular"));
	if (!check_walls(map))
	{
		print_error("Map don't have walls");
		return (0);
	}
	if (!check_elements(map))
	{
		print_error("Invalid map elements");
		return (0);
	}
	if (map->players != 1 || map->exits != 1 || map->collectibles < 1
		|| map->cherry > 1)
	{
		print_error("Invalid number of players, exits, collectibles or cherry");
		return (0);
	}
	if (!all_accessible(map) || !all_accessible2(map))
		return (0);
	return (1);
}
