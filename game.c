/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:31:00 by apintus           #+#    #+#             */
/*   Updated: 2024/02/20 12:49:42 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_exit(t_game *map)
{
	int	height;
	int	lenght;

	height = 0;
	lenght = 0;
	map->anim_exit.anim_exit[0] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit1.xpm", &lenght, &height);
	map->anim_exit.anim_exit[1] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit2.xpm", &lenght, &height);
	map->anim_exit.anim_exit[2] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit3.xpm", &lenght, &height);
	map->anim_exit.anim_exit[3] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit4.xpm", &lenght, &height);
	map->anim_exit.anim_exit[4] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit5.xpm", &lenght, &height);
	map->anim_exit.anim_exit[5] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit6.xpm", &lenght, &height);
	map->anim_exit.anim_exit[6] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit7.xpm", &lenght, &height);
	map->anim_exit.anim_exit[7] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit8.xpm", &lenght, &height);
	map->anim_exit.anim_exit[8] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit9.xpm", &lenght, &height);
	map->anim_exit.anim_exit[9] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit10.xpm", &lenght, &height);
	map->anim_exit.anim_exit[10] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit11.xpm", &lenght, &height);
	map->anim_exit.anim_exit[11] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit12.xpm", &lenght, &height);
	map->anim_exit.anim_exit[12] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit13.xpm", &lenght, &height);
	map->anim_exit.anim_exit[13] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit14.xpm", &lenght, &height);
	map->anim_exit.anim_exit[14] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit15.xpm", &lenght, &height);
	map->anim_exit.anim_exit[15] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit16.xpm", &lenght, &height);
	map->anim_exit.anim_exit[16] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit17.xpm", &lenght, &height);
	map->anim_exit.anim_exit[17] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit18.xpm", &lenght, &height);
	map->anim_exit.anim_exit[18] = mlx_xpm_file_to_image(map->mlx, "img/Gravity/exit19.xpm", &lenght, &height);
}

void	get_wall(t_game *map)
{
	int	height;
	int	lenght;

	height = 0;
	lenght = 0;
	map->anim_wall.anim_wall[0] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_0.xpm", &lenght, &height);
	map->anim_wall.anim_wall[1] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_1.xpm", &lenght, &height);
	map->anim_wall.anim_wall[2] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_2.xpm", &lenght, &height);
	map->anim_wall.anim_wall[3] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_3.xpm", &lenght, &height);
	map->anim_wall.anim_wall[4] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_4.xpm", &lenght, &height);
	map->anim_wall.anim_wall[5] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_5.xpm", &lenght, &height);
	map->anim_wall.anim_wall[6] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_6.xpm", &lenght, &height);
	map->anim_wall.anim_wall[7] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_7.xpm", &lenght, &height);
	map->anim_wall.anim_wall[8] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_8.xpm", &lenght, &height);
	map->anim_wall.anim_wall[9] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_9.xpm", &lenght, &height);
	map->anim_wall.anim_wall[10] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_10.xpm", &lenght, &height);
	map->anim_wall.anim_wall[11] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_11.xpm", &lenght, &height);
	map->anim_wall.anim_wall[12] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_12.xpm", &lenght, &height);
	map->anim_wall.anim_wall[13] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_13.xpm", &lenght, &height);
	map->anim_wall.anim_wall[14] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_14.xpm", &lenght, &height);
	map->anim_wall.anim_wall[15] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_15.xpm", &lenght, &height);
	map->anim_wall.anim_wall[16] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_16.xpm", &lenght, &height);
	map->anim_wall.anim_wall[17] = mlx_xpm_file_to_image(map->mlx, "img/fire/wall_17.xpm", &lenght, &height);
}

/*void	get_wall(t_game *map)
{
    int	height;
    int	lenght;
    int i;

    height = 0;
    lenght = 0;
    char *filenames[] = {
        "img/fire/wall_0.xpm", "img/fire/wall_1.xpm", "img/fire/wall_2.xpm",
        "img/fire/wall_3.xpm", "img/fire/wall_4.xpm", "img/fire/wall_5.xpm",
        "img/fire/wall_6.xpm", "img/fire/wall_7.xpm", "img/fire/wall_8.xpm",
        "img/fire/wall_9.xpm", "img/fire/wall_10.xpm", "img/fire/wall_11.xpm",
        "img/fire/wall_12.xpm", "img/fire/wall_13.xpm", "img/fire/wall_14.xpm",
        "img/fire/wall_15.xpm", "img/fire/wall_16.xpm", "img/fire/wall_17.xpm",
    };
	while (i < 18)
    {
        map->anim_wall.anim_wall[i] = mlx_xpm_file_to_image(map->mlx, filenames[i], &lenght, &height);
        if (map->anim_wall.anim_wall[i] == NULL) { // check if image is loaded successfully
            ft_printf("Failed to load image: %s\n", filenames[i]);
            exit(1);
        }
		i++;
    }
}*/

