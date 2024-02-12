/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:12:09 by apintus           #+#    #+#             */
/*   Updated: 2024/02/12 17:38:47 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	visual_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}


int	main (int argc, char **argv)
{
	t_game_map	*map;

	map = malloc(sizeof(t_game_map));
	if (argc != 2 || check_extension(argv[1]))
		return (printf("extension n'est pas valide\n"), 1);

	get_map(map, argv[1]);
	visual_map(map->map);

	/*if (check_map(&map) == 1)
		return (printf("Map pas valide\n"), 1);
	else
		return (printf("MAP OK\n"), 0);*/
	
	return (0);
}
