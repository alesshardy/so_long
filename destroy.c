/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:03:35 by apintus           #+#    #+#             */
/*   Updated: 2024/02/22 19:26:38 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_exit(t_game *map)
{
	int	i;

	i = 0;
	while (i < EXIT_FRAMES)
	{
		if (map->exit.anim[i] != NULL)
			mlx_destroy_image(map->mlx, map->exit.anim[i]);
		i++;
	}
}

void	destroy_spawn(t_game *map)
{
	int	i;

	i = 0;
	while (i < SPAWN_FRAMES)
	{
		if (map->spawn.anim[i] != NULL)
			mlx_destroy_image(map->mlx, map->spawn.anim[i]);
		i++;
	}
}

void	destroy_player(t_game *map)
{
	int	i;

	i = 0;
	while (i < PLAYER_FRAMES)
	{
		if (map->player.anim[i] != NULL)
			mlx_destroy_image(map->mlx, map->player.anim[i]);
		i++;
	}
}

void	destroy_img(t_game *map)
{
	if (map->img.floor != NULL)
		mlx_destroy_image(map->mlx, map->img.floor);
	if (map->img.collect != NULL)
		mlx_destroy_image(map->mlx, map->img.collect);
	if (map->img.enemies != NULL)
		mlx_destroy_image(map->mlx, map->img.enemies);
}

void	destroy_wall(t_game *map)
{
	int	i;

	i = 0;
	while (i < WALL_FRAMES)
	{
		if (map->wall.anim[i] != NULL)
			mlx_destroy_image(map->mlx, map->wall.anim[i]);
		i++;
	}
}
