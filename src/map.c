/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:45:19 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/02 11:52:39 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_map_point	*make_map_point(int x, int y, int z, int color)
{
	t_map_point *map;

	if ((map = malloc(sizeof(t_map_point))) == NULL)
		return (NULL);
	map->x = x;
	map->y = y;
	map->z = z;
	map->color = color;
	return (map);
}

t_map_point	**make_map_array(char *str)
{
	char		**strarr;
	t_map_point	**map_arr;

	strarr = ft_strsplit(str, ' ');
	map_arr = malloc(ft_arrlen((void **)strarr) * sizeof(t_map_point *));
	return (0);
}
