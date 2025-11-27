/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:55:39 by banne             #+#    #+#             */
/*   Updated: 2025/11/14 13:52:33 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_bonuses(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->ghost.panic_ghost1 = mlx_xpm_file_to_image(game->mlx,
			"textures/ghost/ghost_panic1.xpm", &width, &height);
	game->ghost.panic_ghost2 = mlx_xpm_file_to_image(game->mlx,
			"textures/ghost/ghost_panic2.xpm", &width, &height);
	game->player.super_pacman_up = mlx_xpm_file_to_image(game->mlx,
			"textures/player/super_pacman/pacman_up.xpm", &width, &height);
	game->player.super_pacman_down = mlx_xpm_file_to_image(game->mlx,
			"textures/player/super_pacman/pacman_down.xpm", &width, &height);
	game->player.super_pacman_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player/super_pacman/pacman_left.xpm", &width, &height);
	game->player.super_pacman_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player/super_pacman/pacman_right.xpm", &width, &height);
	if (!game->ghost.panic_ghost1 || !game->ghost.panic_ghost2
		|| !game->player.super_pacman_up || !game->player.super_pacman_down
		|| !game->player.super_pacman_left || !game->player.super_pacman_right)
	{
		print_error("Failed to load bonus textures");
		free_grid(game->map->grid);
	}
}
