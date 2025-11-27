/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:49:40 by banne             #+#    #+#             */
/*   Updated: 2025/11/17 09:22:53 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "ft_printf.h"

# define TILE_SIZE 32

# define W_KEY		119
# define A_KEY		97
# define S_KEY		115
# define D_KEY		100
# define KEY_ESC	65307

# define UP_KEY    65362
# define DOWN_KEY  65364
# define LEFT_KEY  65361
# define RIGHT_KEY 65363

typedef struct s_player
{
	int		direction;
	int		frame;
	void	*pacman;
	void	*pacman_up;
	void	*pacman_down;
	void	*pacman_left;
	void	*pacman_right;
	void	*pacman_mid_up;
	void	*pacman_mid_down;
	void	*pacman_mid_left;
	void	*pacman_mid_right;
	void	*super_pacman_up;
	void	*super_pacman_down;
	void	*super_pacman_left;
	void	*super_pacman_right;
}	t_player;

typedef struct s_ghost
{
	int		direction;
	void	*ghost_right;
	void	*ghost_left;
	void	*panic_ghost1;
	void	*panic_ghost2;
}	t_ghost;

typedef struct s_exit
{
	void	*closed;
	void	*open;
}	t_exit;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_map
{
	int			width;
	int			height;
	char		**grid;
	t_position	player_pos;
	t_position	exit_pos;
	int			collectibles;
	int			collected;
	int			exits;
	int			players;
	int			cherry;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		*map;
	int			moves;
	void		*wall;
	void		*floor;
	t_player	player;
	void		*collectible;
	t_exit		exit;
	t_ghost		ghost;
	void		*cherry;
	int			super_pacman;
}	t_game;

/* parsing */
t_map	*parse_map(char *filename);
void	free_map(t_map *map);
int		validate_map(t_map *map);
int		check_args(int argc, char **argv);
char	**make_copy_grid(t_map *map);
int		all_accessible2(t_map *map);

/* game */
t_game	*init_game(t_map *map);
void	load_images(t_game *game);
void	render_map(t_game *game);
int		close_game(t_game *game);
int		key_handler(int keycode, t_game *game);
void	load_bonuses(t_game *game);
void	move_superpacman(t_game *game, int dx, int dy);
void	render_map_superpacman(t_game *game);
void	put_player_mid(t_game *game, int x, int y);
void	put_tile(t_game *game, void *img, int x, int y);
int		get_direction(int dx, int dy);
void	win_game(t_game *game);
void	*move_player2(t_game *game, int new_x, int new_y, char dest_tile);
void	render_map(t_game *game);
void	move_superpacman(t_game *game, int dx, int dy);
void	*print_moves(t_game *game);

/* utils */
int		print_error(char *msg);
int		ft_strlenn(char *s);
void	free_grid(char **grid);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strrchr(char *s, int c);
int		is_in(char c, char *str);
int		ft_strlcpy(char *dst, char *src, size_t size);
int		all_accessible(t_map *map);
void	free_game(t_game *game);
char	*ft_itoa(int n);

#endif
