/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:31:00 by apintus           #+#    #+#             */
/*   Updated: 2024/02/19 16:04:26 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_game *map)
{
	int	height;
	int	lenght;

	height = 0;
	lenght = 0;
	map->img.floor = mlx_xpm_file_to_image(map->mlx, "img/floor.xpm", &lenght, &height);
	map->img.wall = mlx_xpm_file_to_image(map->mlx, "img/wall.xpm", &lenght, &height);
	map->img.exit = mlx_xpm_file_to_image(map->mlx, "img/exit.xpm", &lenght, &height);
	map->img.player = mlx_xpm_file_to_image(map->mlx, "img/player.xpm", &lenght, &height);
	map->img.collect = mlx_xpm_file_to_image(map->mlx, "img/collect.xpm", &lenght, &height);
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
				mlx_put_image_to_window(map->mlx, map->win, map->img.wall, x * 64, y * 64);
			if (map->map[y][x] == 'E')
				mlx_put_image_to_window(map->mlx, map->win, map->img.exit, x * 64, y * 64);
			if (map->map[y][x] == 'C')
				mlx_put_image_to_window(map->mlx, map->win, map->img.collect, x * 64, y * 64);
			if (map->map[y][x] == 'P')
				mlx_put_image_to_window(map->mlx, map->win, map->img.player, x * 64, y * 64);
			x++;
		}
		y++;
	}
}


void	init_game(t_game *map)
{
	map->win = mlx_new_window(map->mlx, map->map_lenght * 64, map->map_height * 64, "so_long");
	get_img(map);
	put_background(map);
	put_img(map);
	map->count_steps = 0;
}
int	 key_pressed(int keycode, t_game *map)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(map->mlx, map->win);
		free_map(map);
		exit(0);
	}
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
