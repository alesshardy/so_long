/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:31:17 by apintus           #+#    #+#             */
/*   Updated: 2024/02/23 11:58:42 by apintus          ###   ########.fr       */
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
	ft_putstr_fd(str, 2);
	free(map);
	exit(1);
}

void	exit_error(t_game *map, char *str)
{
	ft_putstr_fd(str, 2);
	free_map(map);
	exit(1);
}

int	close_game(t_game *map)
{
	destroy_img(map);
	destroy_player(map);
	destroy_wall(map);
	destroy_exit(map);
	destroy_spawn(map);
	if (map->win != NULL)
		mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	exit(0);
}
