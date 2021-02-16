/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:44:33 by apita-da          #+#    #+#             */
/*   Updated: 2021/02/05 12:43:01 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		colors_cel(t_map *map, char *line)
{
	int	r;
	int	g;
	int	b;
	int	i;
	
	i = 0;
	if (line[1] != ' ')
		write(1, "error\n", 6);
	line = line + 2;
	r = ft_atoi(line);
	line = line + intlen(r) + 1;
	g = ft_atoi(line);
	line = line + intlen(g)  + 1;
	b = ft_atoi(line);
	map->cel_colors = rgb_int(r, g, b);
	return(0);
}
