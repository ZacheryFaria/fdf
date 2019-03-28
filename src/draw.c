/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:54:13 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/28 15:39:03 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>
#include <math.h>
#include <colors.h>
#include <mlx.h>

#define SIZE 20

void	transform_points(t_coor *p[4], t_proj *proj)
{
	int i;

	i = 0;
	while (i < 4)
	{
		rotate_x(p[i], proj->deltax);
		rotate_y(p[i], proj->deltay);
		rotate_z(p[i], proj->deltaz);
		i++;
	}
}

void	point_add(t_coor *p[4], float x, float y)
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

void	set_points(t_coor *p[4], int j, int i, t_list *points, t_mlx *mlx)
{
	int *point2;
	int	wd;
	int hd;

	wd = mlx->mapwid / 2;
	hd = mlx->maphei / 2;
	point2 = (int *)ft_lstat(points, 1);
	p[0] = COOR2((i - wd) * (SIZE * mlx->zoom), (j - hd) * (SIZE * mlx->zoom));
	p[0]->z = -((int *)points->content)[i] * mlx->zoom;
	if (i < mlx->mapwid - 1)
	{
		p[1] = COOR2(((i - wd) + 1) * (SIZE * mlx->zoom), (j - hd) * (SIZE * mlx->zoom));
		p[1]->z = -((int *)points->content)[i + 1] * mlx->zoom;
	}
	if (j < mlx->maphei - 1 && i < mlx->mapwid - 1)
	{
		p[2] = COOR2((i - wd) * (SIZE * mlx->zoom), ((j - hd) + 1) * (SIZE * mlx->zoom));
		p[2]->z = -point2[i] * mlx->zoom;
	}
	if (i < mlx->mapwid - 1 && j < mlx->maphei - 1)
	{
		p[3] = COOR2(((i - wd) + 1) * (SIZE * mlx->zoom), ((j - hd) + 1) * (SIZE * mlx->zoom));
		p[3]->z = -point2[i + 1] * mlx->zoom;
	}
}

void	plot_map(t_mlx *mlx)
{
	int i;
	int j;
	t_coor	*p[4];
	t_list	*points;

	i = 0;
	j = 0;
	points = mlx->points;
	while (points)
	{
		i = 0;
		while (i < mlx->mapwid)
		{
			p[0] = 0;
			p[1] = 0;
			p[2] = 0;
			p[3] = 0;
			set_points(p, j, i, points, mlx);
			transform_points(p, mlx->proj);
			point_add(p, mlx->width / 2, mlx->height / 2);
			point_add(p, mlx->origin->x, mlx->origin->y);
			if (p[0] && p[1])
				image_plot_line(mlx, *p[0], *p[1], RED);
			if (p[2] && p[3])
				image_plot_line(mlx, *p[2], *p[3], RED);
			if (p[1] && p[3])
				image_plot_line(mlx, *p[1], *p[3], RED);	
			if (p[0] && p[2])
				image_plot_line(mlx, *p[0], *p[2], RED);
			freev(p[0], p[1], p[2], p[3], 0);
			i++;
		}
		j++;
		points = points->next;
	}
}

void	redraw(t_mlx *mlx)
{
	ft_bzero(mlx->img->ptr, mlx->img->wid * mlx->height);
	plot_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
