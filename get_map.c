/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:23:23 by apintus           #+#    #+#             */
/*   Updated: 2024/02/23 11:31:26 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_game *map)
{
	map->data.fd = 0;
	map->data.i = 0;
	map->data.check = 0;
	map->data.line = NULL;
	map->data.old_line = NULL;
	map->data.temp = NULL;
}

void	process_line(t_game *map)
{
	if (map->data.temp[0] == '\n')
		map->data.check++;
	if (!map->data.line)
		map->data.line = ft_strdup("");
	map->data.old_line = map->data.line;
	map->data.line = ft_strjoin(map->data.old_line, map->data.temp);
	free(map->data.old_line);
	free(map->data.temp);
	map->data.i++;
}

void	check_errors(t_game *map)
{
	if (map->data.check != 0)
	{
		free(map->data.line);
		exit_read(map, "Error\nMAp content not valid\n");
	}
}

char	**get_map(t_game *get_map, char *file_name)
{
	init_data(get_map);
	get_map->data.fd = open(file_name, O_RDONLY);
	if (get_map->data.fd < 0)
		exit_read(get_map, "Error\nFile not found\n");
	while (1)
	{
		get_map->data.temp = get_next_line(get_map->data.fd, 0);
		if (get_map->data.temp == NULL)
		{
			if (get_map->data.i == 0)
				exit_read(get_map, "Error\nEmpty file\n");
			break ;
		}
		process_line(get_map);
	}
	check_errors(get_map);
	get_map->map_height = get_map->data.i;
	get_map->data.map = ft_split(get_map->data.line, '\n');
	close(get_map->data.fd);
	free(get_map->data.line);
	return (get_map->data.map);
}
