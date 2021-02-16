/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:06:27 by apita-da          #+#    #+#             */
/*   Updated: 2021/02/05 17:47:16 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_lines(t_map *map, char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'R')
		get_resolution(map, line);
	if (line[i] == 'N')
		text_north(map, line);
	if (line[i] == 'S')
	{
		if (line[i + 1] == 'O')
			text_south(map, line);
		else
			text_sprite(map, line);
	}
	if (line[i] == 'W')
		text_west(map, line);
	if (line[i] == 'E')
		text_east(map, line);
	if (line[i] == 'F')
		colors_flo(map, line);
	if (line[i] == 'C')
		colors_cel(map, line);
	if (line[i] == '1' || line[i] == ' ')
		parse_map(map, line);
	return (0);
}
