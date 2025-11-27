/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:11:25 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 09:11:08 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	*move_player2(t_game *game, int new_x, int new_y, char dest_tile)
{
	if (dest_tile == 'G')
	{
		ft_printf("Ghost touches you!\n");
		close_game(game);
		return (NULL);
	}
	if (dest_tile == 'S')
	{
		ft_printf("Super Pacman activated!\n");
		game->super_pacman = 1;
	}
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	game->map->grid[game->map->player_pos.y][game->map->player_pos.x] = '0';
	game->map->player_pos.x = new_x;
	game->map->player_pos.y = new_y;
	game->map->grid[new_y][new_x] = 'P';
	render_map(game);
	return (NULL);
}

void	*move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	dest_tile;

	new_x = game->map->player_pos.x + dx;
	new_y = game->map->player_pos.y + dy;
	dest_tile = game->map->grid[new_y][new_x];
	game->player.direction = get_direction(dx, dy);
	if (dest_tile == '1')
		return (print_moves(game));
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
		return (NULL);
	}
	move_player2(game, new_x, new_y, dest_tile);
	return (NULL);
}

int	key_handler(int keycode, t_game *game)
{
	if (game->super_pacman)
	{
		if (keycode == KEY_ESC)
			close_game(game);
		if (keycode == UP_KEY || keycode == W_KEY)
			move_superpacman(game, 0, -1);
		else if (keycode == DOWN_KEY || keycode == S_KEY)
			move_superpacman(game, 0, 1);
		else if (keycode == LEFT_KEY || keycode == A_KEY)
			move_superpacman(game, -1, 0);
		else if (keycode == RIGHT_KEY || keycode == D_KEY)
			move_superpacman(game, 1, 0);
		return (0);
	}
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
