/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:30:00 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/28 15:33:18 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <fdf.h>

void	rotate_x(t_coor *point, double theta)
{
	int		y;
	double	z;

	if (!point)
		return ;
	y = point->y;
	z = point->z * 25;
	point->y = y * cos(theta) + z * sin(theta);
	point->z = -y * sin(theta) + z * cos(theta);
}

void	rotate_y(t_coor *point, double theta)
{
	int		x;
	double	z;

	if (!point)
		return ;
	x = point->x;
	z = point->z;
	point->x = x * cos(theta) + z * sin(theta);
	point->z = -x * sin(theta) + z * cos(theta);
}

void	rotate_z(t_coor *point, double theta)
{
	int x;
	int y;

	if (!point)
		return ;
	x = point->x;
	y = point->y;
	point->x = x * cos(theta) - y * sin(theta);
	point->y = x * sin(theta) + y * cos(theta);
}
