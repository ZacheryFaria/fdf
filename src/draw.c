/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:54:13 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/28 12:04:01 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>
#include <math.h>
#include <colors.h>

#define SIZE 15

void	transform_point(t_coor *point)
{
	int lastx;
	int lasty;

	if (!point)
		return ;
	lastx = point->x;
	lasty = point->y;
	point->x = (lastx - lasty) * cos(0.523599);
	point->y = -point->z + (lastx + lasty) * sin(0.523599);
}

void	transform_points(t_coor *p[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		transform_point(p[i]);
		i++;
	}
}

void	point_add(t_coor *p[4], int x, int y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (p[i])
		{
			p[i]->x += x;
			p[i]->y += y;
		}
		i++;
	}
}

void	set_points(t_coor *p[4], int j, int i, t_list *points, int width, int height)
{
	int *point2;

	point2 = (int *)ft_lstat(points, 1);
	p[0] = COOR2(i * SIZE, j * SIZE);
	p[0]->z = ((int *)points->content)[i];
	if (i < width - 1)
	{
		p[1] = COOR2((i + 1) * SIZE, j * SIZE);
		p[1]->z = ((int *)points->content)[i + 1];
	}
	if (j < height - 1 && i < width - 1)
	{
		p[2] = COOR2(i * SIZE, (j + 1) * SIZE);
		p[2]->z = point2[i];
	}
	if (i < width - 1 && j < height - 1)
	{
		p[3] = COOR2((i + 1) * SIZE, (j + 1) * SIZE);
		p[3]->z = point2[i + 1];
	}
}

void	plot_map(t_mlx *mlx, t_list *points, int width)
{
	int i;
	int j;
	int	height;
	t_coor	*p[4];

	i = 0;
	j = 0;
	height = ft_lstlen(points);
	while (points)
	{
		i = 0;
		while (i < width)
		{
			p[0] = 0;
			p[1] = 0;
			p[2] = 0;
			p[3] = 0;
			set_points(p, j, i, points, width, height);
			transform_points(p);
			point_add(p, 250, 250);
			if (p[0] && p[1])
				image_plot_line(mlx, p[0], p[1], RED);
			if (p[2] && p[3])
				image_plot_line(mlx, p[2], p[3], RED);
			if (p[1] && p[3])
				image_plot_line(mlx, p[1], p[3], RED);	
			if (p[0] && p[2])
				image_plot_line(mlx, p[0], p[2], RED);
			freev(p[0], p[1], p[2], p[3], 0);
			i++;
		}
		j++;
		points = points->next;
	}
}
