/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 11:58:34 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/30 12:36:23 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include <fdf.h>
#include <stdio.h>

t_image	*image_new(t_mlx *mlx)
{
	t_image *ret;

	if (!(ret = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!(ret->img = mlx_new_image(mlx->mlx, mlx->width, mlx->height)))
	{
		free(ret);
		return (NULL);
	}
	ret->ptr = (int *)mlx_get_data_addr(ret->img, &ret->bpp,
		&ret->wid, &ret->end);
	return (ret);
}

void	image_set_pixel(t_mlx *mlx, t_coor *vec, int color)
{
	if (vec->y + 1 >= mlx->height)
		return ;
	if (!(vec->x < 0 || vec->x >= mlx->width)
		&& !(vec->y < 0 || vec->y >= mlx->height))
		mlx->img->ptr[(int)(vec->x + (vec->y * mlx->img->wid / 4))] = color;
}

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_coor start, t_coor end, t_coor current, t_coor delta)
{
	double	p;
	int		red;
	int		green;
	int		blue;

	if (delta.x > delta.y)
		p = percent(start.x, end.x, current.x);
	else
		p = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, p);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, p);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, p);
	return ((red << 16) | (green << 8) | blue);
}

void	image_plot_line(t_mlx *mlx, t_coor v1, t_coor v2)
{
	t_coor	delta;
	t_coor	sign;
	t_coor	err;
	t_coor	npoint;
	t_coor	orig;

	orig = v1;
	sign = (t_coor){v1.x < v2.x ? 1 : -1, v1.y < v2.y ? 1 : -1, 0, 0};
	delta = (t_coor){ft_abs(v2.x - v1.x), ft_abs(v2.y - v1.y), 0, 0};
	err.x = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	npoint = (t_coor){v1.x, v2.y, 0, 0};
	while (!(v1.x == v2.x && v1.y == v2.y))
	{
		image_set_pixel(mlx, &v1, get_color(orig, v2, v1, delta));
		err.y = err.x;
		if (err.y > -delta.x)
		{
			err.x -= delta.y;
			v1.x += sign.x;
		}
		if (err.y < delta.y)
		{
			err.x += delta.x;
			v1.y += sign.y;
		}
	}
}
