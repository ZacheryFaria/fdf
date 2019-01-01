/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 11:58:34 by zfaria            #+#    #+#             */
/*   Updated: 2019/01/01 13:13:00 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include <libft.h>

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
	ret->ptr = mlx_get_data_addr(ret->img, &ret->bpp, &ret->sline, &ret->end);
	return (ret);
}

void	image_set_pixel(t_mlx *mlx, t_v2d *vec, int color)
{
	*((int *)mlx->img->ptr + (vec->x + (vec->y * mlx->width))) = color;
}

void	image_plot_line(t_mlx *mlx, t_v2d *v1, t_v2d *v2, int color)
{
	t_v2d	*dpoint;
	t_v2d	*sign;
	int		delta_err;
	t_v2d	*npoint;
	int		err;

	sign = vector_make_2d(v1->x < v2->x ? 1 : -1, v1->y < v2->y ? 1 : -1);
	dpoint = vector_make_2d(ft_abs(v2->x - v1->x), ft_abs(v2->y - v1->y));
	delta_err = (dpoint->x > dpoint->y ? dpoint->x : -dpoint->y) / 2;
	npoint = vector_make_2d(v1->x, v2->y);
	while (!(v1->x == v2->x && v1->y == v2->y))
	{
		image_set_pixel(mlx, v1, color);
		err = delta_err;
		if (err > -dpoint->x)
		{
			delta_err -= dpoint->y;
			v1->x += sign->x;
		}
		if (err < dpoint->y)
		{
			delta_err += dpoint->x;
			v1->y += sign->y;
		}
	}
}
