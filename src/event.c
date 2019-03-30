/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zfaria <zfaria@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 10:08:56 by zfaria            #+#    #+#             */
/*   Updated: 2019/03/30 14:48:02 by zfaria           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

#define TRANS 10
#define ROTS .075

void	event_trans(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (keycode == 24)
		mlx->zoom *= 1.1;
	if (keycode == 27)
		mlx->zoom /= 1.1;
	if (keycode == 13)
		mlx->origin->y -= TRANS;
	if (keycode == 0)
		mlx->origin->x -= TRANS;
	if (keycode == 1)
		mlx->origin->y += TRANS;
	if (keycode == 2)
		mlx->origin->x += TRANS;
}

void	event_rot(int keycode, void *param)
{
	t_mlx *mlx;

	mlx = param;
	if (keycode == 123)
		mlx->proj->deltay += ROTS;
	if (keycode == 124)
		mlx->proj->deltay -= ROTS;
	if (keycode == 125)
		mlx->proj->deltax -= ROTS;
	if (keycode == 126)
		mlx->proj->deltax += ROTS;
	if (keycode == 116)
		mlx->proj->deltaz += ROTS;
	if (keycode == 121)
		mlx->proj->deltaz -= ROTS;
}

int		event_key(int keycode, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(((t_mlx *)param)->mlx, ((t_mlx *)param)->win);
		exit(0);
	}
	if (keycode == 34)
		mlx->proj = &ISO_21;
	event_trans(keycode, param);
	event_rot(keycode, param);
	redraw(mlx);
	return (0);
}

int		event_close(void)
{
	exit(0);
}
