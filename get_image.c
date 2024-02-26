/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:34:14 by apintus           #+#    #+#             */
/*   Updated: 2024/02/22 19:26:02 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_spawn(t_game *map)
{
	char	*filenames[SPAWN_FRAMES];

	filenames[0] = "image/spawn/spawn0.xpm";
	filenames[1] = "image/spawn/spawn1.xpm";
	filenames[2] = "image/spawn/spawn2.xpm";
	filenames[3] = "image/spawn/spawn3.xpm";
	filenames[4] = "image/spawn/spawn4.xpm";
	filenames[5] = "image/spawn/spawn5.xpm";
	filenames[6] = "image/spawn/spawn6.xpm";
	filenames[7] = "image/spawn/spawn7.xpm";
	get_img_anim(map, filenames, (void **)map->spawn.anim, SPAWN_FRAMES);
}

void	get_player(t_game *map)
{
	char	*filenames[PLAYER_FRAMES];

	filenames[0] = "image/player/player.xpm";
	filenames[1] = "image/player/player1.xpm";
	filenames[2] = "image/player/player2.xpm";
	filenames[3] = "image/player/player3.xpm";
	filenames[4] = "image/player/player4.xpm";
	filenames[5] = "image/player/player5.xpm";
	get_img_anim(map, filenames, (void **)map->player.anim, PLAYER_FRAMES);
}

void	get_wall(t_game *map)
{
	char	*filenames[WALL_DELAY];

	filenames[0] = "image/wall/wall_0.xpm";
	filenames[1] = "image/wall/wall_1.xpm";
	filenames[2] = "image/wall/wall_2.xpm";
	filenames[3] = "image/wall/wall_3.xpm";
	filenames[4] = "image/wall/wall_4.xpm";
	filenames[5] = "image/wall/wall_5.xpm";
	filenames[6] = "image/wall/wall_6.xpm";
	filenames[7] = "image/wall/wall_7.xpm";
	filenames[8] = "image/wall/wall_8.xpm";
	filenames[9] = "image/wall/wall_9.xpm";
	filenames[10] = "image/wall/wall_10.xpm";
	filenames[11] = "image/wall/wall_11.xpm";
	filenames[12] = "image/wall/wall_12.xpm";
	filenames[13] = "image/wall/wall_13.xpm";
	filenames[14] = "image/wall/wall_14.xpm";
	filenames[15] = "image/wall/wall_15.xpm";
	filenames[16] = "image/wall/wall_16.xpm";
	filenames[17] = "image/wall/wall_17.xpm";
	get_img_anim(map, filenames, (void **)map->wall.anim, WALL_FRAMES);
}

void	get_exit(t_game *map)
{
	char	*filenames[EXIT_FRAMES];

	filenames[0] = "image/exit/exit1.xpm";
	filenames[1] = "image/exit/exit2.xpm";
	filenames[2] = "image/exit/exit3.xpm";
	filenames[3] = "image/exit/exit4.xpm";
	filenames[4] = "image/exit/exit5.xpm";
	filenames[5] = "image/exit/exit6.xpm";
	filenames[6] = "image/exit/exit7.xpm";
	filenames[7] = "image/exit/exit8.xpm";
	filenames[8] = "image/exit/exit9.xpm";
	filenames[9] = "image/exit/exit10.xpm";
	filenames[10] = "image/exit/exit11.xpm";
	filenames[11] = "image/exit/exit12.xpm";
	filenames[12] = "image/exit/exit13.xpm";
	filenames[13] = "image/exit/exit14.xpm";
	filenames[14] = "image/exit/exit15.xpm";
	filenames[15] = "image/exit/exit16.xpm";
	filenames[16] = "image/exit/exit17.xpm";
	filenames[17] = "image/exit/exit18.xpm";
	filenames[18] = "image/exit/exit19.xpm";
	get_img_anim(map, filenames, (void **)map->exit.anim, EXIT_FRAMES);
}

void	get_image(t_game *map)
{
	get_img(map, "image/floor/floor.xpm", (void **)&map->img.floor);
	get_img(map, "image/collectible/collect.xpm", (void **)&map->img.collect);
	get_img(map, "image/ennemie/hole2.xpm", (void **)&map->img.enemies);
	get_spawn(map);
	get_wall(map);
	get_exit(map);
	get_player(map);
}
