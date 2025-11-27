/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:51:26 by banne             #+#    #+#             */
/*   Updated: 2025/11/14 14:14:50 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x * 32, y * 32);
}

void	rend(t_game *game, int x, int y)
{
	int	tile;

	tile = game->map->grid[y][x];
	put_tile(game, game->floor, x, y);
	if (tile == '1')
		put_tile(game, game->wall, x, y);
	else if (tile == 'P')
	{
		put_tile(game, game->player, x, y);
	}
	else if (tile == 'C')
		put_tile(game, game->collectible, x, y);
	else if (tile == 'E')
		put_tile(game, game->exit, x, y);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			rend(game, x, y);
			x++;
		}
		y++;
	}
}
