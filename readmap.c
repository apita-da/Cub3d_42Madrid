/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:36:53 by apita-da          #+#    #+#             */
/*   Updated: 2021/02/15 17:58:56 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*readmap(t_map *map, char *line)
{
	int		fd; 
	
	line = NULL;
	map->parse = NULL;
	fd = open("maps/map.cub", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		get_lines(map, line);
		free(line);
	}
	free(line);
	map->mapa = ft_split(map->parse, '\n');
	free(map->parse);
	close(fd);
	//system("leaks cub3d");
	return(map);
}
