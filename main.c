/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:12:09 by apintus           #+#    #+#             */
/*   Updated: 2024/02/14 13:08:26 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	visual_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);//DEBUG
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
		return (free(map), ft_printf("Error\nInvalid argument or extension\n"), 1);
	map->map = get_map(map, argv[1]);
	//visual_map(map->map);
	check_map(map);
	free_map(map);
	return (0);
}
