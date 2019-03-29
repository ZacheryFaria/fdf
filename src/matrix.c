/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:30:00 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/29 11:51:46 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <fdf.h>

void	rotate_x(t_coor *point, float thetacos, float thetasin)
{
	int		y;
	float	z;

	if (!point)
		return ;
	y = point->y;
	z = point->z * 25;
	point->y = y * thetacos + z * thetasin;
	point->z = -y * thetasin + z * thetacos;
}

void	rotate_y(t_coor *point, float thetacos, float thetasin)
{
	int		x;
	float	z;

	if (!point)
		return ;
	x = point->x;
	z = point->z;
	point->x = x * thetacos + z * thetasin;
	point->z = -x * thetasin + z * thetacos;
}

void	rotate_z(t_coor *point, float thetacos, float thetasin)
{
	int x;
	int y;

	if (!point)
		return ;
	x = point->x;
	y = point->y;
	point->x = x * thetacos - y * thetasin;
	point->y = x * thetasin + y * thetacos;
}
