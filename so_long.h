/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:13:09 by apintus           #+#    #+#             */
/*   Updated: 2024/02/15 13:24:44 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>

//STRUCT
typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_game
{
	int	map_height;
	int	map_lenght;
	int	count_c;
	int	count_e;
	int	count_p;
	char **map;
	int	nombre_lignes;
	t_pos	pos;
}	t_game;

//PARSSING
int		check_extension(char *str);
int		check_map_content(t_game *map);
int		check_map_rectangle(t_game *map);
int		check_map_close(t_game *map);
void	check_map(t_game *map);
char	**get_map(t_game *get_map, char *file_name);
int		ft_strlen_so(char *str);
void	init_count(t_game *map);

//FLOOD_FILL
char	**copy_map(t_game *map);
void	flood_fill(t_game *map, int x, int y, char **copy);
int		check_map_flood_fill(t_game *map);

//EXIT
void	exit_error(t_game *map, char *str);
void	exit_read(t_game *map, char *str);
void	free_copy(char **copy);
void	free_map(t_game *map);

//VISUAL
void	visual_map(char **map);

#endif
