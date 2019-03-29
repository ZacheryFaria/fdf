/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:54:13 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/29 11:55:26 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <fdf.h>
#include <math.h>
#include <colors.h>
#include <mlx.h>

#define SIZE 20

void	transform_points(t_mlx *mlx)
{
	int i;
	int j;
	t_proj x;
	t_proj y;
	t_proj z;

	i = 0;
	j = 0;
	x.deltax = cos(mlx->proj->deltax);
	x.deltay = sin(mlx->proj->deltax);
	y.deltax = cos(mlx->proj->deltay);
	y.deltay = sin(mlx->proj->deltay);
	z.deltax = cos(mlx->proj->deltaz);
	z.deltay = sin(mlx->proj->deltaz);
	while (i < mlx->maphei)
	{
		j = 0;
		while (j < mlx->mapwid)
		{
			rotate_x(&mlx->pbuf[i][j], x.deltax, x.deltay);
			rotate_y(&mlx->pbuf[i][j], y.deltax, y.deltay);
			rotate_z(&mlx->pbuf[i][j], z.deltax, z.deltay);
			j++;
		}
		i++;
	}
}

void	point_add(t_mlx *mlx, float x, float y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mlx->maphei)
	{
		j = 0;
		while (j < mlx->mapwid)
		{
			mlx->pbuf[i][j].x += x;
			mlx->pbuf[i][j].y += y;
			j++;
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

void	calc_points(t_mlx *mlx)
{
	int		i;
	int		j;
	int		wd;
	int		hd;
	t_list	*points;

	i = 0;
	j = 0;
	wd = mlx->mapwid / 2;
	hd = mlx->maphei / 2;
	points = mlx->points;
	while (points)
	{
		i = 0;
		while (i < mlx->mapwid)
		{
			mlx->pbuf[j][i].x = (i - wd) * (SIZE * mlx->zoom);
			mlx->pbuf[j][i].y = (j - hd) * (SIZE * mlx->zoom);
			mlx->pbuf[j][i].z = -((int *)points->content)[i] * mlx->zoom;
			i++;
		}
		j++;
		points = points->next;
	}
}

void	plot_map(t_mlx *mlx)
{
	int i;
	int j;

	i = 0;
	j = 0;
	calc_points(mlx);
	transform_points(mlx);
	point_add(mlx, mlx->width / 2, mlx->height / 2);
	point_add(mlx, mlx->origin->x, mlx->origin->y);
	while (i < mlx->maphei)
	{
		j = 0;
		while (j < mlx->mapwid)
		{
			if (j < mlx->mapwid - 1)
				image_plot_line(mlx, mlx->pbuf[i][j], mlx->pbuf[i][j + 1], RED);
			if (i < mlx->maphei - 1)
				image_plot_line(mlx, mlx->pbuf[i][j], mlx->pbuf[i + 1][j], RED);
			j++;
		}
		i++;
	}
}

void	redraw(t_mlx *mlx)
{
	ft_bzero(mlx->img->ptr, mlx->img->wid * mlx->height);
	plot_map(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
