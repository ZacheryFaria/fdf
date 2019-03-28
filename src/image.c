/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 11:58:34 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/28 15:39:55 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include <fdf.h>

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

void	image_plot_line(t_mlx *mlx, t_coor v1, t_coor v2, int color)
{
	t_coor	dpoint;
	t_coor	sign;
	int		delta_err;
	t_coor	npoint;
	int		err;

	sign = (t_coor){v1.x < v2.x ? 1 : -1, v1.y < v2.y ? 1 : -1, 0, 0};
	dpoint = (t_coor){ft_abs(v2.x - v1.x), ft_abs(v2.y - v1.y), 0, 0};
	delta_err = (dpoint.x > dpoint.y ? dpoint.x : -dpoint.y) / 2;
	npoint = (t_coor){v1.x, v2.y, 0, 0};
	while (!(v1.x == v2.x && v1.y == v2.y))
	{
		image_set_pixel(mlx, &v1, color);
		err = delta_err;
		if (err > -dpoint.x)
		{
			delta_err -= dpoint.y;
			v1.x += sign.x;
		}
		if (err < dpoint.y)
		{
			delta_err += dpoint.x;
			v1.y += sign.y;
		}
	}
}
