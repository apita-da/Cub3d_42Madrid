/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:12:04 by apita-da          #+#    #+#             */
/*   Updated: 2021/02/05 12:43:38 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	text_north(t_map *map, char *line)
{
	line = line + 2;
	line = line + check_blanks(line);
	map->north = line;
	return(0);
}

char	text_south(t_map *map, char *line)
{
	if (line[2] != ' ')
	write(1, "error\n", 6);
	line = line + 3;
	line = line + check_blanks(line);
	map->south = line;
	return(0);

}

char	text_west(t_map *map, char *line)
{
	if (line[2] != ' ')
	write(1, "error\n", 6);
	line = line + 3;
	line = line + check_blanks(line);
	map->west = line;
	return(0);

}

char	text_east(t_map *map, char *line)
{
	if (line[2] != ' ')
	write(1, "error\n", 6);
	line = line + 3;
	line = line + check_blanks(line);
	map->east = line;
	return(0);

}

char	text_sprite(t_map *map, char *line)
{
	if (line[1] != ' ')
	write(1, "error\n", 6);
	line = line + 2;
	line = line + check_blanks(line);
	map->sprite = line;
	return(0);

}
