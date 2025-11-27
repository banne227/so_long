/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:50:32 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 09:15:36 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit/portail_open.xpm", &width, &height);
	if (!game->wall || !game->floor || !game->collectible)
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
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player/pacman.xpm", &width, &height);
	game->cherry = mlx_xpm_file_to_image(game->mlx,
			"textures/cherry.xpm", &width, &height);
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
	game->moves = 0;
	load_map(game);
	load_player(game);
	return (game);
}
