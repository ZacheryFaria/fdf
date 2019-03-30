/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 11:17:23 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/30 14:20:16 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

int	event_mouse(int x, int y, void *ptr)
{
	t_mlx *mlx;

	mlx = ptr;
	if (mlx->rotate == 0)
	{
		mlx->mouse_p.x = x;
		mlx->mouse_p.y = y;
	}
	else
		mlx->update = 1;
	mlx->mouse_c.x = x;
	mlx->mouse_c.y = y;
	return (0);
}

int	event_mouse_pressed(int keycode, int x, int y, void *ptr)
{
	t_mlx *mlx;

	mlx = ptr;
	(void)x;
	(void)y;
	if (keycode == 1)
	{
		mlx->rotate = 1;
	}
	return (0);
}

int	event_mouse_released(int keycode, int x, int y, void *ptr)
{
	t_mlx *mlx;

	mlx = ptr;
	(void)x;
	(void)y;
	if (keycode == 1)
	{
		mlx->rotate = 0;
	}
	return (0);
}

int	fdf_loop(void *ptr)
{
	t_mlx *mlx;

	mlx = ptr;
	if (mlx->update)
	{
		mlx->update = 0;
		mlx->proj->deltay += (mlx->mouse_c.x - mlx->mouse_p.x) / 100.0;
		mlx->proj->deltax += (mlx->mouse_c.y - mlx->mouse_p.y) / 100.0;
		mlx->mouse_p.x = mlx->mouse_c.x;
		mlx->mouse_p.y = mlx->mouse_c.y;
		redraw(mlx);
	}
	return (0);
}
