/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:51:26 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 09:21:22 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x * 32, y * 32);
}

void	put_player_mid(t_game *game, int x, int y)
{
	if (!game)
		return ;
	if (game->player.direction == 0)
		put_tile(game, game->player.pacman_mid_up, x, y);
	else if (game->player.direction == 1)
		put_tile(game, game->player.pacman_mid_down, x, y);
	else if (game->player.direction == 2)
		put_tile(game, game->player.pacman_mid_left, x, y);
	else if (game->player.direction == 3)
		put_tile(game, game->player.pacman_mid_right, x, y);
}

static void	put_player(t_game *game, int x, int y)
{
	if (!game)
		return ;
	if (game->player.frame % 2 == 1)
	{
		put_player_mid(game, x, y);
		return ;
	}
	if (game->player.direction == -1)
		put_tile(game, game->player.pacman, x, y);
	else if (game->player.direction == 0)
		put_tile(game, game->player.pacman_up, x, y);
	else if (game->player.direction == 1)
		put_tile(game, game->player.pacman_down, x, y);
	else if (game->player.direction == 2)
		put_tile(game, game->player.pacman_left, x, y);
	else if (game->player.direction == 3)
		put_tile(game, game->player.pacman_right, x, y);
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
		put_player(game, x, y);
		game->player.frame++;
	}
	else if (tile == 'C')
		put_tile(game, game->collectible, x, y);
	else if (tile == 'G')
	{
		if (game->ghost.direction == 1)
			put_tile(game, game->ghost.ghost_right, x, y);
		else
			put_tile(game, game->ghost.ghost_left, x, y);
		game->ghost.direction *= -1;
	}
}

void	render_map(t_game *game)
{
	int	x;
	int	y;
	int	x_exit;

	y = 0;
	x_exit = game->map->exit_pos.x;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			rend(game, x, y);
			if (game->map->grid[y][x] == 'S')
				put_tile(game, game->cherry, x, y);
			if (game->map->collected == game->map->collectibles)
			{
				put_tile(game, game->exit.open,
					x_exit, game->map->exit_pos.y);
				game->map->grid[game->map->exit_pos.y][x_exit] = 'E';
			}
			x++;
		}
		y++;
	}
	print_moves(game);
}
