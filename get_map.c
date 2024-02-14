/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:44:59 by apintus           #+#    #+#             */
/*   Updated: 2024/02/14 16:26:55 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **get_map(t_game *get_map, char *file_name)
{
    int fd;
    int i;
    char *line;
    char *temp;
    char *old_line;
    char **map;

    i = 0;
    line = NULL;
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        exit_read(get_map, "Error\nFile not found\n");
    while (1)
    {
        temp = get_next_line(fd, 0);
        if (temp == NULL)
        {
            if (i == 0)
                exit_read(get_map, "Error\nEmpty file\n");
            break;
        }
        if (temp[0] == '\n')
            exit_read(get_map, "Error\nMAp content not valid(nnn)\n");
        if (!line)
            line = ft_strdup("");
        old_line = line;
        line = ft_strjoin(old_line, temp);
        free(old_line);
        free(temp);
        i++;
    }
    printf("%s\n", line);//DEBUG
    get_map->map_height = i;
    printf("%d\n", get_map->map_height);//DEBUG
    map = ft_split(line, '\n');
    close(fd);
    free(line);
    int j = 0;//DEBUG
    while (map[j])
    {
        printf("%s\n", map[j]);
        j++;
    }
    return (map);
}
