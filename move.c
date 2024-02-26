/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:22:06 by apintus           #+#    #+#             */
/*   Updated: 2024/02/23 11:15:58 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_step_counter(t_game *map)
{
	char	*message;
	char	*step_count;

	step_count = ft_itoa(map->count_steps);
	message = ft_strjoin("Step count: ", step_count);
	mlx_string_put(map->mlx, map->win, 10, 10, 0xFFFFFF, message);
	free(step_count);
	free(message);
}

void	move_up(t_game *map)
{
	if (map->map[map->pos.y - 1][map->pos.x] != '1' )
	{
		if (map->map[map->pos.y - 1][map->pos.x] == 'E' && map->count_c == 0)
			exit_game(map, 1);
		else if (map->map[map->pos.y - 1][map->pos.x] == 'E'
			&& map->count_c != 0)
			return ;
		else if (map->map[map->pos.y - 1][map->pos.x] == 'N')
			exit_game(map, 0);
		map->map[map->pos.y][map->pos.x] = '0';
		map->pos.y -= 1;
		if (map->map[map->pos.y][map->pos.x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		map->count_steps += 1;
		ft_printf("steps %d\n", map->count_steps);
	}
}

void	move_down(t_game *map)
{
	if (map->map[map->pos.y + 1][map->pos.x] != '1')
	{
		if (map->map[map->pos.y + 1][map->pos.x] == 'E' && map->count_c == 0)
			exit_game(map, 1);
		else if (map->map[map->pos.y + 1][map->pos.x] == 'E'
			&& map->count_c != 0)
			return ;
		else if (map->map[map->pos.y + 1][map->pos.x] == 'N')
			exit_game(map, 0);
		map->map[map->pos.y][map->pos.x] = '0';
		map->pos.y += 1;
		if (map->map[map->pos.y][map->pos.x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		map->count_steps += 1;
		ft_printf("steps %d\n", map->count_steps);
	}
}

void	move_left(t_game *map)
{
	if (map->map[map->pos.y][map->pos.x - 1] != '1')
	{
		if (map->map[map->pos.y][map->pos.x - 1] == 'E' && map->count_c == 0)
			exit_game(map, 1);
		else if (map->map[map->pos.y][map->pos.x - 1] == 'E'
			&& map->count_c != 0)
			return ;
		else if (map->map[map->pos.y][map->pos.x - 1] == 'N')
			exit_game(map, 0);
		map->map[map->pos.y][map->pos.x] = '0';
		map->pos.x -= 1;
		if (map->map[map->pos.y][map->pos.x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		map->count_steps += 1;
		ft_printf("steps %d\n", map->count_steps);
	}
}

void	move_right(t_game *map)
{
	if (map->map[map->pos.y][map->pos.x + 1] != '1')
	{
		if (map->map[map->pos.y][map->pos.x + 1] == 'E' && map->count_c == 0)
			exit_game(map, 1);
		else if (map->map[map->pos.y][map->pos.x + 1] == 'E'
			&& map->count_c != 0)
			return ;
		else if (map->map[map->pos.y][map->pos.x + 1] == 'N')
			exit_game(map, 0);
		map->map[map->pos.y][map->pos.x] = '0';
		map->pos.x += 1;
		if (map->map[map->pos.y][map->pos.x] == 'C')
			map->count_c -= 1;
		map->map[map->pos.y][map->pos.x] = 'P';
		map->count_steps += 1;
		ft_printf("steps %d\n", map->count_steps);
	}
}
