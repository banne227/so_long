/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:55:47 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 09:36:52 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	destroy_img(void *mlx, void **img)
{
	if (mlx && img && *img)
	{
		mlx_destroy_image(mlx, *img);
		*img = NULL;
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	if (map->grid)
	{
		if (!map->grid)
			return ;
		while (map->grid[i])
		{
			free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
	free(map);
}

void	free_images(t_game *game)
{
	if (!game)
		return ;
	destroy_img(game->mlx, &game->player.pacman);
	destroy_img(game->mlx, &game->player.pacman_up);
	destroy_img(game->mlx, &game->player.pacman_down);
	destroy_img(game->mlx, &game->player.pacman_left);
	destroy_img(game->mlx, &game->player.pacman_right);
	destroy_img(game->mlx, &game->player.pacman_mid_up);
	destroy_img(game->mlx, &game->player.pacman_mid_down);
	destroy_img(game->mlx, &game->player.pacman_mid_left);
	destroy_img(game->mlx, &game->player.pacman_mid_right);
	destroy_img(game->mlx, &game->player.super_pacman_up);
	destroy_img(game->mlx, &game->player.super_pacman_down);
	destroy_img(game->mlx, &game->player.super_pacman_left);
	destroy_img(game->mlx, &game->player.super_pacman_right);
	destroy_img(game->mlx, &game->ghost.ghost_right);
	destroy_img(game->mlx, &game->ghost.ghost_left);
	destroy_img(game->mlx, &game->ghost.panic_ghost1);
	destroy_img(game->mlx, &game->ghost.panic_ghost2);
	destroy_img(game->mlx, &game->wall);
	destroy_img(game->mlx, &game->floor);
	destroy_img(game->mlx, &game->collectible);
	destroy_img(game->mlx, &game->cherry);
	destroy_img(game->mlx, &game->exit.closed);
	destroy_img(game->mlx, &game->exit.open);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_images(game);
	if (game->window)
	{
		mlx_destroy_window(game->mlx, game->window);
		game->window = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	free_map(game->map);
	free(game);
}

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
	return (0);
}
