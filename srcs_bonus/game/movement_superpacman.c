/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_superpacman.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:01:19 by banne             #+#    #+#             */
/*   Updated: 2025/11/14 13:52:39 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mov_superpacman2(t_game *game, int new_x, int new_y, char dest_tile)
{
	if (dest_tile == 'G')
		ft_printf("Tasty ghost!\n");
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	game->map->grid[game->map->player_pos.y][game->map->player_pos.x] = '0';
	game->map->player_pos.x = new_x;
	game->map->player_pos.y = new_y;
	game->map->grid[new_y][new_x] = 'P';
	render_map_superpacman(game);
}

void	move_superpacman(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	dest_tile;

	new_x = game->map->player_pos.x + dx;
	new_y = game->map->player_pos.y + dy;
	dest_tile = game->map->grid[new_y][new_x];
	game->player.direction = get_direction(dx, dy);
	if (dest_tile == '1')
		return ;
	if (dest_tile == 'C')
	{
		game->map->collected++;
		game->map->grid[new_y][new_x] = '0';
	}
	if (dest_tile == 'E' && game->map->collected == game->map->collectibles)
	{
		game->moves++;
		ft_printf("You win in %d moves!\n", game->moves);
		close_game(game);
		return ;
	}
	mov_superpacman2(game, new_x, new_y, dest_tile);
}
