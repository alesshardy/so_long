/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:12:09 by apintus           #+#    #+#             */
/*   Updated: 2024/02/13 18:17:56 by apintus          ###   ########.fr       */
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
	t_game	*map;

	map = malloc(sizeof(t_game));
	if (map == NULL)
		return (printf("Malloc error\n"), 1);
	if (argc != 2 || check_extension(argv[1]))
		return (ft_printf("Error\nInvalid arguments ou extension\n"), 1);
	map->map = get_map(map, argv[1]);
	//visual_map(map->map);

	/*if (check_map(map) == 1)
		return (printf("Map pas valide\n"), 1);
	else
		return (printf("MAP OK\n"), 0);*/
	check_map(map);
	return (0);
}
