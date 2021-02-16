/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:35:17 by apita-da          #+#    #+#             */
/*   Updated: 2021/02/05 17:56:32 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*parse_map(t_map *map, char *line)
{
	map->parse = str_join(map->parse, line);
	map->parse = str_join(map->parse, "\n");
	return(0);
}

