/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:06:52 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/28 11:59:48 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_coor	*new_coor(int x, int y, int z, int color)
{
	t_coor *coor;

	coor = malloc(sizeof(t_coor));
	coor->x = x;
	coor->y = y;
	coor->z = z;
	coor->color = color;
	return (coor);
}
