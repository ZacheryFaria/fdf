/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 11:45:19 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/02 14:00:07 by zfaria           ###   ########.fr       */
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

t_map_point	**make_map_array(char *str, int y)
{
	char		**strarr;
	t_map_point	**map_arr;
	char		**tmp;
	int			i;

	strarr = ft_strsplit(str, ' ');
	map_arr = malloc(ft_arrlen((void **)strarr) * sizeof(t_map_point *));
	i = 0;
	while (strarr[i])
	{
		tmp = ft_strsplit(strarr[i], ',');
		map_arr[i] = malloc(sizeof(t_map_point));
		map_arr[i]->x = i;
		map_arr[i]->y = y;
		map_arr[i]->z = ft_atoi(tmp[0]);
		map_arr[i]->color = 0;
		i++;
		free(tmp[0]);
		free(tmp[1]);
		free(tmp);
	}
	map_arr[i] = 0;
	return (map_arr);
}

#include <stdio.h>
void	printmap(t_map_point **map)
{
	for (int i = 0; map[i]; i++)
	{
		printf("%d:%d:%d:%d\n", map[i]->x, map[i]->y, map[i]->z, map[i]->color);
	}
}
