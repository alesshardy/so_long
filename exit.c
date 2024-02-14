/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:03:35 by apintus           #+#    #+#             */
/*   Updated: 2024/02/14 15:51:17 by apintus          ###   ########.fr       */
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