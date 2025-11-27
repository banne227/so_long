/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:50:32 by banne             #+#    #+#             */
/*   Updated: 2025/11/14 13:52:27 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	load_map(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&width, &height);
	game->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->exit.closed = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/portail_close.xpm", &width, &height);
	game->exit.open = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/portail_open.xpm", &width, &height);
	if (!game->wall || !game->floor || !game->collectible)
	{
		print_error("Failed to load textures");
		free_grid(game->map->grid);
	}
}

static void	load_player2(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->ghost.ghost_left = mlx_xpm_file_to_image(game->mlx,
			"textures/ghost/ghost_left.xpm", &width, &height);
	game->player.pacman_mid_up = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman_mid_up.xpm", &width, &height);
	game->player.pacman_mid_down = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman_mid_down.xpm", &width, &height);
	game->player.pacman_mid_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman_mid_left.xpm", &width, &height);
	game->player.pacman_mid_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman_mid_right.xpm", &width, &height);
	if (!game->ghost.ghost_right || !game->player.pacman_up
		|| !game->ghost.ghost_left || !game->player.pacman_right
		|| !game->player.pacman_down || !game->player.pacman_left
		|| !game->player.pacman_mid_up || !game->player.pacman_mid_down
		|| !game->player.pacman_mid_left || !game->player.pacman_mid_right
		|| !game->player.pacman)
	{
		print_error("Failed to load textures");
		free_grid(game->map->grid);
	}
}

static void	load_player(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->player.pacman = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman.xpm", &width, &height);
	game->player.pacman_up = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman_up.xpm", &width, &height);
	game->player.pacman_down = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman_down.xpm", &width, &height);
	game->player.pacman_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman_left.xpm", &width, &height);
	game->player.pacman_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman_right.xpm", &width, &height);
	game->ghost.ghost_right = mlx_xpm_file_to_image(game->mlx,
			"textures/ghost/ghost_right.xpm", &width, &height);
	game->cherry = mlx_xpm_file_to_image(game->mlx,
			"textures/cherry.xpm", &width, &height);
	load_player2(game);
	load_bonuses(game);
}

static void	load_textures_n_init(t_game *game)
{
	load_map(game);
	load_player(game);
	game->moves = 0;
	game->player.direction = -1;
	game->ghost.direction = 1;
	game->map->collected = 0;
	game->player.frame = 0;
}

t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		print_error("Malloc error");
	game->mlx = mlx_init();
	if (!game->mlx)
		print_error("Failed to initialize MLX");
	game->window = mlx_new_window(
			game->mlx,
			map->width * TILE_SIZE,
			map->height * TILE_SIZE,
			"So Long"
			);
	if (!game->window)
		print_error("Failed to create window");
	game->map = map;
	load_textures_n_init(game);
	game->super_pacman = 0;
	return (game);
}
