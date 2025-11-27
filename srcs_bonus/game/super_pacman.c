/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_pacman.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:29:03 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 09:21:51 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:51:26 by banne             #+#    #+#             */
/*   Updated: 2025/11/13 15:26:31 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	reload_sprites(t_game *game)
{
	game->player.pacman_up = game->player.super_pacman_up;
	game->player.pacman_down = game->player.super_pacman_down;
	game->player.pacman_left = game->player.super_pacman_left;
	game->player.pacman_right = game->player.super_pacman_right;
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

static void	rend_super(t_game *game, int x, int y, int tile)
{
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
			put_tile(game, game->ghost.panic_ghost1, x, y);
		else
			put_tile(game, game->ghost.panic_ghost2, x, y);
		game->ghost.direction *= -1;
	}
	else if (game->map->grid[y][x] == 'S')
	{
		put_tile(game, game->cherry, x, y);
		game->super_pacman = 1;
	}
}

void	render_map_superpacman(t_game *game)
{
	int	x;
	int	y;
	int	tile;
	int	x_exit;

	y = 0;
	x_exit = game->map->exit_pos.x;
	while (game->map->grid[y])
	{
		x = 0;
		while (game->map->grid[y][x])
		{
			tile = game->map->grid[y][x];
			rend_super(game, x, y, tile);
			if (game->map->collected == game->map->collectibles)
			{
				put_tile(game, game->exit.open, game->map->exit_pos.x,
					game->map->exit_pos.y);
				game->map->grid[game->map->exit_pos.y][x_exit] = 'E';
			}
			x++;
		}
		y++;
	}
	print_moves(game);
}
