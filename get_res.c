/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:45:54 by apita-da          #+#    #+#             */
/*   Updated: 2021/02/05 12:42:40 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_resolution(t_map *map, char *line)
{
	line = line + 1;
	line = line + check_blanks(line);
	map->res_x = ft_atoi(line);
	line = line + intlen(map->res_x) + check_blanks(line);
	map->res_y = ft_atoi(line);
	return(0);
}
int		intlen(int i)
{
	int	num;

	num = 0;
	while(i != 0)
	{
		i = i / 10;
		num++;		
	}
	return(num);
}

int		ft_atoi(const char *str)
{
	int		cont;
	int		rest;
	int		sign;

	cont = 0;
	rest = 0;
	sign = 1;
	while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == '\f'
			|| str[cont] == '\v' || str[cont] == '\n' || str[cont] == '\r')
		cont++;
	while (str[cont] == '+' || str[cont] == '-')
	{
		if (str[cont] == '-')
			sign = -1;
		cont++;
	}
	while (str[cont] <= '9' && str[cont] >= '0')
	{
		rest = (rest * 10) + (str[cont] - 48);
		cont++;
	}
	return (rest * sign);
}