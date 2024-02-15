/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:00:51 by apintus           #+#    #+#             */
/*   Updated: 2024/02/15 13:28:41 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *map)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (map->map_height + 1));
	if (!copy)
		exit_read(map, "Error\nMalloc failed\n");
	while (i < map->map_height)
	{
		copy[i] = ft_strdup(map->map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
void	flood_fill(t_game *map, int x, int y, char **copy)
{
	//visual_map(copy); //DEBUG
	if (x >= map->map_lenght || y >= map->map_height || copy[y][x] == 'X')
		return ;
	if (copy[y][x] == '1')
		return ;
	if (copy[y][x] == 'E')
	{
		copy[y][x] = 'X';
		return ;
	}
	copy[y][x] = 'X';
	flood_fill(map, x + 1, y, copy);//droite
	flood_fill(map, x - 1, y, copy);//gauche
	flood_fill(map, x, y + 1, copy);//bas
	flood_fill(map, x, y - 1, copy);//haut
	return ;
}
int	check_map_flood_fill(t_game *map)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = copy_map(map);
	printf("x = %d, y = %d\n", map->pos.x, map->pos.y);//DEBUG
	flood_fill(map, map->pos.x, map->pos.y, copy);
	visual_map(copy);
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_lenght)
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
				return (free_copy(copy), 1);
			j++;
		}
		i++;
	}
	free_copy(copy);
	return (0);
}
