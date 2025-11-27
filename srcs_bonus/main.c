/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:57:08 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 09:03:25 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (!check_args(argc, argv))
		return (1);
	map = parse_map(argv[1]);
	if (!map || !validate_map(map))
	{
		if (map)
			free_map(map);
		return (1);
	}
	game = init_game(map);
	if (!game)
	{
		free_map(map);
		return (1);
	}
	render_map(game);
	mlx_hook(game->window, 2, 1, key_handler, game);
	mlx_hook(game->window, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}
