/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:55:47 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 09:37:35 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	destroy_img(game->mlx, &game->player);
	destroy_img(game->mlx, &game->wall);
	destroy_img(game->mlx, &game->floor);
	destroy_img(game->mlx, &game->collectible);
	destroy_img(game->mlx, &game->cherry);
	destroy_img(game->mlx, &game->exit);
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
