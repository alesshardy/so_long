/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:13:09 by apintus           #+#    #+#             */
/*   Updated: 2024/02/13 17:53:17 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

//STRUCT
typedef struct s_game
{
	int	map_height;
	int	map_lenght;
	int	count_c;
	int	count_e;
	int	count_p;
	char **map;
	int	nombre_lignes;
}	t_game;

//PARSSING
int		check_extension(char *str);
int		check_map_content(t_game *map);
int		check_map_rectangle(t_game *map);
int		check_map_close(t_game *map);
int		check_map(t_game *map);
char	**get_map(t_game *get_map, char *file_name);
int		ft_strlen_so(char *str);
void	liberer_map(t_game *map);

#endif
