/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:11:25 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 08:15:25 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_direction(int dx, int dy)
{
	if (dx == 0 && dy == -1)
		return (0);
	else if (dx == 0 && dy == 1)
		return (1);
	else if (dx == -1 && dy == 0)
		return (2);
	else if (dx == 1 && dy == 0)
		return (3);
	return (-1);
}

void	update_pos(t_game *game, int new_x, int new_y)
{
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	game->map->grid[game->map->player_pos.y][game->map->player_pos.x] = '0';
	game->map->player_pos.x = new_x;
	game->map->player_pos.y = new_y;
	game->map->grid[new_y][new_x] = 'P';
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	dest_tile;

	new_x = game->map->player_pos.x + dx;
	new_y = game->map->player_pos.y + dy;
	dest_tile = game->map->grid[new_y][new_x];
	if (dest_tile == '1')
		return ;
	if (dest_tile == 'E' && game->map->collected != game->map->collectibles)
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
	update_pos(game, new_x, new_y);
	render_map(game);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	if (keycode == UP_KEY || keycode == W_KEY)
		move_player(game, 0, -1);
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		move_player(game, 0, 1);
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		move_player(game, -1, 0);
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		move_player(game, 1, 0);
	return (0);
}
