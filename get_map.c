/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:44:59 by apintus           #+#    #+#             */
/*   Updated: 2024/02/12 18:27:28 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/stat.h>
#include <fcntl.h>

void	liberer_map(t_game_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

int get_map(t_game_map *map, char *file_name) {
    int fd = open(file_name, O_RDONLY);
    if (fd < 0) {
        perror("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    map->map = (char **)malloc(INITIAL_CAPACITY * sizeof(char *));
    if (map->map == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour le tableau de chaînes");
        close(fd);
        return -1;
    }

    int capacity = INITIAL_CAPACITY;
    int i = 0;
    char *line;

    while ((line = get_next_line(fd, 0)) != NULL) {
        map->map[i] = strdup(line);
        free(line);

        i++;

        if (i >= capacity) {
            capacity += INCREMENT;
            char **new_map = realloc(map->map, capacity * sizeof(char *));
            if (new_map == NULL) {
                perror("Erreur lors de la réallocation de mémoire pour le tableau de chaînes");
                liberer_map(map);
                close(fd);
                return -1;
            }
            map->map = new_map;
        }
    }

    map->nombre_lignes = i;

    char **new_map = realloc(map->map, i * sizeof(char *));
    if (new_map == NULL) {
        perror("Erreur lors de la réallocation de mémoire pour le tableau de chaînes");
        liberer_map(map);
        close(fd);
        return -1;
    }
    map->map = new_map;

    close(fd);
    return 0;
}