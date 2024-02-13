/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:33:01 by apintus           #+#    #+#             */
/*   Updated: 2024/02/13 15:08:12 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_so(char *str)
{
	int	i;

	while (str[i])
		i++;
	return (i);
}

int	check_extension(char *str)
{
	if (str[0] == '.')
		return (1);
	while (*str != '.' && *str != '\0')
		str++;
	if (*str == '.')
	{
		str++;
		if (ft_strlen_so(str) == 3)
		{
			if (str[0] == 'b' && str[1] == 'e' && str[2] == 'r')
				return (0);
		}
	}
	return (1);
}