/*void	get_exit(t_game *map)
{
	int	height;
	int	lenght;
	int	i;

	height = 0;
	lenght = 0;
	i = 0;
	char *filenames[] = {
		"img/Gravity/exit1.xpm", "img/Gravity/exit2.xpm", "img/Gravity/exit3.xpm",
		"img/Gravity/exit4.xpm", "img/Gravity/exit5.xpm", "img/Gravity/exit6.xpm",
		"img/Gravity/exit7.xpm", "img/Gravity/exit8.xpm", "img/Gravity/exit9.xpm",
		"img/Gravity/exit10.xpm", "img/Gravity/exit11.xpm", "img/Gravity/exit12.xpm",
		"img/Gravity/exit13.xpm", "img/Gravity/exit14.xpm", "img/Gravity/exit15.xpm",
		"img/Gravity/exit16.xpm", "img/Gravity/exit17.xpm", "img/Gravity/exit18.xpm",
		"img/Gravity/exit19.xpm",
	};
	while (i < 19)
	{
		map->anim_exit.anim_exit[i] = mlx_xpm_file_to_image(map->mlx, filenames[i], &lenght, &height);
		if (map->anim_exit.anim_exit[i] == NULL) { // check if image is loaded successfully
			ft_printf("Failed to load image: %s\n", filenames[i]);
			exit(1);
		}
		i++;
	}

}*/

void	get_img(t_game *map)
{
	int	height;
	int	lenght;

	height = 0;
	lenght = 0;
	map->img.floor = mlx_xpm_file_to_image(map->mlx, "img/floor.xpm", &lenght, &height);
	map->img.player = mlx_xpm_file_to_image(map->mlx, "img/player.xpm", &lenght, &height);
	map->img.collect = mlx_xpm_file_to_image(map->mlx, "img/collect.xpm", &lenght, &height);
	get_wall(map);
	get_exit(map);
}
void	put_background(t_game *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			mlx_put_image_to_window(map->mlx, map->win, map->img.floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	put_img(t_game *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while(map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '1')
				mlx_put_image_to_window(map->mlx, map->win, map->anim_wall.anim_wall[map->anim_wall.frame], x * 64, y * 64);
			if (map->map[y][x] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->anim_exit.anim_exit[map->anim_wall.frame], x * 64, y * 64);
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->img.collect, x * 64, y * 64);
			if (map->map[y][x] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->img.player, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
int	update_anim(t_game *map)
{
	static int	frameCount = 0;

	frameCount++;
	if (frameCount % FRAME_DELAY == 0)
	{
		map->anim_wall.frame = (map->anim_wall.frame + 1) % WALL_FRAMES;
		map->anim_exit.frame = (map->anim_exit.frame + 1) % EXIT_FRAMES;
		put_background(map);
		put_img(map);
		display_step_counter(map);
	}
	return (0);
}


void	init_game(t_game *map)
{
	map->win = mlx_new_window(map->mlx, map->map_lenght * 64, map->map_height * 64, "so_long");
	map->anim_wall.frame = 0;
	map->anim_exit.frame = 0;
	get_img(map);
	put_background(map);
	put_img(map);
	mlx_loop_hook(map->mlx, update_anim, map);
	map->count_steps = 0;
}
int	 key_pressed(int keycode, t_game *map)
{
	if (keycode == KEY_ESC)
		close_game(map);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(map);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(map);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(map);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(map);
	return (0);
}
