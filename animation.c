/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:43:15 by apintus           #+#    #+#             */
/*   Updated: 2024/02/22 19:09:48 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_wall_anim(t_game *map, int frame_count)
{
	if (frame_count % WALL_DELAY == 0)
	{
		if (map->wall.frame == WALL_FRAMES - 1)
			map->wall.frame = 0;
		else
			map->wall.frame++;
	}
}

void	update_exit_anim(t_game *map, int frame_count)
{
	if (frame_count % EXIT_DELAY == 0)
	{
		if (map->exit.frame == EXIT_FRAMES - 1)
			map->exit.frame = 0;
		else
			map->exit.frame++;
	}
}

void	update_spawn_anim(t_game *map, int frame_count)
{
	if (frame_count % SPAWN_DELAY == 0)
	{
		if (map->spawn.frame == SPAWN_FRAMES - 1)
			map->spawn.frame = 0;
		else
			map->spawn.frame++;
	}
}

void	update_player_anim(t_game *map, int frame_count)
{
	if (frame_count % PLAYER_DELAY == 0)
	{
		if (map->player.frame == PLAYER_FRAMES - 1)
			map->player.frame = 0;
		else
			map->player.frame++;
	}
}

int	update_anim(t_game *map)
{
	static int	frame_count = 0;

	frame_count++;
	if (frame_count > 94120)
		frame_count = 0;
	update_wall_anim(map, frame_count);
	update_exit_anim(map, frame_count);
	update_spawn_anim(map, frame_count);
	update_player_anim(map, frame_count);
	if (frame_count % FRAME_DELAY == 0)
	{
		put_img(map);
		display_step_counter(map);
	}
	return (0);
}
