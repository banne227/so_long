/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_cherry.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:23:18 by banne             #+#    #+#             */
/*   Updated: 2025/11/14 13:54:01 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	flood_fill(t_map *map, char **grid, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'V' || grid[y][x] == 'G')
		return ;
	grid[y][x] = 'V';
	flood_fill(map, grid, x + 1, y);
	flood_fill(map, grid, x - 1, y);
	flood_fill(map, grid, x, y + 1);
	flood_fill(map, grid, x, y - 1);
}

static int	verif_access(char **grid, int width, int height)
{
	int	x;
	int	y;

	if (!grid)
		return (0);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (grid[y][x] == 'S')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	all_accessible2(t_map *map)
{
	int		x;
	int		y;
	char	**copy;
	int		result;

	if (!map || !map->grid)
		return (0);
	x = map->player_pos.x;
	y = map->player_pos.y;
	copy = make_copy_grid(map);
	if (!copy)
		return (0);
	flood_fill(map, copy, x, y);
	result = verif_access(copy, map->width, map->height);
	free_grid(copy);
	if (result == 0)
		print_error("No accessible cherry found");
	return (result);
}
