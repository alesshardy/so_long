/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:58:00 by apintus           #+#    #+#             */
/*   Updated: 2024/02/13 17:19:19 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'P' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'C')
				return (1);
			else if (map->map[i][j] == 'P')
				map->count_p++;
			else if (map->map[i][j] == 'E')
				map->count_e++;
			else if (map->map[i][j] == 'C')
				map->count_c++;
			j++;
		}
		i++;
	}
	if (map->count_c < 1 || map->count_e != 1 || map->count_p != 1)
		return (1);
	return (0);
}

int	check_map(t_game *map)
{
	if (check_map_content(map) == 1)
		return (1);
	return (0);
}
