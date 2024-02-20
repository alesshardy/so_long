/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:03:35 by apintus           #+#    #+#             */
/*   Updated: 2024/02/20 12:46:53 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}

void	free_copy(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}


void	exit_read(t_game *map, char *str)
{
	ft_printf("%s\n", str);
	free(map);
	exit(1);
}

void	exit_error(t_game *map, char *str)
{
	ft_printf("%s\n", str);
	free_map(map);
	exit(1);
}

void	destroy_wall(t_game *map)
{
	int	i;

	i = 0;
	while (i < WALL_FRAMES)
	{
		mlx_destroy_image(map->mlx, map->anim_wall.anim_wall[i]);
		i++;
	}
}

void	destroy_exit(t_game *map)
{
	int	i;

	i = 0;
	while (i < EXIT_FRAMES)
	{
		mlx_destroy_image(map->mlx, map->anim_exit.anim_exit[i]);
		i++;
	}
}

int	close_game(t_game *map)
{
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
