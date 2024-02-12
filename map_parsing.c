/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:24:01 by apintus           #+#    #+#             */
/*   Updated: 2024/02/12 15:46:45 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game_map *map)
{
	if (check_not_empty(map))
		return (1);
	if (check_map_rectangle(map))
		return (1);
	return (0);
}
