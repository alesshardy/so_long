/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:13:09 by apintus           #+#    #+#             */
/*   Updated: 2024/02/23 11:47:12 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx/mlx.h"

# define WALL_FRAMES 18
# define EXIT_FRAMES 19
# define SPAWN_FRAMES 8
# define PLAYER_FRAMES 6
# define FRAME_DELAY 1000
# define WALL_DELAY 3000
# define EXIT_DELAY 1500
# define SPAWN_DELAY 15000
# define PLAYER_DELAY 1500

//key_hook
enum			e_keys
{
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_UP = 65362,
	KEY_S = 115,
	KEY_DOWN = 65364,
	KEY_A = 97,
	KEY_LEFT = 65361,
	KEY_D = 100,
	KEY_RIGHT = 65363,
};

//animation
typedef struct s_anim_wall
{
	void	*anim[WALL_FRAMES];
	int		frame;
}	t_anim_wall;

typedef struct s_anim_exit
{
	void	*anim[EXIT_FRAMES];
	int		frame;
}	t_anim_exit;

typedef struct s_anim_spawn
{
	void	*anim[SPAWN_FRAMES];
	int		frame;
}	t_anim_spawn;

typedef struct s_anim_player
{
	void	*anim[PLAYER_FRAMES];
	int		frame;
}	t_anim_player;

//IMAGE
typedef struct s_img
{
	void	*floor;
	void	*collect;
	void	*enemies;
}	t_img;

//STRUCT
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
	int		fd;
	int		i;
	int		check;
	char	*line;
	char	*temp;
	char	*old_line;
	char	**map;
}	t_data;

typedef struct s_game
{
	int				map_height;
	int				map_lenght;
	int				screen_height;
	int				screen_lenght;
	int				count_c;
	int				count_e;
	int				count_p;
	int				count_steps;
	char			**map;
	void			*mlx;
	void			*win;
	t_data			data;
	t_pos			pos;
	t_img			img;
	t_anim_wall		wall;
	t_anim_exit		exit;
	t_anim_spawn	spawn;
	t_anim_player	player;
}	t_game;

//PARSSING
int		check_extension(char *str);
int		check_and_count(t_game *map, char c, int i, int j);
int		check_map_content(t_game *map);
int		check_map_rectangle(t_game *map);
int		check_map_close(t_game *map);
void	check_map(t_game *map);
char	**get_map(t_game *get_map, char *file_name);
int		ft_strlen_so(char *str);

//FLOOD_FILL
char	**copy_map(t_game *map);
void	flood_fill(t_game *map, int x, int y, char **copy);
int		check_map_flood_fill(t_game *map);

//EXIT
void	exit_error(t_game *map, char *str);
void	exit_read(t_game *map, char *str);
void	exit_game(t_game *map, int win);
void	free_copy(char **copy);
void	free_map(t_game *map);
int		close_game(t_game *map);
void	destroy_wall(t_game *map);
void	destroy_exit(t_game *map);
void	destroy_spawn(t_game *map);
void	destroy_player(t_game *map);
void	destroy_img(t_game *map);

//GAME
void	init_game(t_game *map);
void	get_image(t_game *map);
int		key_pressed(int keycode, t_game *map);
void	put_img(t_game *map);
void	move_up(t_game *map);
void	move_down(t_game *map);
void	move_left(t_game *map);
void	move_right(t_game *map);
void	display_step_counter(t_game *map);

//ANIMATION
int		update_anim(t_game *map);

//GET IMAGE
void	get_image(t_game *map);
void	get_img(t_game *map, char *img_path, void **img_ptr);
void	get_img_anim(t_game *map, char *filenames[], void **img_ptr,
			int frames);

#endif
