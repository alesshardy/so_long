/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:22:06 by apintus           #+#    #+#             */
/*   Updated: 2024/02/20 12:47:04 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 		exit_game(t_game *map)
{
	map->count_steps += 1;
	ft_printf("steps %d\n", map->count_steps);
	printf("You win\n");//DEBUG
	mlx_destroy_image(map->mlx, map->img.floor);
	mlx_destroy_image(map->mlx, map->img.player);
	mlx_destroy_image(map->mlx, map->img.collect);
	destroy_wall(map);
	destroy_exit(map);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free_map(map);
	exit(0);
}
void display_step_counter(t_game *map)
{
    char *message;
    char *step_count;

    step_count = ft_itoa(map->count_steps); // Convert step count to string
    message = ft_strjoin("Step count: ", step_count); // Create message

    mlx_string_put(map->mlx, map->win, 10, 10, 0xFFFFFF, message); // Display message

    free(step_count); // Free memory
    free(message);
}

void	move_up(t_game *map)
{
	if(map->map[map->pos.y - 1][map->pos.x] != '1' )
	{
		if (map->map[map->pos.y - 1][map->pos.x] == 'E' && map->count_c == 0)
			exit_game(map);
		else if (map->map[map->pos.y - 1][map->pos.x] == 'E' && map->count_c != 0)
			return ;
		map->map[map->pos.y][map->pos.x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->img.floor, map->pos.x * 64, map->pos.y * 64);
		map->pos.y -= 1;
		if (map->map[map->pos.y][map->pos.x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		mlx_put_image_to_window(map->mlx, map->win, map->img.player, map->pos.x * 64, map->pos.y * 64);
		map->count_steps += 1;
		ft_printf("steps %d\n", map->count_steps);
	}
}

void	move_down(t_game *map)
{
	if(map->map[map->pos.y + 1][map->pos.x] != '1')
	{
		if (map->map[map->pos.y + 1][map->pos.x] == 'E' && map->count_c == 0)
			exit_game(map);
		else if (map->map[map->pos.y + 1][map->pos.x] == 'E' && map->count_c != 0)
			return ;
		map->map[map->pos.y][map->pos.x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->img.floor, map->pos.x * 64, map->pos.y * 64);
		map->pos.y += 1;
		if (map->map[map->pos.y][map->pos.x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		mlx_put_image_to_window(map->mlx, map->win, map->img.player, map->pos.x * 64, map->pos.y * 64);
		map->count_steps += 1;
		ft_printf("steps %d\n", map->count_steps);
	}
}

void	move_left(t_game *map)
{
	if(map->map[map->pos.y][map->pos.x - 1] != '1')
	{
		if (map->map[map->pos.y][map->pos.x - 1] == 'E' && map->count_c == 0)
			exit_game(map);
		else if (map->map[map->pos.y][map->pos.x - 1] == 'E' && map->count_c != 0)
			return ;
		map->map[map->pos.y][map->pos.x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->img.floor, map->pos.x * 64, map->pos.y * 64);
		map->pos.x -= 1;
		if (map->map[map->pos.y][map->pos.x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		mlx_put_image_to_window(map->mlx, map->win, map->img.player, map->pos.x * 64, map->pos.y * 64);
		map->count_steps += 1;
		ft_printf("steps %d\n", map->count_steps);
	}

}
void	move_right(t_game *map)
{
	if(map->map[map->pos.y][map->pos.x + 1] != '1')
	{
		if (map->map[map->pos.y][map->pos.x + 1] == 'E' && map->count_c == 0)
			exit_game(map);
		else if (map->map[map->pos.y][map->pos.x + 1] == 'E' && map->count_c != 0)
			return ;
		map->map[map->pos.y][map->pos.x] = '0';
		mlx_put_image_to_window(map->mlx, map->win, map->img.floor, map->pos.x * 64, map->pos.y * 64);
		map->pos.x += 1;
		if (map->map[map->pos.y][map->pos.x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		mlx_put_image_to_window(map->mlx, map->win, map->img.player, map->pos.x * 64, map->pos.y * 64);
		map->count_steps += 1;
		ft_printf("steps %d\n", map->count_steps);
	}

}
