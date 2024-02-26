/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:12:09 by apintus           #+#    #+#             */
/*   Updated: 2024/02/23 11:58:13 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	secure_pointer_anim(void **anim, int frames)
{
	int	i;

	i = 0;
	while (i < frames)
	{
		anim[i] = NULL;
		i++;
	}
}

void	ft_secure_pointer(t_game *map)
{
	map->count_c = 0;
	map->count_e = 0;
	map->count_p = 0;
	map->img.floor = NULL;
	map->img.collect = NULL;
	map->img.enemies = NULL;
	map->mlx = NULL;
	map->win = NULL;
	secure_pointer_anim((void **)map->player.anim, PLAYER_FRAMES);
	secure_pointer_anim((void **)map->wall.anim, WALL_FRAMES);
	secure_pointer_anim((void **)map->exit.anim, EXIT_FRAMES);
	secure_pointer_anim((void **)map->spawn.anim, SPAWN_FRAMES);
}

int	key_pressed(int keycode, t_game *map)
{
	if (keycode == KEY_ESC)
		close_game(map);
	if (keycode == KEY_W || keycode == KEY_UP)
		move_up(map);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_down(map);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_left(map);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_right(map);
	return (0);
}

void	exit_game(t_game *map, int win)
{
	map->count_steps += 1;
	ft_printf("steps %d\n", map->count_steps);
	if (win == 1)
		ft_printf("You win\n");
	else
		ft_printf("You lose\n");
	destroy_img(map);
	destroy_wall(map);
	destroy_exit(map);
	destroy_spawn(map);
	destroy_player(map);
	mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	*map;

	map = malloc(sizeof(t_game));
	if (map == NULL)
		return (ft_putstr_fd("Malloc error\n", 2), 1);
	ft_secure_pointer(map);
	if (argc != 2 || check_extension(argv[1]))
		return (free(map), ft_putstr_fd("Error\nWrong arg or extension\n", 2), 1);
	map->map = get_map(map, argv[1]);
	check_map(map);
	map->mlx = mlx_init();
	if (map->mlx == NULL)
		return (free_map(map), ft_putstr_fd("Error\nMlx error\n", 2), 1);
	init_game(map);
	mlx_hook(map->win, 2, 1L << 0, key_pressed, map);
	mlx_hook(map->win, 17, 1L << 17, close_game, map);
	mlx_loop(map->mlx);
	free_map(map);
	return (0);
}
