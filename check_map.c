/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:58:00 by apintus           #+#    #+#             */
/*   Updated: 2024/02/23 12:01:46 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_and_count(t_game *map, char c, int i, int j)
{
	if (c == 'P')
	{
		map->pos.x = j;
		map->pos.y = i;
		map->count_p++;
	}
	else if (c == 'E')
		map->count_e++;
	else if (c == 'C')
		map->count_c++;
	else if (c != '1' && c != '0' && c != 'N')
		return (1);
	return (0);
}

int	check_map_content(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (check_and_count(map, map->map[i][j], i, j))
				return (1);
			j++;
		}
		i++;
	}
	if (map->count_c < 1 || map->count_e != 1 || map->count_p != 1)
		return (1);
	return (0);
}

int	check_map_rectangle(t_game *map)
{
	int	i;

	i = 0;
	map->map_lenght = ft_strlen_so(map->map[0]);
	while (i < map->map_height)
	{
		if (ft_strlen_so(map->map[i]) != map->map_lenght)
			return (1);
		i++;
	}
	return (0);
}

int	check_map_close(t_game *map)
{
	int	i;

	i = 0;
	while (map->map[0][i])
	{
		if (map->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map->map[map->map_height - 1][i])
	{
		if (map->map[map->map_height - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < map->map_height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->map_lenght - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_map(t_game *map)
{
	if (check_map_content(map) == 1)
		return (exit_error(map, "Error\nMap content not valid\n"));
	if (check_map_rectangle(map) == 1)
		return (exit_error(map, "Error\nMap not rectangle\n"));
	if (check_map_close(map) == 1)
		return (exit_error(map, "Error\nMap not close\n"));
	if (check_map_flood_fill(map) == 1)
		return (exit_error(map, "Error\nCollectibles or exit not accessible\n"));
}
