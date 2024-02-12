/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:13:09 by apintus           #+#    #+#             */
/*   Updated: 2024/02/12 18:26:29 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

#define INITIAL_CAPACITY 10
#define INCREMENT 2

typedef struct s_game_map
{
	int	map_height;
	int	map_lenght;
	char **map;
	int	nombre_lignes;
}	t_game_map;

//PARSSING
int		check_extension(char *str);
int		check_map(t_game_map *map);
int		check_map_rectangle(t_game_map *map);
int		check_not_empty(t_game_map *map);
int		get_map(t_game_map *map, char *file_name);
int		ft_strlen_so(char *str);
void	liberer_map(t_game_map *map);
int		ft_read_map_file(char *fn, int *he, int *le, t_game_map **map);

#endif
