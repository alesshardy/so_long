/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:31:00 by apintus           #+#    #+#             */
/*   Updated: 2024/02/23 11:52:02 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_img(t_game *map, char *img_path, void **img_ptr)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	*img_ptr = mlx_xpm_file_to_image(map->mlx, img_path, &width, &height);
	if (*img_ptr == NULL)
	{
		ft_printf("Failed to load image: %s\n", img_path);
		close_game(map);
	}
}

void	get_img_anim(t_game *map, char *filenames[], void **img_ptr, int frames)
{
	int	height;
	int	width;
	int	i;

	height = 0;
	width = 0;
	i = 0;
	while (i < frames)
	{
		img_ptr[i] = mlx_xpm_file_to_image(map->mlx, filenames[i],
				&width, &height);
		if (img_ptr[i] == NULL)
		{
			ft_printf("Failed to load image: %s\n", filenames[i]);
			close_game(map);
		}
		i++;
	}
}

void	put_image(t_game *map, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img.floor,
			x * 64, y * 64);
	else if (c == '1')
		mlx_put_image_to_window(map->mlx, map->win,
			map->wall.anim[map->wall.frame], x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->win,
			map->exit.anim[map->exit.frame], x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->img.collect,
			x * 64, y * 64);
	else if (c == 'P')
	{
		if (map->count_steps == 0)
			mlx_put_image_to_window(map->mlx, map->win,
				map->spawn.anim[map->spawn.frame], x * 64, y * 64);
		else
			mlx_put_image_to_window(map->mlx, map->win,
				map->player.anim[map->player.frame], x * 64, y * 64);
	}
	else if (c == 'N')
		mlx_put_image_to_window(map->mlx, map->win, map->img.enemies,
			x * 64, y * 64);
}

void	put_img(t_game *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			put_image(map, map->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	init_game(t_game *map)
{
	mlx_get_screen_size(map->mlx, &map->screen_lenght, &map->screen_height);
	if (map->map_lenght * 64 > map->screen_lenght
		|| map->map_height * 64 > map->screen_height)
	{
		ft_putstr_fd("Error\nMap is too big\n", 2);
		close_game(map);
	}
	map->win = mlx_new_window(map->mlx, map->map_lenght * 64,
			map->map_height * 64, "so_long");
	map->wall.frame = 0;
	map->exit.frame = 0;
	map->spawn.frame = 0;
	map->player.frame = 0;
	map->count_steps = 0;
	get_image(map);
	put_img(map);
	mlx_loop_hook(map->mlx, update_anim, map);
}
